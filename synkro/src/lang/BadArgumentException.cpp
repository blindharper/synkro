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
// Purpose: Implements 'Bad argument' exception.
//==============================================================================
#include "config.h"
#include <lang/BadArgumentException.h>


namespace synkro
{


namespace lang
{


BadArgumentException::BadArgumentException( const String& message, const String& argument, const String& value ) :
	Exception( message ),
	_argument( argument ),
	_value( value )
{
}

BadArgumentException::BadArgumentException( const String& message, const String& argument ) :
	Exception( message ),
	_argument( argument )
{
}

BadArgumentException::BadArgumentException() :
	Exception( L"Invalid argument." )
{
}

String BadArgumentException::Argument() const
{
	return _argument;
}

String BadArgumentException::Value() const
{
	return _value;
}

String BadArgumentException::ToString() const
{
	return String::Format( L"{0}\r\nArgument: {1,q}\r\nValue: {2,q}", _message, _argument, _value );
}

BadArgumentException::BadArgumentException( const BadArgumentException& )
{
}

BadArgumentException& BadArgumentException::operator=( const BadArgumentException& )
{
	return *this;
}


} // lang


} // synkro
