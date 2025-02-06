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
// Purpose: Animation controller for simple filter.
//==============================================================================
#ifndef _SYNKRO_CORE_SIMPLEFILTERANIMATIONCONTROLLER_
#define _SYNKRO_CORE_SIMPLEFILTERANIMATIONCONTROLLER_


#include "config.h"
#include <view/Filter/ViewportFilterAnimationControllerImpl.h>
#include <view/ISimpleFilterAnimationController.h>


namespace synkro
{


namespace view
{


// Animation controller for simple filter.
class SimpleFilterAnimationController :
	public ViewportFilterAnimationControllerImpl<ISimpleFilterAnimationController>
{
public:
	// Constructor.
	SimpleFilterAnimationController( ISimpleFilter* simpleFilter, anim::IAnimationSystem* animationSystem, anim::IAnimation* animation, anim::AnimationListener* listener );

	// IController methods.
	void													Update( Double delta );

	// IAnimationController methods.
	void													SetAnimation( anim::IAnimation* animation );

	// IViewportFilterAnimationController methods.
	ISimpleFilterAnimationController*						AsSimple() const;

	// ISimpleFilterAnimationController methods.
	anim::IKeyframedFloatTrack*								CreateValueTrack();
	anim::IProceduralFloatTrack*							CreateValueTrack( const anim::AnimationTrack& type );

private:
	ISimpleFilter*											_simpleFilter;
	anim::IAnimationFloatTrack*								_trackValue;
};


} // view


} // synkro


#endif // _SYNKRO_CORE_SIMPLEFILTERANIMATIONCONTROLLER_
