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
#include "config.h"
#include <diag/MessagePriority.h>
#include <internal/Enum.h>


namespace synkro
{


namespace diag
{


SYNKRO_DEFINE_CONST( MessagePriority, Lowest,		0 )
SYNKRO_DEFINE_CONST( MessagePriority, Low,			1 )
SYNKRO_DEFINE_CONST( MessagePriority, BelowNormal,	2 )
SYNKRO_DEFINE_CONST( MessagePriority, Normal,		3 )
SYNKRO_DEFINE_CONST( MessagePriority, AboveNormal,	4 )
SYNKRO_DEFINE_CONST( MessagePriority, High,			5 )
SYNKRO_DEFINE_CONST( MessagePriority, Highest,		6 )


} // diag


} // synkro
