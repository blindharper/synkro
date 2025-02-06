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
// Purpose: Defines index data buffer.
//==============================================================================
#ifndef _SYNKRO_GFX_IINDEXBUFFER_
#define _SYNKRO_GFX_IINDEXBUFFER_


#include "config.h"
#include <gfx/IDataBuffer.h>


namespace synkro
{


namespace gfx
{


/**
 * Index data buffer.
 */
iface IIndexBuffer :
	public IDataBuffer
{
public:
	/**
	 * Binds buffer to the pipeline.
	 */
	virtual void											Bind() = 0;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_IINDEXBUFFER_
