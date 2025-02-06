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
// Purpose: Defines structured buffer resource.
//==============================================================================
#ifndef _SYNKRO_GFX_ISTRUCTUREDBUFFER_
#define _SYNKRO_GFX_ISTRUCTUREDBUFFER_


#include "config.h"
#include <gfx/IBuffer.h>


namespace synkro
{


namespace gfx
{


/**
 * Structured buffer resource.
 */
iface IStructuredBuffer :
	public IBuffer
{
public:
	/**
	 * Sets an array of structures.
	 * @param value Pointer to the first element's data.
	 * @param size Total array size, in bytes.
	 */
	virtual void											Set( const Byte* value, UInt size ) = 0;

	/**
	 * Retrieves size of the buffer element.
	 */
	virtual UInt											GetStride() const = 0;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_ISTRUCTUREDBUFFER_
