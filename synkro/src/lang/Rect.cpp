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
// Purpose: Defines whole number rectangle.
//==============================================================================
#include "config.h"
#include <lang/Rect.h>
#include <internal/Min.h>
#include <internal/Max.h>


namespace synkro
{


namespace lang
{


const Rect Rect::Invalid( -1L, -1L, -1L, -1L );

Rect::Rect( Int left, Int top, Int right, Int bottom ) SYNKRO_NOEXCEPT :
	Left( left ),
	Top( top ),
	Right( right ),
	Bottom( bottom )
{
}

Rect::Rect( const Point& topLeft, const Size& size ) SYNKRO_NOEXCEPT :
	Left( topLeft.X ),
	Top( topLeft.Y ),
	Right( topLeft.X+size.Width ),
	Bottom( topLeft.Y+size.Height )
{
}

Rect::Rect( const Rect& other ) SYNKRO_NOEXCEPT :
	Left( other.Left ),
	Top( other.Top ),
	Right( other.Right ),
	Bottom( other.Bottom )
{
}

Rect::Rect() SYNKRO_NOEXCEPT :
	Left( 0L ),
	Top( 0L ),
	Right( 0L ),
	Bottom( 0L )
{
}

Rect& Rect::Set( Int left, Int top, Int right, Int bottom ) SYNKRO_NOEXCEPT
{
	Left	= left;
	Top		= top;
	Right	= right;
	Bottom	= bottom;
	return *this;
}

Rect& Rect::Set( const Point& topLeft, const Point& bottomRight ) SYNKRO_NOEXCEPT
{
	Left	= topLeft.X;
	Top		= topLeft.Y;
	Right	= bottomRight.X;
	Bottom	= bottomRight.Y;
	return *this;
}

Rect& Rect::Set( const Point& topLeft, const Size& size ) SYNKRO_NOEXCEPT
{
	Left	= topLeft.X;
	Top		= topLeft.Y;
	Right	= topLeft.X + size.Width;
	Bottom	= topLeft.Y + size.Height;
	return *this;
}

Rect& Rect::Move( Int left, Int top ) SYNKRO_NOEXCEPT
{
	const Int dx = left - Left;
	const Int dy = top - Top;
	return Offset( dx, dy );
}

Rect& Rect::Offset( Int x, Int y ) SYNKRO_NOEXCEPT
{
	Left += x; Right += x;
	Top += y; Bottom += y;
	return *this;
}

Rect& Rect::SetSize( Int width, Int height ) SYNKRO_NOEXCEPT
{
	Right = Left + width;
	Bottom = Top + height;
	return *this;
}

Rect& Rect::Inflate( Int x, Int y ) SYNKRO_NOEXCEPT
{
	return Set( Left-x, Top-y, Right+x, Bottom+y );
}

Rect& Rect::Deflate( Int x, Int y ) SYNKRO_NOEXCEPT
{
	return Inflate( -x, -y );
}

Rect& Rect::Center( const Rect& other ) SYNKRO_NOEXCEPT
{
	const Int left = other.Left + (other.Width() - Width()) / 2;
	const Int top = other.Top + (other.Height() - Height()) / 2;
	return Move( left, top );
}

Rect& Rect::Intersect( const Rect& other ) SYNKRO_NOEXCEPT
{
	Int left = Max( Left, other.Left );
	Int top = Max( Top, other.Top );
	const Int right = Min( Right, other.Right );
	const Int bottom = Min( Bottom, other.Bottom );
	left = Min( left, right );
	top = Min( top, bottom );
	Set( left, top, right, bottom );
	return *this;
}

Rect& Rect::Empty() SYNKRO_NOEXCEPT
{
	return Set( 0L, 0L, 0L, 0L );
}

Rect& Rect::operator=( const Rect& other ) SYNKRO_NOEXCEPT
{
	Left	= other.Left;
	Top		= other.Top;
	Right	= other.Right;
	Bottom	= other.Bottom;
	return *this;
}

Bool Rect::operator==( const Rect& other ) const SYNKRO_NOEXCEPT
{
	return (Left == other.Left) && (Top == other.Top) && (Right == other.Right) && (Bottom == other.Bottom);
}

Bool Rect::operator!=( const Rect& other ) const SYNKRO_NOEXCEPT
{
	return (Left != other.Left) || (Top != other.Top) || (Right != other.Right) || (Bottom != other.Bottom);
}

Rect Rect::Inflated( Int x, Int y ) const SYNKRO_NOEXCEPT
{
	return Rect( Left-x, Top-y, Right+x, Bottom+y );
}

Rect Rect::Deflated( Int x, Int y ) const SYNKRO_NOEXCEPT
{
	return Inflated( -x, -y );
}

Rect Rect::Centered( const Rect& other ) const SYNKRO_NOEXCEPT
{	
	Rect rc( *this );
	const Int left = other.Left + (other.Width() - Width()) / 2;
	const Int top = other.Top + (other.Height() - Height()) / 2;
	rc.Move( left, top );
	return rc;
}

Rect Rect::Intersection( const Rect& other ) const SYNKRO_NOEXCEPT
{
	Int left = Max( Left, other.Left );
	Int top = Max( Top, other.Top );
	const Int right = Min( Right, other.Right );
	const Int bottom = Min( Bottom, other.Bottom );
	left = Min( left, right );
	top = Min( top, bottom );
	return Rect( left, top, right, bottom );
}

Bool Rect::IsInside( const Point& point ) const SYNKRO_NOEXCEPT
{
	return (point.X > Left) && (point.X < Right) && (point.Y > Top) && (point.Y < Bottom);
}

Bool Rect::IsOutside( const Point& point ) const SYNKRO_NOEXCEPT
{
	return (point.X < Left) || (point.X > Right) || (point.Y < Top) || (point.Y > Bottom);
}

Bool Rect::IsOnBorder( const Point& point ) const SYNKRO_NOEXCEPT
{
	return !IsInside(point) && !IsOutside(point);
}

Bool Rect::IsNull() const SYNKRO_NOEXCEPT
{
	return (Left == 0L) && (Top == 0L) && (Right == 0L) && (Bottom == 0L);
}

Bool Rect::IsEmpty() const SYNKRO_NOEXCEPT
{
	return (Width() == 0L) || (Height() == 0L);
}

Point Rect::TopLeft() const SYNKRO_NOEXCEPT
{
	return Point( Left, Top );
}

Point Rect::BottomRight() const SYNKRO_NOEXCEPT
{
	return Point( Right, Bottom );
}

Int Rect::Width() const SYNKRO_NOEXCEPT
{
	return Right - Left;
}

Int Rect::Height() const SYNKRO_NOEXCEPT
{
	return Bottom - Top;
}


} // lang


} // synkro
