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
// Purpose: Motion blur viewport filter implementation.
//==============================================================================
#ifndef _SYNKRO_VIEW_MOTIONBLURFILTER_
#define _SYNKRO_VIEW_MOTIONBLURFILTER_


#include "config.h"
#include "DepthFilterImpl.h"
#include <view/IMotionBlurFilter.h>


namespace synkro
{


namespace view
{


// Motion blur viewport filter implementation.
class MotionBlurFilter :
	public DepthFilterImpl<IMotionBlurFilter>
{
public:
	// Constructor.
	MotionBlurFilter( IViewport* viewport, gfx::IProgram* program );

	// IViewportFilter methods.
	void													Update();

	// IDepthFilter methods.
	IMotionBlurFilter*										AsMotionBlur() const;

	// IMotionBlurFilter methods.
	void													SetSampleCount( UInt count );
	UInt													GetSampleCount() const;

private:
	gfx::ProgramParam*										_paramPrevViewProj;
	gfx::ProgramParam*										_paramSampleCount;
	math::Matrix4x4											_transViewProj;
};


#include "MotionBlurFilter.inl"


} // view


} // synkro


#endif // _SYNKRO_VIEW_MOTIONBLURFILTER_
