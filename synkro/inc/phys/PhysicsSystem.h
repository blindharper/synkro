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
// Purpose: Defines physics system types.
//==============================================================================
#ifndef _SYNKRO_PHYS_PHYSICSSYSTEM_
#define _SYNKRO_PHYS_PHYSICSSYSTEM_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace phys
{


/**
 * Physics system types.
 */
SYNKRO_ENUM_BEGIN( PhysicsSystem )
	/** Custom physics system. */
	SYNKRO_ENUM_CONST( PhysicsSystem, Custom )

	/** PhysX physics system. */
	SYNKRO_ENUM_CONST( PhysicsSystem, PhysX )
SYNKRO_ENUM_END()


} // phys


} // synkro


#endif // _SYNKRO_PHYS_PHYSICSSYSTEM_
