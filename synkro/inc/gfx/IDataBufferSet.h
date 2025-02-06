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
// Purpose: Defines data buffer set.
//==============================================================================
#ifndef _SYNKRO_GFX_IDATABUFFERSET_
#define _SYNKRO_GFX_IDATABUFFERSET_


#include "config.h"
#include <core/IObject.h>


namespace synkro
{


namespace gfx
{


/**
 * Collection of data buffers.
 */
iface IDataBufferSet :
	public core::IObject
{
public:
	/**
	 * Binds buffers to the pipeline.
	 */
	virtual void											Bind() = 0;

	/**
	 * Retrieves the total number of buffers in the set.
	 */
	virtual UInt											GetSize() const = 0;

	/**
	 * Retrieves buffer by index.
	 * @param index Buffer index.
	 * @return Requested buffer.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual IDataBuffer*									Get( UInt index ) const = 0;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_IDATABUFFERSET_
