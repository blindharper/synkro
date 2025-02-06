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
// Purpose: Defines extended data buffer format.
//==============================================================================
#ifndef _SYNKRO_GFX_IDATAFORMATEX_
#define _SYNKRO_GFX_IDATAFORMATEX_


#include "config.h"
#include <gfx/IDataFormat.h>


namespace synkro
{


namespace gfx
{


/**
 * Extended data buffer format.
 */
iface IDataFormatEx :
	public IDataFormat
{
public:
	/**
	 * Adds vertex stream.
	 * @param type Stream type.
	 * @param dataType Stream data type.
	 */
	virtual void											AddVertexStream( const DataStream& type, const ProgramDataType& dataType ) = 0;

	/**
	 * Adds instance stream.
	 * @param type Stream type.
	 * @param dataType Stream data type.
	 */
	virtual void											AddInstanceStream( const DataStream& type, const ProgramDataType& dataType ) = 0;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_IDATAFORMATEX_
