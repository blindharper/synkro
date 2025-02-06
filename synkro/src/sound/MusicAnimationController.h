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
// Purpose: Animation controller for music track.
//==============================================================================
#ifndef _SYNKRO_SOUND_MUSICANIMATIONCONTROLLER_
#define _SYNKRO_SOUND_MUSICANIMATIONCONTROLLER_


#include "config.h"
#include <anim/PlaybackControllerImpl.h>
#include <sound/IMusicAnimationController.h>


namespace synkro
{


namespace sound
{


// Music controller implementation.
class MusicAnimationController :
	public anim::PlaybackControllerImpl<IMusicAnimationController>
{
public:
	// Constructor.
	MusicAnimationController( IMusic* music, anim::IAnimationSystem* animationSystem, anim::IAnimation* animation, anim::AnimationListener* listener );

	// IController methods.
	void													Update( Double delta );

	// IAnimationController methods.
	void													SetAnimation( anim::IAnimation* animation );

	// IMusicAnimationController methods.
	anim::IKeyframedIntTrack*								CreateVolumeTrack();
	anim::IKeyframedIntTrack*								CreatePanTrack();

private:
	IMusic*													_music;
	anim::IAnimationIntTrack*								_trackVolume;
	anim::IAnimationIntTrack*								_trackPan;
};


} // sound


} // synkro


#endif // _SYNKRO_SOUND_MUSICANIMATIONCONTROLLER_
