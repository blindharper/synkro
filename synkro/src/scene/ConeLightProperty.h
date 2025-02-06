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
// Purpose: Defines cone light source property names.
//==============================================================================
#ifndef _SYNKRO_SCENE_CONELIGHTPROPERTY_
#define _SYNKRO_SCENE_CONELIGHTPROPERTY_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace scene
{


// Cone light source property names.
SYNKRO_ENUM_BEGIN( ConeLightProperty )
	// Light range.
	SYNKRO_ENUM_CONST( ConeLightProperty, Range )

	// Inner angle.
	SYNKRO_ENUM_CONST( ConeLightProperty, InnerAngle )

	// Outer angle.
	SYNKRO_ENUM_CONST( ConeLightProperty, OuterAngle )

	// Falloff.
	SYNKRO_ENUM_CONST( ConeLightProperty, Falloff )

	// Converts property to string.
	lang::String											ToString() const;
SYNKRO_ENUM_END()


} // scene


} // synkro


#endif // _SYNKRO_SCENE_CONELIGHTPROPERTY_
