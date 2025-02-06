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
#include "config.h"
#include <input/InputSystem.h>
#include <internal/Enum.h>



namespace synkro
{


namespace input
{


SYNKRO_DEFINE_CONST( InputSystem, Custom,		0 )
SYNKRO_DEFINE_CONST( InputSystem, Win32,		1 )
SYNKRO_DEFINE_CONST( InputSystem, DirectInput8,	2 )


} // input


} // synkro
