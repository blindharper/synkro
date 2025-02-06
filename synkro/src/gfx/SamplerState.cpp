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
#include "config.h"
#include "SamplerState.h"


//------------------------------------------------------------------------------

using namespace synkro::lang;
using namespace synkro::math;

//------------------------------------------------------------------------------


namespace synkro
{


namespace gfx
{


SamplerState::SamplerState( ISamplerState* state, Bool readonly ) :
	_state( state ),
	_readonly( readonly )
{
	assert( state != nullptr );

	_state->SetMinFilter( TextureFilter::Point );
	_state->SetMagFilter( TextureFilter::Point );
	_state->SetMipFilter( TextureFilter::Point );
	_state->SetMaxAnisotropy( 16 );
	_state->SetAddressU( TextureAddress::Wrap );
	_state->SetAddressV( TextureAddress::Wrap );
	_state->SetAddressW( TextureAddress::Wrap );
	_state->SetBorderColor( Vector4(0.0f, 0.0f, 0.0f, 1.0f) );
}

void SamplerState::PreventModify()
{
	if ( _readonly )
		throw InvalidOperationException( L"Cannot modify default sampler state." );
}


} // gfx


} // synkro
