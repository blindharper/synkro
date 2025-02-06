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
// Purpose: Defines sound channels in a multi-channel stream.
//==============================================================================
#include "config.h"
#include <sound/SoundChannel.h>
#include <internal/Enum.h>


namespace synkro
{


namespace sound
{


SYNKRO_DEFINE_CONST( SoundChannel, Unknown,					0x00000 )
SYNKRO_DEFINE_CONST( SoundChannel, FrontLeft,				0x00001 )
SYNKRO_DEFINE_CONST( SoundChannel, FrontRight,				0x00002 )
SYNKRO_DEFINE_CONST( SoundChannel, FrontCenter,				0x00004 )
SYNKRO_DEFINE_CONST( SoundChannel, LowFrequency,			0x00008 )
SYNKRO_DEFINE_CONST( SoundChannel, BackLeft,				0x00010 )
SYNKRO_DEFINE_CONST( SoundChannel, BackRight,				0x00020 )
SYNKRO_DEFINE_CONST( SoundChannel, FrontLeftOfCenter,		0x00040 )
SYNKRO_DEFINE_CONST( SoundChannel, FrontRightOfCenter,		0x00080 )
SYNKRO_DEFINE_CONST( SoundChannel, BackCenter,				0x00100 )
SYNKRO_DEFINE_CONST( SoundChannel, SurroundLeft,			0x00200 )
SYNKRO_DEFINE_CONST( SoundChannel, SurroundRight,			0x00400 )
SYNKRO_DEFINE_CONST( SoundChannel, TopCenter,				0x00800 )
SYNKRO_DEFINE_CONST( SoundChannel, TopFrontLeft,			0x01000 )
SYNKRO_DEFINE_CONST( SoundChannel, TopFrontCenter,			0x02000 )
SYNKRO_DEFINE_CONST( SoundChannel, TopFrontRight,			0x04000 )
SYNKRO_DEFINE_CONST( SoundChannel, TopBackLeft,				0x08000 )
SYNKRO_DEFINE_CONST( SoundChannel, TopBackCenter,			0x10000 )
SYNKRO_DEFINE_CONST( SoundChannel, TopBackRight,			0x20000 )
SYNKRO_DEFINE_CONST( SoundChannel, Mono,					0x00004 )
SYNKRO_DEFINE_CONST( SoundChannel, Stereo,					0x00003 )
SYNKRO_DEFINE_CONST( SoundChannel, Rear,					0x00030 )
SYNKRO_DEFINE_CONST( SoundChannel, TwoPointOne,				0x0000B )
SYNKRO_DEFINE_CONST( SoundChannel, Three,					0x00007 )
SYNKRO_DEFINE_CONST( SoundChannel, ThreeSurround,			0x00103 )
SYNKRO_DEFINE_CONST( SoundChannel, Quad,					0x00033 )
SYNKRO_DEFINE_CONST( SoundChannel, Surround,				0x00107 )
SYNKRO_DEFINE_CONST( SoundChannel, Five,					0x00037 )
SYNKRO_DEFINE_CONST( SoundChannel, FiveSurround,			0x00607 )
SYNKRO_DEFINE_CONST( SoundChannel, FivePointOne,			0x0003F )
SYNKRO_DEFINE_CONST( SoundChannel, FivePointOneSurround,	0x0060F )
SYNKRO_DEFINE_CONST( SoundChannel, Six,						0x00137 )
SYNKRO_DEFINE_CONST( SoundChannel, SixSurround,				0x00707 )
SYNKRO_DEFINE_CONST( SoundChannel, SixPointOne,				0x0013F )
SYNKRO_DEFINE_CONST( SoundChannel, SixPointOneSurround,		0x0070F )
SYNKRO_DEFINE_CONST( SoundChannel, Seven,					0x000F7 )
SYNKRO_DEFINE_CONST( SoundChannel, SevenSurround,			0x00637 )
SYNKRO_DEFINE_CONST( SoundChannel, SevenPointOne,			0x000FF )
SYNKRO_DEFINE_CONST( SoundChannel, SevenPointOneSurround,	0x0063F )
SYNKRO_DEFINE_CONST( SoundChannel, EightSurround,			0x00737 )
SYNKRO_DEFINE_CONST( SoundChannel, EightPointOneSurround,	0x0073F )
SYNKRO_DEFINE_CONST( SoundChannel, NineSurround,			0x05637 )
SYNKRO_DEFINE_CONST( SoundChannel, NinePointOneSurround,	0x0563F )
SYNKRO_DEFINE_CONST( SoundChannel, TenSurround,				0x05737 )
SYNKRO_DEFINE_CONST( SoundChannel, TenPointOneSurround,		0x0573F )
SYNKRO_DEFINE_CONST( SoundChannel, ElevenSurround,			0x056F7 )
SYNKRO_DEFINE_CONST( SoundChannel, ElevenPointOneSurround,	0x056FF )


} // sound


} // synkro
