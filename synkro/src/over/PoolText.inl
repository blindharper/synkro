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
SYNKRO_INLINE void PoolText::Clear()
{
	SetText( lang::String::Empty );
}

SYNKRO_INLINE void PoolText::SetGroupOrder( const Order& order )
{
	// Do nothing.
}

SYNKRO_INLINE void PoolText::SetOrder( const Order& order )
{
	// Do nothing.
}

SYNKRO_INLINE Bool PoolText::IsVisible() const
{
	return _visible;
}

SYNKRO_INLINE Bool PoolText::IsWrapped() const
{
	return _desc.Wrapped;
}

SYNKRO_INLINE Bool PoolText::IsRectEnabled() const
{
	return false;
}

SYNKRO_INLINE Bool PoolText::IsCenterEnabled() const
{
	return _desc.CenterEnabled;
}

SYNKRO_INLINE void PoolText::GetRect( lang::Rect& rect ) const
{
	rect = _desc.Rect;
}

SYNKRO_INLINE void PoolText::GetCenter( lang::Point& center ) const
{
	center = _desc.Center;
}

SYNKRO_INLINE void PoolText::GetLocation( lang::Point& location ) const
{
	location = _desc.Location;
}

SYNKRO_INLINE Float PoolText::GetOrientation() const
{
	return _desc.Orientation;
}

SYNKRO_INLINE Float PoolText::GetScale() const
{
	return _desc.Scale;
}

SYNKRO_INLINE void PoolText::GetGradient( img::ColorGradient& gradient ) const
{
	gradient = _desc.Gradient;
}

SYNKRO_INLINE void PoolText::GetColor( img::Color& color ) const
{
	color = _desc.Color;
}

SYNKRO_INLINE Float PoolText::GetOpacity() const
{
	return _desc.Opacity;
}

SYNKRO_INLINE lang::String PoolText::GetText() const
{
	return _desc.Text;
}
