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
// Purpose: Animation controller for sound source.
//==============================================================================
#ifndef _SYNKRO_SCENE_SOUNDANIMATIONCONTROLLER_
#define _SYNKRO_SCENE_SOUNDANIMATIONCONTROLLER_


#include "config.h"
#include "NodeAnimationControllerImpl.h"
#include <scene/ISoundAnimationController.h>


namespace synkro
{


namespace scene
{


// Animation controller for sound source.
class SoundAnimationController :
	public NodeAnimationControllerImpl<ISoundAnimationController>
{
public:
	// Constructor.
	SoundAnimationController( ISound* sound, anim::IAnimationSystem* animationSystem, anim::IAnimation* animation, anim::AnimationListener* listener );

	// IController methods.
	void													Update( Double delta );

	// IAnimationController methods.
	void													SetAnimation( anim::IAnimation* animation );

	// INodeAnimationController methods.
	ISoundAnimationController*								AsSound() const;

	// ISoundAnimationController methods.
	anim::IKeyframedFloatTrack*								CreateInnerVolumeTrack();
	anim::IProceduralFloatTrack*							CreateInnerVolumeTrack( const anim::AnimationTrack& type );
	anim::IKeyframedFloatTrack*								CreateOuterVolumeTrack();
	anim::IProceduralFloatTrack*							CreateOuterVolumeTrack( const anim::AnimationTrack& type );
	anim::IKeyframedBoolTrack*								CreateAvailabilityTrack();

private:
	ISound*													_sound;
	anim::IAnimationFloatTrack*								_trackInnerVolume;
	anim::IAnimationFloatTrack*								_trackOuterVolume;
	anim::IAnimationBoolTrack*								_trackAvailability;
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_SOUNDANIMATIONCONTROLLER_
