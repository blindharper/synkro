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
// Purpose: Defines stream system types.
//==============================================================================
#ifndef _SYNKRO_IO_STREAMSYSTEM_
#define _SYNKRO_IO_STREAMSYSTEM_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace io
{


/**
 * Stream system types.
 */
SYNKRO_ENUM_BEGIN( StreamSystem )
	/** Custom stream system. */
	SYNKRO_ENUM_CONST( StreamSystem, Custom )

	/** Win32 stream system. */
	SYNKRO_ENUM_CONST( StreamSystem, Win32 )
SYNKRO_ENUM_END()


} // io


} // synkro


#endif // _SYNKRO_IO_STREAMSYSTEM_
