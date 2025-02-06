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
#ifndef _SYNKRO_CORE_POINTMESHCONFIGURATIONSCENE_
#define _SYNKRO_CORE_POINTMESHCONFIGURATIONSCENE_


#include "config.h"
#include "ConfigurationScene.h"
#include <scene/IPointMesh.h>
#include <view/ISimpleFilter.h>
#include <view/IKernel3x3Filter.h>


namespace synkro
{


namespace core
{


// Configuration scene.
class PointMeshConfigurationScene :
	public ConfigurationScene
{
public:
	// Constructor.
	PointMeshConfigurationScene( ISynkro* synkro );

private:
	P(scene::IPointMesh)									_sphere;
	P(view::IKernel3x3Filter)								_blurFilter;
	P(view::ISimpleFilter)									_contrastFilter;
};


} // core


} // synkro


#endif // _SYNKRO_CORE_POINTMESHCONFIGURATIONSCENE_
