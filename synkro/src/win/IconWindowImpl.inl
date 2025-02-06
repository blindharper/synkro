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
// Purpose: Generic icon window implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE IconWindowImpl<T>::IconWindowImpl( UInt icon, const lang::String& hint ) :
	WindowImpl<T>( 0, 0, 0, 0 ),
	_listeners( A(WindowListener*) ),
	_icon( icon ),
	_hint( hint )
{
}

template <class T>
SYNKRO_INLINE IconWindowImpl<T>::~IconWindowImpl()
{
}

template <class T>
SYNKRO_INLINE void IconWindowImpl<T>::Listen( WindowListener* listener )
{
	assert( listener != nullptr );

	if ( !_listeners.Contains(listener) )
	{
		_listeners.Add( listener );
	}
}

template <class T>
SYNKRO_INLINE void IconWindowImpl<T>::SetIcon( UInt icon )
{
	_icon = icon;
}

template <class T>
SYNKRO_INLINE void IconWindowImpl<T>::SetHint( const lang::String& hint )
{
	_hint = hint;
}

template <class T>
SYNKRO_INLINE UInt IconWindowImpl<T>::GetIcon() const
{
	return _icon;
}

template <class T>
SYNKRO_INLINE lang::String IconWindowImpl<T>::GetHint() const
{
	return _hint;
}

template <class T>
SYNKRO_INLINE void IconWindowImpl<T>::FireCommandEvent( UInt command )
{
	for ( UInt i = 0; i < _listeners.Size(); ++i )
	{
		_listeners[i]->OnWindowCommand( _handle, command );
	}
}
