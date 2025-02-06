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
// Purpose: Generic window implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE WindowImpl<T>::WindowImpl( Int left, Int top, UInt width, UInt height ) :
	_handle( 0 ),
	_active( false ),
	_closing( false ),
	_left( left ),
	_top( top ),
	_width( width ),
	_height( height ),
	_dpi( 96 )
{
}

template <class T>
SYNKRO_INLINE WindowImpl<T>::~WindowImpl()
{
}

template <class T>
SYNKRO_INLINE void WindowImpl<T>::SetPosition( Int left, Int top )
{
	_left	= left;
	_top	= top;
}

template <class T>
SYNKRO_INLINE void WindowImpl<T>::SetSize( UInt width, UInt height )
{
	_width	= width;
	_height	= height;
}

template <class T>
SYNKRO_INLINE Int WindowImpl<T>::GetLeft() const
{
	return _left;
}

template <class T>
SYNKRO_INLINE Int WindowImpl<T>::GetTop() const
{
	return _top;
}

template <class T>
SYNKRO_INLINE UInt WindowImpl<T>::GetWidth() const
{
	return _width;
}

template <class T>
SYNKRO_INLINE UInt WindowImpl<T>::GetHeight() const
{
	return _height;
}

template <class T>
SYNKRO_INLINE UInt WindowImpl<T>::GetHandle() const
{
	return _handle;
}

template <class T>
SYNKRO_INLINE UInt WindowImpl<T>::GetDpi() const
{
	return _dpi;
}

template <class T>
SYNKRO_INLINE Bool WindowImpl<T>::IsActive() const
{
	return _active;
}

template <class T>
SYNKRO_INLINE Bool WindowImpl<T>::IsClosing() const
{
	return _closing;
}
