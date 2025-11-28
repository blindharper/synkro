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
// Purpose: Defines noise animation track for a boolean value.
//==============================================================================
#ifndef _SYNKRO_ANIM_INOISEBOOLTRACK_
#define _SYNKRO_ANIM_INOISEBOOLTRACK_


#include "config.h"
#include <anim/IProceduralBoolTrack.h>


namespace synkro
{


namespace anim
{


/**
 * Noise animation track for a boolean value.
 */
iface INoiseBoolTrack :
	public IProceduralBoolTrack
{
public:
	/**
	 * Sets noise seed.
	 * @param seed Noise seed.
	 */
	virtual void											SetSeed( UInt seed ) = 0;

	/**
	 * Retrieves noise seed.
	 */
	virtual UInt											GetSeed() const = 0;
};


} // anim


} // synkro


#endif // _SYNKRO_ANIM_INOISEBOOLTRACK_
