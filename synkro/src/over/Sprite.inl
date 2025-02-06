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
// Purpose: Sprite implementation.
//==============================================================================
SYNKRO_INLINE void Sprite::Show( Bool show )
{
	_sprite->Enable( show );
}

SYNKRO_INLINE void Sprite::Stretch( Bool stretch )
{
	if ( stretch != _stretched )
	{
		_stretched = stretch;
		SetPositions( _location, _size, _orientation );
	}
}

SYNKRO_INLINE void Sprite::EnableRect( Bool enable )
{
	_rectEnabled = enable;
	if ( _rectEnabled && (_scissor == nullptr) )
	{
		_scissor = _context->GetGraphicsSystem()->GetDevice()->CreateScissorRect( _rect.Left, _rect.Top, _rect.Right, _rect.Bottom );
	}
	_sprite->SetScissorRect( _rectEnabled ? _scissor : nullptr );
}

SYNKRO_INLINE void Sprite::EnableCenter( Bool enable )
{
	_centerEnabled = enable;
}

SYNKRO_INLINE void Sprite::SetRect( const lang::Rect& rect )
{
	if ( rect != _rect )
	{
		if ( _scissor != nullptr )
		{
			_scissor->SetBounds( rect.Left, rect.Top, rect.Right, rect.Bottom );
		}
		_rect = rect;
	}
}

SYNKRO_INLINE void Sprite::SetCenter( const lang::Point& center )
{
	if ( center != _center )
	{
		_center = center;
	}
}

SYNKRO_INLINE void Sprite::SetOpacity( Float opacity )
{
	if ( opacity != _opacity )
	{
		_fragmentParams->Set( _paramColor, ToVector(img::Color::White, opacity) );
		_opacity = opacity;
	}
}

SYNKRO_INLINE void Sprite::SetGroupOrder( const Order& order )
{
	if ( order != _order )
	{
		_sprite->SetOrder( Order::GetValue(_groupOrder, order) );
		_order = order;
	}
}

SYNKRO_INLINE void Sprite::SetOrder( const Order& order )
{
	if ( order != _groupOrder )
	{
		_sprite->SetOrder( Order::GetValue(order, _order) );
		_groupOrder = order;
	}
}

SYNKRO_INLINE Bool Sprite::IsVisible() const
{
	return _sprite->IsEnabled();
}

SYNKRO_INLINE Bool Sprite::IsStretched() const
{
	return _stretched;
}

SYNKRO_INLINE Bool Sprite::IsRectEnabled() const
{
	return _rectEnabled;
}

SYNKRO_INLINE Bool Sprite::IsCenterEnabled() const
{
	return _centerEnabled;
}

SYNKRO_INLINE void Sprite::GetRect( lang::Rect& rect ) const
{
	rect = _rect;
}

SYNKRO_INLINE void Sprite::GetCenter( lang::Point& center ) const
{
	center = _center;
}

SYNKRO_INLINE void Sprite::GetLocation( lang::Point& location ) const
{
	location = _location;
}

SYNKRO_INLINE void Sprite::GetSize( lang::Size& size ) const
{
	size = _size;
}

SYNKRO_INLINE Float Sprite::GetOrientation() const
{
	return _orientation;
}

SYNKRO_INLINE Float Sprite::GetOpacity() const
{
	return _opacity;
}

SYNKRO_INLINE void Sprite::GetFrame( lang::RectF& frame ) const
{
	frame = _frame;
}

SYNKRO_INLINE Order Sprite::GetGroupOrder() const
{
	return _groupOrder;
}

SYNKRO_INLINE Order Sprite::GetOrder() const
{
	return _order;
}

SYNKRO_INLINE img::IImage* Sprite::GetImage() const
{
	return _image;
}
