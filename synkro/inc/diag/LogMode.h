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
// Purpose: Defines logging mode.
//==============================================================================
#ifndef _SYNKRO_DIAG_LOGMODE_
#define _SYNKRO_DIAG_LOGMODE_


#include "config.h"
#include <lang/Flag.h>


namespace synkro
{


namespace diag
{


/**
 * Logging mode. Determines which types of messages are sent to the log.
 */
SYNKRO_FLAG_BEGIN( LogMode )
	/** Allow logging informational messages. */
	SYNKRO_FLAG_CONST( LogMode, Info )
	
	/** Allow logging warnings. */
	SYNKRO_FLAG_CONST( LogMode, Warning )
	
	/** Allow logging errors. */
	SYNKRO_FLAG_CONST( LogMode, Error )
	
	/** Allow log everything. */
	SYNKRO_FLAG_CONST( LogMode, All )
SYNKRO_FLAG_END()


} // diag


} // synkro


#endif // _SYNKRO_DIAG_LOGMODE_
