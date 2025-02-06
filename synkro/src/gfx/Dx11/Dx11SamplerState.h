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
// Purpose: DX11 based sampler state implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_DX11SAMPLERSTATE_
#define _SYNKRO_GFX_DX11SAMPLERSTATE_


#include "config.h"
#include <gfx/SamplerStateImpl.h>
#include <gfx/ISamplerState.h>
#undef new
#include "Dx11.h"
#define new SYNKRO_NEW


namespace synkro
{


namespace gfx
{


// DX11 based sampler state implementation.
class Dx11SamplerState :
	public SamplerStateImpl<ISamplerState>
{
public:
	// Constructors & destructor.
	Dx11SamplerState( ID3D11Device* device );
	Dx11SamplerState( const Dx11SamplerState& other );
	~Dx11SamplerState();

	// ISamplerState methods.
	ISamplerState*											Clone() const;

	// Other methods.
	ID3D11SamplerState*										GetState();

private:
	ID3D11Device*											_device;
	ID3D11SamplerState*										_state;

	void													Destroy();
	void													Prepare();
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_DX11SAMPLERSTATE_
