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
// Purpose: Generic mouse implementation.
//==============================================================================
#ifndef _SYNKRO_INPUT_MOUSEIMPL_
#define _SYNKRO_INPUT_MOUSEIMPL_


#include "config.h"
#include <core/ObjectImpl.h>
#include <input/MouseState.h>
#include <input/MouseDesc.h>
#include <input/MouseButton.h>
#include <input/InputException.h>
#include <input/Axis.h>


namespace synkro
{


namespace input
{


// Generic mouse implementation.
template <class T>
class MouseImpl :
	public core::ObjectImpl<T>
{
public:
	// Constructor & destructor.
	MouseImpl( const MouseDesc& desc );
	virtual ~MouseImpl();

	// IMouse methods.
	virtual Bool											IsButtonDown( const MouseButton& button ) const;
	virtual Bool											IsButtonUp( const MouseButton& button ) const;
	virtual Int												GetAxisMovement( const Axis& axis ) const;
	virtual void											GetState( MouseState& state ) const;
	virtual void											GetDesc( MouseDesc& desc ) const;

protected:
	MouseState												_state;
	MouseDesc												_desc;
};


#include "MouseImpl.inl"


} // input


} // synkro


#endif // _SYNKRO_INPUT_MOUSEIMPL_
