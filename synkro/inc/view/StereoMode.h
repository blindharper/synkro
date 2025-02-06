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
// Purpose: Defines stereo mode.
//==============================================================================
#ifndef _SYNKRO_VIEW_STEREOMODE_
#define _SYNKRO_VIEW_STEREOMODE_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace view
{


/**
 * Stereo picture modes.
 */
SYNKRO_ENUM_BEGIN( StereoMode )
	/** Monoscopic picture. */
	SYNKRO_ENUM_CONST( StereoMode, None )

	/** True stereoscopic picture. Left and right picture channels are generated in sequence. */
	SYNKRO_ENUM_CONST( StereoMode, True )

	/** Left picture channel is stored in red, and right one is stored in green and blue. */
	SYNKRO_ENUM_CONST( StereoMode, RedCyan )

	/** Left picture channel is stored in green, and right one is stored in red and blue. */
	SYNKRO_ENUM_CONST( StereoMode, GreenMagenta )

	/** Left picture channel is stored in blue, and right one is stored in red and green. */
	SYNKRO_ENUM_CONST( StereoMode, BlueYellow )

	/** Right picture channel is stored in red, and left one is stored in green and blue. */
	SYNKRO_ENUM_CONST( StereoMode, CyanRed )

	/** Right picture channel is stored in green, and left one is stored in red and blue. */
	SYNKRO_ENUM_CONST( StereoMode, MagentaGreen )

	/** Right picture channel is stored in blue, and left one is stored in red and green. */
	SYNKRO_ENUM_CONST( StereoMode, YellowBlue )

	/** Creates stereo mode from string. */
	StereoMode( const lang::String& mode );

	/** Converts stereo mode to string. */
	lang::String											ToString() const;
SYNKRO_ENUM_END()


} // view


} // synkro


#endif // _SYNKRO_VIEW_STEREOMODE_
