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
// Purpose: Defines abstract value animation track.
//==============================================================================
#ifndef _SYNKRO_ANIM_ITRACK_
#define _SYNKRO_ANIM_ITRACK_


#include "config.h"
#include <core/IObject.h>
#include <anim/AnimationDataType.h>


namespace synkro
{


namespace anim
{


/**
 * Abstract value animation track.
 */
iface IAnimationTrack :
	public core::IObject
{
public:
	/**
	 * Retrieves track name.
	 */
	virtual lang::String									GetName() const = 0;

	/** 
	 * Retrieves track data type.
	 */
	virtual AnimationDataType								GetType() const = 0;

	/**
	 * Retrieves track length, in seconds.
	 */
	virtual Double											GetLength() const = 0;

	/**
	 * Casts track to boolean track.
	 * @return Non-null for boolean track, nullptr otherwise.
	 */
	virtual IAnimationBoolTrack*							AsBool() const = 0;

	/**
	 * Casts track to color track.
	 * @return Non-null for color track, nullptr otherwise.
	 */
	virtual IAnimationColorTrack*							AsColor() const = 0;

	/**
	 * Casts track to color gradient track.
	 * @return Non-null for color gradient track, nullptr otherwise.
	 */
	virtual IAnimationColorGradientTrack*					AsColorGradient() const = 0;

	/**
	 * Casts track to floating-point track.
	 * @return Non-null for floating-point track, nullptr otherwise.
	 */
	virtual IAnimationFloatTrack*							AsFloat() const = 0;

	/**
	 * Casts track to floating-point rectangle track.
	 * @return Non-null for floating-point rectangle track, nullptr otherwise.
	 */
	virtual IAnimationFloatRectTrack*						AsFloatRect() const = 0;

	/**
	 * Casts track to whole-number track.
	 * @return Non-null for whole-number track, nullptr otherwise.
	 */
	virtual IAnimationIntTrack*								AsInt() const = 0;

	/**
	 * Casts track to 4x4 matrix track.
	 * @return Non-null for 4x4 matrix track, nullptr otherwise.
	 */
	virtual IAnimationMatrix4x4Track*						AsMatrix4x4() const = 0;

	/**
	 * Casts track to point track.
	 * @return Non-null for point track, nullptr otherwise.
	 */
	virtual IAnimationPointTrack*							AsPoint() const = 0;

	/**
	 * Casts track to quaternion track.
	 * @return Non-null for quaternion track, nullptr otherwise.
	 */
	virtual IAnimationQuaternionTrack*						AsQuaternion() const = 0;

	/**
	 * Casts track to range track.
	 * @return Non-null for range track, nullptr otherwise.
	 */
	virtual IAnimationRangeTrack*							AsRange() const = 0;

	/**
	 * Casts track to rectangle track.
	 * @return Non-null for rectangle track, nullptr otherwise.
	 */
	virtual IAnimationRectTrack*							AsRect() const = 0;

	/**
	 * Casts track to size track.
	 * @return Non-null for size track, nullptr otherwise.
	 */
	virtual IAnimationSizeTrack*							AsSize() const = 0;

	/**
	 * Casts track to 3-component vector track.
	 * @return Non-null for 3-component vector track, nullptr otherwise.
	 */
	virtual IAnimationVector3Track*							AsVector3() const = 0;
};


} // anim


} // synkro


#endif // _SYNKRO_ANIM_ITRACK_
