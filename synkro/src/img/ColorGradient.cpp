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
// Purpose: Defines color gradient.
//==============================================================================
#include "config.h"
#include <img/ColorGradient.h>


namespace synkro
{


namespace img
{


ColorGradient::ColorGradient( const lang::GradientType& type, const Color& start, const Color& end ) :
	Type( type ),
	Start( start ),
	End( end )
{
}

ColorGradient::ColorGradient( const ColorGradient& other ) :
	Type( other.Type ),
	Start( other.Start ),
	End( other.End )
{
}

ColorGradient::ColorGradient() :
	Type( lang::GradientType::Horizontal ),
	Start( Color::Black ),
	End( Color::Black )
{
}

ColorGradient& ColorGradient::operator=( const ColorGradient& other )
{
	Type	= other.Type;
	Start	= other.Start;
	End		= other.End;
	return *this;
}

Bool ColorGradient::operator==( const ColorGradient& other ) const
{
	return (Type == other.Type) && (Start == other.Start) && (End == other.End);
}

Bool ColorGradient::operator!=( const ColorGradient& other ) const
{
	return (Type != other.Type) || (Start != other.Start) || (End != other.End);
}


} // img


} // synkro
