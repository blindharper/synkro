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
// Purpose: Defines stream seek origin.
//==============================================================================
#ifndef _SYNKRO_IO_SEEKORIGIN_
#define _SYNKRO_IO_SEEKORIGIN_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace io
{


/**
 * Stream seek origin.
 */
SYNKRO_ENUM_BEGIN( SeekOrigin )
	/** Seek from the beginning of a stream. */
	SYNKRO_ENUM_CONST( SeekOrigin, Start )
	
	/** Seek from the current position in a stream. */
	SYNKRO_ENUM_CONST( SeekOrigin, Current )
	
	/** Seek from the end of a stream. */
	SYNKRO_ENUM_CONST( SeekOrigin, End )
SYNKRO_ENUM_END()


} // io


} // synkro


#endif // _SYNKRO_IO_SEEKORIGIN_
