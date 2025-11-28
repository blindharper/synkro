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
// Purpose: Defines noise animation track for a color gradient value.
//==============================================================================
#ifndef _SYNKRO_ANIM_INOISECOLORGRADIENTTRACK_
#define _SYNKRO_ANIM_INOISECOLORGRADIENTTRACK_


#include "config.h"
#include <anim/IProceduralColorGradientTrack.h>
#include <lang/GradientType.h>


namespace synkro
{


namespace anim
{


/**
 * Noise animation track for a color gradient value.
 */
iface INoiseColorGradientTrack :
	public IProceduralColorGradientTrack
{
public:
	/**
	 * Sets gradient type.
	 * @param type Gradient type.
	 */
	virtual void											SetGradientType( const lang::GradientType& type ) = 0;

	/**
	 * Sets noise seed.
	 * @param seed Noise seed.
	 */
	virtual void											SetSeed( UInt seed ) = 0;

	/**
	 * Retrieves gradient type.
	 */
	virtual lang::GradientType								GetGradientType() const = 0;

	/**
	 * Retrieves noise seed.
	 */
	virtual UInt											GetSeed() const = 0;
};


} // anim


} // synkro


#endif // _SYNKRO_ANIM_INOISECOLORGRADIENTTRACK_
