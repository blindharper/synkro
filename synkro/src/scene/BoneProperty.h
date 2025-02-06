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
// Purpose: Defines skeleton bone property names.
//==============================================================================
#ifndef _SYNKRO_SCENE_BONEPROPERTY_
#define _SYNKRO_SCENE_BONEPROPERTY_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace scene
{


// Skeleton bone property names.
SYNKRO_ENUM_BEGIN( BoneProperty )
	// Bone transformation.
	SYNKRO_ENUM_CONST( BoneProperty, Transform )

	// Bone position.
	SYNKRO_ENUM_CONST( BoneProperty, Position )

	// Bone orientation.
	SYNKRO_ENUM_CONST( BoneProperty, Orientation )

	// Bone scale.
	SYNKRO_ENUM_CONST( BoneProperty, Scale )

	// Converts bone property to string.
	lang::String											ToString() const;
SYNKRO_ENUM_END()


} // scene


} // synkro


#endif // _SYNKRO_SCENE_BONEPROPERTY_
