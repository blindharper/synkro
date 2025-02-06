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
// Purpose: Defines logging level.
//==============================================================================
#ifndef _SYNKRO_DIAG_LOGLEVEL_
#define _SYNKRO_DIAG_LOGLEVEL_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace diag
{


/**
 * Logging level. Determines how detailed the log is.
 */
SYNKRO_ENUM_BEGIN( LogLevel )
	/** Quiet logging. */
	SYNKRO_ENUM_CONST( LogLevel, Quiet )
	
	/** Minimal logging. */
	SYNKRO_ENUM_CONST( LogLevel, Minimal )

	/** Limited logging. */
	SYNKRO_ENUM_CONST( LogLevel, Limited )
	
	/** Normal logging. */
	SYNKRO_ENUM_CONST( LogLevel, Normal )
	
	/** Moderate logging. */
	SYNKRO_ENUM_CONST( LogLevel, Moderate )

	/** Verbose logging. */
	SYNKRO_ENUM_CONST( LogLevel, Verbose )

	/** Extensive logging. */
	SYNKRO_ENUM_CONST( LogLevel, Extensive )
SYNKRO_ENUM_END()


} // diag


} // synkro


#endif // _SYNKRO_DIAG_LOGLEVEL_
