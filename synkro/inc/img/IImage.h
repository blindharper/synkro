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
// Purpose: Defines abstract image.
//==============================================================================
#ifndef _SYNKRO_IMG_IIMAGE_
#define _SYNKRO_IMG_IIMAGE_


#include "config.h"
#include <core/IObject.h>
#include <img/PixelFormat.h>
#include <img/ImageCodec.h>
#include <img/ImageType.h>
#include <img/Color.h>


namespace synkro
{


namespace img
{


/**
 * Abstract image.
 * @remarks Image represents an array of pixel elements.
 */
iface IImage :
	public core::IObject
{
public:
	/**
	 * Uploads image data to the graphics device.
	 * @param format Pixel format to which to convert image data.
	 * @param levelCount Number of mip levels to generate.
	 */
	virtual void											Prepare( const PixelFormat& format, UInt levelCount ) = 0;

	/**
	 * Saves image to the stream in the given format.
	 * @param stream Stream to which to save image.
	 * @param format Image pixel format.
	 * @param type Image codec type.
	 */
	virtual void											Save( io::IStream* stream, const PixelFormat& format, const ImageCodec& type ) = 0;

	/**
	 * Saves image to the stream in the given format. Image type is guessed from stream name.
	 * @param stream Stream to which to save image.
	 * @param format Image pixel format.
	 */
	virtual void											Save( io::IStream* stream, const PixelFormat& format ) = 0;

	/**
	 * Asynchronously saves image to the stream in the given format.
	 * @param stream Stream to which to save image.
	 * @param format Image pixel format.
	 * @param type Image codec type.
	 */
	virtual void											SaveAsync( io::IStream* stream, const PixelFormat& format, const ImageCodec& type ) = 0;

	/**
	 * Asynchronously saves image to the stream in the given format. Image type is guessed from stream name.
	 * @param stream Stream to which to save image.
	 * @param format Image pixel format.
	 */
	virtual void											SaveAsync( io::IStream* stream, const PixelFormat& format ) = 0;

	/**
	 * Adds new element with one mip level.
	 * @param width Surface width.
	 * @param height Surface height.
	 * @param stride Surface stride, in bytes.
	 * @param data Data for primary level of the element. Pass null to allocate storage.
	 * @param size Data size, in bytes.
	 * @return Pointer to the element's mip level data.
	 * @exception BadArgumentException Image dimensions do not match those of the previously added element.
	 */
	virtual Byte*											AddElement( UInt width, UInt height, UInt stride, const Byte* data, UInt size ) = 0;

	/**
	 * Adds new mip level to the last added element. Creates element, if image has no elements.
	 * @param width Mip level width.
	 * @param height Mip level height.
	 * @param stride Mip level stride, in bytes.
	 * @param data Data for the added mip level. Pass null to allocate storage.
	 * @param size Data size, in bytes.
	 * @return Pointer to the mip level data.
	 * @exception BadArgumentException Mip level dimensions do not match those of the previously added element.
	 */
	virtual Byte*											AddLevel( UInt width, UInt height, UInt stride, const Byte* data, UInt size ) = 0;

	/**
	 * Zeroes the opacity of the pixels having the specified color.
	 * @param color Color denoting transparent pixels.
	 * @exception InvalidOperationException Image is compressed or has no alpha channel.
	 */
	virtual void											SetTransparentColor( const Color& color ) = 0;

	/**
	 * Zeroes the opacity of the pixels having the color matching top-left pixel color.
	 * @exception InvalidOperationException Image is compressed or has no alpha channel.
	 */
	virtual void											SetTransparentColor() = 0;

	/**
	 * Sets image alpha channel from another image.
	 * @param alpha Image storing transparency mask.
	 * @exception BadArgumentException Alpha channel is not specified.
	 * @exception BadArgumentException Image is not a valid alpha channel.
	 * @exception BadArgumentException Alpha channel dimensions do not match those of the image.
	 */
	virtual void											SetAlpha( IImage* alpha ) = 0;

	/**
	 * Sets image pixel format.
	 * @param format Format to convert image data to.
	 * @exception BadArgumentException Pixel format is unknown.
	 * @exception InvalidOperationException Image is not empty.
	 */
	virtual void											SetFormat( const PixelFormat& format ) = 0;

	/**
	 * Sets image type. This can be useful, for instance, to treat an array of 6 plain images as a single cube image.
	 * @param type Image type.
	 * @exception BadArgumentException Image data cannot be treated in the way specified.
	 */
	virtual void											SetType( const ImageType& type ) = 0;

	/**
	 * Indicates whether the image is completely loaded.
	 */
	virtual Bool											IsLoaded() const = 0;

	/**
	 * Retrieves the total number of image elements. For volume images this is the number of depth slices.
	 */
	virtual UInt											GetElementCount() const = 0;

	/**
	 * Retrieves particular element data.
	 * @param element Image element index.
	 * @return Data for the topmost level of the specified element.
	 * @exception BadArgumentException Wrong level index.
	 */
	virtual Byte*											GetElement( UInt element ) const = 0;

	/**
	 * Retrieves primary element data.
	 * @return Data for the topmost level of the primary element.
	 */
	virtual Byte*											GetElement() const = 0;

	/**
	 * Retrieves the total number of mip levels in each element.
	 */
	virtual UInt											GetLevelCount() const = 0;

	/**
	 * Retrieves mip level data.
	 * @param element Image element index.
	 * @param level Mip level index.
	 * @return Data for the given level of the specified element.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual Byte*											GetLevel( UInt element, UInt level ) const = 0;

	/**
	 * Retrieves mip level width.
	 * @param level Mip level index.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual UInt											GetWidth( UInt level ) const = 0;

	/**
	 * Retrieves primary mip level width.
	 */
	virtual UInt											GetWidth() const = 0;

	/**
	 * Retrieves mip level height.
	 * @param level Mip level index.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual UInt											GetHeight( UInt level ) const = 0;

	/**
	 * Retrieves primary mip level height.
	 */
	virtual UInt											GetHeight() const = 0;

	/**
	 * Retrieves mip level stride.
	 * @param level Mip level index.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual UInt											GetStride( UInt level ) const = 0;

	/**
	 * Retrieves primary mip level stride.
	 */
	virtual UInt											GetStride() const = 0;

	/**
	 * Retrieves image slice stride.
	 * @param level Mip level index.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual UInt											GetSliceStride( UInt level ) const = 0;

	/**
	 * Retrieves primary mip level slice stride.
	 */
	virtual UInt											GetSliceStride() const = 0;

	/**
	 * Retrieves image pixel format.
	 */
	virtual PixelFormat										GetFormat() const = 0;

	/**
	 * Retrieves image type.
	 */
	virtual ImageType										GetType() const = 0;

	/**
	 * Casts image to graphics resource.
	 */
	virtual gfx::IResource*									AsResource() const = 0;

	/**
	 * Casts image to plain render texture.
	 */
	virtual gfx::IPlainRenderTexture*						AsPlainRenderTexture() const = 0;

	/**
	 * Casts image to cube render texture.
	 */
	virtual gfx::ICubeRenderTexture*						AsCubeRenderTexture() const = 0;

	/**
	 * Produces a copy of the image converted to the specified pixel format.
	 */
	virtual IImage*											Clone( const PixelFormat& format ) const = 0;

	/**
	 * Produces exact copy of the image.
	 */
	virtual IImage*											Clone() const = 0;
};


} // img


} // synkro


#endif // _SYNKRO_IMG_IIMAGE_
