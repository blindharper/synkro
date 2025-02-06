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
// Purpose: Defines log message priority.
//==============================================================================
#ifndef _SYNKRO_DIAG_MESSAGEPRIORITY_
#define _SYNKRO_DIAG_MESSAGEPRIORITY_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace diag
{


/**
 * Log message priority.
 */
SYNKRO_ENUM_BEGIN( MessagePriority )
	/** Lowest priority. */
	SYNKRO_ENUM_CONST( MessagePriority, Lowest )
	
	/** Low priority. */
	SYNKRO_ENUM_CONST( MessagePriority, Low )
	
	/** Below normal priority. */
	SYNKRO_ENUM_CONST( MessagePriority, BelowNormal )
	
	/** Normal priority. */
	SYNKRO_ENUM_CONST( MessagePriority, Normal )
	
	/** Above normal priority. */
	SYNKRO_ENUM_CONST( MessagePriority, AboveNormal )
	
	/** High priority. */
	SYNKRO_ENUM_CONST( MessagePriority, High )
	
	/** Highest priority. */
	SYNKRO_ENUM_CONST( MessagePriority, Highest )
SYNKRO_ENUM_END()


} // diag


} // synkro


#endif // _SYNKRO_DIAG_MESSAGEPRIORITY_
