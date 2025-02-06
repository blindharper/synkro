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
#include "config.h"
#include <diag/LogLevel.h>
#include <internal/Enum.h>


namespace synkro
{


namespace diag
{


SYNKRO_DEFINE_CONST( LogLevel, Quiet,		6 )
SYNKRO_DEFINE_CONST( LogLevel, Minimal,		5 )
SYNKRO_DEFINE_CONST( LogLevel, Limited,		4 )
SYNKRO_DEFINE_CONST( LogLevel, Normal,		3 )
SYNKRO_DEFINE_CONST( LogLevel, Moderate,	2 )
SYNKRO_DEFINE_CONST( LogLevel, Verbose,		1 )
SYNKRO_DEFINE_CONST( LogLevel, Extensive,	0 )


} // diag


} // synkro
