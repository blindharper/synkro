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
// Purpose: Defines 'Not supported' exception.
//==============================================================================
#include "config.h"
#include <lang/NotSupportedException.h>


namespace synkro
{


namespace lang
{


NotSupportedException::NotSupportedException( const String& message ) :
	Exception( message )
{
}

NotSupportedException::NotSupportedException() :
	Exception( L"Method is not supported." )
{
}

String NotSupportedException::ToString() const
{
	return _message;
}

NotSupportedException::NotSupportedException( const NotSupportedException& )
{
}

NotSupportedException& NotSupportedException::operator=( const NotSupportedException& )
{
	return *this;
}


} // lang


} // synkro
