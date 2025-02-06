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
// Purpose: Implements Png image codec.
//==============================================================================
#include "config.h"
#include "PngImageCodec.h"
#include <libpng/png.h>


//------------------------------------------------------------------------------

using namespace synkro::io;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace img
{


static void png_read( png_structp png_ptr, png_bytep data, png_size_t length )
{
	IStream* s = (IStream*)png_ptr->io_ptr;
	s->Read( (void*)data, CastUInt(length) );
}

static void png_write( png_structp png_ptr, png_bytep data, png_size_t length )
{
	IStream* s = (IStream*)png_ptr->io_ptr;
	s->Write( (void*)data, CastUInt(length) );
}

static void png_flush( png_structp png_ptr )
{
	IStream* s = (IStream*)png_ptr->io_ptr;
	s->Flush();
}

static void png_error_func( png_structp png_ptr, png_const_charp message )
{
	throw Exception( message );
}

static void png_warn_func( png_structp png_ptr, png_const_charp message )
{
	return;
}

//------------------------------------------------------------------------------

PngImageCodec::PngImageCodec( Float quality ) :
	ImageCodecImpl<IImageCodec>( quality )
{
}

void PngImageCodec::LoadSurface( IStream* stream, ImageCodecContext* context )
{
	UInt width = 0;
	UInt height = 0;
	UInt stride = 0;
	int colorType = 0;
	int bpp = 0;
	int channels = 0;
	png_uint_32 w, h;
	png_bytepp row_pointers = nullptr;

	// Initialize png reader.
	png_structp png_ptr = png_create_read_struct( PNG_LIBPNG_VER_STRING, nullptr, png_error_func, png_warn_func );
	if ( !png_ptr )
		throw Exception( L"Failed to initialize PNG reader." );

	// Set custom I/O routine.
	png_ptr->io_ptr = stream;

	// Allocate/initialize the memory for image information.
	png_infop info_ptr = png_create_info_struct( png_ptr );
	if ( !info_ptr )
	{
		png_destroy_read_struct( &png_ptr, nullptr, nullptr );
		throw Exception( L"Failed to initialize PNG reader." );
	}

	// Set function pointers.
	png_set_read_fn( png_ptr, stream, png_read );
	png_set_error_fn( png_ptr, stream, png_error_func, png_warn_func );

	// Read file info up to image data.
	png_read_info( png_ptr, info_ptr );

	// Read image header.
	if ( setjmp(png_ptr->jmpbuf) )
	{
		png_destroy_read_struct( &png_ptr, &info_ptr, nullptr );
		throw Exception();
	}

	png_get_IHDR( png_ptr, info_ptr, &w, &h, &bpp, &colorType, nullptr, nullptr, nullptr );
	width = w;
	height = h;
	stride = w;

	// Expand palette images to RGB, low-bit-depth grayscale images to 8 bits,
	// transparency chunks to full alpha channel; strip 16-bit-per-sample
	// images to 8 bits per sample; and convert grayscale to RGB[A]
	if ( (colorType == PNG_COLOR_TYPE_GRAY) && (bpp < 8) )
	{
		png_set_expand( png_ptr );
	}

	// Expand paletted colors into true RGB triplets
	if ( colorType | PNG_COLOR_TYPE_PALETTE )
	{
		png_set_expand( png_ptr );
	}

	// Expand paletted or RGB images with transparency to full alpha channels
	// so the data will be available as RGBA quartets.
	if ( png_get_valid(png_ptr, info_ptr, PNG_INFO_tRNS) )
	{
		png_set_expand( png_ptr );
	}

	if ( bpp < 8 )
	{
		bpp = 8;
	}

	// Determine color depth.
	bpp = info_ptr->pixel_depth;

	// Determine pixel format.
	PixelFormat format = GetImageFormat( context );
	if ( colorType == PNG_COLOR_TYPE_GRAY_ALPHA )
	{
		png_set_gray_to_rgb( png_ptr );
		format = PixelFormat::R8;
	}
	else if ( colorType == PNG_COLOR_TYPE_RGBA )
	{
		if ( info_ptr->pixel_depth == 32 )
			format = PixelFormat::R8G8B8A8;
	}
	else if ( colorType == PNG_COLOR_TYPE_RGB )
	{
		if ( info_ptr->pixel_depth == 24 )
			format = PixelFormat::R8G8B8;
	}

	png_read_update_info( png_ptr, info_ptr );
	channels = png_get_channels( png_ptr, info_ptr );

	// Allocate image.
	UInt dstStride = width * format.BytesPerPixel();
	Byte* img = CreateSurface( context, width, height, dstStride, nullptr, height*dstStride );

	// Allocate array of row pointers.
	row_pointers = (png_bytepp)new Byte[height * sizeof(png_bytep)];

	// Set the individual row_pointers to point at the correct offsets.
	for ( UInt i = 0; i < height; ++i )
	{
		row_pointers[i] = (png_bytep)img + i*dstStride;
	}

	// Read the entire image.
	png_read_image( png_ptr, row_pointers );

	// Perform clean-up.
	png_destroy_read_struct( &png_ptr, &info_ptr, nullptr );

	// Free array of row pointers.
	delete row_pointers;
}

void PngImageCodec::SaveSurface( IStream* stream, const Byte* data, ImageCodecContext* context )
{
	// See if the requested format is supported.
	if ( (context->Format.BitsPerPixel() != 32) && (context->Format.BitsPerPixel() != 24) )
		throw Exception( L"Formats other than 32-bit or 24-bit are not supported." );

	/*_is = stream;*/
	const UInt width = GetImageWidth( context );
	const UInt height = GetImageHeight( context );
	const UInt stride = GetImageStride( context );

	// Create compressor.
	png_structp png_ptr; png_infop info_ptr; png_colorp palette;
	png_ptr = png_create_write_struct( PNG_LIBPNG_VER_STRING, nullptr, png_error_func, png_warn_func );
	if ( png_ptr == nullptr )
		throw Exception( L"Failed to initialize PNG writer." );

	// Set custom I/O routine.
	png_ptr->io_ptr = stream;

	// Allocate/initialize the image information data.
	info_ptr = png_create_info_struct( png_ptr );
	if ( info_ptr == nullptr )
	{
		png_destroy_write_struct( &png_ptr, (png_infopp)nullptr );
		throw Exception( L"Failed to initialize PNG writer." );
	}

	// Set function pointers.
	png_set_write_fn( png_ptr, stream, png_write, png_flush );
	png_set_error_fn( png_ptr, stream, png_error_func, png_warn_func );

	// Set color type.
	int color_type = PNG_COLOR_TYPE_RGB;
	switch ( context->Format.BitsPerPixel() )
	{
		case 32: color_type = PNG_COLOR_TYPE_RGBA; break;
		case 24: color_type = PNG_COLOR_TYPE_RGB; break;
	}
	png_set_IHDR( png_ptr, info_ptr, width, height, 8, color_type, PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE );

	// Set the palette if there is one.
	palette = (png_colorp)png_malloc( png_ptr, PNG_MAX_PALETTE_LENGTH * sizeof(png_color) );

	// Set palette colors.
	png_set_PLTE( png_ptr, info_ptr, palette, PNG_MAX_PALETTE_LENGTH );

	// Write file header information.
	png_write_info( png_ptr, info_ptr );

	// Invert monochrome pixels.
	png_set_invert_mono( png_ptr );

	// Pack pixels into bytes.
	png_set_packing( png_ptr );

	// Swap location of alpha bytes from ARGB to RGBA.
	png_set_swap_alpha( png_ptr );

	// Get rid of filler (OR ALPHA) bytes, pack XRGB/RGBX/ARGB/RGBA into RGB (4 channels -> 3 channels).
	png_set_filler( png_ptr, 0, PNG_FILLER_BEFORE );

	// Flip BGR pixels to RGB.
	png_set_bgr( png_ptr );

	// Swap bytes of 16-bit files to most significant byte first.
	png_set_swap( png_ptr );

	// Swap bits of 1, 2, 4 bit packed pixel formats.
	png_set_packswap( png_ptr );

	// Allocate image.
	int bytes_per_pixel = context->Format.BytesPerPixel();
	png_bytep image0 = (png_bytep)new Byte[height*width*bytes_per_pixel];
	png_bytep* row_pointers = (png_bytep*)new Byte[height * sizeof(png_bytep)];
	for ( UInt k = 0; k < height; ++k )
	{
		row_pointers[k] = image0 + k*width*bytes_per_pixel;
	}

	// Write scanlines.
	png_write_image( png_ptr, row_pointers );

	// Flush output buffer.
	png_write_end( png_ptr, info_ptr );

	// Free pallette.
	png_free( png_ptr, palette );
	palette = nullptr;

	// Free allocated memory.
	png_free( png_ptr, nullptr );

	// Uninitialize compressor.
	png_destroy_write_struct( &png_ptr, &info_ptr );

	delete image0;
}


} // img


} // synkro
