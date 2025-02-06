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
// Purpose: Overlay text implementation.
//==============================================================================
SYNKRO_INLINE void Text::Show( Bool show )
{
	_text->Enable( show );
}

SYNKRO_INLINE void Text::Clear()
{
	SetText( lang::String::Empty );
}

SYNKRO_INLINE void Text::EnableRect( Bool enable )
{
	_rectEnabled = enable;
	if ( _rectEnabled && (_scissor == nullptr) )
	{
		_scissor = _context->GetGraphicsSystem()->GetDevice()->CreateScissorRect( _desc.Rect.Left, _desc.Rect.Top, _desc.Rect.Right, _desc.Rect.Bottom );
	}
	_text->SetScissorRect( _rectEnabled ? _scissor : nullptr );
}

SYNKRO_INLINE void Text::SetRect( const lang::Rect& rect )
{
	if ( rect != _desc.Rect )
	{
		if ( _scissor != nullptr )
		{
			_scissor->SetBounds( rect.Left, rect.Top, rect.Right, rect.Bottom );
		}
		_desc.Rect = rect;
	}
}

SYNKRO_INLINE void Text::SetGroupOrder( const Order& order )
{
	if ( order != _order )
	{
		_order = order;
		_text->SetOrder( Order::GetValue(_groupOrder, _order) );
	}
}

SYNKRO_INLINE void Text::SetOrder( const Order& order )
{
	if ( order != _groupOrder )
	{
		_groupOrder = order;
		_text->SetOrder( Order::GetValue(_groupOrder, _order) );
	}
}

SYNKRO_INLINE Bool Text::IsVisible() const
{
	return _text->IsEnabled();
}

SYNKRO_INLINE Bool Text::IsWrapped() const
{
	return _desc.Wrapped;
}

SYNKRO_INLINE Bool Text::IsRectEnabled() const
{
	return _rectEnabled;
}

SYNKRO_INLINE Bool Text::IsCenterEnabled() const
{
	return _desc.CenterEnabled;
}

SYNKRO_INLINE void Text::GetRect( lang::Rect& rect ) const
{
	rect = _desc.Rect;
}

SYNKRO_INLINE void Text::GetCenter( lang::Point& center ) const
{
	center = _desc.Center;
}

SYNKRO_INLINE void Text::GetLocation( lang::Point& location ) const
{
	location = _desc.Location;
}

SYNKRO_INLINE Float Text::GetOrientation() const
{
	return _desc.Orientation;
}

SYNKRO_INLINE Float Text::GetScale() const
{
	return _desc.Scale;
}

SYNKRO_INLINE void Text::GetGradient( img::ColorGradient& gradient ) const
{
	gradient = _desc.Gradient;
}

SYNKRO_INLINE void Text::GetColor( img::Color& color ) const
{
	color = _desc.Gradient.Start;
}

SYNKRO_INLINE Float Text::GetOpacity() const
{
	return _desc.Opacity;
}

SYNKRO_INLINE Order Text::GetGroupOrder() const
{
	return _groupOrder;
}

SYNKRO_INLINE Order Text::GetOrder() const
{
	return _order;
}

SYNKRO_INLINE lang::String Text::GetText() const
{
	return _desc.Text;
}

SYNKRO_INLINE IFont* Text::GetFont() const
{
	return dynamic_cast<IFont*>( _font );
}
