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
// Purpose: Defines procedural animation track for a floating-point value.
//==============================================================================
#ifndef _SYNKRO_ANIM_IPROCEDURALFLOATTRACK_
#define _SYNKRO_ANIM_IPROCEDURALFLOATTRACK_


#include "config.h"
#include <anim/IAnimationFloatTrack.h>
#include <anim/ProcedureType.h>


namespace synkro
{


namespace anim
{


/**
 * Procedural animation track for a floating-point value.
 */
iface IProceduralFloatTrack :
	public IAnimationFloatTrack
{
public:
	/**
	 * Sets track length, in seconds.
	 * @param length Track length.
	 */
	virtual void											SetLength( Double length ) = 0;

	/** 
	 * Retrieves procedure type.
	 */
	virtual ProcedureType									GetProcedureType() const = 0;

	/**
	 * Casts track to noise track.
	 * @return Non-null for noise track, nullptr otherwise.
	 */
	virtual INoiseFloatTrack*								AsNoise() const = 0;

	/**
	 * Casts track to wave track.
	 * @return Non-null for wave track, nullptr otherwise.
	 */
	virtual IWaveFloatTrack*								AsWave() const = 0;
};


} // anim


} // synkro


#endif // _SYNKRO_ANIM_IPROCEDURALFLOATTRACK_
