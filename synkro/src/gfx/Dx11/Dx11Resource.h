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
// Purpose: DX11 resource.
//==============================================================================
#ifndef _SYNKRO_GFX_DX11RESOURCE_
#define _SYNKRO_GFX_DX11RESOURCE_


#include "config.h"
#include <dx/d3dx11tex.h>


namespace synkro
{


namespace gfx
{


// DirectX 11 base resource.
class Dx11Resource
{
public:
	// Generates full set of mipmap levels.
	virtual void											GenerateMipmaps() = 0;

	// Returns underlying DX11 resource view.
	virtual ID3D11ShaderResourceView*						AsDx11ShaderResourceView() const = 0;
};


// Casts object to Dx11Resource.
#define AsDx11Resource( OBJ ) dynamic_cast<Dx11Resource*>( OBJ )


} // gfx


} // synkro


#endif // _SYNKRO_GFX_DX11RESOURCE_
