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
// Purpose: Defines memory mapping mode.
//==============================================================================
#ifndef _SYNKRO_GFX_MAPMODE_
#define _SYNKRO_GFX_MAPMODE_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace gfx
{


/**
 * Memory mapping mode.
 */
SYNKRO_ENUM_BEGIN( MapMode )
	/** Maps memory for reading. */
	SYNKRO_ENUM_CONST( MapMode, Read )

	/** Maps memory for writing. */
	SYNKRO_ENUM_CONST( MapMode, Write )
SYNKRO_ENUM_END()


} // gfx


} // synkro


#endif // _SYNKRO_GFX_MAPMODE_
