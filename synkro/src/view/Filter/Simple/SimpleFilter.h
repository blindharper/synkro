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
// Purpose: Simple viewport filter implementation.
//==============================================================================
#ifndef _SYNKRO_VIEW_SIMPLEFILTER_
#define _SYNKRO_VIEW_SIMPLEFILTER_


#include "config.h"
#include <view/Filter/ViewportFilterImpl.h>
#include <view/ISimpleFilter.h>
#include <view/ISimpleFilterAnimationController.h>


namespace synkro
{


namespace view
{


// Simple viewport filter implementation.
class SimpleFilter :
	public ViewportFilterImpl<ISimpleFilter>
{
public:
	// Constructor.
	SimpleFilter( IViewport* viewport, anim::IAnimationSystem* animationSystem, gfx::IProgram* program );

	// IViewportFilter methods.
	IViewportFilterAnimationController*						CreateAnimationController( anim::IAnimation* animation, anim::AnimationListener* listener );

	// ISimpleFilter methods.
	void													SetValue( Float value );
	Float													GetValue() const;
	ISimpleFilter*											AsSimple() const;

private:
	P(ISimpleFilterAnimationController)						_ctrlAnimation;
	gfx::ProgramParam*										_paramValue;
};


#include "SimpleFilter.inl"


} // view


} // synkro


#endif // _SYNKRO_VIEW_SIMPLEFILTER_
