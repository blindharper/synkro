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
// Purpose: Logical sampler state set.
//==============================================================================
#ifndef _SYNKRO_GFX_SAMPLERSTATESET_
#define _SYNKRO_GFX_SAMPLERSTATESET_


#include "config.h"
#include "SamplerStateSetImpl.h"
#include <gfx/ISamplerStateSet.h>


namespace synkro
{


namespace gfx
{


// Logical sampler state set.
class SamplerStateSet :
	public SamplerStateSetImpl<ISamplerStateSet>
{
public:
	// Constructors.
	SamplerStateSet( ISamplerStateSet* set );
	SamplerStateSet( const SamplerStateSet& other, UInt ownerID );

	// IRenderState methods.
	void													Bind();

	// ISamplerStateSet methods.
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
	ISamplerStateSet*										Clone( UInt ownerID ) const;

private:
	P(ISamplerStateSet)										_set;
};


#include "SamplerStateSet.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_SAMPLERSTATESET_
