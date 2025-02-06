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
// Purpose: Defines joystick state.
//==============================================================================
#ifndef _SYNKRO_INPUT_JOYSTICKSTATE_
#define _SYNKRO_INPUT_JOYSTICKSTATE_


#include "config.h"


namespace synkro
{


namespace input
{


/**
 * Joystick state.
 */
class SYNKRO_API JoystickState
{
public:
	/** Creates default joystick state. */
	JoystickState();

	/** Joystick buttons. */
	Byte													Buttons[32];

	/** Joystick axes: X, Y, Z. */
	Int														Axes[3];
};


} // input


} // synkro


#endif // _SYNKRO_INPUT_JOYSTICKSTATE_
