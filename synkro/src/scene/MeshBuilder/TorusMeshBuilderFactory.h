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
// Purpose: Torus mesh builder factory.
//==============================================================================
#ifndef _SYNKRO_SCENE_TORUSMESHBUILDERFACTORY_
#define _SYNKRO_SCENE_TORUSMESHBUILDERFACTORY_


#include "config.h"
#include <core/FactoryImpl.h>
#include <scene/IMeshBuilderFactory.h>
#include <scene/MeshBuilder.h>
#include "TorusMeshBuilder.h"


namespace synkro
{


namespace scene
{


// Torus mesh builder factory.
SYNKRO_FACTORY_BEGIN( TorusMeshBuilderFactory, IMeshBuilderFactory, MeshBuilder, MeshBuilder::Torus )
	IMeshBuilder*	Create() { return new TorusMeshBuilder(); }
SYNKRO_FACTORY_END()


} // scene


} // synkro


#endif // _SYNKRO_SCENE_TORUSMESHBUILDERFACTORY_
