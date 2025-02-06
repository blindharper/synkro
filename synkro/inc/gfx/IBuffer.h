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
// Purpose: Defines buffer resource.
//==============================================================================
#ifndef _SYNKRO_GFX_IBUFFER_
#define _SYNKRO_GFX_IBUFFER_


#include "config.h"
#include <gfx/IResource.h>


namespace synkro
{


namespace gfx
{


/**
 * Buffer resource.
 */
iface IBuffer :
	public IResource
{
public:
	/**
	 * Retrieves the number of buffer elements.
	 */
	virtual UInt											GetSize() const = 0;

	/**
	 * Casts resource to typed buffer.
	 * @return Non-null for typed buffer resource, nullptr otherwise.
	 */
	virtual ITypedBuffer*									AsTyped() const = 0;
	
	/**
	 * Casts resource to structured buffer.
	 * @return Non-null for structured buffer resource, nullptr otherwise.
	 */
	virtual IStructuredBuffer*								AsStructured() const = 0;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_IBUFFER_
