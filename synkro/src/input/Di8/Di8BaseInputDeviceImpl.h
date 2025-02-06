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
// Purpose: Generic DirectInput 8 base input device implementation.
//=============================================================================
#ifndef _SYNKRO_INPUT_DI8BASEINPUTDEVICEIMPL_
#define _SYNKRO_INPUT_DI8BASEINPUTDEVICEIMPL_


#include "config.h"
#include "Di8.h"


namespace synkro
{


namespace input
{


// Generic DirectInput 8 base input device implementation.
template <class T>
class Di8BaseInputDeviceImpl :
	public T
{
public:
	// Constructor and destructor.
	Di8BaseInputDeviceImpl();
	virtual ~Di8BaseInputDeviceImpl();

	// Di8BaseInputDevice methods.
	virtual void											Uninit();

protected:
	IDirectInputDevice8*									_device;
};


#include "Di8BaseInputDeviceImpl.inl"


} // input


} // synkro


#endif // _SYNKRO_INPUT_DI8BASEINPUTDEVICEIMPL_
