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
// Purpose: Defines music object.
//==============================================================================
#ifndef _SYNKRO_SOUND_IMUSIC_
#define _SYNKRO_SOUND_IMUSIC_


#include "config.h"
#include <core/IObject.h>
#include <sound/PlaybackMode.h>


namespace synkro
{


namespace sound
{


/**
 * Music track.
 */
iface IMusic :
	public core::IObject
{
public:
	/**
	 * Creates animation controller for music track.
	 * @param animation Optional music animation.
	 * @param listener Controller listener.
	 * @return Created controller.
	 */
	virtual IMusicAnimationController*						CreateAnimationController( anim::IAnimation* animation, anim::AnimationListener* listener ) = 0;

	/**
	 * Starts or stops playing the music.
	 * @param play Set to true to start playback or to false to stop it.
	 */
	virtual void											Play( Bool play ) = 0;

	/**
	 * Pauses or resumes music playback.
	 * @param pause Set to true to pause the playback or to false to resume it.
	 */
	virtual void											Pause( Bool pause ) = 0;

	/**
	 * Sets music track volume.
	 * @param volume Music volume.
	 */
	virtual void											SetVolume( Int volume ) = 0;

	/**
	 * Sets music pan.
	 * @param pan Music pan.
	 */
	virtual void											SetPan( Int pan ) = 0;

	/**
	 * Sets music playback mode.
	 * @param mode New music playback mode.
	 */
	virtual void											SetMode( const PlaybackMode& mode ) = 0;

	/**
	 * Sets the number of music loops. Set to 0 to loop forever.
	 * @param loopCount Number of loops.
	 */
	virtual void											SetLoopCount( UInt loopCount ) = 0;

	/**
	 * Retrieves music playing state.
	 */
	virtual Bool											IsPlaying() const = 0;

	/**
	 * Retrieves music paused state.
	 */
	virtual Bool											IsPaused() const = 0;

	/**
	 * Retrieves music volume.
	 */
	virtual Int												GetVolume() const = 0;

	/**
	 * Retrieves music pan.
	 */
	virtual Int												GetPan() const = 0;

	/**
	 * Retrieves music playback mode.
	 */
	virtual PlaybackMode									GetMode() const = 0;

	/**
	 * Retrieves music loop count.
	 */
	virtual UInt											GetLoopCount() const = 0;

	/**
	 * Retrieves music duration, in seconds.
	 */
	virtual Double											GetLength() const = 0;
};


} // sound


} // synkro


#endif // _SYNKRO_SOUND_IMUSIC_
