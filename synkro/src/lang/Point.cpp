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
// Purpose: Defines Whole number point.
//==============================================================================
#include "config.h"
#include <lang/Point.h>


namespace synkro
{


namespace lang
{


Point::Point( Int x, Int y ) :
	X( x ),
	Y( y )
{
}

Point::Point( const Point& other ) :
	X( other.X ),
	Y( other.Y )
{
}

Point::Point() :
	X( 0L ),
	Y( 0L )
{
}

Point& Point::Set( Int x, Int y )
{
	X = x;
	Y = y;
	return *this;
}

Point Point::Offset( Int x, Int y ) const
{
	return Point( X+x, Y+y );
}

Point& Point::operator=( const Point& other )
{
	return Set( other.X, other.Y );
}

Point& Point::operator+=( const Point& other )
{
	X += other.X;
	Y += other.Y;
	return *this;
}

Point& Point::operator-=( const Point& other )
{
	X -= other.X;
	Y -= other.Y;
	return *this;
}

Point Point::operator+( const Point& other ) const
{
	return Point( X+other.X, Y+other.Y );
}

Point Point::operator-( const Point& other ) const
{
	return Point( X-other.X, Y-other.Y );
}

Bool Point::operator==( const Point& other ) const
{
	return (X == other.X) && (Y == other.Y);
}

Bool Point::operator!=( const Point& other ) const
{
	return (X != other.X) || (Y != other.Y);
}


} // lang


} // synkro
