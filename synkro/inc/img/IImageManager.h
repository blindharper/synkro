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
// Purpose: Defines image manager.
//==============================================================================
#ifndef _SYNKRO_IMG_IIMAGEMANAGER_
#define _SYNKRO_IMG_IIMAGEMANAGER_


#include "config.h"
#include <core/ISystem.h>
#include <img/PixelFormat.h>
#include <img/ImageCodec.h>
#include <img/ImageStats.h>


#undef LoadImage
#define LoadImage LoadImage


namespace synkro
{


namespace img
{


/**
 * Image manager.
 */
iface IImageManager :
	public core::ISystem
{
public:
	/**
	 * Removes all images from image cache.
	 */
	virtual void											ClearCache() = 0;

	/**
	 * Creates an empty image of the specified pixel format.
	 * @param format Image pixel format.
	 * @return Created image if succeeded, or nullptr otherwise.
	 */
	virtual IImage*											CreateImage( const PixelFormat& format ) = 0;

	/**
	 * Creates an image from the given rendering texture.
	 * @param texture Rendering texture.
	 * @return Created image if succeeded, or nullptr otherwise.
	 */
	virtual IImage*											CreateImage( gfx::IPlainRenderTexture* texture ) = 0;

	/**
	 * Creates an image from the given rendering texture.
	 * @param texture Rendering texture.
	 * @return Created image if succeeded, or nullptr otherwise.
	 */
	virtual IImage*											CreateImage( gfx::ICubeRenderTexture* texture ) = 0;

	/**
	 * Loads image from a stream. Image type is guessed from stream name.
	 * @param stream Stream from which to load image.
	 * @param [in,out] format Format to convert image data to, if possible. Compressed formats ignore this parameter.
	 * @return Loaded image.
	 * @exception BadArgumentException Bad stream.
	 * @exception BadArgumentException Wrong image type.
	 */
	virtual IImage*											LoadImage( io::IStream* stream, PixelFormat& format ) = 0;

	/**
	 * Asynchronously loads image from a stream, if it's not already in the cache. Image type is guessed from stream name.
	 * @param stream Stream from which to load image.
	 * @param [in,out] format Format to convert image data to, if possible. Compressed formats ignore this parameter.
	 * @param listener Optional load progress listener.
	 * @return Loaded image.
	 * @exception BadArgumentException Bad stream.
	 * @exception BadArgumentException Wrong image type.
	 */
	virtual IImage*											LoadImageAsync( io::IStream* stream, PixelFormat& format, core::ProgressListener* listener ) = 0;

	/**
	 * Loads image from a stream set.
	 * @param streams Stream set from which to load image.
	 * @param [in,out] format Format to convert image data to, if possible. Compressed formats ignore this parameter.
	 * @return Loaded image.
	 * @exception BadArgumentException Bad stream set.
	 */
	virtual IImage*											LoadImage( io::IStreamSet* streams, PixelFormat& format ) = 0;

	/**
	 * Asynchronously loads image from a stream set, if it's not already in the cache. Image type is guessed from the first stream name.
	 * @param streams Stream set from which to load image.
	 * @param [in,out] format Format to convert image data to, if possible. Compressed formats ignore this parameter.
	 * @param listener Load progress listener. If not nullptr, method is returned immediately and the image is loaded asynchronously.
	 * @return Loaded image.
	 * @exception BadArgumentException Bad stream set.
	 */
	virtual IImage*											LoadImageAsync( io::IStreamSet* streams, PixelFormat& format, core::ProgressListener* listener ) = 0;

	/**
	 * Retrieves images statistics.
	 */
	virtual void											GetStats( ImageStats& stats ) const = 0;
};


} // img


} // synkro


#endif // _SYNKRO_IMG_IIMAGEMANAGER_
