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
// Purpose: Default scene factory.
//==============================================================================
#ifndef _SYNKRO_SCENE_DEFAULTSCENEFACTORY_
#define _SYNKRO_SCENE_DEFAULTSCENEFACTORY_


#include "config.h"
#include <core/FactoryImpl.h>
#include <scene/ISceneFactory.h>
#include <scene/SceneType.h>
#include "DefaultScene.h"


namespace synkro
{


namespace scene
{


// Default scene factory.
SYNKRO_FACTORY_BEGIN( DefaultSceneFactory, ISceneFactory, Scene, SceneType::Default )
	IScene*	Create( gfx::ISceneRenderQueue* queue, Bool lit ) { return new DefaultScene(queue, lit); }
SYNKRO_FACTORY_END()


} // scene


} // synkro


#endif // _SYNKRO_SCENE_DEFAULTSCENEFACTORY_
