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
// Purpose: Animation controller for emboss filter.
//==============================================================================
#ifndef _SYNKRO_CORE_EMBOSSFILTERANIMATIONCONTROLLER_
#define _SYNKRO_CORE_EMBOSSFILTERANIMATIONCONTROLLER_


#include "config.h"
#include <view/Filter/Kernel3x3/Kernel3x3FilterAnimationControllerImpl.h>
#include <view/IEmbossFilterAnimationController.h>


namespace synkro
{


namespace view
{


// Animation controller for emboss filter.
class EmbossFilterAnimationController :
	public Kernel3x3FilterAnimationControllerImpl<IEmbossFilterAnimationController>
{
public:
	// Constructor.
	EmbossFilterAnimationController( IEmbossFilter* embossFilter, anim::IAnimationSystem* animationSystem, anim::IAnimation* animation, anim::AnimationListener* listener );

	// IController methods.
	void													Update( Double delta );

	// IAnimationController methods.
	void													SetAnimation( anim::IAnimation* animation );

	// IKernel3x3FilterAnimationController methods.
	IEmbossFilterAnimationController*						AsEmboss() const;

	// IEmbossFilterAnimationController methods.
	anim::IKeyframedFloatTrack*								CreateAngleTrack();
	anim::IKeyframedFloatTrack*								CreateDepthTrack();
	anim::IProceduralFloatTrack*							CreateDepthTrack( const anim::AnimationTrack& type );

private:
	IEmbossFilter*											_embossFilter;
	anim::IAnimationFloatTrack*								_trackAngle;
	anim::IAnimationFloatTrack*								_trackDepth;
};


} // view


} // synkro


#endif // _SYNKRO_CORE_EMBOSSFILTERANIMATIONCONTROLLER_
