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
// Purpose: Defines scene node property names.
//==============================================================================
#ifndef _SYNKRO_SCENE_NODEPROPERTY_
#define _SYNKRO_SCENE_NODEPROPERTY_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace scene
{


// Scene node property names.
SYNKRO_ENUM_BEGIN( NodeProperty )
	// Node transformation.
	SYNKRO_ENUM_CONST( NodeProperty, Transform )

	// Node position.
	SYNKRO_ENUM_CONST( NodeProperty, Position )

	// Node position's X coordinate.
	SYNKRO_ENUM_CONST( NodeProperty, PositionX )

	// Node position's Y coordinate.
	SYNKRO_ENUM_CONST( NodeProperty, PositionY )

	// Node position's Z coordinate.
	SYNKRO_ENUM_CONST( NodeProperty, PositionZ )

	// Node orientation.
	SYNKRO_ENUM_CONST( NodeProperty, Orientation )

	// Yaw angle, in radians.
	SYNKRO_ENUM_CONST( NodeProperty, OrientationYaw )

	// Pitch angle, in radians.
	SYNKRO_ENUM_CONST( NodeProperty, OrientationPitch )

	// Roll angle, in radians.
	SYNKRO_ENUM_CONST( NodeProperty, OrientationRoll )

	// Node scale.
	SYNKRO_ENUM_CONST( NodeProperty, Scale )

	// Node scale along X axis.
	SYNKRO_ENUM_CONST( NodeProperty, ScaleX )

	// Node scale along Y axis.
	SYNKRO_ENUM_CONST( NodeProperty, ScaleY )

	// Node scale along Z axis.
	SYNKRO_ENUM_CONST( NodeProperty, ScaleZ )

	// Uniform node scale.
	SYNKRO_ENUM_CONST( NodeProperty, ScaleUniform )

	// Node path phase.
	SYNKRO_ENUM_CONST( NodeProperty, PathPhase )

	// Converts node property to string.
	lang::String											ToString() const;
SYNKRO_ENUM_END()


} // scene


} // synkro


#endif // _SYNKRO_SCENE_NODEPROPERTY_
