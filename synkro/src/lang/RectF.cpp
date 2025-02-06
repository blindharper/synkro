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
// Purpose: Defines floating-point value rectangle.
//==============================================================================
#include "config.h"
#include <lang/RectF.h>


namespace synkro
{


namespace lang
{


const RectF RectF::Invalid( -1.0f, -1.0f, -1.0f, -1.0f );

RectF::RectF( Float left, Float top, Float right, Float bottom ) :
	Left( left ),
	Top( top ),
	Right( right ),
	Bottom( bottom )
{
}

RectF::RectF( const RectF& other ) :
	Left( other.Left ),
	Top( other.Top ),
	Right( other.Right ),
	Bottom( other.Bottom )
{
}

RectF::RectF() :
	Left( 0.0f ),
	Top( 0.0f ),
	Right( 0.0f ),
	Bottom( 0.0f )
{
}

RectF& RectF::Set( Float left, Float top, Float right, Float bottom )
{
	Left	= left;
	Top		= top;
	Right	= right;
	Bottom	= bottom;
	return *this;
}

RectF& RectF::Move( Float left, Float top )
{
	Float dx = left - Left;
	Float dy = top - Top;
	return Offset( dx, dy );
}

RectF& RectF::Offset( Float x, Float y )
{
	Left += x; Right += x;
	Top += y; Bottom += y;
	return *this;
}

RectF& RectF::SetSize( Float width, Float height )
{
	Right = Left + width;
	Bottom = Top + height;
	return *this;
}

RectF& RectF::Inflate( Float  x, Float y )
{
	return Set( Left-x, Top-y, Right+x, Bottom+y );
}

RectF& RectF::Deflate( Float  x, Float y )
{
	return Inflate( -x, -y );
}

RectF& RectF::Center( RectF& other )
{
	Float left = other.Left + (other.Width() - Width()) / 2;
	Float top = other.Top + (other.Height() - Height()) / 2;
	return Move( left, top );
}

RectF& RectF::Empty()
{
	return Set( 0.0f, 0.0f, 0.0f, 0.0f );
}

RectF& RectF::operator=( const RectF& other )
{
	Left	= other.Left;
	Top		= other.Top;
	Right	= other.Right;
	Bottom	= other.Bottom;
	return *this;
}

Bool RectF::operator==( const RectF& other ) const
{
	return (Left == other.Left) && (Top == other.Top) && (Right == other.Right) && (Bottom == other.Bottom);
}

Bool RectF::operator!=( const RectF& other ) const
{
	return (Left != other.Left) || (Top != other.Top) || (Right != other.Right) || (Bottom != other.Bottom);
}

Bool RectF::IsInside( const PointF& point ) const
{
	return (point.X > Left) && (point.X < Right) && (point.Y > Top) && (point.Y < Bottom);
}

Bool RectF::IsOutside( const PointF& point ) const
{
	return (point.X < Left) || (point.X > Right) || (point.Y < Top) || (point.Y > Bottom);
}

Bool RectF::IsOnBorder( const PointF& point ) const
{
	return !IsInside(point) && !IsOutside(point);
}

Bool RectF::IsNull() const
{
	return (Left == 0.0f) && (Top == 0.0f) && (Right == 0.0f) && (Bottom == 0.0f);
}

Bool RectF::IsEmpty() const
{
	return (Width() == 0.0f) || (Height() == 0.0f);
}

Float RectF::Width() const
{
	return Right - Left;
}

Float RectF::Height() const
{
	return Bottom - Top;
}


} // lang


} // synkro
