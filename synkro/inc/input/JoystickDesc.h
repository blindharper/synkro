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
// Purpose: Defines joystick description.
//==============================================================================
#ifndef _SYNKRO_INPUT_JOYSTICKDESC_
#define _SYNKRO_INPUT_JOYSTICKDESC_


#include "config.h"
#include <lang/String.h>


namespace synkro
{


namespace input
{


/**
 * Joystick device description.
 */
class SYNKRO_API JoystickDesc
{
public:
	/** Creates default joystick description. */
	JoystickDesc();

	/** Creates joystick description with the specified properties. */
	JoystickDesc( const lang::String& name, UInt axisCount, UInt buttonCount, Bool forceFeedback );

	/** User-friendly device name. */
	lang::String											Name;

	/** Total number of axes in the joystick. */
	UInt													AxisCount;

	/** Total number of buttons in the joystick. */
	UInt													ButtonCount;

	/** Flag indicating whether the device supports force feedback. */
	Bool													ForceFeedback;
};


} // input


} // synkro


#endif // _SYNKRO_INPUT_JOYSTICKDESC_
