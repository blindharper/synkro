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
// Purpose: Logical blend state set.
//==============================================================================
#include "config.h"
#include "BlendStateSet.h"
#include "BlendState.h"


//------------------------------------------------------------------------------

using namespace synkro::core;

//------------------------------------------------------------------------------


namespace synkro
{


namespace gfx
{


BlendStateSet::BlendStateSet( IBlendStateSet* set ) :
	BlendStateSetImpl<IBlendStateSet>( set->GetSize() ),
	_readonly( true ),
	_set( set )
{
	_set->EnableAlphaToCoverage( false );
	for ( UInt i = 0; i < _set->GetSize(); ++i )
	{
		_states.Add( new BlendState(_set->Get(i), true) );
	}
}

BlendStateSet::BlendStateSet( const BlendStateSet& other ) :
	BlendStateSetImpl<IBlendStateSet>( other._set->GetSize() ),
	_readonly( false ),
	_set( other._set->Clone() )
{
	_set->EnableAlphaToCoverage( other._set->IsAlphaToCoverageEnabled() );
	for ( UInt i = 0; i < _set->GetSize(); ++i )
	{
		_states.Add( new BlendState(_set->Get(i), false) );
	}
}


} // gfx


} // synkro
