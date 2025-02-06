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
// Purpose: Defines input system types.
//==============================================================================
#ifndef _SYNKRO_INPUT_INPUTSYSTEM_
#define _SYNKRO_INPUT_INPUTSYSTEM_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace input
{


/**
 * Input system types.
 */
SYNKRO_ENUM_BEGIN( InputSystem )
	/** Custom input system. */
	SYNKRO_ENUM_CONST( InputSystem, Custom )

	/** Win32 input system. */
	SYNKRO_ENUM_CONST( InputSystem, Win32 )

	/** DirectInput8 based input system. */
	SYNKRO_ENUM_CONST( InputSystem, DirectInput8 )
SYNKRO_ENUM_END()


} // input


} // synkro


#endif // _SYNKRO_INPUT_INPUTSYSTEM_
