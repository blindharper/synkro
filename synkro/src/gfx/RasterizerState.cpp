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
// Purpose: Logical rasterizer state.
//==============================================================================
#include "config.h"
#include "RasterizerState.h"


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace gfx
{


RasterizerState::RasterizerState( IRasterizerState* state ) :
	_state( state ),
	_readonly( true )
{
	assert( state != nullptr );

	_state->SetCullMode( CullMode::Back );
	_state->SetFillMode( FillMode::Solid );
	_state->SetDepthBias( 0.0f );
	_state->SetDepthBiasClamp( 0.0f );
	_state->SetSlopeScaledDepthBias( 0.0f );
	_state->EnableScissor( false );
	_state->EnableMultisample( false );
	_state->EnableAntialiasing( false );
}

RasterizerState::RasterizerState( const RasterizerState& other ) :
	_state( other._state->Clone() ),
	_readonly( false )
{
}

void RasterizerState::PreventModify()
{
	if ( _readonly )
		throw InvalidOperationException( L"Cannot modify default rasterizer state." );
}


} // gfx


} // synkro
