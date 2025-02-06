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
// Purpose: Defines sound channels in a multi-channel audio stream.
//==============================================================================
#ifndef _SYNKRO_SOUND_SOUNDCHANNEL_
#define _SYNKRO_SOUND_SOUNDCHANNEL_


#include "config.h"
#include <lang/Flag.h>


namespace synkro
{


namespace sound
{


/**
 * Sound channels. Define speaker locations in space.
 */
SYNKRO_FLAG_BEGIN( SoundChannel )
	/** Unknown channel. Defines no speaker location. Audio streams are treated as monoaural. */
	SYNKRO_FLAG_CONST( SoundChannel, Unknown )

	/** Front left channel. */
	SYNKRO_FLAG_CONST( SoundChannel, FrontLeft )

	/** Front right channel. */
	SYNKRO_FLAG_CONST( SoundChannel, FrontRight )

	/** Front center channel. */
	SYNKRO_FLAG_CONST( SoundChannel, FrontCenter )

	/** Low frequency channel. */
	SYNKRO_FLAG_CONST( SoundChannel, LowFrequency )

	/** Back left channel. */
	SYNKRO_FLAG_CONST( SoundChannel, BackLeft )

	/** Back right channel. */
	SYNKRO_FLAG_CONST( SoundChannel, BackRight )

	/** Front left of center channel. */
	SYNKRO_FLAG_CONST( SoundChannel, FrontLeftOfCenter )

	/** Front right of center channel. */
	SYNKRO_FLAG_CONST( SoundChannel, FrontRightOfCenter )

	/** Back center channel. */
	SYNKRO_FLAG_CONST( SoundChannel, BackCenter )

	/** Surround left channel. */
	SYNKRO_FLAG_CONST( SoundChannel, SurroundLeft )

	/** Surround right channel. */
	SYNKRO_FLAG_CONST( SoundChannel, SurroundRight )

	/** Top center channel. */
	SYNKRO_FLAG_CONST( SoundChannel, TopCenter )

	/** Top front left channel. */
	SYNKRO_FLAG_CONST( SoundChannel, TopFrontLeft )

	/** Top front center channel. */
	SYNKRO_FLAG_CONST( SoundChannel, TopFrontCenter )

	/** Top front right channel. */
	SYNKRO_FLAG_CONST( SoundChannel, TopFrontRight )

	/** Top back left channel. */
	SYNKRO_FLAG_CONST( SoundChannel, TopBackLeft )

	/** Top back center channel. */
	SYNKRO_FLAG_CONST( SoundChannel, TopBackCenter )

	/** Top back right channel. */
	SYNKRO_FLAG_CONST( SoundChannel, TopBackRight )

	/** One front channel. */
	SYNKRO_FLAG_CONST( SoundChannel, Mono )

	/** Two front channels. */
	SYNKRO_FLAG_CONST( SoundChannel, Stereo )

	/** Two back channels. */
	SYNKRO_FLAG_CONST( SoundChannel, Rear )

	/** Two front and low frequency channel. */
	SYNKRO_FLAG_CONST( SoundChannel, TwoPointOne )

	/** Three front channels. */
	SYNKRO_FLAG_CONST( SoundChannel, Three )

	/** Two front and one back channel. */
	SYNKRO_FLAG_CONST( SoundChannel, ThreeSurround )
	
	/** Two front and two back channels. */
	SYNKRO_FLAG_CONST( SoundChannel, Quad )

	/** Three front and one back channel. */
	SYNKRO_FLAG_CONST( SoundChannel, Surround )

	/** Three front and two back channels. */
	SYNKRO_FLAG_CONST( SoundChannel, Five )

	/** Three front and two surround channels. */
	SYNKRO_FLAG_CONST( SoundChannel, FiveSurround )

	/** Three front, two back and low frequency channel. */
	SYNKRO_FLAG_CONST( SoundChannel, FivePointOne )

	/** Three front, two surround and low frequency channel. */
	SYNKRO_FLAG_CONST( SoundChannel, FivePointOneSurround )

	/** Three front and three back channels. */
	SYNKRO_FLAG_CONST( SoundChannel, Six )

	/** Three front, two surround and one back channel. */
	SYNKRO_FLAG_CONST( SoundChannel, SixSurround )

	/** Three front, three back and low frequency channel. */
	SYNKRO_FLAG_CONST( SoundChannel, SixPointOne )

	/** Three front, two surround, one back and low frequency channel. */
	SYNKRO_FLAG_CONST( SoundChannel, SixPointOneSurround )

	/** Five front and two back channels. */
	SYNKRO_FLAG_CONST( SoundChannel, Seven )

	/** Three front, two surround and two back channels. */
	SYNKRO_FLAG_CONST( SoundChannel, SevenSurround )

	/** Five front, two back and low frequency channel. */
	SYNKRO_FLAG_CONST( SoundChannel, SevenPointOne )

	/** Three front, two surround, two back and low frequency channel. */
	SYNKRO_FLAG_CONST( SoundChannel, SevenPointOneSurround )

	/** Three front, two surround and three back channels. */
	SYNKRO_FLAG_CONST( SoundChannel, EightSurround )

	/** Three front, two surround, three back and low frequency channel. */
	SYNKRO_FLAG_CONST( SoundChannel, EightPointOneSurround )

	/** Three front, two surround, two back and two top channels. */
	SYNKRO_FLAG_CONST( SoundChannel, NineSurround )

	/** Three front, two surround, two back, two top and low frequency channel. */
	SYNKRO_FLAG_CONST( SoundChannel, NinePointOneSurround )

	/** Three front, two surround, three back and two top channels. */
	SYNKRO_FLAG_CONST( SoundChannel, TenSurround )

	/** Three front, two surround, three back, two top and low frequency channel. */
	SYNKRO_FLAG_CONST( SoundChannel, TenPointOneSurround )

	/** Five front, two surround, two back and two top channels. */
	SYNKRO_FLAG_CONST( SoundChannel, ElevenSurround )

	/** Five front, two surround, two back, two top and low frequency channel. */
	SYNKRO_FLAG_CONST( SoundChannel, ElevenPointOneSurround )
SYNKRO_FLAG_END()


} // sound


} // synkro


#endif // _SYNKRO_SOUND_SOUNDCHANNEL_
