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
// Purpose: Implements image.
//==============================================================================
#ifndef _SYNKRO_IMG_IMAGE_
#define _SYNKRO_IMG_IMAGE_


#include "config.h"
#include "ImageImpl.h"
#include <img/IImage.h>
#include "BaseImage.h"
#include <internal/BinarySemaphore.h>


namespace synkro
{


namespace img
{


// Image implementation.
class Image :
	public ImageImpl<IImage>,
	public BaseImage,
	public Logger
{
public:
	// Constructors.
	Image( BaseImageManager* imageManager, const PixelFormat& format, Bool loaded, diag::ILog* log );

	// IImage methods.
	void													Prepare( const PixelFormat& format, UInt levelCount );
	IImage*													Clone( const PixelFormat& format ) const;

	// BaseImage methods.
	void													WaitLoad();
	void													SignalLoad();
	UInt													GetSize() const;

private:
	mutable BinarySemaphore									_lock;
};


#include "Image.inl"


} // img


} // synkro


#endif // _SYNKRO_IMG_IMAGE_
