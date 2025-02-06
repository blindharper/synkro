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
// Purpose: Base input system.
//==============================================================================
#ifndef _SYNKRO_INPUT_BASEINPUTSYSTEM_
#define _SYNKRO_INPUT_BASEINPUTSYSTEM_


#include "config.h"
#include <input/Axis.h>
#include <input/Key.h>
#include <input/MouseButton.h>
#include <input/JoystickButton.h>


namespace synkro
{


namespace input
{


// Base input system.
class BaseInputSystem
{
public:
	virtual void											ListenKeyDown( IKeyboardEx* keyboard, KeyboardListener* listener, const Key& key, Bool discrete ) = 0;
	virtual void											ListenKeyUp( IKeyboardEx* keyboard, KeyboardListener* listener, const Key& key ) = 0;
	virtual void											ListenKeyPress( IKeyboardEx* keyboard, KeyboardListener* listener ) = 0;
	virtual void											ListenMouseClick( IMouseEx* mouse, MouseListener* listener, const MouseButton& buttons ) = 0;
	virtual void											ListenMouseDoubleClick( IMouseEx* mouse, MouseListener* listener, const MouseButton& buttons ) = 0;
	virtual void											ListenMouseDown( IMouseEx* mouse, MouseListener* listener, const MouseButton& buttons ) = 0;
	virtual void											ListenMouseUp( IMouseEx* mouse, MouseListener* listener, const MouseButton& buttons ) = 0;
	virtual void											ListenMouseAxisMove( IMouseEx* mouse, MouseListener* listener, const Axis& axis ) = 0;
	virtual void											ListenJoystickDown( IJoystickEx* joystick, JoystickListener* listener, const JoystickButton& button ) = 0;
	virtual void											ListenJoystickUp( IJoystickEx* joystick, JoystickListener* listener, const JoystickButton& button ) = 0;
	virtual void											ListenJoystickAxisMove( IJoystickEx* joystick, JoystickListener* listener, const Axis& axis ) = 0;
	virtual void											ListenArcballRotate( IArcball* arcball, ArcballListener* listener ) = 0;
	virtual void											ListenArcballZoom( IArcball* arcball, ArcballListener* listener ) = 0;
};


// Casts object to BaseInputSystem.
#define AsBaseInputSystem( OBJ ) dynamic_cast<BaseInputSystem*>( OBJ )


} // input


} // synkro


#endif // _SYNKRO_INPUT_BASEINPUTSYSTEM_
