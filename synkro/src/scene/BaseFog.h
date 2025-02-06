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
// Purpose: Defines base fog.
//==============================================================================
#ifndef _SYNKRO_SCENE_BASEFOG_
#define _SYNKRO_SCENE_BASEFOG_


#include "config.h"
#include "FogState.h"


namespace synkro
{


namespace scene
{


// Base fog.
class BaseFog
{
public:
	virtual void											GetState( FogState& state ) const = 0;
};


// Casts object to BaseFog.
#define AsBaseFog( OBJ ) dynamic_cast<BaseFog*>( OBJ )


} // scene


} // synkro


#endif // _SYNKRO_SCENE_BASEFOG_
