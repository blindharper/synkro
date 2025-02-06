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
// Purpose: Defines stream directory types.
//==============================================================================
#ifndef _SYNKRO_IO_STREAMDIRECTORY_
#define _SYNKRO_IO_STREAMDIRECTORY_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace io
{


/**
 * Stream directory types.
 */
SYNKRO_ENUM_BEGIN( StreamDirectory )
	/** Custom stream directory. */
	SYNKRO_ENUM_CONST( StreamDirectory, Custom )

	/** Zip stream directory. */
	SYNKRO_ENUM_CONST( StreamDirectory, Zip )

	/** Converts stream directory type to string. */
	lang::String											ToString() const;
SYNKRO_ENUM_END()


} // io


} // synkro


#endif // _SYNKRO_IO_STREAMDIRECTORY_
