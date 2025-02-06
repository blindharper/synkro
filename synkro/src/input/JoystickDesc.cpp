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
// Purpose: Implements joystick description.
//==============================================================================
#include "config.h"
#include <input/JoystickDesc.h>


namespace synkro
{


namespace input
{


JoystickDesc::JoystickDesc() :
	AxisCount( 0 ),
	ButtonCount( 0 ),
	ForceFeedback( false )
{
}

JoystickDesc::JoystickDesc( const lang::String& name, UInt axisCount, UInt buttonCount, Bool forceFeedback ) :
	Name( name ),
	AxisCount( axisCount ),
	ButtonCount( buttonCount ),
	ForceFeedback( forceFeedback )
{
}


} // input


} // synkro
