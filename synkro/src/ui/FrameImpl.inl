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
// Purpose: Generic user interface frame implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE FrameImpl<T>::FrameImpl( IFrame* parent, const lang::Point& location, const lang::Size& size ) :
	_widgets( A(P(IWidget)) ),
	_frames( A(P(IFrame)) ),
	_parent( parent ),
	_location( location ),
	_size( size ),
	_anchor( Anchor::None ),
	_visible( true ),
	_borderVisible( false )
{
	CalcRect();
}

template <class T>
SYNKRO_INLINE FrameImpl<T>::~FrameImpl()
{
}

template <class T>
SYNKRO_INLINE void FrameImpl<T>::Show( Bool show )
{
	_visible = show;
	for ( UInt i = 0; i < _widgets.Size(); ++i )
	{
		_widgets[i]->Show( _visible );
	}

	for ( UInt i = 0; i < _frames.Size(); ++i )
	{
		_frames[i]->Show( _visible );
	}
}

template <class T>
SYNKRO_INLINE void FrameImpl<T>::ShowBorder( Bool show )
{
	_borderVisible = show;
}

template <class T>
SYNKRO_INLINE void FrameImpl<T>::SetLocation( const lang::Point& location )
{
	_location = location;
	CalcRect();
}

template <class T>
SYNKRO_INLINE void FrameImpl<T>::SetSize( const lang::Size& size )
{
	_size = size;
	CalcRect();
}

template <class T>
SYNKRO_INLINE void FrameImpl<T>::SetAnchor( const Anchor& anchor )
{
	_anchor = anchor;
}

template <class T>
SYNKRO_INLINE UInt FrameImpl<T>::GetWidgetCount() const
{
	return _widgets.Size();
}

template <class T>
SYNKRO_INLINE IWidget* FrameImpl<T>::GetWidget( UInt index ) const
{
	assert( index < _widgets.Size() );

	if ( index >= _widgets.Size() )
		throw lang::OutOfRangeException( index, _widgets.Size() );

	return _widgets[index];
}

template <class T>
SYNKRO_INLINE UInt FrameImpl<T>::GetFrameCount() const
{
	return _frames.Size();
}

template <class T>
SYNKRO_INLINE IFrame* FrameImpl<T>::GetFrame( UInt index ) const
{
	assert( index < _frames.Size() );

	if ( index >= _frames.Size() )
		throw lang::OutOfRangeException( index, _frames.Size() );

	return _frames[index];
}

template <class T>
SYNKRO_INLINE void FrameImpl<T>::GetLocation( lang::Point& location ) const
{
	location = _location;
}

template <class T>
SYNKRO_INLINE void FrameImpl<T>::GetSize( lang::Size& size ) const
{
	size = _size;
}

template <class T>
SYNKRO_INLINE void FrameImpl<T>::GetRect( lang::Rect& rect ) const
{
	rect = _rect;
}

template <class T>
SYNKRO_INLINE void FrameImpl<T>::GetVisibleRect( lang::Rect& rect ) const
{
	rect = _visibleRect;
}

template <class T>
SYNKRO_INLINE Anchor FrameImpl<T>::GetAnchor() const
{
	return _anchor;
}

template <class T>
SYNKRO_INLINE IFrame* FrameImpl<T>::GetParent() const
{
	return _parent;
}

template <class T>
SYNKRO_INLINE Bool FrameImpl<T>::IsVisible() const
{
	return _visible;
}

template <class T>
SYNKRO_INLINE Bool FrameImpl<T>::IsBorderVisible() const
{
	return _borderVisible;
}

template <class T>
SYNKRO_INLINE IAccordion* FrameImpl<T>::AsAccordion() const
{
	return nullptr;
}

template <class T>
SYNKRO_INLINE void FrameImpl<T>::CalcRect()
{
	lang::Rect rect;
	if ( _parent != nullptr )
	{
		_parent->GetRect( rect );
	}
	_rect.Set( rect.TopLeft()+_location, _size );
	_visibleRect = (!rect.IsEmpty()) ? rect.Intersection( _rect ) : _rect;
}
