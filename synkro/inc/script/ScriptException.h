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
// Purpose: Defines script exception.
//==============================================================================
#ifndef _SYNKRO_SCRIPT_SCRIPTEXCEPTION_
#define _SYNKRO_SCRIPT_SCRIPTEXCEPTION_


#include "config.h"
#include <lang/Exception.h>


namespace synkro
{


namespace script
{


/**
 * Thrown when script system encounters a syntax error.
 */
class SYNKRO_API ScriptException :
	public lang::Exception
{
public:
	/**
	 * Creates an exception.
	 * @param message Error message.
	 */
	ScriptException( const lang::String& message );

	/**
	 * Retrieves formatted error message.
	 */
	lang::String											ToString() const;

	ScriptException( const ScriptException& );

private:
	ScriptException& operator=( const ScriptException& );
};


} // script


} // synkro


#endif // _SYNKRO_SCRIPT_SCRIPTEXCEPTION_
