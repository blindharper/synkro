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
// Purpose: Defines audio system types.
//==============================================================================
#ifndef _SYNKRO_AUDIO_AUDIOSYSTEM_
#define _SYNKRO_AUDIO_AUDIOSYSTEM_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace audio
{


/**
 * Audio system types.
 */
SYNKRO_ENUM_BEGIN( AudioSystem )
	/** Custom audio system. */
	SYNKRO_ENUM_CONST( AudioSystem, Custom )

	/** OpenAL based audio system. */
	SYNKRO_ENUM_CONST( AudioSystem, OpenAL )

	/** DirectSound8 based audio system. */
	SYNKRO_ENUM_CONST( AudioSystem, DirectSound8 )

	/** WinMM based audio system. */
	SYNKRO_ENUM_CONST( AudioSystem, WinMM )
SYNKRO_ENUM_END()


} // audio


} // synkro


#endif // _SYNKRO_AUDIO_AUDIOSYSTEM_
