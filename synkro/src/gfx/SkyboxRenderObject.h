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
// Purpose: Skybox rendering object implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_SKYBOXRENDEROBJECT_
#define _SYNKRO_GFX_SKYBOXRENDEROBJECT_


#include "config.h"
#include "SkyRenderObjectImpl.h"
#include <gfx/ISkyRenderObject.h>


namespace synkro
{


namespace gfx
{


// Skybox rendering object implementation.
class SkyboxRenderObject :
	public SkyRenderObjectImpl<ISkyRenderObject>
{
public:
	// Constructor.
	SkyboxRenderObject( IGraphicsSystemEx* graphicsSystem );
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_SKYBOXRENDEROBJECT_
