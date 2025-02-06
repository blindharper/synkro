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
// Purpose: Pyramid mesh builder factory.
//==============================================================================
#ifndef _SYNKRO_SCENE_PYRAMIDMESHBUILDERFACTORY_
#define _SYNKRO_SCENE_PYRAMIDMESHBUILDERFACTORY_


#include "config.h"
#include <core/FactoryImpl.h>
#include <scene/IMeshBuilderFactory.h>
#include <scene/MeshBuilder.h>
#include "PyramidMeshBuilder.h"


namespace synkro
{


namespace scene
{


// Pyramid mesh builder factory.
SYNKRO_FACTORY_BEGIN( PyramidMeshBuilderFactory, IMeshBuilderFactory, MeshBuilder, MeshBuilder::Pyramid )
	IMeshBuilder*	Create() { return new PyramidMeshBuilder(); }
SYNKRO_FACTORY_END()


} // scene


} // synkro


#endif // _SYNKRO_SCENE_PYRAMIDMESHBUILDERFACTORY_
