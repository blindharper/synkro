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
// Purpose: Logical mouse.
//==============================================================================
SYNKRO_INLINE Bool Mouse::IsButtonDown( const MouseButton& button ) const
{
	return _mouse->IsButtonDown( button );
}

SYNKRO_INLINE Bool Mouse::IsButtonUp( const MouseButton& button ) const
{
	return _mouse->IsButtonUp( button );
}

SYNKRO_INLINE Int Mouse::GetAxisMovement( const Axis& axis ) const
{
	return _mouse->GetAxisMovement( axis );
}

SYNKRO_INLINE void Mouse::GetState( MouseState& state ) const
{
	_mouse->GetState( state );
}

SYNKRO_INLINE void Mouse::GetDesc( MouseDesc& desc ) const
{
	_mouse->GetDesc( desc );
}

SYNKRO_INLINE UInt Mouse::GetIndex() const
{
	return _index;
}
