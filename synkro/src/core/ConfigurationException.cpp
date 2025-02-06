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
// Purpose: Implements configuration exception.
//==============================================================================
#include "config.h"
#include <core/ConfigurationException.h>


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace core
{


ConfigurationException::ConfigurationException( const String& param, const ParamConstraint constraint ) :
	_param( param ),
	_constraint( constraint )
{
}

ConfigurationException::ConfigurationException( const String& message, const String& param ) :
	Exception( message ),
	_param( param )
{
	if		( _constraint == ParamConstraint::NonEmpty )	_message = String::Format( L"Configuration error: Parameter {0,q} is empty.", _param );
	else if ( _constraint == ParamConstraint::Positive )	_message = String::Format( L"Configuration error: Parameter {0,q} is non-positive.", _param );
	else													_message = _message.IsEmpty() ? String::Format( L"Configuration error: Bad parameter {0,q}.", _param ) : _message;
}

ConfigurationException::ConfigurationException( const String& message ) :
	Exception( message )
{
}

String ConfigurationException::Param() const
{
	return _param;
}

String ConfigurationException::ToString() const
{
	return _message;
}

ConfigurationException::ConfigurationException( const ConfigurationException& )
{
}

ConfigurationException& ConfigurationException::operator=( const ConfigurationException& )
{
	return *this;
}


} // core


} // synkro
