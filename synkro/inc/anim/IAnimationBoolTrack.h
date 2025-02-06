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
// Purpose: Defines animation track for a boolean value.
//==============================================================================
#ifndef _SYNKRO_ANIM_IANIMATIONBOOLTRACK_
#define _SYNKRO_ANIM_IANIMATIONBOOLTRACK_


#include "config.h"
#include <anim/IAnimationTrack.h>


namespace synkro
{


namespace anim
{


/**
 * Animation track for a boolean value.
 */
iface IAnimationBoolTrack :
	public IAnimationTrack
{
public:
	/**
	 * Retrieves current track value.
	 * @param time Moment in time for which to retrieve value.
	 * @param [out] value Key value.
	 */
	virtual void											GetValue( Double time, Bool& value ) const = 0;

	/**
	 * Casts track to keyframed track.
	 * @return Non-null for keyframed track, nullptr otherwise.
	 */
	virtual IKeyframedBoolTrack*							AsKeyframed() const = 0;

	/**
	 * Casts track to procedural track.
	 * @return Non-null for procedural track, nullptr otherwise.
	 */
	virtual IProceduralBoolTrack*							AsProcedural() const = 0;

	/**
	 * Casts track to expression track.
	 * @return Non-null for expression track, nullptr otherwise.
	 */
	virtual IExpressionBoolTrack*							AsExpression() const = 0;
};


} // anim


} // synkro


#endif // _SYNKRO_ANIM_IANIMATIONBOOLTRACK_
