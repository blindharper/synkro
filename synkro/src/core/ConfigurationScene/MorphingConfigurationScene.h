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
#ifndef _SYNKRO_CORE_MORPHINGCONFIGURATIONSCENE_
#define _SYNKRO_CORE_MORPHINGCONFIGURATIONSCENE_


#include "config.h"
#include "ConfigurationScene.h"
#include <scene/ILineMesh.h>
#include <view/ISimpleFilter.h>
#include <view/IKernel3x3Filter.h>


namespace synkro
{


namespace core
{


// Configuration scene.
class MorphingConfigurationScene :
	public ConfigurationScene
{
public:
	// Constructor.
	MorphingConfigurationScene( ISynkro* synkro );

private:
	P(scene::ILineMesh)										_mesh;
	P(scene::ILineMesh)										_sphere;
	P(scene::ILineMesh)										_torus;
	P(scene::ILineMesh)										_cylinder;
	P(scene::ILineMesh)										_cone;

	P(view::IKernel3x3Filter)								_blurFilter;
	P(view::ISimpleFilter)									_contrastFilter;
};


} // core


} // synkro


#endif // _SYNKRO_CORE_MORPHINGCONFIGURATIONSCENE_
