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
// Purpose: Generic user interface widget implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE WidgetImpl<T>::WidgetImpl( BaseUi* ui, IFrame* parent, const lang::Point& location, const lang::Size& size ) :
	_ui( ui ),
	_parent( parent ),
	_color( img::Color::White ),
	_opacity( 1.0f ),
	_location( location ),
	_size( size ),
	_anchor( Anchor::None ),
	_zOrder( over::Order::GetValue(over::Order::Normal, over::Order::Normal) ),
	_tabOrder( 0 ),
	_data( null ),
	_active( false ),
	_enabled( true ),
	_visible( true ),
	_cursor( CursorType::Pointer )
{
	AsBaseFrame( parent )->AddWidget( this );
	if ( _ui != nullptr )
	{
		lang::Rect rect; _parent->GetRect( rect );
		_scissorRect = _ui->CreateScissorRect( rect.Left, rect.Top, rect.Right, rect.Bottom );
	}
	CalcRect();
}

template <class T>
SYNKRO_INLINE WidgetImpl<T>::~WidgetImpl()
{
}

template <class T>
SYNKRO_INLINE void WidgetImpl<T>::Activate( Bool activate )
{
	_active = activate;
}

template <class T>
SYNKRO_INLINE void WidgetImpl<T>::Enable( Bool enable )
{
	_enabled = enable;
}

template <class T>
SYNKRO_INLINE void WidgetImpl<T>::Show( Bool show )
{
	_visible = show;

	if ( _object != nullptr )
	{
		_object->Enable( show );
	}

	if ( _object2 != nullptr )
	{
		_object2->Enable( show );
	}

	if ( _object3 != nullptr )
	{
		_object3->Enable( show );
	}

	if ( _text != nullptr )
	{
		_text->Show( show );
	}
}

template <class T>
SYNKRO_INLINE void WidgetImpl<T>::SetOpacity( Float opacity )
{
	opacity = Clamp( opacity, 0.0f, 1.0f );
	if ( opacity != _opacity )
	{
		_opacity = opacity;
		if ( _text != nullptr )
		{
			_text->SetOpacity( _opacity );
		}
		if ( (_object != nullptr) && (_paramColor != nullptr) )
		{
			SetColor( _color );
		}
		if ( _effect != nullptr )
		{
			_effect->SetOpacity( _opacity );
		}
	}
}

template <class T>
SYNKRO_INLINE void WidgetImpl<T>::SetLocation( const lang::Point& location )
{
	_location = location;
	CalcRect();
}

template <class T>
SYNKRO_INLINE void WidgetImpl<T>::SetSize( const lang::Size& size )
{
	_size = size;
	CalcRect();
}

template <class T>
SYNKRO_INLINE void WidgetImpl<T>::SetHotKey( const HotKey& key )
{
	// Do nothing.
}

template <class T>
SYNKRO_INLINE void WidgetImpl<T>::SetAnchor( const Anchor& anchor )
{
	_anchor = anchor;
}

template <class T>
SYNKRO_INLINE void WidgetImpl<T>::SetZOrder( UInt order )
{
	_zOrder = order;
}

template <class T>
SYNKRO_INLINE void WidgetImpl<T>::SetTabOrder( UInt order )
{
	_tabOrder = order;
}

template <class T>
SYNKRO_INLINE void WidgetImpl<T>::SetData( Pointer data )
{
	_data = data;
}

template <class T>
SYNKRO_INLINE Bool WidgetImpl<T>::IsActive() const
{
	return _active;
}

template <class T>
SYNKRO_INLINE Bool WidgetImpl<T>::IsEnabled() const
{
	return _enabled;
}

template <class T>
SYNKRO_INLINE Bool WidgetImpl<T>::IsVisible() const
{
	return _visible;
}

template <class T>
SYNKRO_INLINE Float WidgetImpl<T>::GetOpacity() const
{
	return _opacity;
}

template <class T>
SYNKRO_INLINE void WidgetImpl<T>::GetLocation( lang::Point& location ) const
{
	location = _location;
}

template <class T>
SYNKRO_INLINE void WidgetImpl<T>::GetSize( lang::Size& size ) const
{
	size = _size;
}

template <class T>
SYNKRO_INLINE void WidgetImpl<T>::GetRect( lang::Rect& rect ) const
{
	rect = _rect;
}

template <class T>
SYNKRO_INLINE void WidgetImpl<T>::GetVisibleRect( lang::Rect& rect ) const
{
	rect = _visibleRect;
}

template <class T>
SYNKRO_INLINE void WidgetImpl<T>::GetHotKey( HotKey& key ) const
{
	// Do nothing.
}

template <class T>
SYNKRO_INLINE Anchor WidgetImpl<T>::GetAnchor() const
{
	return _anchor;
}

template <class T>
SYNKRO_INLINE UInt WidgetImpl<T>::GetZOrder() const
{
	return _zOrder;
}

