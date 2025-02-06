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
// Purpose: Defines keyframed animation track for a color value.
//==============================================================================
#ifndef _SYNKRO_ANIM_IKEYFRAMEDCOLORTRACK_
#define _SYNKRO_ANIM_IKEYFRAMEDCOLORTRACK_


#include "config.h"
#include <anim/IAnimationColorTrack.h>
#include <anim/Interpolation.h>


namespace synkro
{


namespace anim
{


/**
 * Keyframed animation track for a color value.
 */
iface IKeyframedColorTrack :
	public IAnimationColorTrack
{
public:
	/**
	 * Removes all keys from the track.
	 */
	virtual void											Clear() = 0;

	/**
	 * Creates a key at the given moment in time.
	 * @param time Moment of time for which to create the key.
	 * @param value Key value.
	 * @param interpolation Key interpolation type.
	 */
	virtual void											SetKey( Double time, const img::Color& value, const Interpolation& interpolation ) = 0;

	/**
	 * Creates a key at the given moment in time. Interpolation is defaulted to linear.
	 * @param time Moment of time for which to set the key.
	 * @param value Key value.
	 */
	virtual void											SetKey( Double time, const img::Color& value ) = 0;

	/**
	 * Retrieves the total number of keys in the track.
	 */
	virtual UInt											GetKeyCount() const = 0;

	/**
	 * Retrieves key time by index.
	 * @param index Key index.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual Double											GetKeyTime( UInt index ) const = 0;

	/**
	 * Retrieves key interpolation type by index.
	 * @param index Key index.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual Interpolation									GetKeyInterpolation( UInt index ) const = 0;

	/**
	 * Retrieves key value by index.
	 * @param index Key index.
	 * @param [out] value Key value.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual void											GetKeyValue( UInt index, img::Color& value ) const = 0;
};


} // anim


} // synkro


#endif // _SYNKRO_ANIM_IKEYFRAMEDCOLORTRACK_
