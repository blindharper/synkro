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
// Purpose: Defines base camera.
//==============================================================================
#ifndef _SYNKRO_SCENE_BASECAMERA_
#define _SYNKRO_SCENE_BASECAMERA_


#include "config.h"


namespace synkro
{


namespace scene
{


// Base camera.
class BaseCamera
{
public:
	virtual void											Activate() = 0;
};


// Casts object to BaseCamera.
#define AsBaseCamera( OBJ ) dynamic_cast<BaseCamera*>( OBJ )


} // scene


} // synkro


#endif // _SYNKRO_SCENE_BASECAMERA_
