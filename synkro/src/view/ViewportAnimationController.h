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
// Purpose: Animation controller for viewport.
//==============================================================================
#ifndef _SYNKRO_VIEW_VIEWPORTANIMATIONCONTROLLER_
#define _SYNKRO_VIEW_VIEWPORTANIMATIONCONTROLLER_


#include "config.h"
#include <anim/PlaybackControllerImpl.h>
#include <view/IViewportAnimationController.h>


namespace synkro
{


namespace view
{


// Animation controller for viewport.
class ViewportAnimationController :
	public anim::PlaybackControllerImpl<IViewportAnimationController>
{
public:
	// Constructor.
	ViewportAnimationController( IViewport* viewport, anim::IAnimationSystem* animationSystem, anim::IAnimation* animation, anim::AnimationListener* listener );

	// IController methods.
	void													Update( Double delta );

	// IAnimationController methods.
	void													SetAnimation( anim::IAnimation* animation );

	// IViewportAnimationController methods.
	anim::IKeyframedPointTrack*								CreateLocationTrack();
	anim::IKeyframedSizeTrack*								CreateSizeTrack();
	anim::IKeyframedRectTrack*								CreateRectTrack();
	anim::IKeyframedColorTrack*								CreateColorTrack();
	anim::IProceduralColorTrack*							CreateColorTrack( const anim::AnimationTrack& type );
	anim::IKeyframedFloatTrack*								CreateOpacityTrack();
	anim::IProceduralFloatTrack*							CreateOpacityTrack( const anim::AnimationTrack& type );

private:
	IViewport*												_viewport;
	anim::IAnimationPointTrack*								_trackLocation;
	anim::IAnimationSizeTrack*								_trackSize;
	anim::IAnimationRectTrack*								_trackRect;
	anim::IAnimationColorTrack*								_trackColor;
	anim::IAnimationFloatTrack*								_trackOpacity;
};


} // view


} // synkro


#endif // _SYNKRO_VIEW_VIEWPORTANIMATIONCONTROLLER_
