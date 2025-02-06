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
// Purpose: Defines script method's parameter.
//==============================================================================
#ifndef _SYNKRO_SCRIPT_SCRIPTPARAM_
#define _SYNKRO_SCRIPT_SCRIPTPARAM_


#include "config.h"
#include <script/ScriptParamType.h>


namespace synkro
{


namespace script
{


/**
 * Script method's parameter.
 */
class SYNKRO_API ScriptParam
{
public:
	/** Creates boolean parameter. */
	ScriptParam( Bool value );

	/** Creates numeric parameter. */
	ScriptParam( Double value );

	/** Creates string parameter. */
	ScriptParam( const char* value );

	/** Creates object parameter. */
	ScriptParam( IScriptObject* value );

	/** Creates default parameter. */
	ScriptParam();

	/** Sets boolean value. */
	void													Set( Bool value );
	
	/** Sets numeric value. */
	void													Set( Double value );

	/** Sets string value. */
	void													Set( const char* value );

	/** Sets object value. */
	void													Set( IScriptObject* value );

	/** Retrieves boolean value. */
	Bool													GetBoolean() const;

	/** Retrieves numeric value. */
	Double													GetNumber() const;

	/** Retrieves string value. */
	const char*												GetString() const;

	/** Retrieves object value. */
	IScriptObject*											GetObject() const;

	/** Retrieves parameter type. */
	ScriptParamType											GetType() const;

private:
	ScriptParamType											Type;
	Bool													ValueBoolean;
	Double													ValueNumber;
	const char*												ValueString;
	IScriptObject*											ValueObject;
};


} // script


} // synkro


#endif // _SYNKRO_SCRIPT_SCRIPTPARAM_
