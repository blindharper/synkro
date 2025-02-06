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
// Purpose: Generic DX11 base rendering texture implementation.
//=============================================================================
#ifndef _SYNKRO_GFX_DX11BASERENDERTEXTUREIMPL_
#define _SYNKRO_GFX_DX11BASERENDERTEXTUREIMPL_


#include "config.h"
#include <d3d11.h>
#include <internal/SafeRelease.h>


namespace synkro
{


namespace gfx
{


// Generic DX11 base rendering texture implementation.
template <class T>
class Dx11BaseRenderTextureImpl :
	public T
{
public:
	// Constructor and destructor.
	Dx11BaseRenderTextureImpl();
	virtual ~Dx11BaseRenderTextureImpl();

	// Dx11BaseRenderTexture methods.
	virtual ID3D11RenderTargetView*							AsDx11RenderTargetView() const;

protected:
	ID3D11RenderTargetView*									_rtv;
};


#include "Dx11BaseRenderTextureImpl.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_DX11BASERENDERTEXTUREIMPL_
