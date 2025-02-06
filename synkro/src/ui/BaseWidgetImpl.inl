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
// Purpose: Generic widget implementation.
//=============================================================================
template <class T>
SYNKRO_INLINE BaseWidgetImpl<T>::BaseWidgetImpl()
{
}

template <class T>
SYNKRO_INLINE BaseWidgetImpl<T>::~BaseWidgetImpl()
{
}

template <class T>
SYNKRO_INLINE UiEvent BaseWidgetImpl<T>::OnHotKey( const HotKey& hotkey )
{
	return UI_EVENT_NONE;
}

template <class T>
SYNKRO_INLINE UiEvent BaseWidgetImpl<T>::OnKeyDown( Double deltaTime, const input::Key& key, Bool alt, Bool shift, Bool control )
{
	return UI_EVENT_NONE;
}

template <class T>
SYNKRO_INLINE UiEvent BaseWidgetImpl<T>::OnKeyUp( const input::Key& key, Bool alt, Bool shift, Bool control )
{
	return UI_EVENT_NONE;
}

template <class T>
SYNKRO_INLINE UiEvent BaseWidgetImpl<T>::OnKeyPress( Char key )
{
	return UI_EVENT_NONE;
}

template <class T>
SYNKRO_INLINE UiEvent BaseWidgetImpl<T>::OnMouseClick( const lang::Point& location )
{
	return UI_EVENT_NONE;
}

template <class T>
SYNKRO_INLINE UiEvent BaseWidgetImpl<T>::OnMouseDoubleClick( const lang::Point& location )
{
	return UI_EVENT_NONE;
}

template <class T>
SYNKRO_INLINE UiEvent BaseWidgetImpl<T>::OnMouseMove( const lang::Point& location )
{
	return UI_EVENT_NONE;
}

template <class T>
SYNKRO_INLINE UiEvent BaseWidgetImpl<T>::OnMouseScroll( Int delta )
{
	return UI_EVENT_NONE;
}

template <class T>
SYNKRO_INLINE UiEvent BaseWidgetImpl<T>::OnMouseEnter()
{
	return UI_EVENT_NONE;
}

template <class T>
SYNKRO_INLINE UiEvent BaseWidgetImpl<T>::OnMouseLeave()
{
	return UI_EVENT_NONE;
}

template <class T>
SYNKRO_INLINE UiEvent BaseWidgetImpl<T>::OnMouseDown( const lang::Point& location )
{
	return UI_EVENT_NONE;
}

template <class T>
SYNKRO_INLINE UiEvent BaseWidgetImpl<T>::OnMouseUp()
{
	return UI_EVENT_NONE;
}
