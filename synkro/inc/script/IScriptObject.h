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
// Purpose: Defines script object.
//==============================================================================
#ifndef _SYNKRO_SCRIPT_ISCRIPTOBJECT_
#define _SYNKRO_SCRIPT_ISCRIPTOBJECT_


#include "config.h"
#include <core/IObject.h>


namespace synkro
{


namespace script
{


/**
 * Script object.
 */
iface IScriptObject :
	public core::IObject
{
public:
	/**
	 * Executes a piece of script code.
	 * @param script Stream from which to read script code.
	 * @exception ScriptException Incorrect script syntax.
	 */
	virtual void											Execute( io::IStream* script ) = 0;

	/**
	 * Adds methods to the object.
	 * @param methods Array of object methods.
	 * @param methodCount Total number of object methods.
	 */
	virtual void											AddMethods( const ScriptMethod** methods, UInt methodCount ) = 0;

	/**
	 * Retrieves owner script machine.
	 */
	virtual IScriptMachine*									GetMachine() const = 0;
};


} // script


} // synkro


#endif // _SYNKRO_SCRIPT_ISCRIPTOBJECT_
