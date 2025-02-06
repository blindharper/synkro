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
#ifndef _SYNKRO_CORE_CONFIGURATIONSCENE_
#define _SYNKRO_CORE_CONFIGURATIONSCENE_


#include "config.h"
#include <lang/Ptr.h>
#include <math/Math.h>
#include <core/ISynkro.h>
#include <scene/ISceneEx.h>
#include <scene/ICamera.h>
#include <view/IViewport.h>


namespace synkro
{


namespace core
{


// Scene displayed in the configuration editor.
class ConfigurationScene
{
public:
	// Constructor.
	ConfigurationScene( ISynkro* synkro, Bool lit );

protected:
	ISynkro*												_synkro;
	P(scene::ISceneEx)										_scene;
	P(scene::ICamera)										_camera;
	P(view::IViewport)										_viewport;
};


} // core


} // synkro


#endif // _SYNKRO_CORE_CONFIGURATIONSCENE_
