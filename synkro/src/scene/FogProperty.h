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
// Purpose: Defines fog property names.
//==============================================================================
#ifndef _SYNKRO_SCENE_FOGPROPERTY_
#define _SYNKRO_SCENE_FOGPROPERTY_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace scene
{


// Fog property names.
SYNKRO_ENUM_BEGIN( FogProperty )
	// Fog color.
	SYNKRO_ENUM_CONST( FogProperty, Color )

	// Fog density.
	SYNKRO_ENUM_CONST( FogProperty, Density )

	// Fog start distance.
	SYNKRO_ENUM_CONST( FogProperty, Start )

	// Fog end distance.
	SYNKRO_ENUM_CONST( FogProperty, End )

	// Converts fog property to string.
	lang::String											ToString() const;
SYNKRO_ENUM_END()


} // scene


} // synkro


#endif // _SYNKRO_SCENE_FOGPROPERTY_
