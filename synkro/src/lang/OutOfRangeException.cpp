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
// Purpose: Implements 'Out of range' exception.
//==============================================================================
#include "config.h"
#include <lang/OutOfRangeException.h>
#include <core/Str.h>


//------------------------------------------------------------------------------

using namespace synkro::core;

//------------------------------------------------------------------------------


namespace synkro
{


namespace lang
{


OutOfRangeException::OutOfRangeException( UInt index, UInt maximum ) :
	Exception( Str::OutOfRange ),
	_index( index ),
	_maximum( maximum )
{
}

UInt OutOfRangeException::Index() const
{
	return _index;
}

UInt OutOfRangeException::Maximum() const
{
	return _maximum;
}

String OutOfRangeException::ToString() const
{
	return String::Format( L"{0}\r\nIndex: {1}\r\nAllowed maximum: {2}", _message, _index, (_maximum > 0) ? _maximum-1 : (Int)-1 );
}

OutOfRangeException::OutOfRangeException( const OutOfRangeException& )
{
}

OutOfRangeException& OutOfRangeException::operator=( const OutOfRangeException& )
{
	return *this;
}


} // lang


} // synkro
