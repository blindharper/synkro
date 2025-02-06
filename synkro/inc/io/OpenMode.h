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
// Purpose: Defines stream open mode.
//==============================================================================
#ifndef _SYNKRO_IO_OPENMODE_
#define _SYNKRO_IO_OPENMODE_


#include "config.h"
#include <lang/Flag.h>


namespace synkro
{


namespace io
{


/**
 * Stream open mode.
 */
SYNKRO_FLAG_BEGIN( OpenMode )
	/** Stream is closed. */
	SYNKRO_FLAG_CONST( OpenMode, None )

	/** Open stream for reading. */
	SYNKRO_FLAG_CONST( OpenMode, Read )
	
	/** Open stream for writing, overwriting existing stream content. */
	SYNKRO_FLAG_CONST( OpenMode, Write )
	
	/** Open stream for both reading and writing, preserving existing stream content. */
	SYNKRO_FLAG_CONST( OpenMode, ReadWrite )
	
	/** Append to the end of stream, preserving existing stream content. */
	SYNKRO_FLAG_CONST( OpenMode, Append )
SYNKRO_FLAG_END()


} // io


} // synkro


#endif // _SYNKRO_IO_OPENMODE_
