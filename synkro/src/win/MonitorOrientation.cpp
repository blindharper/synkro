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
// Purpose: Defines monitor orientation.
//==============================================================================
#include "config.h"
#include <win/MonitorOrientation.h>
#include <internal/Enum.h>


namespace synkro
{


namespace win
{


SYNKRO_DEFINE_CONST( MonitorOrientation, Landscape,			0 )
SYNKRO_DEFINE_CONST( MonitorOrientation, Portrait,			1 )
SYNKRO_DEFINE_CONST( MonitorOrientation, LandscapeFlipped,	2 )
SYNKRO_DEFINE_CONST( MonitorOrientation, PortraitFlipped,	3 )


} // win


} // synkro
