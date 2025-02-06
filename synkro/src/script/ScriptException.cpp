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
// Purpose: Implements script exception.
//==============================================================================
#include "config.h"
#include <script/ScriptException.h>


namespace synkro
{


namespace script
{


ScriptException::ScriptException( const lang::String& message ) :
	lang::Exception( message )
{
}

lang::String ScriptException::ToString() const
{
	return lang::String::Format( L"Script error: {0}", _message );
}

ScriptException::ScriptException( const ScriptException& )
{
}

ScriptException& ScriptException::operator=( const ScriptException& )
{
	return *this;
}


} // script


} // synkro
