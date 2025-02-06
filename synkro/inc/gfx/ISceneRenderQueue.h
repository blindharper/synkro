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
// Purpose: Defines scene rendering queue.
//==============================================================================
#ifndef _SYNKRO_GFX_ISCENERENDERQUEUE_
#define _SYNKRO_GFX_ISCENERENDERQUEUE_


#include "config.h"
#include <gfx/IRenderQueue.h>


namespace synkro
{


namespace gfx
{


/**
 * Scene rendering queue.
 */
iface ISceneRenderQueue :
	public IRenderQueue
{
public:
	/**
	 * Creates rendering object and adds it to the queue.
	 * @param data Visual primitive.
	 * @param occluder Indicates whether the primitive will occlude other primitives.
	 * @return Created rendering object.
	 * @exception BadArgumentException Data is null.
	 */
	virtual ISceneRenderObject*								CreateObject( IPrimitive* data, Bool occluder ) = 0;

	/**
	 * Creates sky sphere rendering object and adds it to the queue.
	 * @param radius Sphere radius.
	 * @return Created sky sphere object.
	 */
	virtual ISkyRenderObject*								CreateSkysphereObject( Float radius ) = 0;

	/**
	 * Creates skybox rendering object and adds it to the queue.
	 * @return Created skybox object.
	 */
	virtual ISkyRenderObject*								CreateSkyboxObject() = 0;

	/**
	 * Retrieves line rendering queue.
	 */
	virtual ILineRenderQueue*								GetLineQueue() const = 0;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_ISCENERENDERQUEUE_