template <class T>
SYNKRO_INLINE UInt WidgetImpl<T>::GetTabOrder() const
{
	return _tabOrder;
}

template <class T>
SYNKRO_INLINE Pointer WidgetImpl<T>::GetData() const
{
	return _data;
}

template <class T>
SYNKRO_INLINE CursorType WidgetImpl<T>::GetCursor() const
{
	return _cursor;
}

template <class T>
SYNKRO_INLINE IFrame* WidgetImpl<T>::GetParent() const
{
	return _parent;
}

template <class T>
SYNKRO_INLINE IAngle* WidgetImpl<T>::AsAngle() const
{
	return nullptr;
}

template <class T>
SYNKRO_INLINE IButton* WidgetImpl<T>::AsButton() const
{
	return nullptr;
}

template <class T>
SYNKRO_INLINE IDropList* WidgetImpl<T>::AsDropList() const
{
	return nullptr;
}

template <class T>
SYNKRO_INLINE IEdit* WidgetImpl<T>::AsEdit() const
{
	return nullptr;
}

template <class T>
SYNKRO_INLINE ILabel* WidgetImpl<T>::AsLabel() const
{
	return nullptr;
}

template <class T>
SYNKRO_INLINE IList* WidgetImpl<T>::AsList() const
{
	return nullptr;
}

template <class T>
SYNKRO_INLINE IOption* WidgetImpl<T>::AsOption() const
{
	return nullptr;
}

template <class T>
SYNKRO_INLINE IPicture* WidgetImpl<T>::AsPicture() const
{
	return nullptr;
}

template <class T>
SYNKRO_INLINE IProgress* WidgetImpl<T>::AsProgress() const
{
	return nullptr;
}

template <class T>
SYNKRO_INLINE ISlider* WidgetImpl<T>::AsSlider() const
{
	return nullptr;
}

template <class T>
SYNKRO_INLINE ISwitch* WidgetImpl<T>::AsSwitch() const
{
	return nullptr;
}

template <class T>
SYNKRO_INLINE void WidgetImpl<T>::SetIndices( gfx::IOverlayRenderObject* object, const UShort* data, UInt start, UInt count )
{
	P(gfx::IShortStream) stream = (gfx::IShortStream*)object->GetData()->GetIndexStream();
	if ( stream->Open(io::OpenMode::Write) )
	{
		stream->SetPosition( start );
		stream->Write( data, count );
		stream->Close();
	}
}

template <class T>
SYNKRO_INLINE void WidgetImpl<T>::SetIndicesCentered( gfx::IOverlayRenderObject* object )
{
	// (0)-(1)----------(2)-(3)
	//  |   |            |   |
	// (4)-(5)----------(6)-(7)
	//  |   |            |   |
	// (8)-(9)---------(10)-(11)
	//  |   |            |   |
	// (12)-(13)-------(14)-(15)
	UShort indices[] =
	{
		4, 0, 1, 4, 1, 5,
		5, 1, 2, 5, 2, 6,
		6, 2, 3, 6, 3, 7,
		8, 4, 5, 8, 5, 9,
		9, 5, 6, 9, 6, 10,
		10, 6, 7, 10, 7, 11,
		12, 8, 9, 12, 9, 13,
		13, 9, 10, 13, 10, 14,
		14, 10, 11, 14, 11, 15,
	};
	SetIndices( object, indices, 0, 54 );
}

template <class T>
SYNKRO_INLINE void WidgetImpl<T>::SetPositions( gfx::IOverlayRenderObject* object, const math::Vector4* data, UInt start, UInt count )
{
	P(gfx::IVector4Stream) stream = (gfx::IVector4Stream*)object->GetData()->GetVertexStream( gfx::DataStream::Position2D, 0 );
	if ( stream->Open(io::OpenMode::Write) )
	{
		stream->SetPosition( start );
		stream->Write( data, count );
		stream->Close();
	}
}

template <class T>
SYNKRO_INLINE void WidgetImpl<T>::SetPositions( const math::Vector4* data, UInt start, UInt count )
{
	SetPositions( _object, data, start, count );
}

template <class T>
SYNKRO_INLINE void WidgetImpl<T>::SetPositions2( const math::Vector4* data, UInt start, UInt count )
{
	SetPositions( _object2, data, start, count );
}

