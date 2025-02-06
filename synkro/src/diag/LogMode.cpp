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
#include "config.h"
#include <diag/LogMode.h>
#include <internal/Enum.h>


namespace synkro
{


namespace diag
{


SYNKRO_DEFINE_CONST( LogMode, Info,		0x01 )
SYNKRO_DEFINE_CONST( LogMode, Warning,	0x02 )
SYNKRO_DEFINE_CONST( LogMode, Error,	0x04 )
SYNKRO_DEFINE_CONST( LogMode, All,		0x07 )


} // diag


} // synkro
