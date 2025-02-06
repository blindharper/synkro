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
// Purpose: Defines waveform type constant values.
//==============================================================================
#ifndef _SYNKRO_ANIM_WAVETYPECONST_
#define _SYNKRO_ANIM_WAVETYPECONST_


#include "config.h"


namespace synkro
{


namespace anim
{


// Waveform type constant values.
enum WaveTypeConst
{
	WAVE_TYPE_UNKNOWN		= 0,
	WAVE_TYPE_SINE			= 1,
	WAVE_TYPE_STEP			= 2,
	WAVE_TYPE_SQUARE		= 3,
	WAVE_TYPE_TRIANGLE		= 4,
	WAVE_TYPE_SAWTOOTH_UP	= 5,
	WAVE_TYPE_SAWTOOTH_DOWN	= 6,
};


} // anim


} // synkro


#endif // _SYNKRO_ANIM_WAVETYPECONST_
