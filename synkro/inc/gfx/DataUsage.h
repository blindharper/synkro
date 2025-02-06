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
// Purpose: Defines data usage hint.
//==============================================================================
#ifndef _SYNKRO_GFX_DATAUSAGE_
#define _SYNKRO_GFX_DATAUSAGE_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace gfx
{


/**
 * Data usage hint.
 */
SYNKRO_ENUM_BEGIN( DataUsage )
	/** No usage hint. */
	SYNKRO_ENUM_CONST( DataUsage, Default )

	/** Data will be updated just once and used many times. */
	SYNKRO_ENUM_CONST( DataUsage, Static )

	/** Data will be updated periodically and used many times. */
	SYNKRO_ENUM_CONST( DataUsage, Dynamic )

	/** Data will be updated once and used at most a few times. */
	SYNKRO_ENUM_CONST( DataUsage, Stream )
SYNKRO_ENUM_END()


} // gfx


} // synkro


#endif // _SYNKRO_GFX_DATAUSAGE_
