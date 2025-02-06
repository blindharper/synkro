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
// Purpose: Defines joystick buttons.
//=============================================================================
#ifndef _SYNKRO_INPUT_JOYSTICKBUTTON_
#define _SYNKRO_INPUT_JOYSTICKBUTTON_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace input
{


/**
 * Joystick buttons.
 */
SYNKRO_ENUM_BEGIN( JoystickButton )
	/** Unknown button. */
	SYNKRO_ENUM_CONST( JoystickButton, Unknown )

	/** Button #1. */
	SYNKRO_ENUM_CONST( JoystickButton, Button1 )

	/** Button #2. */
	SYNKRO_ENUM_CONST( JoystickButton, Button2 )

	/** Button #3. */
	SYNKRO_ENUM_CONST( JoystickButton, Button3 )

	/** Button #4. */
	SYNKRO_ENUM_CONST( JoystickButton, Button4 )

	/** Button #5. */
	SYNKRO_ENUM_CONST( JoystickButton, Button5 )

	/** Button #6. */
	SYNKRO_ENUM_CONST( JoystickButton, Button6 )

	/** Button #7. */
	SYNKRO_ENUM_CONST( JoystickButton, Button7 )

	/** Button #8. */
	SYNKRO_ENUM_CONST( JoystickButton, Button8 )

	/** Button #9. */
	SYNKRO_ENUM_CONST( JoystickButton, Button9 )

	/** Button #10. */
	SYNKRO_ENUM_CONST( JoystickButton, Button10 )

	/** Button #11. */
	SYNKRO_ENUM_CONST( JoystickButton, Button11 )

	/** Button #12. */
	SYNKRO_ENUM_CONST( JoystickButton, Button12 )

	/** Button #13. */
	SYNKRO_ENUM_CONST( JoystickButton, Button13 )

	/** Button #14. */
	SYNKRO_ENUM_CONST( JoystickButton, Button14 )

	/** Button #15. */
	SYNKRO_ENUM_CONST( JoystickButton, Button15 )

	/** Button #16. */
	SYNKRO_ENUM_CONST( JoystickButton, Button16 )

	/** Button #17. */
	SYNKRO_ENUM_CONST( JoystickButton, Button17 )

	/** Button #18. */
	SYNKRO_ENUM_CONST( JoystickButton, Button18 )

	/** Button #19. */
	SYNKRO_ENUM_CONST( JoystickButton, Button19 )

	/** Button #20. */
	SYNKRO_ENUM_CONST( JoystickButton, Button20 )

	/** Button #21. */
	SYNKRO_ENUM_CONST( JoystickButton, Button21 )

	/** Button #22. */
	SYNKRO_ENUM_CONST( JoystickButton, Button22 )

	/** Button #23. */
	SYNKRO_ENUM_CONST( JoystickButton, Button23 )

	/** Button #24. */
	SYNKRO_ENUM_CONST( JoystickButton, Button24 )

	/** Button #25. */
	SYNKRO_ENUM_CONST( JoystickButton, Button25 )

	/** Button #26. */
	SYNKRO_ENUM_CONST( JoystickButton, Button26 )

	/** Button #27. */
	SYNKRO_ENUM_CONST( JoystickButton, Button27 )

	/** Button #28. */
	SYNKRO_ENUM_CONST( JoystickButton, Button28 )

	/** Button #29. */
	SYNKRO_ENUM_CONST( JoystickButton, Button29 )

	/** Button #30. */
	SYNKRO_ENUM_CONST( JoystickButton, Button30 )

	/** Button #31. */
	SYNKRO_ENUM_CONST( JoystickButton, Button31 )

	/** Button #32. */
	SYNKRO_ENUM_CONST( JoystickButton, Button32 )

	/** Creates joystick button from string. */
	JoystickButton( const lang::String& button );

	/** Converts joystick button to string. */
	lang::String											ToString() const;
SYNKRO_ENUM_END()


} // input


} // synkro


#endif // _SYNKRO_INPUT_JOYSTICKBUTTON_
