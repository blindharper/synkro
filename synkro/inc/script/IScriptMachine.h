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
// Purpose: Defines virtual script machine.
//==============================================================================
#ifndef _SYNKRO_SCRIPT_ISCRIPTMACHINE_
#define _SYNKRO_SCRIPT_ISCRIPTMACHINE_


#include "config.h"
#include <core/IObject.h>
#include <script/ScriptMethod.h>


namespace synkro
{


namespace script
{


/**
 * Virtual script machine. Provides access to high-level objects from scripts.
 */
iface IScriptMachine :
	public core::IObject
{
public:
	/**
	 * Executes given script against current context.
	 * @param script Script stream.
	 * @exception ScriptException Incorrect script syntax.
	 */
	virtual void											Execute( io::IStream* script ) = 0;

	/**
	 * Executes a piece of script code against current context.
	 * @param script Script code.
	 * @exception ScriptException Incorrect script syntax.
	 */
	virtual void											Execute( const lang::String& script ) = 0;

	/**
	 * Creates script proxy for the given high-level object.
	 * @param object Corresponding high-level object.
	 * @param script Stream from which to read initialization script.
	 * @param methods Array of object methods.
	 * @param methodCount Total number of object methods.
	 * @return Created script object.
	 */
	virtual IScriptObject*									CreateObject( void* object, io::IStream* script, const ScriptMethod** methods, UInt methodCount ) = 0;

	/**
	 * Sets script context. The context is referred in the script code as 'this'.
	 * @param context Script object to set as 'this'.
	 * @exception ScriptException Script object does not belong to this machine.
	 */
	virtual void											SetContext( IScriptObject* context ) = 0;

	/**
	 * Retrieves script context.
	 */
	virtual IScriptObject*									GetContext() const = 0;

	/**
	 * Retrieves machine name.
	 */
	virtual lang::String									GetName() const = 0;
};


} // script


} // synkro


#endif // _SYNKRO_SCRIPT_ISCRIPTMACHINE_
