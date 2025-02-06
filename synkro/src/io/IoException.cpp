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
// Purpose: Implements input/output exception.
//==============================================================================
#include "config.h"
#include <io/IoException.h>


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace io
{


IoException::IoException( const String& message ) :
	Exception( message )
{
}

IoException::IoException() :
	Exception( L"Unknown input/output error." )
{
}

String IoException::ToString() const
{
	return _message;
}

IoException::IoException( const IoException& )
{
}

IoException& IoException::operator=( const IoException& )
{
	return *this;
}


} // io


} // synkro
