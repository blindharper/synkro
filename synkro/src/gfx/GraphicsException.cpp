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
// Purpose: Implements graphics system exception.
//==============================================================================
#include "config.h"
#include <gfx/GraphicsException.h>
#include <core/ExceptionHandler.h>


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace gfx
{


GraphicsException::GraphicsException( const String& message, const String& details, const String& code ) :
	Exception( message ),
	_details( details ),
	_code( code )
{
}

GraphicsException::GraphicsException( const String& message, const String& code ) :
	Exception( message ),
	_code( code )
{
}

GraphicsException::GraphicsException( const String& message ) :
	Exception( message )
{
}

String GraphicsException::Details() const
{
	return _details;
}

String GraphicsException::Code() const
{
	return _code;
}

String GraphicsException::ToString() const
{
	return String::Format( L"Graphics Exception: {0} \r\nDetails: {1}\r\nCode: {2}", _message, _details, _code );
}

GraphicsException::GraphicsException( const GraphicsException& )
{
}

GraphicsException& GraphicsException::operator=( const GraphicsException& )
{
	return *this;
}


} // gfx


} // synkro
