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
// Purpose: Defines force mode.
//==============================================================================
#ifndef _SYNKRO_PHYS_FORCEMODE_
#define _SYNKRO_PHYS_FORCEMODE_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace phys
{


/**
 * Force application modes.
 */
SYNKRO_ENUM_BEGIN( ForceMode )
	/** Unknown mode. */
	SYNKRO_ENUM_CONST( ForceMode, Unknown )

	/** Force changes body's acceleration taking into account its mass. */
	SYNKRO_ENUM_CONST( ForceMode, Force )

	/** Force changes body's impulse. */
	SYNKRO_ENUM_CONST( ForceMode, Impulse )

	/** Force changes body's velocity. */
	SYNKRO_ENUM_CONST( ForceMode, Velocity )

	/** Force changes body's acceleration regardless of its mass. */
	SYNKRO_ENUM_CONST( ForceMode, Acceleration )

	/** Creates force mode from string. */
	ForceMode( const lang::String& mode );

	/** Converts force mode to string. */
	lang::String								ToString() const;
SYNKRO_ENUM_END()


} // phys


} // synkro


#endif // _SYNKRO_PHYS_FORCEMODE_
