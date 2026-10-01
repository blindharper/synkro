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
// Purpose: Scene rendering object implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_SCENERENDEROBJECT_
#define _SYNKRO_GFX_SCENERENDEROBJECT_


#include "config.h"
#include "SceneRenderObjectImpl.h"
#include <gfx/ISceneRenderObject.h>
#include "BaseSceneRenderObjectImpl.h"
#include "BaseSceneRenderObject.h"


namespace synkro
{


namespace gfx
{


// Scene rendering object implementation.
class SceneRenderObject :
	public SceneRenderObjectImpl<ISceneRenderObject>,
	public BaseSceneRenderObjectImpl<BaseSceneRenderObject>
{
public:
	// Constructor & destructor.
	SceneRenderObject( SceneRenderQueue* queue, IPrimitive* data );
	~SceneRenderObject();
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_SCENERENDEROBJECT_
