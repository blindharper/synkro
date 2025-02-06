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
// Purpose: Implements bit flag set.
//==============================================================================
#include "config.h"
#include <lang/Flag.h>


namespace synkro
{


namespace lang
{


Flag::Flag( UInt value ) :
	Enum( value )
{
}

void Flag::Set( const Flag& flag )
{
	_value |= flag._value;
}

void Flag::Reset( const Flag& flag )
{
	_value &= ~flag._value;
}

Bool Flag::IsSet( const Flag& flag ) const
{
	return (this->_value & flag._value) != 0;
}

Bool Flag::IsNotSet( const Flag& flag ) const
{
	return (this->_value & flag._value) == 0;
}

UInt Flag::Bits() const
{
	UInt cnt = 0;

	UInt bit = 1;
	for ( UInt i = 0; i < 32; ++i, bit <<= 1 )
	{
		if ( (_value & bit) != 0 )
		{
			++cnt;
		}
	}

	return cnt;
}


} // lang


} // synkro
