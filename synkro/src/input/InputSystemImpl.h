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
// Purpose: Generic input system implementation.
//=============================================================================
#ifndef _SYNKRO_INPUT_INPUTSYSTEMIMPL_
#define _SYNKRO_INPUT_INPUTSYSTEMIMPL_


#include "config.h"
#include <lang/Vector.h>
#include <core/ObjectImpl.h>
#include <input/KeyboardDesc.h>
#include <input/MouseDesc.h>
#include <input/JoystickDesc.h>
#include <input/InputException.h>
#include <win/IWindowSystemEx.h>


namespace synkro
{


namespace input
{


// Generic input system implementation.
template <class T>
class InputSystemImpl :
	public core::ObjectImpl<T>,
	public Logger
{
public:
	// Constructor and destructor.
	InputSystemImpl( diag::ILog* log );
	virtual ~InputSystemImpl();

	// ISystem methods.
	virtual Bool											Update( Double delta );

	// IInputSystem methods.
	virtual UInt											GetTotalMouseCount() const;
	virtual void											GetMouseDesc( UInt index, MouseDesc& desc ) const;
	virtual UInt											GetTotalJoystickCount() const;
	virtual void											GetJoystickDesc( UInt index, JoystickDesc& desc ) const;
	virtual UInt											GetTotalKeyboardCount() const;
	virtual void											GetKeyboardDesc( UInt index, KeyboardDesc& desc ) const;

protected:
	lang::Vector<KeyboardDesc>								_keyboards;
	lang::Vector<MouseDesc>									_mice;
	lang::Vector<JoystickDesc>								_joysticks;
};


#include "InputSystemImpl.inl"


} // input


} // synkro


#endif // _SYNKRO_INPUT_INPUTSYSTEMIMPL_
