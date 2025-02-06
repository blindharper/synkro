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
// Purpose: Defines floating-point value volume.
//==============================================================================
#include "config.h"
#include <lang/Volume.h>


namespace synkro
{


namespace lang
{


Volume::Volume( Float left, Float top, Float _near, Float right, Float bottom, Float _far ) :
	Left( left ),
	Top( top ),
	Near( _near ),
	Right( right ),
	Bottom( bottom ),
	Far( _far )
{
}

Volume::Volume( const Volume& other ) :
	Left( other.Left ),
	Top( other.Top ),
	Near( other.Near ),
	Right( other.Right ),
	Bottom( other.Bottom ),
	Far( other.Far )
{
}

Volume::Volume() :
	Left( 0.0f ),
	Top( 0.0f ),
	Near( 0.0f ),
	Right( 0.0f ),
	Bottom( 0.0f ),
	Far( 0.0f )
{
}

Volume& Volume::Set( Float left, Float top, Float _near, Float right, Float bottom, Float _far )
{
	Left	= left;
	Top		= top;
	Near	= _near;
	Right	= right;
	Bottom	= bottom;
	Far		= _far;
	return *this;
}

Volume& Volume::Inflate( Float  x, Float y, Float z )
{
	return Set( Left-x, Top-y, Near-z, Right+x, Bottom+y, Far+z );
}

Volume& Volume::Deflate( Float  x, Float y, Float z )
{
	return Inflate( -x, -y, -z );
}

Volume& Volume::Empty()
{
	return Set( 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f );
}

Volume& Volume::operator=( const Volume& other )
{
	Left	= other.Left;
	Top		= other.Top;
	Near	= other.Near;
	Right	= other.Right;
	Bottom	= other.Bottom;
	Far		= other.Far;
	return *this;
}

Bool Volume::operator==( const Volume& other ) const
{
	return (Left == other.Left) && (Top == other.Top) && (Near == other.Near) &&
		   (Right == other.Right) && (Bottom == other.Bottom) && (Far == other.Far);
}

Bool Volume::operator!=( const Volume& other ) const
{
	return (Left != other.Left) || (Top != other.Top) || (Near != other.Near) ||
		   (Right != other.Right) || (Bottom != other.Bottom) || (Far != other.Far);;
}

Bool Volume::IsNull() const
{
	return (Left == 0.0f) && (Top == 0.0f) && (Near == 0.0f) &&
		   (Right == 0.0f) && (Bottom == 0.0f) && (Far == 0.0f);
}

Bool Volume::IsEmpty() const
{
	return (Width() == 0.0f) || (Height() == 0.0f) || (Depth() == 0.0f);
}

Float Volume::Width() const
{
	return Right - Left;
}

Float Volume::Height() const
{
	return Top - Bottom;
}

Float Volume::Depth() const
{
	return Far - Near;
}


} // lang


} // synkro
