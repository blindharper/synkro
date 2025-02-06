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
// Purpose: Logical keyboard.
//==============================================================================
SYNKRO_INLINE Bool Keyboard::IsKeyDown( const Key& key ) const
{
	return _keyboard->IsKeyDown( key );
}

SYNKRO_INLINE Bool Keyboard::IsKeyUp( const Key& key ) const
{
	return _keyboard->IsKeyUp( key );
}

SYNKRO_INLINE Key Keyboard::ToKey( Byte code ) const
{
	return _keyboard->ToKey( code );
}

SYNKRO_INLINE char Keyboard::ToChar( Byte code, Bool shift ) const
{
	return _keyboard->ToChar( code, shift );
}

SYNKRO_INLINE void Keyboard::GetState( KeyboardState& state ) const
{
	return _keyboard->GetState( state );
}

SYNKRO_INLINE void Keyboard::GetDesc( KeyboardDesc& desc ) const
{
	return _keyboard->GetDesc( desc );
}

SYNKRO_INLINE UInt Keyboard::GetIndex() const
{
	return _index;
}
