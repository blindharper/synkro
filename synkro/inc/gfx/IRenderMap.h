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
// Purpose: Defines abstract rendering map.
//==============================================================================
#ifndef _SYNKRO_GFX_IRENDERMAP_
#define _SYNKRO_GFX_IRENDERMAP_


#include "config.h"
#include <core/IObject.h>


namespace synkro
{


namespace gfx
{


/**
 * Abstract rendering map.
 */
iface IRenderMap :
	public core::IObject
{
public:
	/** 
	 * Sets scene's vertex program parameters.
	 * @param params Program parameters.
	 */
	virtual void											SetVertexParams( IParameterSet* params ) = 0;

	/** 
	 * Retrieves scene's vertex program parameters.
	 */
	virtual IParameterSet*									GetVertexParams() const = 0;

	/**
	 * Retrieves underlying rendering queue.
	 */
	virtual IRenderQueue*									GetQueue() const = 0;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_IRENDERMAP_
