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
// Purpose: DirectInput 8 input system factory.
//==============================================================================
#ifndef _SYNKRO_INPUT_DI8INPUTSYSTEMFACTORY_
#define _SYNKRO_INPUT_DI8INPUTSYSTEMFACTORY_


#include "config.h"
#include <core/FactoryImpl.h>
#include <input/IInputSystemFactory.h>
#include <input/InputSystem.h>
#include "Di8InputSystem.h"


namespace synkro
{


namespace input
{


// DirectInput 8 input system factory.
SYNKRO_FACTORY_BEGIN( Di8InputSystemFactory, IInputSystemFactory, InputSystem, InputSystem::DirectInput8 )
	IInputSystem*	Create( Pointer module, win::IWindowSystemEx* windowSystem, diag::ILog* log ) { return new Di8InputSystem(module, windowSystem, log); }
SYNKRO_FACTORY_END()


} // input


} // synkro


#endif // _SYNKRO_INPUT_DI8INPUTSYSTEMFACTORY_
