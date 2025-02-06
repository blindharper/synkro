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
// Purpose: Implements 'Invalid operation' exception.
//==============================================================================
#include "config.h"
#include <lang/InvalidOperationException.h>


namespace synkro
{


namespace lang
{


InvalidOperationException::InvalidOperationException( const String& message ) :
	Exception( message )
{
}

InvalidOperationException::InvalidOperationException() :
	Exception( L"Invalid operation." )
{
}

String InvalidOperationException::ToString() const
{
	return _message;
}

InvalidOperationException::InvalidOperationException( const InvalidOperationException& )
{
}

InvalidOperationException& InvalidOperationException::operator=( const InvalidOperationException& )
{
	return *this;
}


} // lang


} // synkro
