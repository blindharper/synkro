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
// Purpose: Implements enumeration value.
//==============================================================================
#include "config.h"
#include <lang/Enum.h>
#include <ui/EditStyle.h>
#include <ui/Alignment.h>


namespace synkro
{


namespace lang
{


Enum::Enum( UInt value ) :
	_value( value )
{
}

Enum::Enum() :
	_value( 0 )
{
}

Bool Enum::operator==( const Enum& other ) const
{
	return (this->_value == other._value);
}

Bool Enum::operator!=( const Enum& other ) const
{
	return (this->_value != other._value);
}

Int Enum::HashCode() const
{
	return CastInt(_value);
}

UInt Enum::Value() const
{
	return _value;
}

Enum::operator UInt() const
{
	return _value;
}

UInt Enum::GetValue( const String& type, const String& value )
{
	if ( type.EqualsTo(L"Alignment", true) )
		return ui::Alignment(value).Value();
	else if ( type.EqualsTo(L"EditStyle", true) )
		return ui::EditStyle(value).Value();

	return 0;
}


} // lang


} // synkro
