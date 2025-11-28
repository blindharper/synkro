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
#ifndef _SYNKRO_CORE_TEAPOTCONFIGURATIONSCENE_
#define _SYNKRO_CORE_TEAPOTCONFIGURATIONSCENE_


#include "config.h"
#include "ConfigurationScene.h"
#include <mat/IOpaqueMaterial.h>
#include <scene/IDirectLight.h>
#include <scene/ITriangleMesh.h>


namespace synkro
{


namespace core
{


// Configuration scene.
class TeapotConfigurationScene :
	public ConfigurationScene
{
public:
	// Constructor.
	TeapotConfigurationScene( ISynkro* synkro );

private:
	P(scene::IDirectLight)									_light;
	P(mat::IOpaqueMaterial)									_material;
	P(scene::ITriangleMesh)									_teapot;

	mat::IOpaqueMaterial*									CreateMaterial( const img::Color& color );
};


} // core


} // synkro


#endif // _SYNKRO_CORE_TEAPOTCONFIGURATIONSCENE_
