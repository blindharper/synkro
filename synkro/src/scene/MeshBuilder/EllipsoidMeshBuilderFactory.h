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
// Purpose: Ellispoid mesh builder factory.
//==============================================================================
#ifndef _SYNKRO_SCENE_ELLIPSOIDMESHBUILDERFACTORY_
#define _SYNKRO_SCENE_ELLIPSOIDMESHBUILDERFACTORY_


#include "config.h"
#include <core/FactoryImpl.h>
#include <scene/IMeshBuilderFactory.h>
#include <scene/MeshBuilder.h>
#include "EllipsoidMeshBuilder.h"


namespace synkro
{


namespace scene
{


// Ellispoid mesh builder factory.
SYNKRO_FACTORY_BEGIN( EllipsoidMeshBuilderFactory, IMeshBuilderFactory, MeshBuilder, MeshBuilder::Ellipsoid )
	IMeshBuilder*	Create() { return new EllipsoidMeshBuilder(); }
SYNKRO_FACTORY_END()


} // scene


} // synkro


#endif // _SYNKRO_SCENE_ELLIPSOIDMESHBUILDERFACTORY_
