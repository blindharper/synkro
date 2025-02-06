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
template <class T>
SYNKRO_INLINE MouseImpl<T>::MouseImpl( const MouseDesc& desc ) :
	_desc( desc )
{
	Zero( _state.Buttons, sizeof(_state.Buttons) );
	Zero( _state.Axes, sizeof(_state.Axes) );
}

template <class T>
SYNKRO_INLINE MouseImpl<T>::~MouseImpl()
{
}

template <class T>
SYNKRO_INLINE Bool MouseImpl<T>::IsButtonDown( const MouseButton& button ) const
{
	UInt index = -1;
	UInt b = button;
	while ( b > 0 )
	{
		b >>= 1;
		++index;
	}
	return (index != -1) ? ((_state.Buttons[index] & 0x80) != 0) : false;
}

template <class T>
SYNKRO_INLINE Bool MouseImpl<T>::IsButtonUp( const MouseButton& button ) const
{
	return !IsButtonDown( button );
}

template <class T>
SYNKRO_INLINE Int MouseImpl<T>::GetAxisMovement( const Axis& axis ) const
{
	UInt a = axis;
	return (a > 0) ? _state.Axes[a-1] : 0L;
}

template <class T>
SYNKRO_INLINE void MouseImpl<T>::GetState( MouseState& state ) const
{
	state = _state;
}

template <class T>
SYNKRO_INLINE void MouseImpl<T>::GetDesc( MouseDesc& desc ) const
{
	desc = _desc;
}
