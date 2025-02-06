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
// Purpose: DirectInput 8 keyboard.
//==============================================================================
SYNKRO_INLINE Bool Di8Keyboard::IsKeyDown( const Key& key ) const
{
	UInt k = key;
	return ((_state.Keys[k] & 0x80) != 0);
}

SYNKRO_INLINE Key Di8Keyboard::ToKey( Byte code ) const
{
	return (Key)code;
}
