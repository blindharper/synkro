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
// Purpose: Defines omni light source property names.
//==============================================================================
#ifndef _SYNKRO_SCENE_OMNILIGHTPROPERTY_
#define _SYNKRO_SCENE_OMNILIGHTPROPERTY_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace scene
{


// Omni light source property names.
SYNKRO_ENUM_BEGIN( OmniLightProperty )
	// Light range.
	SYNKRO_ENUM_CONST( OmniLightProperty, Range )

	// Converts property to string.
	lang::String											ToString() const;
SYNKRO_ENUM_END()


} // scene


} // synkro


#endif // _SYNKRO_SCENE_OMNILIGHTPROPERTY_
