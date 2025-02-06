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
// Purpose: Defines extended scripting system.
//==============================================================================
#ifndef _SYNKRO_SCRIPT_ISCRIPTSYSTEMEX_
#define _SYNKRO_SCRIPT_ISCRIPTSYSTEMEX_


#include "config.h"
#include <script/IScriptSystem.h>


namespace synkro
{


namespace script
{


/**
 * Extended scripting system.
 */
iface IScriptSystemEx :
	public IScriptSystem
{
public:
	/**
	 * Retrieves the total number of created script machines.
	 */
	virtual UInt											GetMachineCount() const = 0;

	/**
	 * Retrieves script machine by index.
	 * @param index Index of the script machine to retrieve.
	 * @return Requested script machine.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual IScriptMachine*									GetMachine( UInt index ) const = 0;

	/**
	 * Retrieves script machine by name.
	 * @param name Name of the script machine to retrieve.
	 * @return Requested script machine if one exists, or null otherwise.
	 */
	virtual IScriptMachine*									GetMachine( const lang::String& name ) const = 0;
};


} // script


} // synkro


#endif // _SYNKRO_SCRIPT_ISCRIPTSYSTEMEX_
