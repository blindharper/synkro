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
// Purpose: Emboss filter implementation.
//==============================================================================
#ifndef _SYNKRO_VIEW_EMBOSSFILTER_
#define _SYNKRO_VIEW_EMBOSSFILTER_


#include "config.h"
#include <view/Filter/Kernel3x3/Kernel3x3FilterImpl.h>
#include <view/IEmbossFilter.h>
#include <view/IEmbossFilterAnimationController.h>


namespace synkro
{


namespace view
{


// Emboss filter implementation.
class EmbossFilter :
	public Kernel3x3FilterImpl<IEmbossFilter>
{
public:
	// Constructor.
	EmbossFilter( IViewport* viewport, anim::IAnimationSystem* animationSystem, gfx::IProgram* program );

	// IViewportFilter methods.
	IViewportFilterAnimationController*						CreateAnimationController( anim::IAnimation* animation, anim::AnimationListener* listener );

	// IKernel3x3Filter methods.
	IEmbossFilter*											AsEmboss() const;

	// IEmbossFilter methods.
	void													SetAngle( Float angle );
	void													SetDepth( Float depth );
	Float													GetAngle() const;
	Float													GetDepth() const;

private:
	P(IEmbossFilterAnimationController)						_ctrlAnimation;
	gfx::ProgramParam*										_paramWeights;
	gfx::ProgramParam*										_paramDepth;
	Float													_angle;
	Float													_weights[9];
};


#include "EmbossFilter.inl"


} // view


} // synkro


#endif // _SYNKRO_VIEW_EMBOSSFILTER_
