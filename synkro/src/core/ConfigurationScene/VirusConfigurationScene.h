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
#ifndef _SYNKRO_CORE_VIRUSCONFIGURATIONSCENE_
#define _SYNKRO_CORE_VIRUSCONFIGURATIONSCENE_


#include "config.h"
#include "ConfigurationScene.h"
#include <scene/ITriangleMesh.h>
#include <view/IKernel3x3Filter.h>


namespace synkro
{


namespace core
{


// Configuration scene.
class VirusConfigurationScene :
	public ConfigurationScene
{
public:
	// Constructor.
	VirusConfigurationScene( ISynkro* synkro );

private:
	P(scene::ITriangleMesh)									_virus;
	P(view::IKernel3x3Filter)								_filter;
};


} // core


} // synkro


#endif // _SYNKRO_CORE_VIRUSCONFIGURATIONSCENE_
