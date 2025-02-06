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
// Purpose: Defines controller state constant values.
//==============================================================================
#ifndef _SYNKRO_CORE_CONTROLLERSTATECONST_
#define _SYNKRO_CORE_CONTROLLERSTATECONST_


#include "config.h"


namespace synkro
{


namespace core
{


// Controller state constant values.
enum ControllerStateConst
{
	CONTROLLER_STATE_INACTIVE	= 0,
	CONTROLLER_STATE_ACTIVE		= 1,
	CONTROLLER_STATE_SUSPENDED	= 2,
};


} // core


} // synkro


#endif // _SYNKRO_CORE_CONTROLLERSTATECONST_
