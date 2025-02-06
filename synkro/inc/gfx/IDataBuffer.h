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
// Purpose: Defines multi-stream data buffer.
//==============================================================================
#ifndef _SYNKRO_GFX_IDATABUFFER_
#define _SYNKRO_GFX_IDATABUFFER_


#include "config.h"
#include <core/IObject.h>
#include <gfx/MapMode.h>


namespace synkro
{


namespace gfx
{


/**
 * Multi-stream data buffer.
 */
iface IDataBuffer :
	public core::IObject
{
public:
	/**
	 * Gets access to buffer data. Call Unmap() to release access.
	 * @param mode Map mode.
	 * @return True, if data were successfully mapped, false otherwise.
	 */
	virtual Bool											Map( const MapMode& mode ) = 0;

	/**
	 * Releases access to buffer data.
	 * @return True, if data were successfully unmapped, false otherwise.
	 */
	virtual Bool											Unmap() = 0;

	/**
	 * Sets new buffer size.
	 * @param count Buffer size, in elements.
	 */
	virtual void											Resize( UInt count ) = 0;

	/**
	 * Sets buffer data. Buffer should be mapped for writing.
	 * @param data Buffer data.
	 * @param size Element size, in bytes.
	 * @param offset Offset from the buffer start, in bytes.
	 * @param start Index of the buffer element at which to start writing data.
	 * @param count Number of elements to write.
	 */
	virtual void											SetData( const Byte* data, UInt size, UInt offset, UInt start, UInt count ) = 0;

	/**
	 * Gets buffer data. Buffer should be mapped for reading.
	 * @param [out] data Destination memory.
	 * @param size Element size, in bytes.
	 * @param offset Offset from the buffer start, in bytes.
	 * @param start Index of the buffer element at which to start reading data.
	 * @param count Number of elements to read.
	 */
	virtual void											GetData( Byte* data, UInt size, UInt offset, UInt start, UInt count ) = 0;

	/**
	 * Retrieves size of the buffer element.
	 */
	virtual UInt											GetStride() const = 0;

	/**
	 * Retrieves the number of buffer elements.
	 */
	virtual UInt											GetSize() const = 0;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_IDATABUFFER_
