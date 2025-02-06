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
// Purpose: Generic view window implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE ViewWindowImpl<T>::ViewWindowImpl( IFrameWindow* parent, Int left, Int top, UInt width, UInt height ) :
	WindowImpl<T>( left, top, width, height ),
	_parent( parent ),
	_visible( true )
{
}

template <class T>
SYNKRO_INLINE ViewWindowImpl<T>::~ViewWindowImpl()
{
}

template <class T>
SYNKRO_INLINE Bool ViewWindowImpl<T>::Update()
{
	// Do nothing.
	return true;
}

template <class T>
SYNKRO_INLINE void ViewWindowImpl<T>::Show( Bool show )
{
	_visible = show;
}

template <class T>
SYNKRO_INLINE Bool ViewWindowImpl<T>::IsVisible() const
{
	return _visible;
}

template <class T>
SYNKRO_INLINE IFrameWindow* ViewWindowImpl<T>::GetParent() const
{
	return _parent;
}
