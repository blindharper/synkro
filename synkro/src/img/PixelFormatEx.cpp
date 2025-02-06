//==============================================================================
// This file is a part of the Synkro Framework.
// 
// Copyright (c) Nobody. No rights reserved ;-7
//
// The contents herein is the property of the Mankind.
// Use, distribution and modification of this source code
// is allowed without any permission from the Synkro Project.
// Website: https://synkro.pro Email: mailto:blindharper70@gmail.com
//
// Purpose: Defines extended pixel format.
//==============================================================================
#include "config.h"
#include "PixelFormatEx.h"
#include <lang/BadArgumentException.h>
#include <math/Math.h>


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::lang;
using namespace synkro::math;

//------------------------------------------------------------------------------


namespace synkro
{


namespace img
{


struct PixelFormatDesc
{
	UInt	type;
	UInt	red;
	UInt	green;
	UInt	blue;
	UInt	alpha;
};

static PixelFormatDesc _formats[] = 
{
	{ /*PixelFormat::Unknown*/			0,		0x00000000,	0x00000000,	0x00000000,	0x00000000 },
	{ /*PixelFormat::R32G32B32A32F*/	1,		0x00000000,	0x00000000,	0x00000000,	0x00000000 },
	{ /*PixelFormat::R32G32F*/			2,		0x00000000,	0x00000000,	0x00000000,	0x00000000 },
	{ /*PixelFormat::R16G16B16A16F*/	3,		0x00000000,	0x00000000,	0x00000000,	0x00000000 },
	{ /*PixelFormat::R16G16B16A16*/		4,		0x00000000,	0x00000000,	0x00000000,	0x00000000 },
	{ /*PixelFormat::R32F*/				5,		0x00000000,	0x00000000,	0x00000000,	0x00000000 },
	{ /*PixelFormat::R16G16F*/			6,		0x00000000,	0x00000000,	0x00000000,	0x00000000 },
	{ /*PixelFormat::R10G10B10A2*/		7,		0x3ff00000,	0x000ffc00,	0x000003ff,	0xc0000000 },
	{ /*PixelFormat::R16G16*/			8,		0xffff0000,	0x0000ffff,	0x00000000,	0x00000000 },
	{ /*PixelFormat::R8G8B8A8*/			9,		0x00ff0000,	0x0000ff00,	0x000000ff,	0xff000000 },
	{ /*PixelFormat::R8G8B8X8*/			10,		0x00ff0000,	0x0000ff00,	0x000000ff,	0x00000000 },
	{ /*PixelFormat::B8G8R8A8*/			11,		0x000000ff,	0x0000ff00,	0x00ff0000,	0xff000000 },
	{ /*PixelFormat::B8G8R8X8*/			12,		0x000000ff,	0x0000ff00,	0x00ff0000,	0x00000000 },
	{ /*PixelFormat::R8G8B8*/			13,		0x00ff0000,	0x0000ff00,	0x000000ff,	0x00000000 },
	{ /*PixelFormat::B8G8R8*/			14,		0x000000ff,	0x0000ff00,	0x00ff0000,	0x00000000 },
	{ /*PixelFormat::R16F*/				15,		0x00000000,	0x00000000,	0x00000000,	0x00000000 },
	{ /*PixelFormat::R5G5B5A1*/			16,		0x00007c00, 0x000003e0, 0x0000001f, 0x00008000 },
	{ /*PixelFormat::R5G5B5X1*/			17,		0x00007c00, 0x000003e0, 0x0000001f, 0x00000000 },
	{ /*PixelFormat::R5G6B5*/			18,		0x0000f800, 0x000007e0, 0x0000001f, 0x00000000 },
	{ /*PixelFormat::R4G4B4A4*/			19,		0x00000f00, 0x000000f0, 0x0000000f, 0x0000f000 },
	{ /*PixelFormat::R4G4B4X4*/			20,		0x00000f00, 0x000000f0, 0x0000000f, 0x00000000 },
	{ /*PixelFormat::R3G3B2A8*/			21,		0x000000e0, 0x0000001c, 0x00000003, 0x0000ff00 },
	{ /*PixelFormat::R3G2B3A8*/			22,		0x000000e0, 0x00000018, 0x00000007, 0x0000ff00 },
	{ /*PixelFormat::R3G3B2*/			23,		0x000000e0, 0x0000001c, 0x00000003, 0x00000000 },
	{ /*PixelFormat::R3G2B3*/			24,		0x000000e0, 0x00000018, 0x00000007, 0x00000000 },
	{ /*PixelFormat::R8*/				25,		0x000000ff, 0x000000ff, 0x000000ff, 0x00000000 },
	{ /*PixelFormat::A8*/				26,		0x00000000, 0x00000000, 0x00000000, 0x000000ff },
	{ /*PixelFormat::BC1*/				27,		0x00000000,	0x00000000,	0x00000000,	0x00000000 },
	{ /*PixelFormat::BC2*/				28,		0x00000000,	0x00000000,	0x00000000,	0x00000000 },
	{ /*PixelFormat::BC3*/				29,		0x00000000,	0x00000000,	0x00000000,	0x00000000 },
	{ /*PixelFormat::BC4*/				30,		0x00000000,	0x00000000,	0x00000000,	0x00000000 },
	{ /*PixelFormat::BC5*/				31,		0x00000000,	0x00000000,	0x00000000,	0x00000000 },
};
const UInt _formatCount = sizeof(_formats)/sizeof(_formats[0]);

UInt GetPixelFormat( UInt red, UInt green, UInt blue, UInt alpha )
{
	for ( UInt i = 0; i < _formatCount; ++i )
	{
		PixelFormatDesc& pf = _formats[i];
		if ( (pf.red == red) && (pf.green == green) && 
			 (pf.blue == blue) && (pf.alpha == alpha) )
			return pf.type;
	}

	return 0;
}

//------------------------------------------------------------------------------

// Internal image description.
struct ImageDesc
{
	const Byte* data;
	UInt		width;
	UInt		height;
	UInt		stride;
	UInt		pixelSize;
	UInt		maskR;
	UInt		maskG;
	UInt		maskB;
	Int			shiftR;
	Int			shiftG;
	Int			shiftB;
	Byte		transR;
	Byte		transG;
	Byte		transB;
};

// Returns left shift (=zero bit count before first non-zero bit) from a bit mask.
static SYNKRO_INLINE Int GetShiftByMask( UInt mask )
{
	Int count = 0;
	UInt testBit = 1;
	if ( mask == 0 )
		return 32;

	while ( (mask & testBit) == 0 )
	{
		++count;
		testBit <<= 1;
	}
	return count;
}

// Returns number of non-zero bits in the dword.
static SYNKRO_INLINE Int BitCount( UInt mask )
{
	Int count = 0;
	UInt testBit = 1;
	while ( testBit != 0 )
	{
		if ( (mask & testBit) != 0 )
			++count;
		testBit <<= 1;
	}
	return count;
}

//------------------------------------------------------------------------------

void PixelFormatEx::SetAlpha( Byte* data, const PixelFormat& format, UInt width, UInt height, UInt stride, const Byte* alpha, UInt strideAlpha )
{
	assert( data != nullptr );
	assert( format != PixelFormat::Unknown );

	if ( data == nullptr )
		throw BadArgumentException( L"Missing image data.", L"data" );

	if ( format == PixelFormat::Unknown )
		throw BadArgumentException( L"Unknown pixel format.", L"format" );

	if ( alpha == 0 )
		throw BadArgumentException( L"Missing alpha channel data.", L"alpha" );

	Byte* pixel = 0;
	UInt pixelSize = format.BitsPerPixel() >> 3;

	const Byte* pixelAlpha = 0;
	const UInt pixelSizeAlpha = 8;

	// Compute aux channel variables.
	const UInt maskR = _formats[format].red;
	const UInt maskG = _formats[format].green;
	const UInt maskB = _formats[format].blue;
	const UInt maskA = _formats[format].alpha;
	const Int shiftR = GetShiftByMask( maskR );
	const Int shiftG = GetShiftByMask( maskG );
	const Int shiftB = GetShiftByMask( maskB );
	const Int shiftA = GetShiftByMask( maskA );

	// Iterate through pixels.
	for ( UInt y = 0; y < height; ++y )
	{
		// Get scanline.
		pixel = data + y*stride;
		pixelAlpha = alpha + y*strideAlpha;

		for ( UInt x = 0; x < width; ++x )
		{
			// Get pixel value.
			UInt value = 0;
			switch ( pixelSize )
			{
				case 4:	value |= (UInt)pixel[3] << 24;
				case 3:	value |= (UInt)pixel[2] << 16;
				case 2:	value |= (UInt)pixel[1] << 8;
				case 1:	value |= (UInt)pixel[0];
			}

			// Get color channels.
			const Byte r = (value & maskR) >> shiftR;
			const Byte g = (value & maskG) >> shiftG;
			const Byte b = (value & maskB) >> shiftB;
			const Byte a = *pixelAlpha;

			// Set alpha channel value.
			value = 0;
			value |= CastUInt(((maskR >> shiftR) & r) << shiftR);
			value |= CastUInt(((maskG >> shiftG) & g) << shiftG);
			value |= CastUInt(((maskB >> shiftB) & b) << shiftB);
			value |= CastUInt(((maskA >> shiftA) & a) << shiftA);

			// Write pixel value.
			switch ( pixelSize )
			{
				case 4:	pixel[3] = CastByte(value >> 24);
				case 3:	pixel[2] = CastByte(value >> 16);
				case 2:	pixel[1] = CastByte(value >> 8);
				case 1:	pixel[0] = CastByte(value);
			}

			// Move to next pixel.
			pixel += pixelSize;
			pixelAlpha += 1;
		}
	}
}

void PixelFormatEx::SetAlpha( Byte* data, const PixelFormat& format, UInt width, UInt height, UInt stride, const Color& color, Byte alpha )
{
	assert( data != nullptr );
	assert( format != PixelFormat::Unknown );

	if ( data == nullptr)
		throw BadArgumentException( L"Missing image data.", L"data");

	if ( format == PixelFormat::Unknown )
		throw BadArgumentException( L"Unknown pixel format.", L"format");

	Byte* pixel = nullptr;
	UInt pixelSize = format.BitsPerPixel() >> 3;

	// Compute aux channel variables.
	const UInt maskR = _formats[format].red;
	const UInt maskG = _formats[format].green;
	const UInt maskB = _formats[format].blue;
	const UInt maskA = _formats[format].alpha;
	const Int shiftR = GetShiftByMask( maskR );
	const Int shiftG = GetShiftByMask( maskG );
	const Int shiftB = GetShiftByMask( maskB );
	const Int shiftA = GetShiftByMask( maskA );

	const Byte red = CastByte(255 * color.R);
	const Byte green = CastByte(255 * color.G);
	const Byte blue = CastByte(255 * color.B);

	// Iterate through pixels.
	for ( UInt y = 0; y < height; ++y )
	{
		// Get scanline.
		pixel = data + y*stride;
		for ( UInt x = 0; x < width; ++x )
		{
			// Get pixel value.
			UInt value = 0;
			switch ( pixelSize )
			{
				case 4:	value |= (UInt)pixel[3] << 24;
				case 3:	value |= (UInt)pixel[2] << 16;
				case 2:	value |= (UInt)pixel[1] << 8;
				case 1:	value |= (UInt)pixel[0];
			}

			// Get color channels.
			const Byte r = (value & maskR) >> shiftR;
			const Byte g = (value & maskG) >> shiftG;
			const Byte b = (value & maskB) >> shiftB;
			if ( (r == red) && (g == green) && (b == blue) )
			{
				// Set alpha channel value.
				value = 0;
				value |= CastUInt(((maskR >> shiftR) & r) << shiftR);
				value |= CastUInt(((maskG >> shiftG) & g) << shiftG);
				value |= CastUInt(((maskB >> shiftB) & b) << shiftB);
				value |= CastUInt(((maskA >> shiftA) & alpha) << shiftA);

				// Write pixel value.
				switch ( pixelSize )
				{
					case 4:	pixel[3] = CastByte(value >> 24);
					case 3:	pixel[2] = CastByte(value >> 16);
					case 2:	pixel[1] = CastByte(value >> 8);
					case 1:	pixel[0] = CastByte(value);
				}
			}

			// Move to next pixel.
			pixel += pixelSize;
		}
	}
}

void PixelFormatEx::SetPixel( Byte* data, const PixelFormat& format, UInt width, UInt height, UInt stride, UInt x, UInt y, const Color& color )
{
	assert( data != nullptr );
	assert( format != PixelFormat::Unknown );
	assert( x < width );
	assert( y < height );

	if ( data == nullptr )
		throw BadArgumentException( L"Missing image data.", L"data" );

	if ( format == PixelFormat::Unknown )
		throw BadArgumentException( L"Unknown pixel format.", L"format" );

	if ( (x >= width) || (y >= height) )
		throw BadArgumentException( L"Invalid pixel coordinate.", L"coordinate" );

	// Locate pixel data.
	UInt pixelSize = format.BitsPerPixel() >> 3;
	Byte* pixel = data + (y*stride + x*pixelSize);

	// Compute aux channel variables.
	const UInt maskR = _formats[format].red;
	const UInt maskG = _formats[format].green;
	const UInt maskB = _formats[format].blue;
	const UInt maskA = _formats[format].alpha;
	const Int shiftR = GetShiftByMask( maskR );
	const Int shiftG = GetShiftByMask( maskG );
	const Int shiftB = GetShiftByMask( maskB );
	const Int shiftA = GetShiftByMask( maskA );

	// Convert pixel value.
	const Byte r = CastByte(255 * color.R);
	const Byte g = CastByte(255 * color.G);
	const Byte b = CastByte(255 * color.B);
	const Byte a = CastByte(255);

	UInt value = 0;
	value |= CastUInt(((maskR >> shiftR) & r) << shiftR);
	value |= CastUInt(((maskG >> shiftG) & g) << shiftG);
	value |= CastUInt(((maskB >> shiftB) & b) << shiftB);
	value |= CastUInt(((maskA >> shiftA) & a) << shiftA);

	// Write pixel value.
	switch ( pixelSize )
	{
		case 4:	pixel[3] = CastByte(value >> 24);
		case 3:	pixel[2] = CastByte(value >> 16);
		case 2:	pixel[1] = CastByte(value >> 8);
		case 1:	pixel[0] = CastByte(value);
	}
}

Color PixelFormatEx::GetPixel( const Byte* data, const PixelFormat& format, UInt width, UInt height, UInt stride, UInt x, UInt y )
{
	assert( data != nullptr );
	assert( format != PixelFormat::Unknown );
	assert( x < width );
	assert( y < height );

	// Validate arguments.
	if ( data == nullptr )
		throw BadArgumentException( L"Missing image data.", L"data" );

	if ( format == PixelFormat::Unknown )
		throw BadArgumentException( L"Unknown pixel format.", L"format" );

	if ( (x >= width) || (y >= height) )
		throw BadArgumentException( L"Invalid pixel coordinate.", L"coordinate" );

	// Locate pixel data.
	const UInt pixelSize = format.BitsPerPixel() >> 3;
	const Byte* pixel = data + (y*stride + x*pixelSize);
	UInt value = 0;
	switch ( pixelSize )
	{
		case 4:	value |= (UInt)pixel[3] << 24;
		case 3:	value |= (UInt)pixel[2] << 16;
		case 2:	value |= (UInt)pixel[1] << 8;
		case 1:	value |= (UInt)pixel[0];
	}

	// Compute aux channel variables.
	const UInt maskR = _formats[format].red;
	const UInt maskG = _formats[format].green;
	const UInt maskB = _formats[format].blue;
	const UInt maskA = _formats[format].alpha;
	const Int shiftR = GetShiftByMask( maskR );
	const Int shiftG = GetShiftByMask( maskG );
	const Int shiftB = GetShiftByMask( maskB );
	const Int shiftA = GetShiftByMask( maskA );

	// Calculate channel values.
	const Byte r = (value & maskR) >> shiftR;
	const Byte g = (value & maskG) >> shiftG;
	const Byte b = (value & maskB) >> shiftB;
	const Byte a = (value & maskA) >> shiftA;

	return Color( r, g, b );
}

void PixelFormatEx::CopyPixels( Byte* dst, const PixelFormat& dstFormat, const Byte* src, const PixelFormat& srcFormat, UInt pixels )
{
	assert( srcFormat != PixelFormat::Unknown );

	const Byte* srcBytes = src;
	Byte* dstBytes = dst;
	const UInt srcPixelSize = srcFormat.BitsPerPixel() >> 3;
	const UInt dstPixelSize = dstFormat.BitsPerPixel() >> 3;
	const UInt* srcMasks = &_formats[srcFormat].red;
	const UInt* dstMasks = &_formats[dstFormat].red;
	Int srcBits[4] = {}; Int dstBits[4] = {}; Int srcShifts[4] = {}; Int dstShifts[4] = {};
	UInt srcPixel = 0; UInt dstPixel = CastUInt(-1);

	// Compute aux channel variables.
	for ( UInt i = 0; i < 4; ++i )
	{
		srcBits[i] = BitCount( srcMasks[i] );
		dstBits[i] = BitCount( dstMasks[i] );
		srcShifts[i] = GetShiftByMask( srcMasks[i] );
		dstShifts[i] = GetShiftByMask( dstMasks[i] );
	}

	for ( UInt i = 0; i < pixels; ++i )
	{
		// Read pixel.
		srcPixel = 0;
		switch ( srcPixelSize )
		{
			case 4:	srcPixel |= (UInt)srcBytes[3] << 24;
			case 3:	srcPixel |= (UInt)srcBytes[2] << 16;
			case 2:	srcPixel |= (UInt)srcBytes[1] << 8;
			case 1:	srcPixel |= (UInt)srcBytes[0];
		}

		// Convert pixel.
		dstPixel = CastUInt(-1);
		for ( Int k = 0; k < 4; ++k )
		{
			const UInt srcVal = ((srcPixel & srcMasks[k]) >> srcShifts[k]) << (8-srcBits[k]);
			const UInt dstVal = (srcVal >> (8-dstBits[k])) << dstShifts[k];
			dstPixel = (dstPixel & ~dstMasks[k]) | dstVal;
			if ( srcBits[k] == 0 )
				dstPixel |= dstMasks[k];
		}

		// Write pixel.
		switch ( dstPixelSize )
		{
			case 4:	dstBytes[3] = CastByte(dstPixel >> 24);
			case 3:	dstBytes[2] = CastByte(dstPixel >> 16);
			case 2:	dstBytes[1] = CastByte(dstPixel >> 8);
			case 1:	dstBytes[0] = CastByte(dstPixel);
		}

		// Move to next pixel.
		srcBytes += srcPixelSize;
		dstBytes += dstPixelSize;
	}
}

void PixelFormatEx::CopyPixels( Byte* dst, const PixelFormat& dstFormat, UInt dstStride, UInt dstX, UInt dstY, UInt dstWidth, UInt dstHeight, const Byte* src, const PixelFormat& srcFormat, UInt srcStride, UInt srcX, UInt srcY )
{
	assert( dst != nullptr );
	assert( dstFormat != PixelFormat::Unknown );
	assert( src != nullptr);
	assert( srcFormat != PixelFormat::Unknown );

	// Validate arguments.
	if ( dst == nullptr )
		throw BadArgumentException( L"Bad destination image data.", L"dst" );

	if ( dstFormat == PixelFormat::Unknown )
		throw BadArgumentException( L"Unknown destination pixel format.", L"dstFormat" );

	if ( src == nullptr )
		throw BadArgumentException( L"Bad source image data.", L"src" );

	if ( srcFormat == PixelFormat::Unknown )
		throw BadArgumentException( L"Unknown source pixel format.", L"srcFormat" );

	Byte* dstPixel = nullptr;
	const Byte* srcPixel = nullptr;
	UInt dstPixelSize = dstFormat.BitsPerPixel() >> 3;
	const UInt srcPixelSize = srcFormat.BitsPerPixel() >> 3;
	const UInt* srcMasks = &_formats[srcFormat].red;
	const UInt* dstMasks = &_formats[dstFormat].red;
	Int srcBits[4] = {}; Int dstBits[4] = {}; Int srcShifts[4] = {}; Int dstShifts[4] = {};

	// Compute aux channel variables.
	for ( UInt i = 0; i < 4; ++i )
	{
		srcBits[i] = BitCount( srcMasks[i] );
		dstBits[i] = BitCount( dstMasks[i] );
		srcShifts[i] = GetShiftByMask( srcMasks[i] );
		dstShifts[i] = GetShiftByMask( dstMasks[i] );
	}

	// Iterate through pixels.
	const UInt y1 = dstY + dstHeight;
	UInt yS = srcY;
	for ( UInt y = dstY; y < y1; ++y, ++yS )
	{
		const UInt x1 = dstX + dstWidth;
		UInt xS = srcX;
		for ( UInt x = dstX; x < x1; ++x, ++xS )
		{
			// Locate dst and src pixels.
			dstPixel = dst + y*dstStride + x*dstPixelSize;
			srcPixel = src + yS*srcStride + xS*srcPixelSize;

			// Read pixel.
			UInt srcValue = 0;
			switch ( srcPixelSize )
			{
				case 4:	srcValue |= (UInt)srcPixel[3] << 24;
				case 3:	srcValue |= (UInt)srcPixel[2] << 16;
				case 2:	srcValue |= (UInt)srcPixel[1] << 8;
				case 1:	srcValue |= (UInt)srcPixel[0];
			}

			// Convert pixel.
			UInt dstValue = CastInt(-1);
			for ( Int k = 0; k < 4; ++k )
			{
				const UInt srcVal = ((srcValue & srcMasks[k]) >> srcShifts[k]) << (8-srcBits[k]);
				const UInt dstVal = (srcVal >> (8-dstBits[k])) << dstShifts[k];
				dstValue = (dstValue & ~dstMasks[k]) | dstVal;
				if ( srcBits[k] == 0 )
					dstValue |= dstMasks[k];
			}

			// Write pixel.
			switch ( dstPixelSize )
			{
				case 4:	dstPixel[3] = CastByte(dstValue >> 24);
				case 3:	dstPixel[2] = CastByte(dstValue >> 16);
				case 2:	dstPixel[1] = CastByte(dstValue >> 8);
				case 1:	dstPixel[0] = CastByte(dstValue);
			}
		}
	}
}

static UInt GetNonEmptyColumn( ImageDesc& img, UInt left, UInt top, UInt bottom )
{
	const Byte* p = nullptr; UInt value = 0;
	for ( UInt x = left; x < img.width; ++x )
	{
		for ( UInt y = top; y < bottom; ++y )
		{
			p = img.data + y*img.stride + x*img.pixelSize;
			value = 0;
			switch ( img.pixelSize )
			{
				case 4:	value |= (UInt)p[3] << 24;
				case 3:	value |= (UInt)p[2] << 16;
				case 2:	value |= (UInt)p[1] << 8;
				case 1:	value |= (UInt)p[0];
			}
			const Byte r = (value & img.maskR) >> img.shiftR;
			const Byte g = (value & img.maskG) >> img.shiftG;
			const Byte b = (value & img.maskB) >> img.shiftB;

			if ( (r != img.transR) || (g != img.transG) || (b != img.transB) )
			{
				return x;
			}
		}
	}
	return none;
}

static UInt GetEmptyColumn( ImageDesc& img, UInt left, UInt top, UInt bottom )
{
	const Byte* p = nullptr; UInt value = 0;
	for ( UInt x = left; x < img.width; ++x )
	{
		UInt y = top;
		for ( ; y < bottom; ++y )
		{
			p = img.data + y*img.stride + x*img.pixelSize;
			value = 0;
			switch ( img.pixelSize )
			{
				case 4:	value |= (UInt)p[3] << 24;
				case 3:	value |= (UInt)p[2] << 16;
				case 2:	value |= (UInt)p[1] << 8;
				case 1:	value |= (UInt)p[0];
			}
			const Byte r = (value & img.maskR) >> img.shiftR;
			const Byte g = (value & img.maskG) >> img.shiftG;
			const Byte b = (value & img.maskB) >> img.shiftB;

			if ( (r != img.transR) || (g != img.transG) || (b != img.transB) )
			{
				break;
			}
		}
		if ( y == bottom )
			return x;
	}
	return none;
}

static Bool GetGlyph( ImageDesc& img, UInt& left, UInt top, UInt bottom, RectF& rect )
{
	left = GetNonEmptyColumn( img, left, top, bottom );
	if ( left == none )
		return false;

	int right = GetEmptyColumn( img, left+1, top, bottom );
	if ( right == none )
	{
		right = img.width;
	}

	rect.Set( left, top, right, bottom );
	left = right;
	return true;
}

static UInt GetNonEmptyLine( ImageDesc& img, UInt start )
{
	const Byte* p = nullptr; UInt value = 0;
	for ( UInt y = start; y < img.height; ++y )
	{
		p = img.data + y*img.stride;

		for ( UInt x = 0; x < img.width; ++x )
		{
			value = 0;
			switch ( img.pixelSize )
			{
				case 4:	value |= (UInt)p[3] << 24;
				case 3:	value |= (UInt)p[2] << 16;
				case 2:	value |= (UInt)p[1] << 8;
				case 1:	value |= (UInt)p[0];
			}
			const Byte r = (value & img.maskR) >> img.shiftR;
			const Byte g = (value & img.maskG) >> img.shiftG;
			const Byte b = (value & img.maskB) >> img.shiftB;

			if ( (r != img.transR) || (g != img.transG) || (b != img.transB) )
			{
				return y;
			}
			p += img.pixelSize;
		}
	}
	return none;
}

static UInt GetEmptyLine( ImageDesc& img, UInt start )
{
	const Byte* p = nullptr; UInt value = 0;
	for ( UInt y = start; y < img.height; ++y )
	{
		p = img.data + y*img.stride;

		UInt x = 0;
		for ( ; x < img.width; ++x )
		{
			value = 0;
			switch ( img.pixelSize )
			{
				case 4:	value |= (UInt)p[3] << 24;
				case 3:	value |= (UInt)p[2] << 16;
				case 2:	value |= (UInt)p[1] << 8;
				case 1:	value |= (UInt)p[0];
			}
			const Byte r = (value & img.maskR) >> img.shiftR;
			const Byte g = (value & img.maskG) >> img.shiftG;
			const Byte b = (value & img.maskB) >> img.shiftB;

			if ( (r != img.transR) || (g != img.transG) || (b != img.transB) )
			{
				break;
			}
			p += img.pixelSize;
		}
		if ( x == img.width )
			return y;
	}
	return none;
}

static Bool GetRow( ImageDesc& img, UInt& start, UInt& end )
{
	end = none;
	start = GetNonEmptyLine( img, start );
	if ( start == none )
		return false;

	end = GetEmptyLine( img, start+1 );
	if ( end == none )
	{
		end = img.height;
	}
	return true;
}

void PixelFormatEx::ExtractGlyphs( const Byte* data, const PixelFormat& format, UInt width, UInt height, UInt stride, const Language& language, Map<Char, RectF>& glyphs )
{
	assert( data != nullptr );
	assert( format != PixelFormat::Unknown );
	assert( language != Language::Unknown );

	// Validate arguments.
	if ( data == nullptr )
		throw BadArgumentException( L"Missing image data.", L"data" );

	if ( format == PixelFormat::Unknown )
		throw BadArgumentException( L"Unknown pixel format.", L"format" );

	if ( language == Language::Unknown )
		throw BadArgumentException( L"Unknown language.", L"language" );

	const Byte* pixel = nullptr;
	const UInt pixelSize = format.BitsPerPixel() >> 3;

	// Compute aux channel variables.
	const UInt maskR = _formats[format].red;
	const UInt maskG = _formats[format].green;
	const UInt maskB = _formats[format].blue;
	const Int shiftR = GetShiftByMask( maskR );
	const Int shiftG = GetShiftByMask( maskG );
	const Int shiftB = GetShiftByMask( maskB );

	// Get left top pixel color.
	pixel = data;
	UInt value = 0;
	switch ( pixelSize )
	{
		case 4:	value |= (UInt)pixel[3] << 24;
		case 3:	value |= (UInt)pixel[2] << 16;
		case 2:	value |= (UInt)pixel[1] << 8;
		case 1:	value |= (UInt)pixel[0];
	}

	// Build image description.
	ImageDesc img;
	img.data		= data;
	img.width		= width;
	img.height		= height;
	img.stride		= stride;
	img.pixelSize	= pixelSize;
	img.maskR		= maskR;
	img.maskG		= maskG;
	img.maskB		= maskB;
	img.shiftR		= shiftR;
	img.shiftG		= shiftG;
	img.shiftB		= shiftB;
	img.transR		= (value & maskR) >> shiftR;
	img.transG		= (value & maskG) >> shiftG;
	img.transB		= (value & maskB) >> shiftB;

	// Extract glyphs.
	Float minTop = CastFloat(height); Float maxHeight = 0.0f;
	UInt i = 0; UInt start = 0; UInt end = 0; RectF rect;
	while( GetRow(img, start, end) )
	{
		// Keep track of the topmost and highest glyphs.
		const Float hgt = CastFloat(end-start);
		if (hgt > maxHeight )
		{
			maxHeight = hgt;
		}
		if ( CastFloat(start) < minTop )
		{
			minTop = CastFloat(start);
		}

		UInt left = 0;
		while ( GetGlyph( img, left, start, end, rect) )
		{
			const Char ch = language.GetChar( i++ );
			glyphs[ch] = rect;
		}
		start = end+1;
	}

	// Adjust glyph coordinates.
	const Float deltaWidth = Math::Round( 0.05f*maxHeight );
	Float deltaHeight = Math::Round( 0.1f*maxHeight );
	if ( deltaHeight > minTop )
	{
		deltaHeight = minTop;
	}
	MapIterator<Char, RectF> it = glyphs.Begin();
	const MapIterator<Char, RectF> itEnd = glyphs.End();
	for ( ; it != itEnd ; ++it )
	{
		RectF& rc = it.Value();
		if ( rc.Left >= deltaWidth )
		{
			rc.Left -= deltaWidth;
		}
		if ( rc.Right+deltaWidth < CastFloat(width) )
		{
			rc.Right += deltaWidth;
		}
		const Float delta = maxHeight - rc.Height();
		if ( delta > 0.0f )
		{
			rc.Top -= delta/2;
		}
		rc.Top -= deltaHeight;
		rc.Bottom += deltaHeight;

		// Normalize coordinates.
		rc.Left = CastFloat(rc.Left)/CastFloat(width);
		rc.Top = CastFloat(rc.Top)/CastFloat(height);
		rc.Right = CastFloat(rc.Right)/CastFloat(width);
		rc.Bottom = CastFloat(rc.Bottom)/CastFloat(height);
	}
}


} // img


} // synkro
