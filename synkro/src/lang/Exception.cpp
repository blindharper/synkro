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
// Purpose: Implements base exception.
//==============================================================================
#include "config.h"
#include <lang/Exception.h>
#include <core/ExceptionHandler.h>
#include <core/CallStack.h>
#include <core/Str.h>


//------------------------------------------------------------------------------

using namespace synkro::core;

//------------------------------------------------------------------------------


namespace synkro
{


namespace lang
{


Exception::Exception( const String& message ) :
	_message( message )
{
	CallStack::Stop();
}

Exception::Exception() :
	_message( Str::UnknownError )
{
	CallStack::Stop();
}

Exception::~Exception()
{
}

void Exception::Show() const
{
	ExceptionHandler::Show( ToString() );
}

String Exception::Stack() const
{
	return CallStack::GetStackTrace();
}

String Exception::Message() const
{
	return _message;
}

String Exception::ToString() const
{
	return _message;
}

Exception::Exception( const Exception& )
{
}

Exception& Exception::operator=( const Exception& )
{
	return *this;
}


} // lang


} // synkro
