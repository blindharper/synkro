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
// Purpose: Logical cube depth texture.
//==============================================================================
#ifndef _SYNKRO_GFX_CUBEDEPTHTEXTURE_
#define _SYNKRO_GFX_CUBEDEPTHTEXTURE_


#include "config.h"
#include <gfx/CubeDepthTextureImpl.h>
#include <gfx/ICubeDepthTexture.h>
#include "BaseResourceImpl.h"
#include "BaseResource.h"


namespace synkro
{


namespace gfx
{


// Logical cube depth texture.
class CubeDepthTexture :
	public CubeDepthTextureImpl<ICubeDepthTexture>,
	public BaseResourceImpl<BaseResource>
{
public:
	// Constructor.
	CubeDepthTexture( ICubeDepthTexture* texture );

	// IResource methods.
	IDepthTexture*											AsDepthTexture() const;

	// IDepthTexture methods.
	void													Clear();
	void													SetDefaultDepth( Float depth );
	void													SetDefaultStencil( Byte stencil );

	// ICubeDepthTexture methods.
	Bool													BindFace( const CubeFace& face );

private:
	P(ICubeDepthTexture)									_texture;
};


#include "CubeDepthTexture.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_CUBEDEPTHTEXTURE_
