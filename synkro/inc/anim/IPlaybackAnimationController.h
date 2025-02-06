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
// Purpose: Defines playback animation controller.
//==============================================================================
#ifndef _SYNKRO_ANIM_IPLAYBACKANIMATIONCONTROLLER_
#define _SYNKRO_ANIM_IPLAYBACKANIMATIONCONTROLLER_


#include "config.h"
#include <anim/IAnimationController.h>
#include <anim/AnimationMode.h>
#include <anim/AnimationDirection.h>
#include <anim/AnimationTrack.h>


namespace synkro
{


namespace anim
{


/**
 * Playback animation controller. Used to playback animation.
 */
iface IPlaybackAnimationController :
	public IAnimationController
{
public:
	/**
	 * Sets rate at which the animation is played. Default is 1.0.
	 * @param speed Animation speed.
	 */
	virtual void											SetSpeed( Double speed ) = 0;

	/**
	 * Sets start time from which the animation is played. Default is 0.0.
	 * @param offset Animation offset.
	 */
	virtual void											SetOffset( Double offset ) = 0;

	/**
	 * Sets animation playback mode.
	 * @param mode New animation mode.
	 */
	virtual void											SetMode( const AnimationMode& mode ) = 0;

	/**
	 * Sets animation direction.
	 * @param direction New direction.
	 */
	virtual void											SetDirection( const AnimationDirection& direction ) = 0;

	/**
	 * Sets the number of animation loops. Set to 0 to loop forever.
	 * @param loopCount Number of loops.
	 */
	virtual void											SetLoopCount( UInt loopCount ) = 0;

	/**
	 * Retrieves speed at which the animation is played.
	 */
	virtual Double											GetSpeed() const = 0;

	/**
	 * Retrieves start time from which the animation is played.
	 */
	virtual Double											GetOffset() const = 0;

	/**
	 * Retrieves animation playback mode.
	 */
	virtual AnimationMode									GetMode() const = 0;

	/**
	 * Retrieves animation direction.
	 */
	virtual AnimationDirection								GetDirection() const = 0;

	/**
	 * Retrieves animation loop count.
	 */
	virtual UInt											GetLoopCount() const = 0;

	/**
	 * Retrieves current animation iteration.
	 */
	virtual UInt											GetIteration() const = 0;
};


} // anim


} // synkro


#endif // _SYNKRO_ANIM_IPLAYBACKANIMATIONCONTROLLER_
