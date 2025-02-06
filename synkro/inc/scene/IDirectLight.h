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
// Purpose: Defines direct light node.
//==============================================================================
#ifndef _SYNKRO_SCENE_IDIRECTLIGHT_
#define _SYNKRO_SCENE_IDIRECTLIGHT_


#include "config.h"
#include <scene/ILight.h>


namespace synkro
{


namespace scene
{


/**
 * Direct light node.
 */
iface IDirectLight :
	public ILight
{
public:
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_IDIRECTLIGHT_
