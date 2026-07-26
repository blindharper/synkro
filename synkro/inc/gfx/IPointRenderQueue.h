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
// Purpose: Defines point rendering queue.
//==============================================================================
#ifndef _SYNKRO_GFX_IPOINTRENDERQUEUE_
#define _SYNKRO_GFX_IPOINTRENDERQUEUE_


#include "config.h"
#include <gfx/IRenderQueue.h>


namespace synkro
{


namespace gfx
{


/**
 * Point rendering queue.
 * Used to draw point stuff in 3D.
 */
iface IPointRenderQueue :
	public IRenderQueue
{
public:
	/**
	 * Creates rendering object and adds it to the queue.
	 * @param data Visual primitive.
	 * @return Created rendering object.
	 * @exception BadArgumentException Data is null.
	 */
	virtual IPointRenderObject*								CreateObject( IPrimitive* data ) = 0;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_IPOINTRENDERQUEUE_
