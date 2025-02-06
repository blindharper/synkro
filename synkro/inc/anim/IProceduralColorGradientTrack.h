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
// Purpose: Defines procedural animation track for a color gradient value.
//==============================================================================
#ifndef _SYNKRO_ANIM_IPROCEDURALCOLORGRADIENTTRACK_
#define _SYNKRO_ANIM_IPROCEDURALCOLORGRADIENTTRACK_


#include "config.h"
#include <anim/IAnimationColorGradientTrack.h>
#include <anim/ProcedureType.h>


namespace synkro
{


namespace anim
{


/**
 * Procedural animation track for a color gradient value.
 */
iface IProceduralColorGradientTrack :
	public IAnimationColorGradientTrack
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
};


} // anim


} // synkro


#endif // _SYNKRO_ANIM_IPROCEDURALCOLORGRADIENTTRACK_
