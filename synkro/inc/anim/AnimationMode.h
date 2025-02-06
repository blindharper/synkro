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
// Purpose: Defines animation playback mode.
//==============================================================================
#ifndef _SYNKRO_ANIM_ANIMATIONMODE_
#define _SYNKRO_ANIM_ANIMATIONMODE_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace anim
{


/**
 * Animation playback mode. Controls animation behavior after it reaches the end.
 */
SYNKRO_ENUM_BEGIN( AnimationMode )
	/** Animation is stopped after a single play. */
	SYNKRO_ENUM_CONST( AnimationMode, Single )

	/** Animation is replayed from the beginning for the given number of iterations or forever. */
	SYNKRO_ENUM_CONST( AnimationMode, Loop )

	/** Animation is oscillating between the beginning and the end. */
	SYNKRO_ENUM_CONST( AnimationMode, PingPong )
SYNKRO_ENUM_END()


} // anim


} // synkro


#endif // _SYNKRO_ANIM_ANIMATIONMODE_
