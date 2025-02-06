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
// Purpose: Implements network system exception.
//==============================================================================
#include "config.h"
#include <net/NetworkException.h>
#include <lang/Formatter.h>


namespace synkro
{


namespace net
{


NetworkException::NetworkException( const lang::String& message, const lang::String& details, const lang::String& code ) :
	lang::Exception( message ),
	_details( details ),
	_code( code )
{
}

NetworkException::NetworkException( const lang::String& message, const lang::String& code ) :
	lang::Exception( message ),
	_code( code )
{
}

NetworkException::NetworkException( const lang::String& message ) :
	lang::Exception( message )
{
}

lang::String NetworkException::Details() const
{
	return _details;
}

lang::String NetworkException::Code() const
{
	return _code;
}

lang::String NetworkException::ToString() const
{
	if ( !_code.IsEmpty() )
	{
		if ( !_details.IsEmpty() )
		{
			return lang::String::Format( L"{0} Code: {1}. Details: {2}", _message, _code, _details );
		}
		return lang::String::Format( L"{0} Code: {1}", _message, _code );
	}
	return _message;
}

NetworkException::NetworkException( const NetworkException& )
{
}

NetworkException& NetworkException::operator=( const NetworkException& )
{
	return *this;
}


} // net


} // synkro
