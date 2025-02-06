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
// Purpose: Implements Targa image codec.
//==============================================================================
#include "config.h"
#include "TgaImageCodec.h"


//------------------------------------------------------------------------------

using namespace synkro::io;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace img
{


#define TARGATYPE_NONE 0
#define TARGATYPE_INDEXED 1
#define TARGATYPE_RGB 2
#define TARGATYPE_GRAY 3

#define TARGAFLAG_VERT_FLIP	0x10
#define TARGAFLAG_HORZ_FLIP	0x01


//------------------------------------------------------------------------------


TgaImageCodec::TgaImageCodec( Float quality ) :
	ImageCodecImpl<IImageCodec>( quality )
{
}

void TgaImageCodec::LoadSurface( IStream* stream, ImageCodecContext* context )
{
	// Read file header.
	const Byte identsize = ReadByte( context, stream );
	const Byte colormaptype = ReadByte( context, stream );
	const Byte imagetype = ReadByte( context, stream );
	const UShort colormapstart = ReadShort( context, stream );
	const UShort colormaplength = ReadShort( context, stream );
	const Byte colormapbits = ReadByte( context, stream );
	const UShort xstart = ReadShort( context, stream );
	const UShort ystart = ReadShort( context, stream );
	const UShort w = ReadShort( context, stream );
	const UShort h = ReadShort( context, stream );
	const Byte bits = ReadByte( context, stream );
	const Byte descriptor = ReadByte( context, stream );

	const UInt idLength = identsize;
	const UInt cmapType = colormaptype;
	const UInt subType = imagetype;
	const UInt cmapLength = colormaplength;
	const UInt cmapEntrySize = colormapbits >> 3;
	const UInt width = w;
	const UInt height = h;
	const UInt bitsPerPixel = bits;
	const UInt desc = descriptor;
	const Bool bottomUp = ((desc & TARGAFLAG_VERT_FLIP) != 0);
	const UInt interlaceType = CastInt( unsigned(desc) >> 6 );
	const Bool rle = (subType > 8);
	const UInt stride = width * ((bitsPerPixel+7) >> 3);

	if ( (cmapType > 1) || ((bitsPerPixel%8) != 0) || (interlaceType != 0) )
		throw Exception( L"Bad Targa file." );

	if ( rle )
		throw Exception( L"RLE Targa files are not supported." );

	// Skip identifier.
	Seek( context, stream, idLength, SeekOrigin::Current );

	// Read colormap.
	RGBA colormap[256] = {};
	if ( cmapLength > 0 )
	{
		if ( (cmapLength > 256) || ((colormapstart) != 0) )
			throw Exception( L"Bad Targa file." );

		Read( context, stream, colormap, cmapEntrySize*cmapLength );
	}
	else if ( cmapType != 0 )
	{
		throw Exception( L"Bad Targa file." );
	}

	PixelFormat srcFormat = PixelFormat::Unknown;
	switch ( bitsPerPixel )
	{
		case 16: srcFormat = PixelFormat::R5G5B5X1; break;
		case 24: srcFormat = PixelFormat::R8G8B8; break;
		case 32: srcFormat = PixelFormat::R8G8B8A8; break;
	}
	PixelFormat dstFormat = GetImageFormat( context );

	// Set destination format.
	if ( dstFormat == PixelFormat::Unknown )
	{
		dstFormat = srcFormat;
	}
	SetImageFormat( context, dstFormat );

	// Allocate image.
	UInt dstStride = width * dstFormat.BytesPerPixel();
	const UInt size = height * dstStride;
	Byte* img = CreateSurface( context, width, height, dstStride, nullptr, height*dstStride );
		
	// Read pixels.
	Vector<Byte> buffer( A(Byte), stride );
	buffer.SetSize( stride );
	Byte* scanline = buffer.Begin();
	for ( Int j = 0; j < CastInt(height); ++j )
	{
		Read( context, stream, scanline, stride );
		Int j1 = bottomUp ? (height - j-1) : j;
		Byte* dstline = (Byte*)(img + j1*dstStride);

		switch ( subType )
		{
			case TARGATYPE_INDEXED:
				if ( (bitsPerPixel == 8) && (cmapType == 1) )
				{
					Int k = 0;
					for ( Int i = 0; i < CastInt(width); ++i )
					{
						const Int idx = scanline[i];
						dstline[k++] = colormap[idx].Blue;
						dstline[k++] = colormap[idx].Green;
						dstline[k++] = colormap[idx].Red;
					}
				}
				else
				{
					throw Exception( L"Bad Targa file." );
				}
				break;

			case TARGATYPE_RGB:
				switch ( bitsPerPixel )
				{
					case 16:
						if ( dstFormat == PixelFormat::R5G5B5X1 )
							Copy( dstline, scanline, stride );
						else
							PixelFormatEx::CopyPixels( dstline, dstFormat, scanline, PixelFormat::R5G5B5X1, width );
						break;

					case 24:
						if ( dstFormat == PixelFormat::R8G8B8 )
							Copy( dstline, scanline, stride );
						else
							PixelFormatEx::CopyPixels( dstline, dstFormat, scanline, PixelFormat::R8G8B8, width );
						break;

					case 32:
						if ( dstFormat == PixelFormat::R8G8B8A8 )
							Copy( dstline, scanline, stride );
						else
							PixelFormatEx::CopyPixels( dstline, dstFormat, scanline, PixelFormat::R8G8B8A8, width );
						break;

					default:
						throw Exception( L"Bad Targa file." );
				}
				break;

			case TARGATYPE_GRAY:
				if ( bitsPerPixel == 8 )
				{
					Int k = 0;
					for ( Int i = 0; i < CastInt(width); ++i )
					{
						dstline[k++] = scanline[i];
						dstline[k++] = scanline[i];
						dstline[k++] = scanline[i];
					}
				}
				else
				{
					throw Exception( L"Bad Targa file." );
				}
				break;

			default:
				throw Exception( L"Bad Targa file." );
		}
	}
}

void TgaImageCodec::SaveSurface( IStream* stream, const Byte* data, ImageCodecContext* context )
{
	// See if the requested format is supported.
	if ( (context->Format != PixelFormat::R8) && (context->Format != PixelFormat::R5G5B5X1) && (context->Format != PixelFormat::R8G8B8) && (context->Format != PixelFormat::R8G8B8A8) )
		throw Exception( L"Formats other than grayscale, 16-bit, 24-bit or 32-bit are not supported." );

	const UInt width = GetImageWidth( context );
	const UInt height = GetImageHeight( context );
	const PixelFormat fmt = GetImageFormat( context );
	const UInt stride = width * fmt.BytesPerPixel();
	const UInt dstStride = width * context->Format.BytesPerPixel();

	// Write header.
	WriteByte( stream, 0 ); // identsize
	WriteByte( stream, 0 ); // colormaptype
	WriteByte( stream, (context->Format == PixelFormat::R8) ? TARGATYPE_GRAY : TARGATYPE_RGB ); // imagetype
	WriteShort( stream, 0 ); // colormapstart
	WriteShort( stream, 0 ); // colormaplength
	WriteByte( stream, 0 ); // colormapbits
	WriteShort( stream, 0 ); // xstart
	WriteShort( stream, 0 ); // ystart
	WriteShort( stream, CastShort(width) ); // width
	WriteShort( stream, CastShort(height) ); // height
	WriteByte( stream, CastByte(context->Format.BitsPerPixel()) ); // bits
	WriteByte( stream, CastByte(TARGAFLAG_VERT_FLIP) ); // descriptor

	// Write pixels.
	Vector<Byte> buffer( A(Byte), dstStride );
	buffer.SetSize( dstStride );
	Byte* dstline = buffer.Begin();
	for ( Int i = height-1; i >= 0; --i )
	{
		const Byte* srcline = data + i*stride;
		if ( context->Format == fmt )
			Copy( dstline, srcline, stride );
		else
			PixelFormatEx::CopyPixels( dstline, context->Format, srcline, fmt, width );
		stream->Write( dstline, dstStride );
	}
}

void TgaImageCodec::WriteByte( IStream* stream, Byte b )
{
	stream->Write( &b, sizeof(Byte) );
}

void TgaImageCodec::WriteShort( IStream* stream, UShort s )
{
	stream->Write( &s, sizeof(UShort) );
}

Byte TgaImageCodec::ReadByte( ImageCodecContext* context, IStream* stream )
{
	Byte b = 0;
	const UInt bytes = Read( context, stream, &b, sizeof(Byte) );
	if ( bytes < sizeof(Byte) )
		throw Exception( L"Wrong targa file header." );

	return b;
}

UShort TgaImageCodec::ReadShort( ImageCodecContext* context, IStream* stream )
{
	UShort s = 0;
	const UInt bytes = Read( context, stream, &s, sizeof(UShort) );
	if ( bytes < sizeof(UShort) )
		throw Exception( L"Wrong targa file header." );

	return s;
}


} // img


} // synkro
