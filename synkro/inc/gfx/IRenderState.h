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
// Purpose: Defines abstract rendering state.
//==============================================================================
#ifndef _SYNKRO_GFX_IRENDERSTATE_
#define _SYNKRO_GFX_IRENDERSTATE_


#include "config.h"
#include <core/IObject.h>


namespace synkro
{


namespace gfx
{


/**
 * Abstract rendering state.
 */
iface IRenderState :
	public core::IObject
{
public:
	/**
	 * Binds state to the pipeline.
	 */
	virtual void											Bind() = 0;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_IRENDERSTATE_
