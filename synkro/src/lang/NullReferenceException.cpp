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
// Purpose: Implements 'Null reference' exception.
//==============================================================================
#include "config.h"
#include <lang/NullReferenceException.h>
#include <core/Str.h>


//------------------------------------------------------------------------------

using namespace synkro::core;

//------------------------------------------------------------------------------


namespace synkro
{


namespace lang
{


NullReferenceException::NullReferenceException( const String& file, UInt line ) :
	Exception( String::Format(L"{0} File: {1}. Line: {2}", Str::NullReference, file, line) )
{
}

String NullReferenceException::ToString() const
{
	return _message;
}

NullReferenceException::NullReferenceException( const NullReferenceException& )
{
}

NullReferenceException& NullReferenceException::operator=( const NullReferenceException& )
{
	return *this;
}


} // lang


} // synkro
