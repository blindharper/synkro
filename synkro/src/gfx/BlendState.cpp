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
// Purpose: Logical blend state.
//==============================================================================
#include "config.h"
#include "BlendState.h"


//------------------------------------------------------------------------------

using namespace synkro::img;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace gfx
{


BlendState::BlendState( IBlendState* state, Bool readonly ) :
	_readonly( readonly ),
	_state( state )
{
	assert( _state != nullptr );

	_state->Enable( false );
	_state->SetColorSrcMode( BlendMode::One );
	_state->SetColorDstMode( BlendMode::Zero );
	_state->SetColorOperation( BlendOperation::Add );
	_state->SetAlphaSrcMode( BlendMode::One );
	_state->SetAlphaDstMode( BlendMode::Zero );
	_state->SetAlphaOperation( BlendOperation::Add );
	_state->SetWriteChannels( PixelChannel::All );
}

void BlendState::PreventModify()
{
	if ( _readonly )
		throw InvalidOperationException( L"Cannot modify default blend state." );
}


} // gfx


} // synkro
