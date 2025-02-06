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
template <class T>
SYNKRO_INLINE KeyboardImpl<T>::KeyboardImpl( const KeyboardDesc& desc ) :
	_desc( desc )
{
	Zero( _state.Keys, sizeof(_state.Keys) );
}

template <class T>
SYNKRO_INLINE KeyboardImpl<T>::~KeyboardImpl()
{
}

template <class T>
SYNKRO_INLINE Bool KeyboardImpl<T>::IsKeyUp( const Key& key ) const
{
	return !IsKeyDown( key );
}

template <class T>
SYNKRO_INLINE void KeyboardImpl<T>::GetState( KeyboardState& state ) const
{
	state = _state;
}

template <class T>
SYNKRO_INLINE void KeyboardImpl<T>::GetDesc( KeyboardDesc& desc ) const
{
	desc = _desc;
}
