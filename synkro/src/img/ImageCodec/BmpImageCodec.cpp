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
// Purpose: Implements Bmp image codec.
//==============================================================================
#include "config.h"
#include "BmpImageCodec.h"


//------------------------------------------------------------------------------

using namespace synkro::io;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace img
{


BmpImageCodec::BmpImageCodec( Float quality ) :
	ImageCodecImpl<IImageCodec>( quality )
{
}

void BmpImageCodec::LoadSurface( IStream* stream, ImageCodecContext* context )
{
	Int width = 0; Int height = 0;
	UInt planeCount = 0; UInt bitCount = 0; UInt pad = 0;
	UInt mapEntrySize = 0; UInt compression = 0; UInt usedCount = 0;

	// Read file header.
	BITMAPFILEHEADER filehdr;
	UInt bytes = Read( context, stream, &filehdr, sizeof(filehdr) );
	if ( bytes < sizeof(filehdr) )
		throw Exception( L"Wrong bmp file header." );

	// Verify BM magic.
	if ( filehdr.bfType != 0x4D42 )
		throw Exception( L"Wrong bmp file magic." );

	// Verify file size.
	if ( filehdr.bfSize != stream->GetLength() )
		throw Exception( L"Wrong bmp file length." );

	// Read info header.
	DWORD dwSize = 0;
	bytes = Read( context, stream, &dwSize, sizeof(dwSize) );
	if ( bytes < sizeof(dwSize) )
		throw Exception( L"Wrong bmp info header." );

	if ( dwSize == sizeof(BITMAPINFOHEADER) )
	{
		BITMAPINFOHEADER infohdr;
		bytes = Read( context, stream, &infohdr.biWidth, sizeof(infohdr)-sizeof(dwSize) );
		if ( bytes < sizeof(infohdr)-sizeof(dwSize) )
			throw Exception( L"Wrong bmp info header." );

		width = infohdr.biWidth;
		height = infohdr.biHeight;
		planeCount = infohdr.biPlanes;
		bitCount = infohdr.biBitCount;
		pad = filehdr.bfOffBits - (dwSize + sizeof(BITMAPFILEHEADER));
		compression = infohdr.biCompression;
		usedCount = infohdr.biClrUsed;
		if ( (bitCount == 4) || (bitCount == 8) )
		{
			mapEntrySize = 4;
		}
	}
	else if ( dwSize == sizeof(BITMAPCOREHEADER) )
	{
		BITMAPCOREHEADER infohdr;
		bytes = Read( context, stream, &infohdr.bcWidth, sizeof(infohdr)-sizeof(dwSize) );
		if ( bytes < sizeof(infohdr)-sizeof(dwSize) )
			throw Exception( L"Wrong bmp info header." );

		width = infohdr.bcWidth;
		height = infohdr.bcHeight;
		planeCount = infohdr.bcPlanes;
		bitCount = infohdr.bcBitCount;
		pad = filehdr.bfOffBits - (dwSize + sizeof(BITMAPFILEHEADER));
		if ( bitCount == 8 )
		{
			mapEntrySize = 3;
		}
	}

	// Read colormap if any.
	RGBA colormap[256] = {};
	if ( mapEntrySize > 0 )
	{
		if ( usedCount == 0 )
			usedCount = (1 << bitCount);
		if ( usedCount > 256 )
			throw Exception( L"Wrong used color count." );

		pad -= usedCount * mapEntrySize;
		Read( context, stream, colormap, usedCount*mapEntrySize );
	}
	Seek( context, stream, pad, SeekOrigin::Current );

	// Calculate row stride aligned to 4-byte boundary.
	PixelFormat srcFormat = PixelFormat::Unknown;
	switch ( bitCount )
	{
		case 16: srcFormat = PixelFormat::R5G5B5X1; break;
		case 24: srcFormat = PixelFormat::R8G8B8; break;
		case 32: srcFormat = PixelFormat::R8G8B8A8; break;
	}
	PixelFormat dstFormat = GetImageFormat( context );
	UInt stride = (width * bitCount) >> 3;
	stride += 3; stride &= ~3;

	// Set destination format.
	if ( dstFormat == PixelFormat::Unknown )
	{
		dstFormat = srcFormat;
	}
	SetImageFormat( context, dstFormat );

	// Allocate image.
	UInt dstStride = width * dstFormat.BytesPerPixel();
	Byte* img = CreateSurface( context, width, height, dstStride, nullptr, height*dstStride );

	// Read pixels.
	Vector<Byte> buffer( A(Byte), stride );
	buffer.SetSize( stride );
	Byte* scanline = buffer.Begin();
	for ( Int j = height - 1; j >= 0 ; --j )
	{
		Read( context, stream, scanline, stride );
		Byte* dstline = (Byte*)(img + j*dstStride);
		UInt k = 0;

		switch ( bitCount )
		{
			case 4:
				for ( Int i = 0 ; i < width ; ++i )
				{
					UInt idx = scanline[i>>1];
					if ( (i & 1) == 0 )
					{
						idx >>= 4;
					}
					idx &= 0xF;
					dstline[k++] = colormap[idx].Blue;
				}
				break;

			case 8:
				for ( Int i = 0 ; i < width ; ++i )
				{
					UInt idx = scanline[i];
					dstline[k++] = colormap[idx].Blue;
				}
				break;

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
		}
	}
}

void BmpImageCodec::SaveSurface( IStream* stream, const Byte* data, ImageCodecContext* context )
{
	// See if the requested format is supported.
	if ( (context->Format.BitsPerPixel() != 32) && (context->Format.BitsPerPixel() != 24) )
		throw Exception( L"Formats other than 32-bit or 24-bit are not supported." );

	const UInt width = GetImageWidth( context );
	const UInt height = GetImageHeight( context );
	const PixelFormat fmt = GetImageFormat( context );
	const UInt stride = width * fmt.BytesPerPixel();
	UInt dstStride = width * context->Format.BytesPerPixel();
	dstStride += 3L; dstStride &= ~3L;
	const Int hdrSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

	// Write file header.
	BITMAPFILEHEADER filehdr;
	Zero( &filehdr );
	filehdr.bfType = 0x4D42;
	filehdr.bfSize = hdrSize + dstStride*height;
	filehdr.bfOffBits = hdrSize ;
	stream->Write( &filehdr, sizeof(filehdr) );

	// Write bitmap header.
	BITMAPINFOHEADER infohdr;
	Zero( &infohdr );
	infohdr.biSize = sizeof(infohdr);
	infohdr.biWidth = width;
	infohdr.biHeight = height;
	infohdr.biPlanes = 1;
	infohdr.biBitCount = context->Format.BitsPerPixel();
	stream->Write( &infohdr, sizeof(infohdr) );

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


} // img


} // synkro
