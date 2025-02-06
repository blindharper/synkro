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
// Purpose: Defines mouse state.
//==============================================================================
#include "config.h"
#include <input/MouseState.h>
#include <internal/Zero.h>


namespace synkro
{


namespace input
{


MouseState::MouseState()
{
	Zero( Buttons, sizeof(Buttons) );
	Zero( Axes, sizeof(Axes) );
}


} // input


} // synkro
