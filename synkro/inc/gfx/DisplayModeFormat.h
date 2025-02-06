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
// Purpose: Defines display mode formats.
//==============================================================================
#ifndef _SYNKRO_GFX_DISPLAYMODEFORMAT_
#define _SYNKRO_GFX_DISPLAYMODEFORMAT_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace gfx
{


/**
 * Display mode formats.
 */
SYNKRO_ENUM_BEGIN( DisplayModeFormat )
	/** Dimensions. widthXheight */
	SYNKRO_ENUM_CONST( DisplayModeFormat, Short )
	
	/** Dimensions and color depth. widthXheightXdepth */
	SYNKRO_ENUM_CONST( DisplayModeFormat, Long )
	
	/** Dimensions, color depth and aspect. widthXheightXdepth (w:h) */
	SYNKRO_ENUM_CONST( DisplayModeFormat, Aspect )

	/** Dimensions and color depth with fullscreen/windowed suffix. */
	SYNKRO_ENUM_CONST( DisplayModeFormat, Complete )
SYNKRO_ENUM_END()


} // gfx


} // synkro


#endif // _SYNKRO_GFX_DISPLAYMODEFORMAT_
