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
// Purpose: Logical depth-stencil state.
//==============================================================================
#include "config.h"
#include "DepthStencilState.h"


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace gfx
{


DepthStencilState::DepthStencilState( IDepthStencilState* state ) :
	_state( state ),
	_readonly( true )
{
	assert( state != nullptr );

	_state->EnableDepth( true );
	_state->EnableDepthWrite( true );
	_state->SetDepthFunction( CompareFunction::LessOrEqual );
	_state->EnableStencil( false );
	_state->SetReadMask( 0xff );
	_state->SetWriteMask( 0xff );
	_state->SetReference( 0x00 );
	_state->SetStencilFunction( CompareFunction::Always );
	_state->SetFailOperation( StencilOperation::None );
	_state->SetDepthFailOperation( StencilOperation::None );
	_state->SetPassOperation( StencilOperation::None );
}

DepthStencilState::DepthStencilState( const DepthStencilState& other ) :
	_state( other._state->Clone() ),
	_readonly( false )
{
}

void DepthStencilState::PreventModify()
{
	if ( _readonly )
		throw InvalidOperationException( L"Cannot modify default depth-stencil state." );
}


} // gfx


} // synkro
