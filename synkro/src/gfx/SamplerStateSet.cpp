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
#include "config.h"
#include "SamplerStateSet.h"
#include "SamplerState.h"


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace gfx
{


SamplerStateSet::SamplerStateSet( ISamplerStateSet* set ) :
	SamplerStateSetImpl<ISamplerStateSet>( ProgramStageType::Unknown ),
	_set( set )
{
	for ( UInt i = 0; i < _set->GetSize(); ++i )
	{
		_states.Add( new SamplerState(_set->Get(i), true) );
	}
}

SamplerStateSet::SamplerStateSet( const SamplerStateSet& other, UInt ownerID ) :
	SamplerStateSetImpl<ISamplerStateSet>( ProgramStageType::Unknown ),
	_set( other._set->Clone(ownerID) )
{
	for ( UInt i = 0; i < _set->GetSize(); ++i )
	{
		_states.Add( new SamplerState(_set->Get(i), false) );
	}
}


} // gfx


} // synkro
