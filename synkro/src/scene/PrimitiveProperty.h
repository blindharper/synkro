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
// Purpose: Defines geometric primitive property names.
//==============================================================================
#ifndef _SYNKRO_SCENE_PRIMITIVEPROPERTY_
#define _SYNKRO_SCENE_PRIMITIVEPROPERTY_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace scene
{


// Geometric primitive property names.
SYNKRO_ENUM_BEGIN( PrimitiveProperty )
	// Primitive transformation.
	SYNKRO_ENUM_CONST( PrimitiveProperty, Transform )

	// Primitive orientation.
	SYNKRO_ENUM_CONST( PrimitiveProperty, Orientation )

	// Yaw angle, in radians.
	SYNKRO_ENUM_CONST( PrimitiveProperty, OrientationYaw )

	// Pitch angle, in radians.
	SYNKRO_ENUM_CONST( PrimitiveProperty, OrientationPitch )

	// Roll angle, in radians.
	SYNKRO_ENUM_CONST( PrimitiveProperty, OrientationRoll )

	// Primitive element range.
	SYNKRO_ENUM_CONST( PrimitiveProperty, ElementRange )

	// Converts primitive property to string.
	lang::String											ToString() const;
SYNKRO_ENUM_END()


} // scene


} // synkro


#endif // _SYNKRO_SCENE_PRIMITIVEPROPERTY_
