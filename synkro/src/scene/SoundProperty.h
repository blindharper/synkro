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
// Purpose: Defines sound source property names.
//==============================================================================
#ifndef _SYNKRO_SCENE_SOUNDPROPERTY_
#define _SYNKRO_SCENE_SOUNDPROPERTY_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace scene
{


// Sound source property names.
SYNKRO_ENUM_BEGIN( SoundProperty )
	// Inner cone volume.
	SYNKRO_ENUM_CONST( SoundProperty, InnerVolume )

	// Outer cone volume.
	SYNKRO_ENUM_CONST( SoundProperty, OuterVolume )

	// Sound availability.
	SYNKRO_ENUM_CONST( SoundProperty, Availability )

	// Converts sound property to string.
	lang::String											ToString() const;
SYNKRO_ENUM_END()


} // scene


} // synkro


#endif // _SYNKRO_SCENE_SOUNDPROPERTY_
