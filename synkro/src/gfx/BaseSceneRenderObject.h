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
// Purpose: Base scene render object.
//==============================================================================
#ifndef _SYNKRO_GFX_BASESCENERENDEROBJECT_
#define _SYNKRO_GFX_BASESCENERENDEROBJECT_


#include "config.h"
#include <lang/String.h>


namespace synkro
{


namespace gfx
{


// Base scene render object.
class BaseSceneRenderObject
{
public:
	// Sets object's keys in the rendering queue.
	virtual void											SetKeys( const lang::String& resourceKey, const lang::String& dataKey, const lang::String& instanceKey ) = 0;

	// Returns resource key.
	virtual lang::String									GetResourceKey() const = 0;

	// Returns data key.
	virtual lang::String									GetDataKey() const = 0;

	// Returns instance key.
	virtual lang::String									GetInstanceKey() const = 0;
};


// Casts object to BaseSceneRenderObject.
#define AsBaseSceneRenderObject( OBJ ) dynamic_cast<BaseSceneRenderObject*>( OBJ )


} // gfx


} // synkro


#endif // _SYNKRO_GFX_BASESCENERENDEROBJECT_
