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
// Purpose: Defines abstract data stream.
//==============================================================================
#ifndef _SYNKRO_GFX_IDATASTREAM_
#define _SYNKRO_GFX_IDATASTREAM_


#include "config.h"
#include <core/IObject.h>
#include <io/OpenMode.h>
#include <gfx/DataStream.h>


namespace synkro
{


namespace gfx
{


/**
 * Abstract data stream.
 */
iface IDataStream :
	public core::IObject
{
public:
	/**
	 * Opens stream with the specified access type.
	 * @param mode Stream open mode.
	 * @return True, if stream was successfully opened, false otherwise.
	 */
	virtual Bool											Open( const io::OpenMode& mode ) = 0;

	/**
	 * Releases access to stream.
	 */
	virtual void											Close() = 0;

	/**
	 * Sets stream pointer to the given item.
	 * @param position Zero-based item index.
	 * @exception GraphicsException Stream is not open.
	 */
	virtual void											SetPosition( UInt position ) = 0;

	/**
	 * Retrieves current stream position, in items.
	 */
	virtual UInt											GetPosition() const = 0;

	/**
	 * Retrieves stream length, in items.
	 */
	virtual UInt											GetLength() const = 0;

	/**
	 * Retrieves stream type.
	 */
	virtual DataStream										GetType() const = 0;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_IDATASTREAM_
