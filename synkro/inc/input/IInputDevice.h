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
// Purpose: Defines abstract input device.
//==============================================================================
#ifndef _SYNKRO_INPUT_IINPUTDEVICE_
#define _SYNKRO_INPUT_IINPUTDEVICE_


#include "config.h"
#include <core/IObject.h>


namespace synkro
{


namespace input
{


/**
 * Abstract input device.
 */
iface IInputDevice :
	public core::IObject
{
public:
	/**
	 * Polls internal device state.
	 * @param delta Time passed since the last poll.
	 * @return True if update succeded, false otherwise.
	 */
	virtual Bool											Update( Double delta ) = 0;
};


} // input


} // synkro


#endif // _SYNKRO_INPUT_IINPUTDEVICE_
