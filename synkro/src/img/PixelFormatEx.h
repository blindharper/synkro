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
#ifndef _SYNKRO_IMG_PIXELFORMATEX_
#define _SYNKRO_IMG_PIXELFORMATEX_


#include "config.h"
#include <img/Color.h>
#include <img/PixelFormat.h>
#include <lang/Map.h>
#include <lang/RectF.h>
#include <core/Language.h>


namespace synkro
{


namespace img
{


// Extended pixel format.
class SYNKRO_API PixelFormatEx
{
public:
	// Sets the value of alpha channel.
	// @param data Image data.
	// @param format Image pixel format.
	// @param width Image width.
	// @param height Image height.
	// @param stride Size, in bytes, of image scanline.
	// @param alpha Alpha channel data.
	// @param strideAlpha Alpha channel stride.
	// @exception BadArgumentException Missing image data.
	// @exception BadArgumentException Unknown pixel format.
	static void												SetAlpha( Byte* data, const PixelFormat& format, UInt width, UInt height, UInt stride, const Byte* alpha, UInt strideAlpha );

	// Sets the value of alpha channel for the pixels with the specified color.
	// @param data Image data.
	// @param format Image pixel format.
	// @param width Image width.
	// @param height Image height.
	// @param stride Size, in bytes, of image scanline.
	// @param color Color of the pixels to set alpha channel for.
	// @param alpha Alpha channel value.
	// @exception BadArgumentException Missing image data.
	// @exception BadArgumentException Unknown pixel format.
	static void												SetAlpha( Byte* data, const PixelFormat& format, UInt width, UInt height, UInt stride, const Color& color, Byte alpha );

	// Sets color value of the specified image pixel.
	// @param data Image data.
	// @param format Image pixel format.
	// @param width Image width.
	// @param height Image height.
	// @param stride Size, in bytes, of image scanline.
	// @param x Pixel's horizontal coordinate.
	// @param y Pixel's vertical coordinate.
	// @param New pixel color.
	// @exception BadArgumentException Missing image data.
	// @exception BadArgumentException Invalid pixel coordinate.
	static void												SetPixel( Byte* data, const PixelFormat& format, UInt width, UInt height, UInt stride, UInt x, UInt y, const Color& color );

	// Retrieves color value of the specified image pixel.
	// @param data Image data.
	// @param format Image pixel format.
	// @param width Image width.
	// @param height Image height.
	// @param stride Size, in bytes, of image scanline.
	// @param x Pixel's horizontal coordinate.
	// @param y Pixel's vertical coordinate.
	// @return Requested pixel color.
	// @exception BadArgumentException Missing image data.
	// @exception BadArgumentException Unknown pixel format.
	// @exception BadArgumentException Invalid pixel coordinate.
	static Color											GetPixel( const Byte* data, const PixelFormat& format, UInt width, UInt height, UInt stride, UInt x, UInt y );

	// Copies an array of pixels to the specified memory block.
	// @param dst Destination memory block.
	// @param dstFormat Destination pixel format.
	// @param src Source memory block.
	// @param srcFormat Source pixel format.
	// @param pixels Pixel count.
	static void												CopyPixels( Byte* dst, const PixelFormat& dstFormat, const Byte* src, const PixelFormat& srcFormat, UInt pixels );

	// Copies an array of pixels from one memory block to another.
	// @param dst Destination memory block.
	// @param dstFormat Destination pixel format.
	// @param dstStride Size, in bytes, of destination image scanline.
	// @param dstX Left coordinate of the rectangle in the destination memory block.
	// @param dstY Top coordinate of the rectangle in the destination memory block.
	// @param dstWidth Width of the rectangle in the destination memory block.
	// @param dstHeight Height of the rectangle in the destination memory block.
	// @param src Source memory block.
	// @param srcFormat Source pixel format.
	// @param srcStride Size, in bytes, of source image scanline.
	// @param srcX Left coordinate of the rectangle in the source memory block.
	// @param srcY Top coordinate of the rectangle in the source memory block.
	// @exception BadArgumentException Bad source or destination memory.
	// @exception BadArgumentException Unknown source or destination pixel format.
	static void												CopyPixels( Byte* dst, const PixelFormat& dstFormat, UInt dstStride, UInt dstX, UInt dstY, UInt dstWidth, UInt dstHeight, const Byte* src, const PixelFormat& srcFormat, UInt srcStride, UInt srcX, UInt srcY );

	// Calculates the minimal rectangle holding the glyph given the initial approximation.
	// @param data Image data.
	// @param format Image pixel format.
	// @param width Image width.
	// @param height Image height.
	// @param stride Size, in bytes, of image scanline.
	// @param [in,out] rect Initial rectangle coordinates.
	static void												ExtractGlyphs( const Byte* data, const PixelFormat& format, UInt width, UInt height, UInt stride, const core::Language& language, lang::Map<Char, lang::RectF>& glyphs );
};


} // img


} // synkro


#endif // _SYNKRO_IMG_PIXELFORMATEX_
