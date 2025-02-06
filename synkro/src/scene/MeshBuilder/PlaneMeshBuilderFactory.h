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
// Purpose: Plane mesh builder factory.
//==============================================================================
#ifndef _SYNKRO_SCENE_PLANEMESHBUILDERFACTORY_
#define _SYNKRO_SCENE_PLANEMESHBUILDERFACTORY_


#include "config.h"
#include <core/FactoryImpl.h>
#include <scene/IMeshBuilderFactory.h>
#include <scene/MeshBuilder.h>
#include "PlaneMeshBuilder.h"


namespace synkro
{


namespace scene
{


// Plane mesh builder factory.
SYNKRO_FACTORY_BEGIN( PlaneMeshBuilderFactory, IMeshBuilderFactory, MeshBuilder, MeshBuilder::Plane )
	IMeshBuilder*	Create() { return new PlaneMeshBuilder(); }
SYNKRO_FACTORY_END()


} // scene


} // synkro


#endif // _SYNKRO_SCENE_PLANEMESHBUILDERFACTORY_
