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
// Purpose: 'input' namespace includes.
//==============================================================================
#ifndef _SYNKRO_INPUT_
#define _SYNKRO_INPUT_


#include <input/IArcball.h>
#include <input/IMouseEx.h>
#include <input/IKeyboardEx.h>
#include <input/IJoystickEx.h>
#include <input/IInputDevice.h>
#include <input/IInputSystem.h>
#include <input/IInputSystemEx.h>
#include <input/IInputSystemFactory.h>
#include <input/InputSystem.h>
#include <input/ArcballListener.h>
#include <input/MouseListener.h>
#include <input/JoystickListener.h>
#include <input/KeyboardListener.h>


#define PtrKeyboardEx P(synkro::input::IKeyboardEx)
#define PtrMouseEx P(synkro::input::IMouseEx)


namespace synkro
{


/**
 * The 'input' namespace contains interfaces for handling user input.
 */
namespace input
{
} // input


} // synkro


#endif // _SYNKRO_INPUT_
