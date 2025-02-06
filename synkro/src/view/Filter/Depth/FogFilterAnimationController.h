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
// Purpose: Animation controller for fog filter.
//==============================================================================
#ifndef _SYNKRO_CORE_FOGFILTERANIMATIONCONTROLLER_
#define _SYNKRO_CORE_FOGFILTERANIMATIONCONTROLLER_


#include "config.h"
#include <view/Filter/ViewportFilterAnimationControllerImpl.h>
#include <view/IFogFilterAnimationController.h>


namespace synkro
{


namespace view
{


// Animation controller for fog filter.
class FogFilterAnimationController :
	public ViewportFilterAnimationControllerImpl<IFogFilterAnimationController>
{
public:
	// Constructor.
	FogFilterAnimationController( IFogFilter* fogFilter, anim::IAnimationSystem* animationSystem, anim::IAnimation* animation, anim::AnimationListener* listener );

	// IController methods.
	void													Update( Double delta );

	// IAnimationController methods.
	void													SetAnimation( anim::IAnimation* animation );

	// IViewportFilterAnimationController methods.
	IFogFilterAnimationController*							AsFog() const;

	// IFogFilterAnimationController methods.
	anim::IKeyframedColorTrack*								CreateColorTrack();
	anim::IProceduralColorTrack*							CreateColorTrack( const anim::AnimationTrack& type );
	anim::IKeyframedFloatTrack*								CreateDensityTrack();
	anim::IProceduralFloatTrack*							CreateDensityTrack( const anim::AnimationTrack& type );
	anim::IKeyframedFloatTrack*								CreateStartTrack();
	anim::IProceduralFloatTrack*							CreateStartTrack( const anim::AnimationTrack& type );
	anim::IKeyframedFloatTrack*								CreateEndTrack();
	anim::IProceduralFloatTrack*							CreateEndTrack( const anim::AnimationTrack& type );

private:
	IFogFilter*												_fogFilter;
	anim::IAnimationColorTrack*								_trackColor;
	anim::IAnimationFloatTrack*								_trackDensity;
	anim::IAnimationFloatTrack*								_trackStart;
	anim::IAnimationFloatTrack*								_trackEnd;
};


} // view


} // synkro


#endif // _SYNKRO_CORE_FOGFILTERANIMATIONCONTROLLER_
