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
// Purpose: Defines scene factory.
//==============================================================================
#ifndef _SYNKRO_SCENE_ISCENEFACTORY_
#define _SYNKRO_SCENE_ISCENEFACTORY_


#include "config.h"
#include <core/IFactory.h>


namespace synkro
{


namespace scene
{


/**
 * Scene factory.
 */
iface ISceneFactory :
	public core::IFactory
{
public:
	/**
	 * Creates scene.
	 * @param queue Underlying rendering queue.
	 * @param lit Indicates whether the scene is lit.
	 * @return Created scene.
	 */
	virtual IScene*											Create( gfx::ISceneRenderQueue* queue, Bool lit ) = 0;
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_ISCENEFACTORY_
