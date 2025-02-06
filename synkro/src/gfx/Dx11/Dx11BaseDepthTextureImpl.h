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
// Purpose: Generic DX11 base depth texture implementation.
//=============================================================================
#ifndef _SYNKRO_GFX_DX11BASEDEPTHTEXTUREIMPL_
#define _SYNKRO_GFX_DX11BASEDEPTHTEXTUREIMPL_


#include "config.h"
#include <d3d11.h>
#include <internal/SafeRelease.h>


namespace synkro
{


namespace gfx
{


// Generic DX11 base depth texture implementation.
template <class T>
class Dx11BaseDepthTextureImpl :
	public T
{
public:
	// Constructor and destructor.
	Dx11BaseDepthTextureImpl();
	virtual ~Dx11BaseDepthTextureImpl();

	// Dx11BaseRenderTexture methods.
	virtual ID3D11DepthStencilView*							AsDx11DepthStencilView() const;

protected:
	ID3D11DepthStencilView*									_dsv;
};


#include "Dx11BaseDepthTextureImpl.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_DX11BASEDEPTHTEXTUREIMPL_
