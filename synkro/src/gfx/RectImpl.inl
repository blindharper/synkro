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
// Purpose: Generic rectangle implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE RectImpl<T>::RectImpl( Int left, Int top, Int right, Int bottom ) :
	_dirty( true ),
	_rect( left, top, right, bottom )
{
}

template <class T>
SYNKRO_INLINE RectImpl<T>::~RectImpl()
{
}

template <class T>
SYNKRO_INLINE void RectImpl<T>::SetBounds( Int left, Int top, Int right, Int bottom )
{
	if ( (left != _rect.Left) || (top != _rect.Top) || (right != _rect.Right) || (bottom != _rect.Bottom) )
	{
		_rect.Set( left, top, right, bottom );
		_dirty = true;
	}
}

template <class T>
SYNKRO_INLINE void RectImpl<T>::SetLocation( Int left, Int top )
{
	if ( (left != _rect.Left) || (top != _rect.Top) )
	{
		_rect.Move( left, top );
		_dirty	= true;
	}
}

template <class T>
SYNKRO_INLINE void RectImpl<T>::SetSize( UInt width, UInt height )
{
	if ( (width != _rect.Width()) || (height != _rect.Height()) )
	{
		_rect.SetSize( width, height );
		_dirty = true;
	}
}

template <class T>
SYNKRO_INLINE void RectImpl<T>::GetBounds( Int& left, Int& top, Int& right, Int& bottom ) const
{
	left	= _rect.Left;
	top		= _rect.Top;
	right	= _rect.Right;
	bottom	= _rect.Bottom;
}

template <class T>
SYNKRO_INLINE void RectImpl<T>::GetLocation( Int& left, Int& top ) const
{
	left	= _rect.Left;
	top		= _rect.Top;
}

template <class T>
SYNKRO_INLINE void RectImpl<T>::GetSize( UInt& width, UInt& height ) const
{
	width	= _rect.Width();
	height	= _rect.Height();
}
