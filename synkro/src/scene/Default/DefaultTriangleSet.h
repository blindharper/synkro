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
// Purpose: Implements default triangle set.
//==============================================================================
#ifndef _SYNKRO_SCENE_DEFAULTTRIANGLESET_
#define _SYNKRO_SCENE_DEFAULTTRIANGLESET_


#include "config.h"
#include <scene/TriangleSetImpl.h>
#include <scene/ITriangleSet.h>


namespace synkro
{


namespace scene
{


// Default triangle set implementation.
class DefaultTriangleSet :
	public TriangleSetImpl<ITriangleSet>
{
public:
	// Constructor.
	DefaultTriangleSet( gfx::ISceneRenderObject* object, UInt start, UInt count );
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_DEFAULTTRIANGLESET_
