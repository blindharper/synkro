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
// Purpose: Defines pixel format.
//==============================================================================
#ifndef _SYNKRO_IMG_PIXELFORMAT_
#define _SYNKRO_IMG_PIXELFORMAT_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace img
{


/**
 * Pixel formats.
 */
SYNKRO_ENUM_BEGIN( PixelFormat )
	/** Unknown format. */
	SYNKRO_ENUM_CONST( PixelFormat, Unknown )

	/** 128-bit floating-point RGB format with alpha channel. */
	SYNKRO_ENUM_CONST( PixelFormat, R32G32B32A32F )

	/** 64-bit floating-point two-component format. */
	SYNKRO_ENUM_CONST( PixelFormat, R32G32F )

	/** 64-bit floating-point four-component format. */
	SYNKRO_ENUM_CONST( PixelFormat, R16G16B16A16F )

	/** 64-bit RGB format with alpha channel. */
	SYNKRO_ENUM_CONST( PixelFormat, R16G16B16A16 )

	/** 32-bit floating-point single-component format. */
	SYNKRO_ENUM_CONST( PixelFormat, R32F )

	/** 32-bit floating-point two-component format. */
	SYNKRO_ENUM_CONST( PixelFormat, R16G16F )

	/** 32-bit RGB format with 2-bit alpha channel. */
	SYNKRO_ENUM_CONST( PixelFormat, R10G10B10A2 )

	/** 32-bit two-component format. */
	SYNKRO_ENUM_CONST( PixelFormat, R16G16 )

	/** 32-bit RGB format with alpha channel. */
	SYNKRO_ENUM_CONST( PixelFormat, R8G8B8A8 )

	/** 32-bit RGB format. */
	SYNKRO_ENUM_CONST( PixelFormat, R8G8B8X8 )

	/** 32-bit RGB format with alpha channel. */
	SYNKRO_ENUM_CONST( PixelFormat, B8G8R8A8 )

	/** 32-bit RGB format without alpha channel. */
	SYNKRO_ENUM_CONST( PixelFormat, B8G8R8X8 )

	/** 24-bit three-component format. */
	SYNKRO_ENUM_CONST( PixelFormat, R8G8B8 )

	/** 24-bit three-component format. */
	SYNKRO_ENUM_CONST( PixelFormat, B8G8R8 )

	/** 16-bit floating-point single-component format. */
	SYNKRO_ENUM_CONST( PixelFormat, R16F )

	/** 16-bit RGB format with 5 bits per color and 1-bit alpha channel. */
	SYNKRO_ENUM_CONST( PixelFormat, R5G5B5A1 )

	/** 16-bit format where 5 bits are reserved for each color. */
	SYNKRO_ENUM_CONST( PixelFormat, R5G5B5X1 )

	/** 16-bit RGB format. */
	SYNKRO_ENUM_CONST( PixelFormat, R5G6B5 )

	/** 16-bit RGB format with alpha channel. */
	SYNKRO_ENUM_CONST( PixelFormat, R4G4B4A4 )

	/** 16-bit RGB format with alpha channel. */
	SYNKRO_ENUM_CONST( PixelFormat, R4G4B4X4 )

	/** 16-bit RGB format with alpha channel. */
	SYNKRO_ENUM_CONST( PixelFormat, R3G3B2A8 )

	/** 16-bit RGB format with alpha channel. */
	SYNKRO_ENUM_CONST( PixelFormat, R3G2B3A8 )

	/** 8-bit RGB format. */
	SYNKRO_ENUM_CONST( PixelFormat, R3G3B2 )

	/** 8-bit RGB format. */
	SYNKRO_ENUM_CONST( PixelFormat, R3G2B3 )

	/** 8-bit luminance format. */
	SYNKRO_ENUM_CONST( PixelFormat, R8 )

	/** 8-bit alpha channel only. */
	SYNKRO_ENUM_CONST( PixelFormat, A8 )

	/** Block compression format (Color (5:6:5), Alpha (1) or no alpha). */
	SYNKRO_ENUM_CONST( PixelFormat, BC1 )

	/** Block compression format (Color (5:6:5), Alpha (4)). */
	SYNKRO_ENUM_CONST( PixelFormat, BC2 )

	/** Block compression format (Color (5:6:5), Alpha (8)). */
	SYNKRO_ENUM_CONST( PixelFormat, BC3 )

	/** Block compression format (Color (8)). */
	SYNKRO_ENUM_CONST( PixelFormat, BC4 )

	/** Block compression format (Color (8), Color (8)). */
	SYNKRO_ENUM_CONST( PixelFormat, BC5 )

	/**
	 * Constructs RGBA format from a set of bitmasks.
	 * Resulting format may be Unknown, if it is unsupported.
	 * @param red Bitmask for red channel.
	 * @param green Bitmask for green channel.
	 * @param blue Bitmask for blue channel.
	 * @param alpha Bitmask for alpha channel.
	 */
	PixelFormat( UInt red, UInt green, UInt blue, UInt alpha );

	/**
	 * Creates pixel format from string.
	 */
	PixelFormat( const lang::String& format );

	/**
	 * Returns the number of channels.
	 */
	UInt													ChannelCount() const;

	/**
	 * Returns the number of bytes required to store one pixel.
	 */
	UInt													BytesPerPixel() const;

	/**
	 * Returns the number of bits required to store one pixel.
	 */
	UInt													BitsPerPixel() const;

	/**
	 * Returns true if the pixel format has alpha channel.
	 */
	Bool													HasAlpha() const;

	/**
	 * Returns true if the pixel format is compressed.
	 */
	Bool													IsCompressed() const;

	/**
	 * Returns true if the pixel format is floating-point.
	 */
	Bool													IsFloatingPoint() const;

	/**
	 * Converts pixel format to string.
	 */
	lang::String											ToString() const;
SYNKRO_ENUM_END()


} // img


} // synkro


#endif // _SYNKRO_IMG_PIXELFORMAT_
