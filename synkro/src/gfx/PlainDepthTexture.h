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
// Purpose: Logical plain depth texture.
//==============================================================================
#ifndef _SYNKRO_GFX_PLAINDEPTHTEXTURE_
#define _SYNKRO_GFX_PLAINDEPTHTEXTURE_


#include "config.h"
#include <gfx/PlainDepthTextureImpl.h>
#include <gfx/IPlainDepthTexture.h>
#include "BaseResourceImpl.h"
#include "BaseResource.h"


namespace synkro
{


namespace gfx
{


// Logical plain depth texture.
class PlainDepthTexture :
	public PlainDepthTextureImpl<IPlainDepthTexture>,
	public BaseResourceImpl<BaseResource>
{
public:
	// Constructor.
	PlainDepthTexture( IPlainDepthTexture* texture );

	// IDepthTexture methods.
	void													Clear();
	void													SetDefaultDepth( Float depth );
	void													SetDefaultStencil( Byte stencil );

private:
	friend class PlainRenderTexture;

	P(IPlainDepthTexture)									_texture;
};


#include "PlainDepthTexture.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_PLAINDEPTHTEXTURE_
