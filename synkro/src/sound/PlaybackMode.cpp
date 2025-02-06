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
// Purpose: Defines sound playback mode.
//==============================================================================
#include "config.h"
#include <sound/PlaybackMode.h>
#include <internal/Enum.h>


namespace synkro
{


namespace sound
{


SYNKRO_DEFINE_CONST( PlaybackMode, Unknown,	0 )
SYNKRO_DEFINE_CONST( PlaybackMode, Stop,	1 )
SYNKRO_DEFINE_CONST( PlaybackMode, Loop,	2 )


} // sound


} // synkro
