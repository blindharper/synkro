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
// Purpose: Implements cube rendering image.
//==============================================================================
#ifndef _SYNKRO_IMG_CUBERENDERIMAGE_
#define _SYNKRO_IMG_CUBERENDERIMAGE_


#include "config.h"
#include <img/ImageImpl.h>
#include <img/IImage.h>
#include <gfx/ICubeRenderTexture.h>


namespace synkro
{


namespace img
{


// Cube rendering image implementation.
class CubeRenderImage :
	public ImageImpl<IImage>
{
public:
	// Constructors.
	CubeRenderImage( BaseImageManager* imageManager, gfx::ICubeRenderTexture* texture );

	// IImage methods.
	gfx::IResource*											AsResource() const;
	gfx::ICubeRenderTexture*								AsCubeRenderTexture() const;

private:
	P(gfx::ICubeRenderTexture)								_cubeTexture;
};


} // img


} // synkro


#endif // _SYNKRO_IMG_CUBERENDERIMAGE_