template <class T>
SYNKRO_INLINE void WidgetImpl<T>::SetPositions( gfx::IOverlayRenderObject* object, const lang::Point& location, const lang::Size& size, const lang::Rect& rect, const lang::Rect& center )
{
	Float left = CastFloat( location.X );
	Float top = CastFloat( location.Y );
	Float w = CastFloat( size.Width );
	Float h = CastFloat( size.Height );
	Float dx1 = CastFloat( center.Left-rect.Left );
	Float dx2 = CastFloat( rect.Right-center.Right );
	Float dy1 = CastFloat( center.Top-rect.Top );
	Float dy2 = CastFloat( rect.Bottom-center.Bottom );
	math::Vector4 pos[] =
	{
		math::Vector4( left,		top,		0.0f, 1.0f ),
		math::Vector4( left+dx1,	top,		0.0f, 1.0f ),
		math::Vector4( left+w-dx2,	top,		0.0f, 1.0f ),
		math::Vector4( left+w,		top,		0.0f, 1.0f ),

		math::Vector4( left,		top+dy1,	0.0f, 1.0f ),
		math::Vector4( left+dx1,	top+dy1,	0.0f, 1.0f ),
		math::Vector4( left+w-dx2,	top+dy1,	0.0f, 1.0f ),
		math::Vector4( left+w,		top+dy1,	0.0f, 1.0f ),

		math::Vector4( left,		top+h-dy2,	0.0f, 1.0f ),
		math::Vector4( left+dx1,	top+h-dy2,	0.0f, 1.0f ),
		math::Vector4( left+w-dx2,	top+h-dy2,	0.0f, 1.0f ),
		math::Vector4( left+w,		top+h-dy2,	0.0f, 1.0f ),

		math::Vector4( left,		top+h,		0.0f, 1.0f ),
		math::Vector4( left+dx1,	top+h,		0.0f, 1.0f ),
		math::Vector4( left+w-dx2,	top+h,		0.0f, 1.0f ),
		math::Vector4( left+w,		top+h,		0.0f, 1.0f ),
	};
	SetPositions( object, pos, 0, 16 );
}

template <class T>
SYNKRO_INLINE void WidgetImpl<T>::SetTextureCoordinates( gfx::IOverlayRenderObject* object, const math::Vector2* data, UInt start, UInt count )
{
	P(gfx::IVector2Stream) stream = (gfx::IVector2Stream*)object->GetData()->GetVertexStream( gfx::DataStream::TexCoord2D, 0 );
	if ( stream->Open(io::OpenMode::Write) )
	{
		stream->SetPosition( start );
		stream->Write( data, count );
		stream->Close();
	}
}

template <class T>
SYNKRO_INLINE void WidgetImpl<T>::SetTextureCoordinates( const math::Vector2* data, UInt start, UInt count )
{
	SetTextureCoordinates( _object, data, start, count );
}

template <class T>
SYNKRO_INLINE void WidgetImpl<T>::SetTextureCoordinates2( const math::Vector2* data, UInt start, UInt count )
{
	SetTextureCoordinates( _object2, data, start, count );
}

template <class T>
SYNKRO_INLINE void WidgetImpl<T>::SetTextureCoordinates( gfx::IOverlayRenderObject* object, const lang::Rect& rect, const lang::Rect& center )
{
	lang::RectF r; _ui->Theme()->ToRectF( rect, r );
	lang::RectF c; _ui->Theme()->ToRectF( center, c );
	math::Vector2 coords[] = 
	{
		math::Vector2( r.Left,		r.Top ),
		math::Vector2( c.Left,		r.Top ),
		math::Vector2( c.Right,		r.Top ),
		math::Vector2( r.Right,		r.Top ),

		math::Vector2( r.Left,		c.Top ),
		math::Vector2( c.Left,		c.Top ),
		math::Vector2( c.Right,		c.Top ),
		math::Vector2( r.Right,		c.Top ),

		math::Vector2( r.Left,		c.Bottom ),
		math::Vector2( c.Left,		c.Bottom ),
		math::Vector2( c.Right,		c.Bottom ),
		math::Vector2( r.Right,		c.Bottom ),

		math::Vector2( r.Left,		r.Bottom ),
		math::Vector2( c.Left,		r.Bottom ),
		math::Vector2( c.Right,		r.Bottom ),
		math::Vector2( r.Right,		r.Bottom ),
	};
	SetTextureCoordinates( object, coords, 0, 16 );
}

template <class T>
SYNKRO_INLINE void WidgetImpl<T>::SetColor( const img::Color& color, Bool update )
{
	_color = color;
	if ( update )
	{
		math::Vector4 col = ToVector( color, _opacity );
		_object->GetFragmentParameters()->Set( _paramColor, col );
		if ( _object2 != nullptr )
		{
			_object2->GetFragmentParameters()->Set( _paramColor2, col );
		}
		if ( _object3 != nullptr )
		{
			_object3->GetFragmentParameters()->Set( _paramColor3, col );
		}
	}
}

template <class T>
SYNKRO_INLINE void WidgetImpl<T>::CalcRect()
{
	lang::Rect rect; _parent->GetRect( rect );
	_rect.Set( rect.TopLeft()+_location, _size );
	_visibleRect = rect.Intersection( _rect );
	if ( _scissorRect != nullptr )
	{
		_scissorRect->SetBounds( rect.Left, rect.Top, rect.Right, rect.Bottom );
	}
}
