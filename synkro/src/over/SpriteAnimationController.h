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
// Purpose: Animation controller for sprite.
//==============================================================================
#ifndef _SYNKRO_OVER_SPRITEANIMATIONCONTROLLER_
#define _SYNKRO_OVER_SPRITEANIMATIONCONTROLLER_


#include "config.h"
#include <anim/PlaybackControllerImpl.h>
#include <over/ISpriteAnimationController.h>


namespace synkro
{


namespace over
{


// Animation controller for sprite.
class SpriteAnimationController :
	public anim::PlaybackControllerImpl<ISpriteAnimationController>
{
public:
	// Constructor.
	SpriteAnimationController( ISprite* sprite, anim::IAnimationSystem* animationSystem, anim::IAnimation* animation, anim::AnimationListener* listener );

	// IController methods.
	void													Update( Double delta );

	// IAnimationController methods.
	void													SetAnimation( anim::IAnimation* animation );

	// ISpriteAnimationController methods.
	anim::IKeyframedPointTrack*								CreateLocationTrack();
	anim::IKeyframedFloatTrack*								CreateLocationXTrack();
	anim::IProceduralFloatTrack*							CreateLocationXTrack( const anim::AnimationTrack& type );
	anim::IKeyframedFloatTrack*								CreateLocationYTrack();
	anim::IProceduralFloatTrack*							CreateLocationYTrack( const anim::AnimationTrack& type );
	anim::IKeyframedSizeTrack*								CreateSizeTrack();
	anim::IKeyframedFloatTrack*								CreateOrientationTrack();
	anim::IProceduralFloatTrack*							CreateOrientationTrack( const anim::AnimationTrack& type );
	anim::IKeyframedFloatTrack*								CreateOpacityTrack();
	anim::IProceduralFloatTrack*							CreateOpacityTrack( const anim::AnimationTrack& type );
	anim::IKeyframedFloatRectTrack*							CreateFrameTrack();
	anim::IKeyframedBoolTrack*								CreateVisibilityTrack();

private:
	ISprite*												_sprite;
	anim::IAnimationPointTrack*								_trackLocation;
	anim::IAnimationFloatTrack*								_trackLocationX;
	anim::IAnimationFloatTrack*								_trackLocationY;
	anim::IAnimationSizeTrack*								_trackSize;
	anim::IAnimationFloatTrack*								_trackOrientation;
	anim::IAnimationFloatTrack*								_trackOpacity;
	anim::IAnimationFloatRectTrack*							_trackFrame;
	anim::IAnimationBoolTrack*								_trackVisibility;
};


} // over


} // synkro


#endif // _SYNKRO_OVER_SPRITEANIMATIONCONTROLLER_
