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
// Purpose: DX11 based rendering texture set implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_DX11RENDERTEXTURESET_
#define _SYNKRO_GFX_DX11RENDERTEXTURESET_


#include "config.h"
#include <gfx/RenderTextureSetImpl.h>
#include <gfx/IRenderTextureSet.h>
#undef new
#include "Dx11.h"
#define new SYNKRO_NEW


namespace synkro
{


namespace gfx
{


// DX11 based rendering texture set.
class Dx11RenderTextureSet :
	public RenderTextureSetImpl<IRenderTextureSet>
{
public:
	// Constructor.
	Dx11RenderTextureSet( Dx11Context* context, UInt size );

	// IRenderTextureSet methods.
	Bool													Bind();
	void													Clear();
	void													Set( UInt index, IRenderTexture* texture );

private:
	lang::Vector<ID3D11RenderTargetView*>					_views;
	Dx11Context												_context;
};


#include "Dx11RenderTextureSet.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_DX11RENDERTEXTURESET_
