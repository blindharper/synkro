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
// Purpose: Defines stream access mode.
//==============================================================================
#ifndef _SYNKRO_IO_ACCESSMODE_
#define _SYNKRO_IO_ACCESSMODE_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace io
{


/**
 * Stream access mode.
 */
SYNKRO_ENUM_BEGIN( AccessMode )
	/** No optimization is made. */
	SYNKRO_ENUM_CONST( AccessMode, Default )
	
	/** Stream is optimized for sequential access. */
	SYNKRO_ENUM_CONST( AccessMode, Sequential )
	
	/** Stream is optimized for random access. */
	SYNKRO_ENUM_CONST( AccessMode, Random )
SYNKRO_ENUM_END()


} // io


} // synkro


#endif // _SYNKRO_IO_ACCESSMODE_
