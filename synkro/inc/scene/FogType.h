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
// Purpose: Defines fog effect types.
//==============================================================================
#ifndef _SYNKRO_SCENE_FOGTYPE_
#define _SYNKRO_SCENE_FOGTYPE_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace scene
{


/**
 * Fog types.
 */
SYNKRO_ENUM_BEGIN( FogType )
	/** No fog. */
	SYNKRO_ENUM_CONST( FogType, None )

	/** Linear fog. */
	SYNKRO_ENUM_CONST( FogType, Linear )

	/** Exponential fog. */
	SYNKRO_ENUM_CONST( FogType, Exponential )

	/** Squared exponential fog. */
	SYNKRO_ENUM_CONST( FogType, ExponentialSquared )

	/** Creates fog type from string. */
	FogType( const lang::String& type );

	/** Converts fog type to string. */
	lang::String											ToString() const;
SYNKRO_ENUM_END()


} // scene


} // synkro


#endif // _SYNKRO_SCENE_FOGTYPE_
