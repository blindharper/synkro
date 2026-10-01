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
// Purpose: Defines extended scene rendering object.
//==============================================================================
#ifndef _SYNKRO_GFX_ISCENERENDEROBJECTEX_
#define _SYNKRO_GFX_ISCENERENDEROBJECTEX_


#include "config.h"
#include <gfx/ISceneRenderObject.h>


namespace synkro
{


namespace gfx
{


/**
 * Extended scene rendering object.
 */
iface ISceneRenderObjectEx :
	public ISceneRenderObject
{
public:
	/**
	 * Creates rendering object level.
	 * @param data Visual primitive.
	 * @return Extended visual primitive.
	 * @exception BadArgumentException Data is nullptr.
	 */
	virtual IPrimitiveEx*									CreateLevel( IPrimitive* data ) = 0;

	/**
	 * Sets rendered level in the given render view.
	 * @param view Render view.
	 * @param level Rendered level index.
	 */
	virtual void											SetLevel( IRenderView* view, UInt level ) = 0;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_ISCENERENDEROBJECTEX_
