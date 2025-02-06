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
// Purpose: Depth viewport filter implementation.
//==============================================================================
#ifndef _SYNKRO_VIEW_DEPTHFILTER_
#define _SYNKRO_VIEW_DEPTHFILTER_


#include "config.h"
#include "DepthFilterImpl.h"
#include <view/IDepthFilter.h>


namespace synkro
{


namespace view
{


// Depth viewport filter implementation.
class DepthFilter :
	public DepthFilterImpl<IDepthFilter>
{
public:
	// Constructor.
	DepthFilter( IViewport* viewport, gfx::IProgram* program );

	// IDepthFilter methods.
	void													SetCamera( scene::ICamera* camera );

private:
	gfx::ProgramParam*										_paramFront;
	gfx::ProgramParam*										_paramBack;
};


#include "DepthFilter.inl"


} // view


} // synkro


#endif // _SYNKRO_VIEW_DEPTHFILTER_
