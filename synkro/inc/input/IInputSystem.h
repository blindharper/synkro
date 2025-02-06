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
// Purpose: Defines input system.
//==============================================================================
#ifndef _SYNKRO_INPUT_IINPUTSYSTEM_
#define _SYNKRO_INPUT_IINPUTSYSTEM_


#include "config.h"
#include <core/ISystem.h>
#include <input/MouseDesc.h>
#include <input/JoystickDesc.h>
#include <input/KeyboardDesc.h>


namespace synkro
{


namespace input
{


/**
 * Input system. Provides access to various input devices.
 */
iface IInputSystem :
	public core::ISystem
{
public:
	/**
	 * Initializes one of the mouse devices installed in the system.
	 * @param index Index of the mouse device to initialize.
	 * @return Created mouse device.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual IMouse*											CreateMouse( UInt index ) = 0;

	/**
	 * Retrieves the total number of mouse devices installed in the system.
	 */
	virtual UInt											GetTotalMouseCount() const = 0;

	/**
	 * Retrieves mouse device description.
	 * @param index Index of the mouse device.
	 * @param [out] desc Mouse description.
	 */
	virtual void											GetMouseDesc( UInt index, MouseDesc& desc ) const = 0;

	/**
	 * Initializes one of the joystick devices installed in the system.
	 * @param index Index of the joystick device to initialize.
	 * @return Created joystick device.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual IJoystick*										CreateJoystick( UInt index ) = 0;

	/**
	 * Retrieves the total number of joystick devices installed in the system.
	 */
	virtual UInt											GetTotalJoystickCount() const = 0;

	/**
	 * Retrieves joystick device description.
	 * @param index Index of the joystick device.
	 * @param [out] desc Joystick description.
	 */
	virtual void											GetJoystickDesc( UInt index, JoystickDesc& desc ) const = 0;

	/**
	 * Initializes one of the keyboard devices installed in the system.
	 * @param index Index of the keyboard device to initialize.
	 * @return Created keyboard device.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual IKeyboard*										CreateKeyboard( UInt index ) = 0;

	/**
	 * Retrieves the total number of keyboard devices installed in the system.
	 */
	virtual UInt											GetTotalKeyboardCount() const = 0;

	/**
	 * Retrieves keyboard device description.
	 * @param index Index of the keyboard device.
	 * @param [out] desc Keyboard description.
	 */
	virtual void											GetKeyboardDesc( UInt index, KeyboardDesc& desc ) const = 0;
};


} // input


} // synkro


#endif // _SYNKRO_INPUT_IINPUTSYSTEM_
