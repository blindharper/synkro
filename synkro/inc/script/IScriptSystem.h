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
// Purpose: Defines scripting system.
//==============================================================================
#ifndef _SYNKRO_SCRIPT_ISCRIPTSYSTEM_
#define _SYNKRO_SCRIPT_ISCRIPTSYSTEM_


#include "config.h"
#include <core/ISystem.h>


namespace synkro
{


namespace script
{


/**
 * Scripting system.
 */
iface IScriptSystem :
	public core::ISystem
{
public:
	/**
	 * Creates virtual script machine.
	 * @param name Unique machine name.
	 * @return Created script machine.
	 * @exception BadArgumentException Script machine with this name already exists.
	 */
	virtual IScriptMachine*									CreateMachine( const lang::String& name ) = 0;
};


} // script


} // synkro


#endif // _SYNKRO_SCRIPT_ISCRIPTSYSTEM_
