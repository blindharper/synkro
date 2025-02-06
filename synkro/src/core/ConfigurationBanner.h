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
// Purpose: Banner displayed in the configuration editor.
//==============================================================================
#ifndef _SYNKRO_CORE_CONFIGURATIONBANNER_
#define _SYNKRO_CORE_CONFIGURATIONBANNER_


#include "config.h"
#include <lang/Ptr.h>
#include <over/IText.h>
#include <gfx/IOverlayRenderObject.h>


namespace synkro
{


namespace core
{


// Configuration scene.
class ConfigurationBanner
{
public:
	// Constructor.
	ConfigurationBanner( ISynkro* synkro );

private:
	ISynkro*												_synkro;
	P(over::IText)											_text;
	P(gfx::IOverlayRenderObject)							_back;
};


} // core


} // synkro


#endif // _SYNKRO_CORE_CONFIGURATIONBANNER_
