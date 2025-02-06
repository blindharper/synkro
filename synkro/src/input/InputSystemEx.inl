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
// Purpose: Extended input system.
//=============================================================================
SYNKRO_INLINE UInt InputSystemEx::GetTotalMouseCount() const
{
	return _inputSystem->GetTotalMouseCount();
}

SYNKRO_INLINE void InputSystemEx::GetMouseDesc( UInt index, MouseDesc& desc ) const
{
	return _inputSystem->GetMouseDesc( index, desc );
}

SYNKRO_INLINE UInt InputSystemEx::GetTotalJoystickCount() const
{
	return _inputSystem->GetTotalJoystickCount();
}

SYNKRO_INLINE void InputSystemEx::GetJoystickDesc( UInt index, JoystickDesc& desc ) const
{
	return _inputSystem->GetJoystickDesc( index, desc );
}

SYNKRO_INLINE UInt InputSystemEx::GetTotalKeyboardCount() const
{
	return _inputSystem->GetTotalKeyboardCount();
}

SYNKRO_INLINE void InputSystemEx::GetKeyboardDesc( UInt index, KeyboardDesc& desc ) const
{
	return _inputSystem->GetKeyboardDesc( index, desc );
}

SYNKRO_INLINE UInt InputSystemEx::GetMouseCount() const
{
	return _mice.Size();
}

SYNKRO_INLINE IMouseEx* InputSystemEx::GetMouse( UInt index ) const
{
	assert( index < _mice.Size() );

	if ( index >= _mice.Size() )
		throw lang::OutOfRangeException( index, _mice.Size() );

	return _mice[index];
}

SYNKRO_INLINE IMouseEx* InputSystemEx::GetMouse() const
{
	return (_mice.Size() > 0) ? _mice[0] : nullptr;
}

SYNKRO_INLINE UInt InputSystemEx::GetJoystickCount() const
{
	return _joysticks.Size();
}

SYNKRO_INLINE IJoystickEx* InputSystemEx::GetJoystick( UInt index ) const
{
	assert( index < _joysticks.Size() );

	if ( index >= _joysticks.Size() )
		throw lang::OutOfRangeException( index, _joysticks.Size() );

	return _joysticks[index];
}

SYNKRO_INLINE IJoystickEx* InputSystemEx::GetJoystick() const
{
	return (_joysticks.Size() > 0) ? _joysticks[0] : nullptr;
}

SYNKRO_INLINE UInt InputSystemEx::GetKeyboardCount() const
{
	return _keyboards.Size();
}

SYNKRO_INLINE IKeyboardEx* InputSystemEx::GetKeyboard( UInt index ) const
{
	assert( index < _keyboards.Size() );

	if ( index >= _keyboards.Size() )
		throw lang::OutOfRangeException( index, _keyboards.Size() );

	return _keyboards[index];
}

SYNKRO_INLINE IKeyboardEx* InputSystemEx::GetKeyboard() const
{
	return (_keyboards.Size() > 0) ? _keyboards[0] : nullptr;
}

SYNKRO_INLINE IArcball* InputSystemEx::GetArcball() const
{
	return _arcball;
}

SYNKRO_INLINE Bool InputSystemEx::Call( IInputDevice* device, Double delta )
{
	return device->Update( delta );
}
