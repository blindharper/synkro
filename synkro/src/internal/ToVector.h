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
// Purpose: Vector4 to color convertor.
//==============================================================================
#ifndef _SYNKRO_INTERNAL_TOVECTOR_
#define _SYNKRO_INTERNAL_TOVECTOR_


#include <img/Color.h>
#include <math/Vector4.h>


// Converts color to a 4-component vector.
SYNKRO_INLINE synkro::math::Vector4 ToVector( const synkro::img::Color& color, synkro::Float alpha )
{
	return synkro::math::Vector4( color.R, color.G, color.B, alpha );
}

// Converts color to a 4-component vector.
SYNKRO_INLINE synkro::math::Vector4 ToVector( const synkro::img::Color& color )
{
	return synkro::math::Vector4( color.R, color.G, color.B, 1.0f );
}


#endif // _SYNKRO_INTERNAL_TOVECTOR_
