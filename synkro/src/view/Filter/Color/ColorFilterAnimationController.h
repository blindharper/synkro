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
// Purpose: Animation controller for color filter.
//==============================================================================
#ifndef _SYNKRO_VIEW_COLORFILTERANIMATIONCONTROLLER_
#define _SYNKRO_VIEW_COLORFILTERANIMATIONCONTROLLER_


#include "config.h"
#include <view/Filter/ViewportFilterAnimationControllerImpl.h>
#include <view/IColorFilterAnimationController.h>


namespace synkro
{


namespace view
{


// Animation controller for color filter.
class ColorFilterAnimationController :
	public ViewportFilterAnimationControllerImpl<IColorFilterAnimationController>
{
public:
	// Constructor.
	ColorFilterAnimationController( IColorFilter* colorFilter, anim::IAnimationSystem* animationSystem, anim::IAnimation* animation, anim::AnimationListener* listener );

	// IController methods.
	void													Update( Double delta );

	// IAnimationController methods.
	void													SetAnimation( anim::IAnimation* animation );

	// IViewportFilterAnimationController methods.
	IColorFilterAnimationController*						AsColor() const;

	// IColorFilterAnimationController methods.
	anim::IKeyframedColorTrack*								CreateColorTrack();
	anim::IProceduralColorTrack*							CreateColorTrack( const anim::AnimationTrack& type );

private:
	IColorFilter*											_colorFilter;
	anim::IAnimationColorTrack*								_trackColor;
};


} // view


} // synkro


#endif // _SYNKRO_VIEW_COLORFILTERANIMATIONCONTROLLER_
