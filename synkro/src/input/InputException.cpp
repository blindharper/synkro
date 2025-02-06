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
// Purpose: Implements input system exception.
//==============================================================================
#include "config.h"
#include <input/InputException.h>


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace input
{


InputException::InputException( const String& message, const String& details, const String& code ) :
	Exception( message ),
	_details( details ),
	_code( code )
{
}

InputException::InputException( const String& message, const String& code ) :
	Exception( message ),
	_code( code )
{
}

InputException::InputException( const String& message ) :
	Exception( message )
{
}

String InputException::Details() const
{
	return _details;
}

String InputException::Code() const
{
	return _code;
}

String InputException::ToString() const
{
	if ( !_code.IsEmpty() )
	{
		if ( !_details.IsEmpty() )
		{
			return String::Format( L"{0} Code: {1}. Details: {2}", _message, _code, _details );
		}
		return String::Format( L"{0} Code: {1}", _message, _code );
	}
	return _message;
}

InputException::InputException( const InputException& )
{
}

InputException& InputException::operator=( const InputException& )
{
	return *this;
}


} // input


} // synkro
