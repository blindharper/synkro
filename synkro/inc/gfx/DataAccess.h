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
// Purpose: Defines data access mode.
//==============================================================================
#ifndef _SYNKRO_GFX_DATAACCESS_
#define _SYNKRO_GFX_DATAACCESS_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace gfx
{


/**
 * Data access mode.
 */
SYNKRO_ENUM_BEGIN( DataAccess )
	/** Write only access. */
	SYNKRO_ENUM_CONST( DataAccess, WriteOnly )

	/** Read-write access. */
	SYNKRO_ENUM_CONST( DataAccess, ReadWrite )
SYNKRO_ENUM_END()


} // gfx


} // synkro


#endif // _SYNKRO_GFX_DATAACCESS_
