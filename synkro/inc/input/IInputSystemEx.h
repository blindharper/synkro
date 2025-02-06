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
// Purpose: Defines extended input system.
//==============================================================================
#ifndef _SYNKRO_INPUT_IINPUTSYSTEMEX_
#define _SYNKRO_INPUT_IINPUTSYSTEMEX_


#include "config.h"
#include <input/IInputSystem.h>


namespace synkro
{


namespace input
{


/**
 * Extended input system.
 */
iface IInputSystemEx :
	public IInputSystem
{
public:
	/**
	 * Creates arcball from a mouse.
	 * @param mouse Base mouse device.
	 * @param window Window in which the arcball will be used.
	 * @return Created arcball.
	 * @exception BadArgumentException Mouse is not specified.
	 * @exception BadArgumentException Window is not specified.
	 */
	virtual IArcball*										CreateArcball( IMouseEx* mouse, win::IWindow* window ) = 0;

	/**
	 * Retrieves arcball device.
	 * @return Arcball device.
	 */
	virtual IArcball*										GetArcball() const = 0;

	/**
	 * Retrieves the total number of initialized mouse devices.
	 * @return Number of mouse devices.
	 */
	virtual UInt											GetMouseCount() const = 0;

	/**
	 * Retrieves mouse device by index.
	 * @param index Index of the mouse device to retrieve.
	 * @return Requested mouse device.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual IMouseEx*										GetMouse( UInt index ) const = 0;

	/**
	 * Retrieves default mouse device.
	 * @return Mouse device if one exists, nullptr otherwise.
	 */
	virtual IMouseEx*										GetMouse() const = 0;

	/**
	 * Retrieves the total number of initialized joystick devices.
	 * @return Number of joystick devices.
	 */
	virtual UInt											GetJoystickCount() const = 0;

	/**
	 * Retrieves joystick device by index.
	 * @param index Index of the joystick device to retrieve.
	 * @return Requested joystick device.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual IJoystickEx*									GetJoystick( UInt index ) const = 0;

	/**
	 * Retrieves default joystick device.
	 * @return Joystick device if one is attached, nullptr otherwise.
	 */
	virtual IJoystickEx*									GetJoystick() const = 0;

	/**
	 * Retrieves the total number of initialized keyboard devices.
	 * @return Number of keyboard devices.
	 */
	virtual UInt											GetKeyboardCount() const = 0;

	/**
	 * Retrieves keyboard device by index.
	 * @param index Index of the keyboard device to retrieve.
	 * @return Requested keyboard device.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual IKeyboardEx*									GetKeyboard( UInt index ) const = 0;

	/**
	 * Retrieves default keyboard device.
	 * @return Keyboard device.
	 */
	virtual IKeyboardEx*									GetKeyboard() const = 0;
};


} // input


} // synkro


#endif // _SYNKRO_INPUT_IINPUTSYSTEMEX_
