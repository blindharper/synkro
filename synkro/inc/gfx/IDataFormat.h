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
// Purpose: Defines data buffer format.
//==============================================================================
#ifndef _SYNKRO_GFX_IDATAFORMAT_
#define _SYNKRO_GFX_IDATAFORMAT_


#include "config.h"
#include <core/IObject.h>
#include <lang/String.h>
#include <gfx/DataStream.h>
#include <gfx/ProgramDataType.h>


namespace synkro
{


namespace gfx
{


/**
 * Data buffer format.
 */
iface IDataFormat :
	public core::IObject
{
public:
	/**
	 * Retrieves the total number of vertex streams in the buffer.
	 */
	virtual UInt											GetVertexStreamCount() const = 0;

	/**
	 * Retrieves vertex stream type.
	 * @param index Stream index.
	 * @return Requested stream name.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual DataStream										GetVertexStreamType( UInt index ) const = 0;

	/**
	 * Retrieves vertex stream type.
	 * @param index Stream index.
	 * @return Requested stream data type.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual ProgramDataType									GetVertexStreamDataType( UInt index ) const = 0;

	/**
	 * Retrieves the total number of instance streams in the buffer.
	 */
	virtual UInt											GetInstanceStreamCount() const = 0;

	/**
	 * Retrieves instance stream type.
	 * @param index Stream index.
	 * @return Requested stream name.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual DataStream										GetInstanceStreamType( UInt index ) const = 0;

	/**
	 * Retrieves instance stream type.
	 * @param index Stream index.
	 * @return Requested stream data type.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual ProgramDataType									GetInstanceStreamDataType( UInt index ) const = 0;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_IDATAFORMAT_
