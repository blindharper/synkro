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
// Purpose: Defines scene debug mode.
//==============================================================================
#ifndef _SYNKRO_SCENE_DEBUGMODE_
#define _SYNKRO_SCENE_DEBUGMODE_


#include "config.h"
#include <lang/Flag.h>


namespace synkro
{


namespace scene
{


/**
 * Scene debug mode.
 */
SYNKRO_FLAG_BEGIN( DebugMode )
	/** No debug geometry is drawn. */
	SYNKRO_FLAG_CONST( DebugMode, None )

	/** Gizmos are drawn. */
	SYNKRO_FLAG_CONST( DebugMode, Gizmos )

	/** Helper objects are drawn. */
	SYNKRO_FLAG_CONST( DebugMode, Helpers )

	/** Curves objects are drawn. */
	SYNKRO_FLAG_CONST( DebugMode, Curves )

	/** Constraints are drawn. */
	SYNKRO_FLAG_CONST( DebugMode, Constraints )

	/** Primitive normals are drawn. */
	SYNKRO_FLAG_CONST( DebugMode, Normals )
SYNKRO_FLAG_END()


} // scene


} // synkro


#endif // _SYNKRO_SCENE_DEBUGMODE_
