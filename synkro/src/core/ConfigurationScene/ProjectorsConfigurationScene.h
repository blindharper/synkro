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
// Purpose: Scene displayed in the configuration editor.
//==============================================================================
#ifndef _SYNKRO_CORE_PROJECTORSCONFIGURATIONSCENE_
#define _SYNKRO_CORE_PROJECTORSCONFIGURATIONSCENE_


#include "config.h"
#include "ConfigurationScene.h"
#include <scene/IConeLight.h>
#include <scene/ITriangleMesh.h>
#include <mat/IOpaqueMaterial.h>


namespace synkro
{


namespace core
{


// Configuration scene.
class ProjectorsConfigurationScene :
	public ConfigurationScene
{
public:
	// Constructor.
	ProjectorsConfigurationScene( ISynkro* synkro );

private:
	P(mat::IOpaqueMaterial)									_material;
	P(scene::ITriangleMesh)									_floor;
	P(scene::INode)											_target;
	P(scene::INode)											_target2;
	P(scene::INode)											_target3;
	P(scene::IConeLight)									_projector;
	P(scene::IConeLight)									_projector2;
	P(scene::IConeLight)									_projector3;
};


} // core


} // synkro


#endif // _SYNKRO_CORE_PROJECTORSCONFIGURATIONSCENE_
