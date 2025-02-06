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
// Purpose: Generic sampler state set implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_SAMPLERSTATESETIMPL_
#define _SYNKRO_GFX_SAMPLERSTATESETIMPL_


#include "config.h"
#include <lang/Vector.h>
#include "RenderStateImpl.h"
#include <gfx/ISamplerState.h>
#include <gfx/ProgramStageType.h>


namespace synkro
{


namespace gfx
{


// Generic sampler state set implementation.
template <class T>
class SamplerStateSetImpl :
	public RenderStateImpl<T>
{
public:
	// Constructor & destructor.
	SamplerStateSetImpl( const ProgramStageType& type );
	virtual ~SamplerStateSetImpl();

	// ISamplerStateSet methods.
	virtual void											SetFilter( const TextureFilter& filter );
	virtual void											SetMinFilter( const TextureFilter& filter );
	virtual void											SetMagFilter( const TextureFilter& filter );
	virtual void											SetMipFilter( const TextureFilter& filter );
	virtual void											SetMaxAnisotropy( UInt anisotropy );
	virtual void											SetAddress( const TextureAddress& address );
	virtual void											SetAddressU( const TextureAddress& address );
	virtual void											SetAddressV( const TextureAddress& address );
	virtual void											SetAddressW( const TextureAddress& address );
	virtual void											SetBorderColor( const math::Vector4& color );
	virtual UInt											GetSize() const;
	virtual ISamplerState*									Get( UInt index ) const;

protected:
	lang::Vector<P(ISamplerState)>							_states;
	ProgramStageType										_type;
};


#include "SamplerStateSetImpl.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_SAMPLERSTATESETIMPL_
