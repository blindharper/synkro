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
// Purpose: Depth-of-field viewport filter implementation.
//==============================================================================
#ifndef _SYNKRO_VIEW_DEPTHOFFIELDFILTER_
#define _SYNKRO_VIEW_DEPTHOFFIELDFILTER_


#include "config.h"
#include "DepthFilterImpl.h"
#include <view/IDepthOfFieldFilter.h>


namespace synkro
{


namespace view
{


// Depth-of-field viewport filter implementation.
class DepthOfFieldFilter :
	public DepthFilterImpl<IDepthOfFieldFilter>
{
public:
	// Constructor.
	DepthOfFieldFilter( IViewport* viewport, gfx::IProgram* program );

	// IDepthFilter methods.
	IDepthOfFieldFilter*									AsDepthOfField() const;

	// IDepthOfFieldFilter methods.
	void													SetFocalDistance( Float distance );
	Float													GetFocalDistance() const;

private:
	gfx::ProgramParam*										_paramFocalPlane;
	math::Vector4											_focalPlane;
};


#include "DepthOfFieldFilter.inl"


} // view


} // synkro


#endif // _SYNKRO_VIEW_DEPTHOFFIELDFILTER_
