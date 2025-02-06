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
#ifndef _SYNKRO_SOUND_PLAYBACKMODE_
#define _SYNKRO_SOUND_PLAYBACKMODE_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace sound
{


/**
 * Sound playback mode. Controls sound behavior after it reaches the end.
 */
SYNKRO_ENUM_BEGIN( PlaybackMode )
	/** Unknown playback mode. */
	SYNKRO_ENUM_CONST( PlaybackMode, Unknown )

	/** Playback is stopped at the end when ended. */
	SYNKRO_ENUM_CONST( PlaybackMode, Stop )

	/** Playback is re-started from the beginning when ended. */
	SYNKRO_ENUM_CONST( PlaybackMode, Loop )
SYNKRO_ENUM_END()


} // sound


} // synkro


#endif // _SYNKRO_SOUND_PLAYBACKMODE_
