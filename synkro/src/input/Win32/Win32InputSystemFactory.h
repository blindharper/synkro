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
// Purpose: Win32 input system factory.
//==============================================================================
#ifndef _SYNKRO_INPUT_WIN32INPUTSYSTEMFACTORY_
#define _SYNKRO_INPUT_WIN32INPUTSYSTEMFACTORY_


#include "config.h"
#include <core/FactoryImpl.h>
#include <input/IInputSystemFactory.h>
#include <input/InputSystem.h>
#include "Win32InputSystem.h"


namespace synkro
{


namespace input
{


// Win32 input system factory.
SYNKRO_FACTORY_BEGIN( Win32InputSystemFactory, IInputSystemFactory, InputSystem, InputSystem::Win32 )
	IInputSystem*	Create( Pointer module, win::IWindowSystemEx* windowSystem, diag::ILog* log ) { return new Win32InputSystem(log); }
SYNKRO_FACTORY_END()


} // input


} // synkro


#endif // _SYNKRO_INPUT_WIN32INPUTSYSTEMFACTORY_
