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
// Purpose: Implements animation controller for point set.
//==============================================================================
#ifndef _SYNKRO_SCENE_POINTSETANIMATIONCONTROLLER_
#define _SYNKRO_SCENE_POINTSETANIMATIONCONTROLLER_


#include "config.h"
#include "PrimitiveAnimationControllerImpl.h"
#include <scene/IPointSetAnimationController.h>


namespace synkro
{


namespace scene
{


// Animation controller for point set implementation.
class PointSetAnimationController :
	public PrimitiveAnimationControllerImpl<IPointSetAnimationController>
{
public:
	// Constructor.
	PointSetAnimationController( IPointSet* pointSet, anim::IAnimationSystem* animationSystem, anim::IAnimation* animation, anim::AnimationListener* listener );

	// IController methods.
	void													Update( Double delta );

	// IAnimationController methods.
	void													SetAnimation( anim::IAnimation* animation );

	// IPrimitiveAnimationController methods.
	IPointSetAnimationController*							AsPointSet() const;

	// IPointSetAnimationController methods.
	anim::IKeyframedColorTrack*								CreateColorTrack();
	anim::IProceduralColorTrack*							CreateColorTrack( const anim::AnimationTrack& type );
	anim::IExpressionColorTrack*							CreateColorTrack( anim::IExpressionScript* script );
	anim::IExpressionColorTrack*							CreateColorTrack( const lang::String& expression );

private:
	IPointSet*												_pointSet;
	anim::IAnimationColorTrack*								_trackColor;
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_POINTSETANIMATIONCONTROLLER_
