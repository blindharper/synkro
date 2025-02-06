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
// Purpose: Defines data type.
//==============================================================================
#ifndef _SYNKRO_LANG_DATATYPE_
#define _SYNKRO_LANG_DATATYPE_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace lang
{


/**
 * Data types.
 */
SYNKRO_ENUM_BEGIN( DataType )
	/** No data. */
	SYNKRO_ENUM_CONST( DataType, Unknown )

	/** Integer data. */
	SYNKRO_ENUM_CONST( DataType, Integer )

	/** Floating-point data. */
	SYNKRO_ENUM_CONST( DataType, Float )
	
	/** String data. */
	SYNKRO_ENUM_CONST( DataType, String )

	/** Date & time data. */
	SYNKRO_ENUM_CONST( DataType, DateTime )

	/** BLOB data. */
	SYNKRO_ENUM_CONST( DataType, Blob )
SYNKRO_ENUM_END()


} // lang


} // synkro


#endif // _SYNKRO_LANG_DATATYPE_
