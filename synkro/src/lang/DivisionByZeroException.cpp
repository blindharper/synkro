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
// Purpose: Implements 'Division by zero' exception.
//==============================================================================
#include "config.h"
#include <lang/DivisionByZeroException.h>
#include <core/Str.h>


//------------------------------------------------------------------------------

using namespace synkro::core;

//------------------------------------------------------------------------------


namespace synkro
{


namespace lang
{


DivisionByZeroException::DivisionByZeroException() :
	Exception( Str::DivisionByZero )
{
}

String DivisionByZeroException::ToString() const
{
	return _message;
}

DivisionByZeroException::DivisionByZeroException( const DivisionByZeroException& )
{
}

DivisionByZeroException& DivisionByZeroException::operator=( const DivisionByZeroException& )
{
	return *this;
}


} // lang


} // synkro
