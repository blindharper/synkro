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
// Purpose: Defines light source property names.
//==============================================================================
#ifndef _SYNKRO_SCENE_LIGHTPROPERTY_
#define _SYNKRO_SCENE_LIGHTPROPERTY_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace scene
{


// Light source property names.
SYNKRO_ENUM_BEGIN( LightProperty )
	// Diffuse color.
	SYNKRO_ENUM_CONST( LightProperty, DiffuseColor )

	// Ambient color.
	SYNKRO_ENUM_CONST( LightProperty, AmbientColor )

	// Specular color.
	SYNKRO_ENUM_CONST( LightProperty, SpecularColor )

	// Light intensity.
	SYNKRO_ENUM_CONST( LightProperty, Intensity )

	// Light availability.
	SYNKRO_ENUM_CONST( LightProperty, Availability )

	// Converts light property to string.
	lang::String											ToString() const;
SYNKRO_ENUM_END()


} // scene


} // synkro


#endif // _SYNKRO_SCENE_LIGHTPROPERTY_
