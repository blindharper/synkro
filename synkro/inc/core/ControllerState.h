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
// Purpose: Defines controller state.
//==============================================================================
#ifndef _SYNKRO_CORE_CONTROLLERSTATE_
#define _SYNKRO_CORE_CONTROLLERSTATE_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace core
{


/**
 * Controller state.
 */
SYNKRO_ENUM_BEGIN( ControllerState )
	/** Controller is inactive. */
	SYNKRO_ENUM_CONST( ControllerState, Inactive )

	/** Controller is active. */
	SYNKRO_ENUM_CONST( ControllerState, Active )
	
	/** Controller update is suspended. */
	SYNKRO_ENUM_CONST( ControllerState, Suspended )
SYNKRO_ENUM_END()


} // core


} // synkro


#endif // _SYNKRO_CORE_CONTROLLERSTATE_
