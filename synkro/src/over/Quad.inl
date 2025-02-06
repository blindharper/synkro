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
// Purpose: Quad implementation.
//==============================================================================
SYNKRO_INLINE void Quad::Show( Bool show )
{
	_quad->Enable( show );
}

SYNKRO_INLINE void Quad::EnableRect( Bool enable )
{
	_rectEnabled = enable;
	if ( _rectEnabled && (_scissor == nullptr) )
	{
		_scissor = _graphicsSystem->GetDevice()->CreateScissorRect( _rect.Left, _rect.Top, _rect.Right, _rect.Bottom );
	}
	_quad->SetScissorRect( _rectEnabled ? _scissor : nullptr );
}

SYNKRO_INLINE void Quad::SetRect( const lang::Rect& rect )
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

SYNKRO_INLINE void Quad::SetLocation( const lang::Point& location )
{
	if ( location != _location )
	{
		_vertexParams->Set( _paramOffset, _ndc->Convert(math::Vector2(CastFloat(location.X), CastFloat(location.Y))) );
		_location = location;
	}
}

SYNKRO_INLINE void Quad::SetColor( const img::Color& color )
{
	if ( color != _color )
	{
		_fragmentParams->Set( _paramColor, ToVector(color, _opacity) );
		_color = color;
	}
}

SYNKRO_INLINE void Quad::SetOpacity( Float opacity )
{
	if ( opacity != _opacity )
	{
		_fragmentParams->Set( _paramColor, ToVector(_color, opacity) );
		_opacity = opacity;
	}
}

SYNKRO_INLINE void Quad::SetGroupOrder( const Order& order )
{
	if ( order != _order )
	{
		_quad->SetOrder( Order::GetValue(_groupOrder, order) );
		_order = order;
	}
}

SYNKRO_INLINE void Quad::SetOrder( const Order& order )
{
	if ( order != _groupOrder )
	{
		_quad->SetOrder( Order::GetValue(order, _order) );
		_groupOrder = order;
	}
}

SYNKRO_INLINE Bool Quad::IsVisible() const
{
	return _quad->IsEnabled();
}

SYNKRO_INLINE Bool Quad::IsRectEnabled() const
{
	return _rectEnabled;
}

SYNKRO_INLINE void Quad::GetRect( lang::Rect& rect ) const
{
	rect = _rect;
}

SYNKRO_INLINE void Quad::GetLocation( lang::Point& location ) const
{
	location = _location;
}

SYNKRO_INLINE void Quad::GetSize( lang::Size& size ) const
{
	size = _size;
}

SYNKRO_INLINE void Quad::GetColor( img::Color& color ) const
{
	color = _color;
}

SYNKRO_INLINE Float Quad::GetOpacity() const
{
	return _opacity;
}

SYNKRO_INLINE Order Quad::GetGroupOrder() const
{
	return _groupOrder;
}

SYNKRO_INLINE Order Quad::GetOrder() const
{
	return _order;
}
