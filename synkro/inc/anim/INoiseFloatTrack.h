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
// Purpose: Defines noise animation track for a floating-point value.
//==============================================================================
#ifndef _SYNKRO_ANIM_INOISEFLOATTRACK_
#define _SYNKRO_ANIM_INOISEFLOATTRACK_


#include "config.h"
#include <anim/IProceduralFloatTrack.h>


namespace synkro
{


namespace anim
{


/**
 * Noise animation track for a floating-point value.
 */
iface INoiseFloatTrack :
	public IProceduralFloatTrack
{
public:
	/**
	 * Sets noise magnitude. Default is 1.0.
	 * @param magnitude Noise magnitude.
	 */
	virtual void											SetMagnitude( Float magnitude ) = 0;

	/**
	 * Sets noise value shift. Default is 0.0.
	 * @param shift Value shift.
	 */
	virtual void											SetShift( Float shift ) = 0;

	/**
	 * Sets noise seed.
	 * @param seed Noise seed.
	 */
	virtual void											SetSeed( UInt seed ) = 0;

	/**
	 * Retrieves noise magnitude.
	 */
	virtual Float											GetMagnitude() const = 0;

	/**
	 * Retrieves noise value shift.
	 */
	virtual Float											GetShift() const = 0;

	/**
	 * Retrieves noise seed.
	 */
	virtual UInt											GetSeed() const = 0;
};


} // anim


} // synkro


#endif // _SYNKRO_ANIM_INOISEFLOATTRACK_
