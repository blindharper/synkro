//==============================================================================
// This file stream a part of the Synkro Project.
// 
// Copyright (c) Nobody. No rights reserved ;-7
//
// The contents herein is the property of the Mankind.
// Use, distribution and modification of this source code
// is allowed without any permission from the Synkro Project.
// Website: https://synkro.pro Email: mailto:blindharper70@gmail.com
//
// Purpose: Implements Jpg image codec.
//==============================================================================
#include "config.h"
#include "JpgImageCodec.h"

#ifndef XMD_H
#	define XMD_H
#endif // XMD_H

#ifdef FAR
#	undef FAR
#endif // FAR

extern "C"
{
#include <libjpeg/jpeglib.h>
#include <libjpeg/jinclude.h>
#include <libjpeg/jerror.h>
}

//------------------------------------------------------------------------------

using namespace synkro::io;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace img
{


//-----------------------------------------------------------------------------

METHODDEF(void) errorExit( j_common_ptr cinfo )
{
	jpeg_abort( cinfo );
	jpeg_destroy( cinfo );
	throw Exception();
}

METHODDEF(void) outputMessage( j_common_ptr )
{
}

//-----------------------------------------------------------------------------

JpgImageCodec::JpgImageCodec( Float quality ) :
	ImageCodecImpl<IImageCodec>( quality )
{
}

void JpgImageCodec::LoadSurface( IStream* stream, ImageCodecContext* context )
{
	jpeg_error_mgr errMgr;
	Zero( &errMgr );
	errMgr.error_exit = errorExit;
	errMgr.output_message = outputMessage;

	jpeg_decompress_struct cinfo;
	Zero( &cinfo );
	cinfo.err = jpeg_std_error( &errMgr );
	jpeg_create_decompress( &cinfo );

	jpeg_stdio_src( &cinfo, stream, context );
	jpeg_read_header( &cinfo, TRUE );
	jpeg_start_decompress( &cinfo );

	const PixelFormat srcFormat = (cinfo.output_components == 3) ? PixelFormat::B8G8R8 : PixelFormat::R8;
	PixelFormat dstFormat = GetImageFormat( context );
	const PixelFormat format = GetImageFormat( context );
	const UInt bpp = srcFormat.BytesPerPixel();
	const UInt width = cinfo.output_width;
	const UInt height = cinfo.output_height;
	const UInt stride = cinfo.output_width*bpp;

	// Set destination format.
	if ( dstFormat == PixelFormat::Unknown )
	{
		dstFormat = srcFormat;
	}
	SetImageFormat( context, dstFormat );

	// Allocate image.
	const UInt dstStride = width * dstFormat.BytesPerPixel();
	const UInt size = cinfo.output_width * cinfo.output_height * bpp;
	Byte* img = CreateSurface( context, width, height, dstStride, nullptr, height*dstStride );

	// Read pixels.
	Vector<Byte> buffer( A(Byte), stride );
	buffer.SetSize( stride );
	Byte* scanlinebuff = buffer.Begin();
	while ( cinfo.output_scanline < cinfo.output_height ) 
	{
		// Read scanline.
		Int scanlineindex = CastInt(cinfo.output_scanline)*CastInt(dstStride);
		Byte* scanline = (Byte*)(img + scanlineindex);
		jpeg_read_scanlines( &cinfo, reinterpret_cast<JSAMPARRAY>(&scanlinebuff), 1 );

		// Convert scanline to destination format.
		if ( cinfo.output_components == 3 )
		{
			if ( dstFormat == PixelFormat::B8G8R8 )
				Copy( scanline, scanlinebuff, stride );
			else
				PixelFormatEx::CopyPixels( scanline, dstFormat, scanlinebuff, PixelFormat::B8G8R8, CastUInt(cinfo.output_width) );
		}
		else if ( cinfo.output_components == 1 )
		{
			if ( dstFormat == PixelFormat::R8 )
				Copy( scanline, scanlinebuff, stride );
			else
				PixelFormatEx::CopyPixels( scanline, dstFormat, scanlinebuff, PixelFormat::R8, CastUInt(cinfo.output_width) );
		}
	}

	// Uninitialize decompressor.
	jpeg_finish_decompress( &cinfo );
	jpeg_destroy_decompress( &cinfo );
}

void JpgImageCodec::SaveSurface( IStream* stream, const Byte* data, ImageCodecContext* context )
{
	// See if the requested format is supported.
	if ( (context->Format != PixelFormat::R8) && (context->Format.BitsPerPixel() != 24) )
		throw Exception( L"Formats other than grayscale or 24-bit are not supported." );

	// Get pixel format with swapped red and blue channels.
	PixelFormat dstFormat = context->Format;
	if ( context->Format == PixelFormat::R8G8B8 )
	{
		dstFormat = PixelFormat::B8G8R8;
	}
	else if ( context->Format == PixelFormat::B8G8R8 )
	{
		dstFormat = PixelFormat::R8G8B8;
	}

	const UInt width = GetImageWidth( context );
	const UInt height = GetImageHeight( context );
	const UInt stride = GetImageStride( context );
	PixelFormat fmt = GetImageFormat( context );
	const UInt dstStride = width * dstFormat.BytesPerPixel();

	jpeg_error_mgr errMgr;
	Zero( &errMgr );
	errMgr.error_exit = errorExit;
	errMgr.output_message = outputMessage;

	jpeg_compress_struct cinfo;
	Zero( &cinfo );
	cinfo.err = jpeg_std_error( &errMgr );
	jpeg_create_compress( &cinfo );
	jpeg_stdio_dest( &cinfo, stream );

	// Set parameters.
	cinfo.image_width = width;
	cinfo.image_height = height;
	cinfo.input_components = dstFormat.BytesPerPixel();
	cinfo.in_color_space = ( (cinfo.input_components == 3) ? JCS_RGB : JCS_GRAYSCALE );
	jpeg_set_defaults( &cinfo );
	jpeg_set_quality( &cinfo, (int)(100.0f*_quality), TRUE );
	jpeg_start_compress( &cinfo, TRUE );

	// Write pixels.
	Vector<Byte> buffer( A(Byte), dstStride );
	buffer.SetSize( dstStride );
	Byte* dstline = buffer.Begin();
	for ( UInt i = 0; i < height ; ++i )
	{
		// Copy scanline.
		Int scanlineindex = i*width*fmt.BytesPerPixel();
		Byte* scanline = (Byte*)(data + scanlineindex);
		if ( dstFormat == fmt )
			Copy( dstline, scanline, dstStride );
		else
			PixelFormatEx::CopyPixels( dstline, dstFormat, scanline, fmt, width );
		jpeg_write_scanlines( &cinfo, reinterpret_cast<JSAMPARRAY>(&dstline), 1 );
	}

	// Uninitialize compressor.
	jpeg_finish_compress( &cinfo );
	jpeg_destroy_compress( &cinfo );
}


} // img


} // synkro
