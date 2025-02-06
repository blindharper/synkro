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
// Purpose: DX11 base depth texture.
//==============================================================================
#ifndef _SYNKRO_GFX_DX11BASEDEPTHTEXTURE_
#define _SYNKRO_GFX_DX11BASEDEPTHTEXTURE_


#include "config.h"
#include <d3d11.h>


namespace synkro
{


namespace gfx
{


// DirectX 11 base depth texture.
class Dx11BaseDepthTexture
{
public:
	// Returns underlying DX11 depth stencil view.
	virtual ID3D11DepthStencilView*							AsDx11DepthStencilView() const = 0;
};


// Casts object to Dx11BaseDepthTexture.
#define AsDx11BaseDepthTexture( OBJ ) dynamic_cast<Dx11BaseDepthTexture*>( OBJ )


} // gfx


} // synkro


#endif // _SYNKRO_GFX_DX11BASEDEPTHTEXTURE_
