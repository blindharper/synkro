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
// Purpose: Implements expression exception.
//==============================================================================
#include "config.h"
#include <anim/ExpressionException.h>


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace anim
{


ExpressionException::ExpressionException( const String& message, UInt line, UInt symbol ) :
	Exception( message ),
	_line( line ),
	_symbol( symbol )
{
}

UInt ExpressionException::Line() const
{
	return _line;
}

UInt ExpressionException::Symbol() const
{
	return _symbol;
}

String ExpressionException::ToString() const
{
	if ( (_line != 0) && (_symbol != 0) )
	{
		return String::Format( L"Syntax error: {0}. Line: {1}. Symbol: {2}", _message, _line, _symbol );	
	}
	return _message;
}

ExpressionException::ExpressionException( const ExpressionException& )
{
}

ExpressionException& ExpressionException::operator=( const ExpressionException& )
{
	return *this;
}


} // anim


} // synkro
