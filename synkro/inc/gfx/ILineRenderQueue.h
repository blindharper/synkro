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
// Purpose: Defines line rendering queue.
//==============================================================================
#ifndef _SYNKRO_GFX_ILINERENDERQUEUE_
#define _SYNKRO_GFX_ILINERENDERQUEUE_


#include "config.h"
#include <gfx/IRenderQueue.h>


namespace synkro
{


namespace gfx
{


/**
 * Line rendering queue.
 * Used to draw line stuff in 3D.
 */
iface ILineRenderQueue :
	public IRenderQueue
{
public:
	/**
	 * Creates rendering object and adds it to the queue.
	 * @param data Visual primitive.
	 * @return Created rendering object.
	 * @exception BadArgumentException Data is null.
	 */
	virtual ILineRenderObject*								CreateObject( IPrimitive* data ) = 0;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_ILINERENDERQUEUE_
