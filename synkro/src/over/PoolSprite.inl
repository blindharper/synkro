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
// Purpose: Pool sprite implementation.
//==============================================================================
SYNKRO_INLINE void PoolSprite::SetGroupOrder( const Order& order )
{
	// Do nothing.
}

SYNKRO_INLINE void PoolSprite::SetOrder( const Order& order )
{
	// Do nothing.
}

SYNKRO_INLINE Bool PoolSprite::IsVisible() const
{
	return _visible;
}

SYNKRO_INLINE Bool PoolSprite::IsStretched() const
{
	return _stretched;
}

SYNKRO_INLINE Bool PoolSprite::IsRectEnabled() const
{
	return false;
}

SYNKRO_INLINE Bool PoolSprite::IsCenterEnabled() const
{
	return _centerEnabled;
}

SYNKRO_INLINE void PoolSprite::GetRect( lang::Rect& rect ) const
{
	// Do nothing.
}

SYNKRO_INLINE void PoolSprite::GetCenter( lang::Point& center ) const
{
	center = _center;
}

SYNKRO_INLINE void PoolSprite::GetLocation( lang::Point& location ) const
{
	location = _location;
}

SYNKRO_INLINE void PoolSprite::GetSize( lang::Size& size ) const
{
	size = _size;
}

SYNKRO_INLINE Float PoolSprite::GetOrientation() const
{
	return _orientation;
}

SYNKRO_INLINE Float PoolSprite::GetOpacity() const
{
	return _opacity;
}

SYNKRO_INLINE void PoolSprite::GetFrame( lang::RectF& frame ) const
{
	frame = _frame;
}
