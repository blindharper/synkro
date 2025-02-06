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
// Purpose: Defines animation mode.
//==============================================================================
#include "config.h"
#include <anim/AnimationMode.h>
#include <internal/Enum.h>
#include "AnimationModeConst.h"


namespace synkro
{


namespace anim
{


SYNKRO_DEFINE_CONST( AnimationMode, Single,		ANIMATION_MODE_SINGLE )
SYNKRO_DEFINE_CONST( AnimationMode, Loop,		ANIMATION_MODE_LOOP )
SYNKRO_DEFINE_CONST( AnimationMode, PingPong,	ANIMATION_MODE_PING_PONG )


} // anim


} // synkro
