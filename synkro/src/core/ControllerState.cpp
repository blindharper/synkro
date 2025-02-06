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
#include "config.h"
#include <core/ControllerState.h>
#include <internal/Enum.h>
#include "ControllerStateConst.h"


namespace synkro
{


namespace core
{


SYNKRO_DEFINE_CONST( ControllerState, Inactive,		CONTROLLER_STATE_INACTIVE )
SYNKRO_DEFINE_CONST( ControllerState, Active,		CONTROLLER_STATE_ACTIVE )
SYNKRO_DEFINE_CONST( ControllerState, Suspended,	CONTROLLER_STATE_SUSPENDED )


} // core


} // synkro
