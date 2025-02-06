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
template <class T>
SYNKRO_INLINE JoystickImpl<T>::JoystickImpl( const JoystickDesc& desc ) :
	_desc( desc )
{
	Zero( _state.Buttons, sizeof(_state.Buttons) );
	Zero( _state.Axes, sizeof(_state.Axes) );
}

template <class T>
SYNKRO_INLINE JoystickImpl<T>::~JoystickImpl()
{
}

template <class T>
SYNKRO_INLINE Bool JoystickImpl<T>::IsButtonDown( const JoystickButton& button ) const
{
	UInt b = button;
	return ((_state.Buttons[b-1] & 0x80) != 0);
}

template <class T>
SYNKRO_INLINE Bool JoystickImpl<T>::IsButtonUp( const JoystickButton& button ) const
{
	return !IsButtonDown( button );
}

template <class T>
SYNKRO_INLINE Int JoystickImpl<T>::GetAxisMovement( const Axis& axis ) const
{
	UInt a = axis;
	return (a > 0) ? _state.Axes[a-1] : 0L;
}

template <class T>
SYNKRO_INLINE void JoystickImpl<T>::GetState( JoystickState& state ) const
{
	state = _state;
}

template <class T>
SYNKRO_INLINE void JoystickImpl<T>::GetDesc( JoystickDesc& desc ) const
{
	desc = _desc;
}
