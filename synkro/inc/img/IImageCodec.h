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
// Purpose: Defines abstract image codec.
//==============================================================================
#ifndef _SYNKRO_IMG_IIMAGECODEC_
#define _SYNKRO_IMG_IIMAGECODEC_


#include "config.h"
#include <core/IObject.h>
#include <img/PixelFormat.h>


namespace synkro
{


namespace img
{


/**
 * Abstract image codec.
 */
iface IImageCodec :
	public core::IObject
{
public:
	/**
	 * Creates image codec context.
	 * @return Created context.
	 */
	virtual ImageCodecContext*								CreateContext() = 0;

	/**
	 * Destroys image codec context, created by a call to CreateContext().
	 * @param context Codec context.
	 */
	virtual void											DestroyContext( ImageCodecContext* context ) = 0;

	/**
	 * Loads image from stream or stream set, possibly overriding pixel format.
	 * @param context Codec context.
	 * @exception BadArgumentException Codec context is null.
	 * @exception BadArgumentException Bad image.
	 * @exception BadArgumentException Both stream and stream set are null.
	 * @exception BadArgumentException Wrong image format.
	 */
	virtual void											Load( ImageCodecContext* context ) = 0;

	/**
	 * Saves image to stream.
	 * @param context Codec context.
	 * @exception BadArgumentException Codec context is null.
	 * @exception BadArgumentException Bad image.
	 * @exception BadArgumentException Both stream and stream set are null.
	 * @exception BadArgumentException Wrong image format.
	 */
	virtual void											Save( ImageCodecContext* context ) = 0;
};


} // img


} // synkro


#endif // _SYNKRO_IMG_IIMAGECODEC_
