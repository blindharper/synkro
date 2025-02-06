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
// Purpose: Defines mouse buttons.
//==============================================================================
#ifndef _SYNKRO_INPUT_MOUSEBUTTON_
#define _SYNKRO_INPUT_MOUSEBUTTON_


#include "config.h"
#include <lang/Flag.h>


namespace synkro
{


namespace input
{


/**
 * Mouse buttons.
 */
SYNKRO_FLAG_BEGIN( MouseButton )
	/** No button is pressed. */
	SYNKRO_FLAG_CONST( MouseButton, None )

	/** The left button. */
	SYNKRO_FLAG_CONST( MouseButton, Left )

	/** The right button. */
	SYNKRO_FLAG_CONST( MouseButton, Right )

	/** The middle button. */
	SYNKRO_FLAG_CONST( MouseButton, Middle )

	/** The first XButton button. */
	SYNKRO_FLAG_CONST( MouseButton, XButton1 )

	/** The second XButton button. */
	SYNKRO_FLAG_CONST( MouseButton, XButton2 )

	/** Creates mouse button from string. */
	MouseButton( const lang::String& button );

	/** Converts mouse button to string. */
	lang::String											ToString() const;
SYNKRO_FLAG_END()


} // input


} // synkro


#endif // _SYNKRO_INPUT_MOUSEBUTTON_
