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
// Purpose: DX11 cube depth texture implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_DX11CUBEDEPTHTEXTURE_
#define _SYNKRO_GFX_DX11CUBEDEPTHTEXTURE_


#include "config.h"
#include <gfx/CubeDepthTextureImpl.h>
#include <gfx/ICubeDepthTexture.h>
#undef new
#include "Dx11BaseDepthTextureImpl.h"
#include "Dx11BaseDepthTexture.h"
#include "Dx11ResourceImpl.h"
#include "Dx11Resource.h"
#include "Dx11.h"
#define new SYNKRO_NEW


namespace synkro
{


namespace gfx
{


// DirectX 11 cube depth texture implementation.
class Dx11CubeDepthTexture :
	public CubeDepthTextureImpl<ICubeDepthTexture>,
	public Dx11BaseDepthTextureImpl<Dx11BaseDepthTexture>,
	public Dx11ResourceImpl<Dx11Resource>
{
public:
	// Constructor & destructor.
	Dx11CubeDepthTexture( Dx11Context* context, UInt length, const DepthFormat& format, Bool stencil, UInt sampleCount, UInt sampleQuality );
	~Dx11CubeDepthTexture();

	// IDepthTexture methods.
	void													Clear();

private:
	ID3D11Texture2D*										_texture;
	UINT													_flags;
};


#include "Dx11CubeDepthTexture.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_DX11CUBEDEPTHTEXTURE_
