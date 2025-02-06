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
#ifndef _SYNKRO_INPUT_MOUSESTATE_
#define _SYNKRO_INPUT_MOUSESTATE_


#include "config.h"


namespace synkro
{


namespace input
{


/**
 * Mouse state.
 */
class SYNKRO_API MouseState
{
public:
	/** Creates default mouse state. */
	MouseState();

	/** Mouse buttons: Left, Right, Middle, XButton1, XButton2. */
	Byte													Buttons[5];

	/** Mouse axes: X, Y, Z. */
	Int														Axes[3];
};


} // input


} // synkro


#endif // _SYNKRO_INPUT_MOUSESTATE_
