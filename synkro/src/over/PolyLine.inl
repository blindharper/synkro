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
// Purpose: PolyLine implementation.
//==============================================================================
SYNKRO_INLINE void PolyLine::Show( Bool show )
{
	_polyline->Enable( show );
}

SYNKRO_INLINE void PolyLine::SetGroupOrder( const Order& order )
{
	if ( order != _order )
	{
		_polyline->SetOrder( Order::GetValue(_groupOrder, order) );
		_order = order;
	}
}

SYNKRO_INLINE void PolyLine::SetOrder( const Order& order )
{
	if ( order != _groupOrder )
	{
		_polyline->SetOrder( Order::GetValue(order, _order) );
		_groupOrder = order;
	}
}

SYNKRO_INLINE Bool PolyLine::IsVisible() const
{
	return _polyline->IsEnabled();
}

SYNKRO_INLINE Order PolyLine::GetGroupOrder() const
{
	return _groupOrder;
}

SYNKRO_INLINE Order PolyLine::GetOrder() const
{
	return _order;
}

SYNKRO_INLINE void PolyLine::GetColor( img::Color& color ) const
{
	color = _color;
}

SYNKRO_INLINE Float PolyLine::GetOpacity() const
{
	return _opacity;
}

SYNKRO_INLINE UInt PolyLine::GetPointCount() const
{
	return _pointCount;
}

SYNKRO_INLINE UInt PolyLine::GetWidth() const
{
	return _width;
}
