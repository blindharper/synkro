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
#ifndef _SYNKRO_INTERNAL_TOCOLOR_
#define _SYNKRO_INTERNAL_TOCOLOR_


#include <img/Color.h>
#include <math/Vector4.h>


// Converts 4-component vector to a color.
SYNKRO_INLINE synkro::img::Color ToColor( const synkro::math::Vector4& vec )
{
	return synkro::img::Color( vec.x, vec.y, vec.z );
}


#endif // _SYNKRO_INTERNAL_TOCOLOR_
