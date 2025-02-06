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
// Purpose: Implements plain rendering image.
//==============================================================================
#ifndef _SYNKRO_IMG_PLAINRENDERIMAGE_
#define _SYNKRO_IMG_PLAINRENDERIMAGE_


#include "config.h"
#include <img/ImageImpl.h>
#include <img/IImage.h>
#include <gfx/IPlainRenderTexture.h>


namespace synkro
{


namespace img
{


// Plain rendering image implementation.
class PlainRenderImage :
	public ImageImpl<IImage>
{
public:
	// Constructor.
	PlainRenderImage( BaseImageManager* imageManager, gfx::IPlainRenderTexture* texture );

	// IImage methods.
	gfx::IResource*											AsResource() const;
	gfx::IPlainRenderTexture*								AsPlainRenderTexture() const;

private:
	P(gfx::IPlainRenderTexture)								_plainTexture;
};


} // img


} // synkro


#endif // _SYNKRO_IMG_PLAINRENDERIMAGE_
