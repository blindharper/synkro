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
// Purpose: Generic animation controller implementation.
//==============================================================================
#ifndef _SYNKRO_ANIM_ANIMATIONCONTROLLERIMPL_
#define _SYNKRO_ANIM_ANIMATIONCONTROLLERIMPL_


#include "config.h"
#include <core/ControllerImpl.h>
#include <anim/IAnimation.h>
#include <anim/IAnimationSystem.h>
#include <anim/IKeyframedBoolTrack.h>
#include <anim/IKeyframedColorTrack.h>
#include <anim/IKeyframedColorGradientTrack.h>
#include <anim/IKeyframedFloatTrack.h>
#include <anim/IKeyframedFloatRectTrack.h>
#include <anim/IKeyframedIntTrack.h>
#include <anim/IKeyframedMatrix4x4Track.h>
#include <anim/IKeyframedPointTrack.h>
#include <anim/IKeyframedQuaternionTrack.h>
#include <anim/IKeyframedRangeTrack.h>
#include <anim/IKeyframedRectTrack.h>
#include <anim/IKeyframedSizeTrack.h>
#include <anim/IKeyframedVector3Track.h>
#include <anim/IExpressionBoolTrack.h>
#include <anim/IExpressionColorTrack.h>
#include <anim/IExpressionColorGradientTrack.h>
#include <anim/IExpressionFloatTrack.h>
#include <anim/IExpressionFloatRectTrack.h>
#include <anim/IExpressionIntTrack.h>
#include <anim/IExpressionMatrix4x4Track.h>
#include <anim/IExpressionPointTrack.h>
#include <anim/IExpressionQuaternionTrack.h>
#include <anim/IExpressionRangeTrack.h>
#include <anim/IExpressionRectTrack.h>
#include <anim/IExpressionSizeTrack.h>
#include <anim/IExpressionVector3Track.h>
#include <anim/IProceduralBoolTrack.h>
#include <anim/IProceduralColorTrack.h>
#include <anim/IProceduralColorGradientTrack.h>
#include <anim/IProceduralFloatTrack.h>
#include <anim/IProceduralFloatRectTrack.h>
#include <anim/IProceduralIntTrack.h>
#include <anim/IProceduralMatrix4x4Track.h>
#include <anim/IProceduralPointTrack.h>
#include <anim/IProceduralQuaternionTrack.h>
#include <anim/IProceduralRangeTrack.h>
#include <anim/IProceduralRectTrack.h>
#include <anim/IProceduralSizeTrack.h>
#include <anim/IProceduralVector3Track.h>
#include "BaseAnimationSystem.h"


namespace synkro
{


namespace anim
{


// Generic animation controller implementation.
template <class T>
class AnimationControllerImpl :
	public core::ControllerImpl<T>
{
public:
	// Constructor & destructor.
	AnimationControllerImpl( IAnimationSystem* animationSystem, IAnimation* animation );
	virtual ~AnimationControllerImpl();

	// IAnimationController methods.
	virtual void											SetAnimation( IAnimation* animation );
	virtual IAnimation*										GetAnimation() const;

protected:
	BaseAnimationSystem*									_animationSystem;
	P(IAnimation)											_animation;
};


#include "AnimationControllerImpl.inl"


} // anim


} // synkro


#endif // _SYNKRO_ANIM_ANIMATIONCONTROLLERIMPL_
