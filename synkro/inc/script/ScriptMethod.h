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
// Purpose: Defines script method.
//==============================================================================
#ifndef _SYNKRO_SCRIPT_SCRIPTMETHOD_
#define _SYNKRO_SCRIPT_SCRIPTMETHOD_


#include "config.h"
#include <script/ScriptParam.h>


namespace synkro
{


namespace script
{


/** 
 * Script method. Gets called from the context of low-level script code.
 */
class SYNKRO_API ScriptMethod
{
public:
	/** Creates default method. */
	ScriptMethod();

	/** Creates method with the given attributes. */
	ScriptMethod( const char* name, const char* inputSignature, const char* outputSignature );

	/** Method's name. */
	const char*												Name;

	/** Method's input signature. Each character refers to parameter type: [b]oolean, [n]umber, [s]tring, [o]bject. */
	const char*												InputSignature;

	/** Method's output signature. Each character refers to parameter type: [b]oolean, [n]umber, [s]tring, [o]bject. */
	const char*												OutputSignature;

	/**
	 * Calls method. Method's return values are stored in output parameters.
	 * @param object Object on which to run the method.
	 * @param inputParams Array of input parameters.
	 * @param outputParams Array of output parameters.
	 */
	virtual void											Call( void* object, const ScriptParam* inputParams, ScriptParam* outputParams ) = 0;
};


} // script


} // synkro


#endif // _SYNKRO_SCRIPT_SCRIPTMETHOD_
