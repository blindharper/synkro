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
// Purpose: Defines stream access mode.
//==============================================================================
#include "config.h"
#include <io/AccessMode.h>
#include <internal/Enum.h>


namespace synkro
{


namespace io
{


SYNKRO_DEFINE_CONST( AccessMode, Default,		0 )
SYNKRO_DEFINE_CONST( AccessMode, Sequential,	1 )
SYNKRO_DEFINE_CONST( AccessMode, Random,		2 )


} // io


} // synkro
