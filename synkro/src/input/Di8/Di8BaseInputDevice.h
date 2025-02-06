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
// Purpose: DirectInput 8 input device.
//==============================================================================
#ifndef _SYNKRO_INPUT_DI8BASEINPUTDEVICE_
#define _SYNKRO_INPUT_DI8BASEINPUTDEVICE_


#include "config.h"


namespace synkro
{


namespace input
{


// DirectInput 8 input device.
class Di8BaseInputDevice
{
public:
	virtual void											Uninit() = 0;
};


} // input


} // synkro


#endif // _SYNKRO_INPUT_DI8BASEINPUTDEVICE_
