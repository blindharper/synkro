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
template <class T>
SYNKRO_INLINE InputSystemImpl<T>::InputSystemImpl( diag::ILog* log ) :
	_keyboards( A(KeyboardDesc) ),
	_mice( A(MouseDesc) ),
	_joysticks( A(JoystickDesc) ),
	Logger( log, diag::LogFacility::InputSystem )
{
}

template <class T>
SYNKRO_INLINE InputSystemImpl<T>::~InputSystemImpl()
{
}

template <class T>
SYNKRO_INLINE Bool InputSystemImpl<T>::Update( Double delta )
{
	return true;
}

template <class T>
SYNKRO_INLINE UInt InputSystemImpl<T>::GetTotalMouseCount() const
{
	return _mice.Size();
}

template <class T>
SYNKRO_INLINE void InputSystemImpl<T>::GetMouseDesc( UInt index, MouseDesc& desc ) const
{
	assert( index < _mice.Size() );

	if ( index >= _mice.Size() )
		throw lang::OutOfRangeException( index, _mice.Size() );

	desc = _mice[index];
}

template <class T>
SYNKRO_INLINE UInt InputSystemImpl<T>::GetTotalJoystickCount() const
{
	return _joysticks.Size();
}

template <class T>
SYNKRO_INLINE void InputSystemImpl<T>::GetJoystickDesc( UInt index, JoystickDesc& desc ) const
{
	assert( index < _joysticks.Size() );

	if ( index >= _joysticks.Size() )
		throw lang::OutOfRangeException( index, _joysticks.Size() );

	desc = _joysticks[index];
}

template <class T>
SYNKRO_INLINE UInt InputSystemImpl<T>::GetTotalKeyboardCount() const
{
	return _keyboards.Size();
}

template <class T>
SYNKRO_INLINE void InputSystemImpl<T>::GetKeyboardDesc( UInt index, KeyboardDesc& desc ) const
{
	assert( index < _keyboards.Size() );

	if ( index >= _keyboards.Size() )
		throw lang::OutOfRangeException( index, _keyboards.Size() );

	desc = _keyboards[index];
}
