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
// Purpose: Defines script system types.
//==============================================================================
#ifndef _SYNKRO_SCRIPT_SCRIPTSYSTEM_
#define _SYNKRO_SCRIPT_SCRIPTSYSTEM_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace script
{


/**
 * Script system types.
 */
SYNKRO_ENUM_BEGIN( ScriptSystem )
	/** Custom script system. */
	SYNKRO_ENUM_CONST( ScriptSystem, Custom )

	/** Lua based script system. */
	SYNKRO_ENUM_CONST( ScriptSystem, Lua )
SYNKRO_ENUM_END()


} // script


} // synkro


#endif // _SYNKRO_SCRIPT_SCRIPTSYSTEM_
