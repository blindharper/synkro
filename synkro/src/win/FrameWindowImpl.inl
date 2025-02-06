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
// Purpose: Generic frame window implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE FrameWindowImpl<T>::FrameWindowImpl( Bool popup, Bool sizeable, Bool renderable, const lang::String& title, UInt icon, UInt width, UInt height ) :
	WindowImpl<T>( 0, 0, width, height ),
	_monitor( nullptr ),
	_title( title ),
	_icon( icon ),
	_popup( popup ),
	_sizeable( sizeable ),
	_renderable( renderable )
{
}

template <class T>
SYNKRO_INLINE FrameWindowImpl<T>::FrameWindowImpl( IMonitor* monitor ) :
	WindowImpl<T>( 0, 0, 0, 0 ),
	_monitor( monitor ),
	_icon( 0 ),
	_popup( false ),
	_sizeable( false ),
	_renderable( true )
{
	lang::Size size;
	monitor->GetSize( size );
	_width = size.Width;
	_height = size.Height;
}

template <class T>
SYNKRO_INLINE FrameWindowImpl<T>::~FrameWindowImpl()
{
}

template <class T>
SYNKRO_INLINE void FrameWindowImpl<T>::SetTitle( const lang::String& title )
{
	_title = title;
}

template <class T>
SYNKRO_INLINE void FrameWindowImpl<T>::SetPopup( Bool popup )
{
	_popup = popup;
}

template <class T>
SYNKRO_INLINE UInt FrameWindowImpl<T>::GetIcon() const
{
	return _icon;
}

template <class T>
SYNKRO_INLINE lang::String FrameWindowImpl<T>::GetTitle() const
{
	return _title;
}

template <class T>
SYNKRO_INLINE IMonitor* FrameWindowImpl<T>::GetMonitor() const
{
	return _monitor;
}

template <class T>
SYNKRO_INLINE Bool FrameWindowImpl<T>::IsPopup() const
{
	return _popup;
}

template <class T>
SYNKRO_INLINE Bool FrameWindowImpl<T>::IsSizeable() const
{
	return _sizeable;
}

template <class T>
SYNKRO_INLINE Bool FrameWindowImpl<T>::IsRenderable() const
{
	return _renderable;
}
