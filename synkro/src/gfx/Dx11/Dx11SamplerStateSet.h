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
// Purpose: DX11 sampler state set implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_DX11SAMPLERSTATESET_
#define _SYNKRO_GFX_DX11SAMPLERSTATESET_


#include "config.h"
#include <gfx/SamplerStateSetImpl.h>
#include <gfx/ISamplerStateSet.h>
#include <gfx/GraphicsException.h>
#undef new
#include "Dx11.h"
#include "Dx11SamplerState.h"
#define new SYNKRO_NEW


namespace synkro
{


namespace gfx
{


// DX11 sampler state set.
class Dx11SamplerStateSet :
	public SamplerStateSetImpl<ISamplerStateSet>
{
public:
	// Constructors.
	Dx11SamplerStateSet( Dx11Context* context, ID3D11ShaderReflection* reflect, const ProgramStageType& type, UINT startSlot );
	Dx11SamplerStateSet( const Dx11SamplerStateSet& other );

	// ISamplerStateSet methods.
	void													Bind();
	ISamplerStateSet*										Clone( UInt ownerID ) const;

private:
	lang::Vector<ID3D11SamplerState*>						_samplers;
	UINT													_startSlot;
	Dx11Context												_context;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_DX11SAMPLERSTATESET_
