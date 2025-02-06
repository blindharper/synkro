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
// Purpose: Defines scene property names.
//==============================================================================
#ifndef _SYNKRO_SCENE_SCENEPROPERTY_
#define _SYNKRO_SCENE_SCENEPROPERTY_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace scene
{


// Scene property names.
SYNKRO_ENUM_BEGIN( SceneProperty )
	// Ambient light color.
	SYNKRO_ENUM_CONST( SceneProperty, AmbientLightColor )

	// Ambient light intensity.
	SYNKRO_ENUM_CONST( SceneProperty, AmbientLightIntensity )

	// Converts scene property to string.
	lang::String											ToString() const;
SYNKRO_ENUM_END()


} // scene


} // synkro


#endif // _SYNKRO_SCENE_SCENEPROPERTY_
