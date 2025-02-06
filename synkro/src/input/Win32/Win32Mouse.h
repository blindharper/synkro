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
// Purpose: Win32 mouse.
//==============================================================================
#ifndef _SYNKRO_INPUT_WINDOWSMOUSE_
#define _SYNKRO_INPUT_WINDOWSMOUSE_


#include "config.h"
#include <input/MouseImpl.h>
#include <input/IMouse.h>


namespace synkro
{


namespace input
{


// Win32 mouse.
class Win32Mouse :
	public MouseImpl<IMouse>
{
public:
	// Constructor & destructor.
	Win32Mouse( const MouseDesc& desc );
	~Win32Mouse();

	// IInputDevice methods.
	Bool													Update( Double delta );

private:
	HHOOK													_hookMouse;
};


} // input


} // synkro


#endif // _SYNKRO_INPUT_WINDOWSMOUSE_
