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
// Purpose: Generic depth-based viewport filter implementation.
//==============================================================================
#ifndef _SYNKRO_VIEW_DEPTHFILTERIMPL_
#define _SYNKRO_VIEW_DEPTHFILTERIMPL_


#include "config.h"
#include <view/Filter/ViewportFilterImpl.h>
#include <scene/ICamera.h>
#include <gfx/IResourceSet.h>
#include <view/IDepthMap.h>


namespace synkro
{


namespace view
{


// Generic depth-based viewport filter implementation.
template <class T>
class DepthFilterImpl :
	public ViewportFilterImpl<T>
{
public:
	// Constructor & destructor.
	DepthFilterImpl( IViewport* viewport, anim::IAnimationSystem* animationSystem, gfx::IProgram* program );
	virtual ~DepthFilterImpl();

	// IViewportFilter methods.
	virtual void											Update();
	virtual IDepthFilter*									AsDepth() const;

	// IDepthFilter methods.
	virtual void											SetDepthMap( IDepthMap* depth );
	virtual void											SetCamera( scene::ICamera* camera );
	virtual IDepthMap*										GetDepthMap() const;
	virtual scene::ICamera*									GetCamera() const;
	virtual IDepthOfFieldFilter*							AsDepthOfField() const;
	virtual IFogFilter*										AsFog() const;
	virtual IMotionBlurFilter*								AsMotionBlur() const;

protected:
	P(gfx::IResourceSet)									_resources;
	IDepthMap*												_depth;
	scene::ICamera*											_camera;
	gfx::ProgramParam*										_paramInvViewProj;
};


#include "DepthFilterImpl.inl"


} // view


} // synkro


#endif // _SYNKRO_VIEW_DEPTHFILTERIMPL_
