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
// Purpose: Defines floating-point point.
//==============================================================================
#include "config.h"
#include <lang/PointF.h>


namespace synkro
{


namespace lang
{


PointF::PointF( Float x, Float y ) SYNKRO_NOEXCEPT :
	X( x ),
	Y( y )
{
}

PointF::PointF( const PointF& other ) SYNKRO_NOEXCEPT :
	X( other.X ),
	Y( other.Y )
{
}

PointF::PointF() SYNKRO_NOEXCEPT :
	X( 0.0f ),
	Y( 0.0f )
{
}

PointF& PointF::Set( Float x, Float y ) SYNKRO_NOEXCEPT
{
	X = x;
	Y = y;
	return *this;
}

PointF& PointF::operator=( const PointF& other ) SYNKRO_NOEXCEPT
{
	return Set( other.X, other.Y );
}

PointF& PointF::operator+=( const PointF& other ) SYNKRO_NOEXCEPT
{
	X += other.X;
	Y += other.Y;
	return *this;
}

PointF& PointF::operator-=( const PointF& other ) SYNKRO_NOEXCEPT
{
	X -= other.X;
	Y -= other.Y;
	return *this;
}

PointF PointF::operator-( const PointF& other ) const SYNKRO_NOEXCEPT
{
	return PointF( X-other.X, Y-other.Y );
}

Bool PointF::operator==( const PointF& other ) const SYNKRO_NOEXCEPT
{
	return (X == other.X) && (Y == other.Y);
}

Bool PointF::operator!=( const PointF& other ) const SYNKRO_NOEXCEPT
{
	return (X != other.X) || (Y != other.Y);
}


} // lang


} // synkro
