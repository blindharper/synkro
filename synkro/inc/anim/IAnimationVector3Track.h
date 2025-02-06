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
// Purpose: Defines animation track for a 3-component vector.
//==============================================================================
#ifndef _SYNKRO_ANIM_IANIMATIONVECTOR3TRACK_
#define _SYNKRO_ANIM_IANIMATIONVECTOR3TRACK_


#include "config.h"
#include <anim/IAnimationTrack.h>
#include <math/Vector3.h>


namespace synkro
{


namespace anim
{


/**
 * Animation track for a 3-component vector.
 */
iface IAnimationVector3Track :
	public IAnimationTrack
{
public:
	/**
	 * Retrieves current track value.
	 * @param time Moment in time for which to retrieve value.
	 * @param [out] value Track value.
	 */
	virtual void											GetValue( Double time, math::Vector3& value ) const = 0;

	/**
	 * Casts track to keyframed track.
	 * @return Non-null for keyframed track, nullptr otherwise.
	 */
	virtual IKeyframedVector3Track*							AsKeyframed() const = 0;

	/**
	 * Casts track to procedural track.
	 * @return Non-null for procedural track, nullptr otherwise.
	 */
	virtual IProceduralVector3Track*						AsProcedural() const = 0;

	/**
	 * Casts track to expression track.
	 * @return Non-null for expression track, nullptr otherwise.
	 */
	virtual IExpressionVector3Track*						AsExpression() const = 0;
};


} // anim


} // synkro


#endif // _SYNKRO_ANIM_IANIMATIONVECTOR3TRACK_
