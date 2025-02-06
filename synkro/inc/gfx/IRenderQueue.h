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
// Purpose: Defines rendering queue.
//==============================================================================
#ifndef _SYNKRO_GFX_IRENDERQUEUE_
#define _SYNKRO_GFX_IRENDERQUEUE_


#include "config.h"
#include <core/IObject.h>


namespace synkro
{


namespace gfx
{


/**
 * Rendering queue.
 */
iface IRenderQueue :
	public core::IObject
{
public:
	/**
	 * Enables or disables the queue.
	 * @param enable Set to true to enable the queue, set to false to disable it.
	 */
	virtual void											Enable( Bool enable ) = 0;

	/**
	 * Indicates whether the queue is enabled.
	 */
	virtual Bool											IsEnabled() const = 0;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_IRENDERQUEUE_
