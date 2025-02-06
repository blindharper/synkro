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
// Purpose: Defines waveform type.
//==============================================================================
#ifndef _SYNKRO_ANIM_WAVETYPE_
#define _SYNKRO_ANIM_WAVETYPE_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace anim
{


/**
 * Waveform type.
 */
SYNKRO_ENUM_BEGIN( WaveType )
	/** Unknown waveform. */
	SYNKRO_ENUM_CONST( WaveType, Unknown )

	/** Sinusoidal waveform. */
	SYNKRO_ENUM_CONST( WaveType, Sine )

	/** Stepped waveform. */
	SYNKRO_ENUM_CONST( WaveType, Step )

	/** Square waveform. */
	SYNKRO_ENUM_CONST( WaveType, Square )

	/** Triangular waveform. */
	SYNKRO_ENUM_CONST( WaveType, Triangle )

	/** SawtoothUp waveform. */
	SYNKRO_ENUM_CONST( WaveType, SawtoothUp )

	/** SawtoothDown waveform. */
	SYNKRO_ENUM_CONST( WaveType, SawtoothDown )

	/** Creates wave type from string. */
	WaveType( const lang::String& type );

	/** Converts wave type to string. */
	lang::String											ToString() const;
SYNKRO_ENUM_END()


} // anim


} // synkro


#endif // _SYNKRO_ANIM_WAVETYPE_
