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
// Purpose: Defines base light.
//==============================================================================
#ifndef _SYNKRO_SCENE_BASELIGHT_
#define _SYNKRO_SCENE_BASELIGHT_


#include "config.h"
#include "LightState.h"


namespace synkro
{


namespace scene
{


// Base light.
class BaseLight
{
public:
	virtual void											GetState( LightState& state ) const = 0;
};


// Casts object to BaseLight.
#define AsBaseLight( OBJ ) dynamic_cast<BaseLight*>( OBJ )


} // scene


} // synkro


#endif // _SYNKRO_SCENE_BASELIGHT_
