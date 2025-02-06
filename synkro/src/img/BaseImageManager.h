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
// Purpose: Defines base image manager.
//==============================================================================
#ifndef _SYNKRO_IMG_BASEIMAGEMANAGER_
#define _SYNKRO_IMG_BASEIMAGEMANAGER_


#include "config.h"
#include <img/ImageCodec.h>
#include <img/PixelFormat.h>


namespace synkro
{


namespace img
{


// Base image manager.
class BaseImageManager
{
public:
	virtual IImage*											Create( const PixelFormat& format ) = 0;
	virtual gfx::ITexture*									PrepareImage( IImage* image, const PixelFormat& format, UInt levelCount ) = 0;
	virtual void											SaveImage( const IImage* image, io::IStream* stream, const PixelFormat& format, const ImageCodec& type ) = 0;
	virtual void											SaveImage( const IImage* image, io::IStream* stream, const PixelFormat& format ) = 0;
	virtual void											SaveImageAsync( const IImage* image, io::IStream* stream, const PixelFormat& format, const ImageCodec& type ) = 0;
	virtual void											SaveImageAsync( const IImage* image, io::IStream* stream, const PixelFormat& format ) = 0;
};


} // img


} // synkro


#endif // _SYNKRO_IMG_BASEIMAGEMANAGER_
