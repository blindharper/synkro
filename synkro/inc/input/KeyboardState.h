//==============================================================================
// This file is a part of the Synkro Framework.
// 
// Copyright (c) Nobody. No rights reserved ;-7
//
// The contents herein is the property of the Mankind.
// Use, distribution, and modification of this source code
// is allowed without any permission from the Synkro Project.
// Website: https://synkro.pro Email: mailto:blindharper70@gmail.com
//
// Purpose: Defines keyboard state.
//==============================================================================
#ifndef _SYNKRO_INPUT_KEYBOARDSTATE_
#define _SYNKRO_INPUT_KEYBOARDSTATE_


#include "config.h"


namespace synkro
{


namespace input
{


/**
 * Keyboard state.
 */
class SYNKRO_API KeyboardState
{
public:
	/** Creates default keyboard state. */
	KeyboardState();

	/** Keyboard keys. */
	Byte													Keys[256];
};


} // input


} // synkro


#endif // _SYNKRO_INPUT_KEYBOARDSTATE_
