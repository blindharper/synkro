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
// Purpose: Defines wave animation track for a floating-point value.
//==============================================================================
#ifndef _SYNKRO_ANIM_IWAVEFLOATTRACK_
#define _SYNKRO_ANIM_IWAVEFLOATTRACK_


#include "config.h"
#include <anim/IProceduralFloatTrack.h>
#include <anim/WaveType.h>


namespace synkro
{


namespace anim
{


/**
 * Wave animation track for a floating-point value.
 */
iface IWaveFloatTrack :
	public IProceduralFloatTrack
{
public:
	/**
	 * Sets wave amplitude.
	 * @param amplitude Wave amplitude.
	 */
	virtual void											SetAmplitude( Float amplitude ) = 0;

	/**
	 * Sets wave amplitude offset.
	 * @param offset Amplitude offset.
	 */
	virtual void											SetOffset( Float offset ) = 0;

	/**
	 * Sets wave frequency.
	 * @param frequency Wave frequency, in Hertz.
	 */
	virtual void											SetFrequency( Float frequency ) = 0;

	/**
	 * Sets wave phase.
	 * @param phase Wave phase, in radians.
	 */
	virtual void											SetPhase( Float phase ) = 0;

	/**
	 * Sets waveform type.
	 * @param type Waveform type.
	 */
	virtual void											SetType( const WaveType& type ) = 0;

	/**
	 * Retrieves wave amplitude.
	 */
	virtual Float											GetAmplitude() const = 0;

	/**
	 * Retrieves wave amplitude offset.
	 */
	virtual Float											GetOffset() const = 0;

	/**
	 * Retrieves wave frequency.
	 */
	virtual Float											GetFrequency() const = 0;

	/**
	 * Retrieves wave phase.
	 */
	virtual Float											GetPhase() const = 0;

	/**
	 * Retrieves waveform type.
	 */
	virtual WaveType										GetWaveType() const = 0;
};


} // anim


} // synkro


#endif // _SYNKRO_ANIM_IWAVEFLOATTRACK_
