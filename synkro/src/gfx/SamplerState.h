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
// Purpose: Logical sampler state.
//==============================================================================
#ifndef _SYNKRO_GFX_SAMPLERSTATE_
#define _SYNKRO_GFX_SAMPLERSTATE_


#include "config.h"
#include <core/ObjectImpl.h>
#include <gfx/ISamplerState.h>


namespace synkro
{


namespace gfx
{


// Logical sampler state.
class SamplerState :
	public core::ObjectImpl<ISamplerState>
{
public:
	// Constructors.
	SamplerState( ISamplerState* state, Bool readonly );

	// ISamplerState methods.
	void													SetFilter( const TextureFilter& filter );
	void													SetMinFilter( const TextureFilter& filter );
	void													SetMagFilter( const TextureFilter& filter );
	void													SetMipFilter( const TextureFilter& filter );
	void													SetMaxAnisotropy( UInt anisotropy );
	void													SetAddress( const TextureAddress& address );
	void													SetAddressU( const TextureAddress& address );
	void													SetAddressV( const TextureAddress& address );
	void													SetAddressW( const TextureAddress& address );
	void													SetBorderColor( const math::Vector4& color );
	TextureFilter											GetMinFilter() const;
	TextureFilter											GetMagFilter() const;
	TextureFilter											GetMipFilter() const;
	UInt													GetMaxAnisotropy() const;
	TextureAddress											GetAddressU() const;
	TextureAddress											GetAddressV() const;
	TextureAddress											GetAddressW() const;
	void													GetBorderColor( math::Vector4& color ) const;

private:
	P(ISamplerState)										_state;
	Bool													_readonly;

	void													PreventModify();
};


#include "SamplerState.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_SAMPLERSTATE_
