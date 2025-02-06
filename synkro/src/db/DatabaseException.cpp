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
// Purpose: Implements database exception.
//==============================================================================
#include "config.h"
#include <db/DatabaseException.h>
#include <lang/Formatter.h>


namespace synkro
{


namespace db
{


DatabaseException::DatabaseException( const lang::String& message, const lang::String& query, const lang::String& code ) :
	lang::Exception( lang::String::Format(L"Database error: {0}", message) ),
	_query( query ),
	_code( code )
{
}

DatabaseException::DatabaseException( const lang::String& message, const lang::String& code ) :
	lang::Exception( lang::String::Format(L"Database error: {0}", message) ),
	_code( code )
{
}

DatabaseException::DatabaseException( const lang::String& query ) :
	_query( query )
{
}

lang::String DatabaseException::Query() const
{
	return _query;
}

lang::String DatabaseException::Code() const
{
	return _code;
}

lang::String DatabaseException::ToString() const
{
	return lang::String::Format( L"Database error: {0}. Code: {1}", _message, _code );
}

DatabaseException::DatabaseException( const DatabaseException& )
{
}

DatabaseException& DatabaseException::operator=( const DatabaseException& )
{
	return *this;
}


} // db


} // synkro
