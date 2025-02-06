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
// Purpose: DX11 base rendering texture.
//==============================================================================
#ifndef _SYNKRO_GFX_DX11BASERENDERTEXTURE_
#define _SYNKRO_GFX_DX11BASERENDERTEXTURE_


#include "config.h"
#include <d3d11.h>


namespace synkro
{


namespace gfx
{


// DirectX 11 base rendering texture.
class Dx11BaseRenderTexture
{
public:
	// Returns underlying DX11 render target view.
	virtual ID3D11RenderTargetView*							AsDx11RenderTargetView() const = 0;
};


// Casts object to Dx11BaseRenderTexture.
#define AsDx11BaseRenderTexture( OBJ ) dynamic_cast<Dx11BaseRenderTexture*>( OBJ )


} // gfx


} // synkro


#endif // _SYNKRO_GFX_DX11BASERENDERTEXTURE_
