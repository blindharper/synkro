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
// Purpose: Generic joystick implementation.
//==============================================================================
#ifndef _SYNKRO_INPUT_JOYSTICKIMPL_
#define _SYNKRO_INPUT_JOYSTICKIMPL_


#include "config.h"
#include <core/ObjectImpl.h>
#include <input/JoystickState.h>
#include <input/JoystickDesc.h>
#include <input/JoystickButton.h>
#include <input/InputException.h>
#include <input/Axis.h>


namespace synkro
{


namespace input
{


// Generic joystick implementation.
template <class T>
class JoystickImpl :
	public core::ObjectImpl<T>
{
public:
	// Constructor & destructor.
	JoystickImpl( const JoystickDesc& desc );
	virtual ~JoystickImpl();

	// IJoystick methods.
	virtual Bool											IsButtonDown( const JoystickButton& button ) const;
	virtual Bool											IsButtonUp( const JoystickButton& button ) const;
	virtual Int												GetAxisMovement( const Axis& axis ) const;
	virtual void											GetState( JoystickState& state ) const;
	virtual void											GetDesc( JoystickDesc& desc ) const;

protected:
	JoystickState											_state;
	JoystickDesc											_desc;
};


#include "JoystickImpl.inl"


} // input


} // synkro


#endif // _SYNKRO_INPUT_JOYSTICKIMPL_
