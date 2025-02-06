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
// Purpose: Defines extended visual primitive.
//==============================================================================
#ifndef _SYNKRO_GFX_IPRIMITIVEEX_
#define _SYNKRO_GFX_IPRIMITIVEEX_


#include "config.h"
#include <gfx/IPrimitive.h>
#include <gfx/DataStream.h>


namespace synkro
{


namespace gfx
{


/**
 * Extended visual primitive.
 */
iface IPrimitiveEx :
	public IPrimitive
{
public:
	/**
	 * Gets vertex stream by type and index.
	 * @param type Stream type.
	 * @param index Stream type index.
	 * @return Requested stream, if one is found or null otherwise.
	 */
	virtual IDataStream*									GetVertexStream( const DataStream& type, UInt index ) const = 0;

	/**
	 * Gets instance stream by type and index.
	 * @param type Stream type.
	 * @param index Stream type index.
	 * @return Requested stream, if one is found or null otherwise.
	 */
	virtual IDataStream*									GetInstanceStream( const DataStream& type, UInt index ) const = 0;

	/**
	 * Gets index stream.
	 * @return Index stream.
	 */
	virtual IDataStream*									GetIndexStream() const = 0;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_IPRIMITIVEEX_
