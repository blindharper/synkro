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
// Purpose: Defines primitive coloring mode.
//==============================================================================
#ifndef _SYNKRO_SCENE_COLORMODE_
#define _SYNKRO_SCENE_COLORMODE_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace scene
{


/**
 * Primitive coloring mode.
 */
SYNKRO_ENUM_BEGIN( ColorMode )
	/** All vertices have the same color. */
	SYNKRO_ENUM_CONST( ColorMode, Monochrome )

	/** Each vertex has its own color. */
	SYNKRO_ENUM_CONST( ColorMode, Colored )
SYNKRO_ENUM_END()


} // scene


} // synkro


#endif // _SYNKRO_SCENE_COLORMODE_
