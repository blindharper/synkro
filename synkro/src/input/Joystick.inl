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
// Purpose: Logical joystick.
//==============================================================================
SYNKRO_INLINE Bool Joystick::IsButtonDown( const JoystickButton& button ) const
{
	return _joystick->IsButtonDown( button );
}

SYNKRO_INLINE Bool Joystick::IsButtonUp( const JoystickButton& button ) const
{
	return _joystick->IsButtonUp( button );
}

SYNKRO_INLINE Int Joystick::GetAxisMovement( const Axis& axis ) const
{
	return _joystick->GetAxisMovement( axis );
}

SYNKRO_INLINE void Joystick::GetState( JoystickState& state ) const
{
	return _joystick->GetState( state );
}

SYNKRO_INLINE void Joystick::GetDesc( JoystickDesc& desc ) const
{
	return _joystick->GetDesc( desc );
}

SYNKRO_INLINE UInt Joystick::GetIndex() const
{
	return _index;
}
