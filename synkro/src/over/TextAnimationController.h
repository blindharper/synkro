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
// Purpose: Animation controller for text implementation.
//==============================================================================
#ifndef _SYNKRO_OVER_TEXTANIMATIONCONTROLLER_
#define _SYNKRO_OVER_TEXTANIMATIONCONTROLLER_


#include "config.h"
#include <anim/PlaybackControllerImpl.h>
#include <over/ITextAnimationController.h>


namespace synkro
{


namespace over
{


// Animation controller for text.
class TextAnimationController :
	public anim::PlaybackControllerImpl<ITextAnimationController>
{
public:
	// Constructor.
	TextAnimationController( IText* text, anim::IAnimationSystem* animationSystem, anim::IAnimation* animation, anim::AnimationListener* listener );

	// IController methods.
	void													Update( Double delta );

	// IAnimationController methods.
	void													SetAnimation( anim::IAnimation* animation );

	// ITextAnimationController methods.
	anim::IKeyframedPointTrack*								CreateLocationTrack();
	anim::IKeyframedFloatTrack*								CreateLocationXTrack();
	anim::IProceduralFloatTrack*							CreateLocationXTrack( const anim::AnimationTrack& type );
	anim::IKeyframedFloatTrack*								CreateLocationYTrack();
	anim::IProceduralFloatTrack*							CreateLocationYTrack( const anim::AnimationTrack& type );
	anim::IKeyframedRectTrack*								CreateRectTrack();
	anim::IKeyframedFloatTrack*								CreateOrientationTrack();
	anim::IProceduralFloatTrack*							CreateOrientationTrack( const anim::AnimationTrack& type );
	anim::IKeyframedFloatTrack*								CreateScaleTrack();
	anim::IProceduralFloatTrack*							CreateScaleTrack( const anim::AnimationTrack& type );
	anim::IKeyframedColorGradientTrack*						CreateColorGradientTrack();
	anim::IKeyframedColorTrack*								CreateColorTrack();
	anim::IProceduralColorTrack*							CreateColorTrack( const anim::AnimationTrack& type );
	anim::IKeyframedFloatTrack*								CreateOpacityTrack();
	anim::IProceduralFloatTrack*							CreateOpacityTrack( const anim::AnimationTrack& type );
	anim::IKeyframedBoolTrack*								CreateVisibilityTrack();

private:
	IText*													_text;
	anim::IAnimationPointTrack*								_trackLocation;
	anim::IAnimationFloatTrack*								_trackLocationX;
	anim::IAnimationFloatTrack*								_trackLocationY;
	anim::IAnimationRectTrack*								_trackRect;
	anim::IAnimationFloatTrack*								_trackOrientation;
	anim::IAnimationFloatTrack*								_trackScale;
	anim::IAnimationColorGradientTrack*						_trackColorGradient;
	anim::IAnimationColorTrack*								_trackColor;
	anim::IAnimationFloatTrack*								_trackOpacity;
	anim::IAnimationBoolTrack*								_trackVisibility;
};


} // over


} // synkro


#endif // _SYNKRO_OVER_TEXTANIMATIONCONTROLLER_
