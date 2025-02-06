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
// Purpose: Defines long value stream.
//==============================================================================
#ifndef _SYNKRO_GFX_ILONGSTREAM_
#define _SYNKRO_GFX_ILONGSTREAM_


#include "config.h"
#include <gfx/IDataStream.h>


namespace synkro
{


namespace gfx
{


/**
 * Long value stream.
 */
iface ILongStream :
	public IDataStream
{
public:
	/**
	 * Reads data from the stream. Stream should be open for reading.
	 * @param [out] data Memory where to read stream data.
	 * @param count Number of items to read.
	 */
	virtual void											Read( UInt* data, UInt count ) = 0;

	/**
	 * Writes data to the stream. Stream should be open for writing.
	 * @param data Stream data source.
	 * @param count Number of items to write.
	 */
	virtual void											Write( const UInt* data, UInt count ) = 0;

	/**
	 * Sets stream items to given value. Stream should be open for writing.
	 * @param value New item value.
	 * @param count Number of items to write.
	 */
	virtual void											Set( const UInt& value, UInt count ) = 0;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_ILONGSTREAM_
