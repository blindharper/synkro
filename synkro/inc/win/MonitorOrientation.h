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
#ifndef _SYNKRO_WIN_MONITORORIENTATION_
#define _SYNKRO_WIN_MONITORORIENTATION_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace win
{


/**
 * Orientation of the monitor.
 */
SYNKRO_ENUM_BEGIN( MonitorOrientation )
	/** Landscape orientation. */
	SYNKRO_ENUM_CONST( MonitorOrientation, Landscape )

	/** Portrait orientation. */
	SYNKRO_ENUM_CONST( MonitorOrientation, Portrait )

	/** Flipped landscape orientation. */
	SYNKRO_ENUM_CONST( MonitorOrientation, LandscapeFlipped )

	/** Flipped portrait orientation. */
	SYNKRO_ENUM_CONST( MonitorOrientation, PortraitFlipped )
SYNKRO_ENUM_END()


} // win


} // synkro


#endif // _SYNKRO_WIN_MONITORORIENTATION_
