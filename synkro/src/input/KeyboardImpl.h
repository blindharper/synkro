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
// Purpose: Generic keyboard implementation.
//==============================================================================
#ifndef _SYNKRO_INPUT_KEYBOARDIMPL_
#define _SYNKRO_INPUT_KEYBOARDIMPL_


#include "config.h"
#include <core/ObjectImpl.h>
#include <input/KeyboardState.h>
#include <input/KeyboardDesc.h>
#include <input/InputException.h>
#include <input/Key.h>


namespace synkro
{


namespace input
{


// Generic keyboard implementation.
template <class T>
class KeyboardImpl :
	public core::ObjectImpl<T>
{
public:
	// Constructor & destructor.
	KeyboardImpl( const KeyboardDesc& desc );
	virtual ~KeyboardImpl();

	// IKeyboard methods.
	virtual Bool											IsKeyUp( const Key& key ) const;
	virtual void											GetState( KeyboardState& state ) const;
	virtual void											GetDesc( KeyboardDesc& desc ) const;

protected:
	KeyboardState											_state;
	KeyboardDesc											_desc;
};


#include "KeyboardImpl.inl"


} // input


} // synkro


#endif // _SYNKRO_INPUT_KEYBOARDIMPL_
