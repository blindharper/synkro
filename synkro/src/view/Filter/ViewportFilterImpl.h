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
// Purpose: Generic viewport filter implementation.
//==============================================================================
#ifndef _SYNKRO_VIEW_VIEWPORTFILTERIMPL_
#define _SYNKRO_VIEW_VIEWPORTFILTERIMPL_


#include "config.h"
#include <core/ObjectImpl.h>
#include <core/IContext.h>
#include <lang/Rect.h>
#include <view/IViewport.h>
#include <gfx/IRect.h>
#include <gfx/IProgram.h>
#include <gfx/IProgramStage.h>
#include <gfx/IParameterSet.h>
#include <gfx/IRenderView.h>
#include <gfx/IRenderWindow.h>
#include <gfx/IGraphicsDevice.h>
#include <gfx/IGraphicsSystemEx.h>
#include <gfx/IPostProcessRenderQueue.h>
#include <gfx/IPostProcessRenderObject.h>
#include <view/BaseViewport.h>


namespace synkro
{


namespace view
{


// Generic viewport filter implementation.
template <class T>
class ViewportFilterImpl :
	public core::ObjectImpl<T>
{
public:
	// Constructor & destructor.
	ViewportFilterImpl( IViewport* viewport, anim::IAnimationSystem* animationSystem, gfx::IProgram* program );
	virtual ~ViewportFilterImpl();

	// IViewportFilter methods.
	virtual IViewportFilterAnimationController*				CreateAnimationController( anim::IAnimation* animation, anim::AnimationListener* listener );
	virtual void											Update();
	virtual void											Enable( Bool enable );
	virtual void											EnableRect( Bool enable );
	virtual void											SetRect( const lang::Rect& rect );
	virtual void											SetOrder( UInt order );
	virtual Bool											IsEnabled() const;
	virtual Bool											IsRectEnabled() const;
	virtual void											GetRect( lang::Rect& rect ) const;
	virtual UInt											GetOrder() const;
	virtual ISimpleFilter*									AsSimple() const;
	virtual IColorFilter*									AsColor() const;
	virtual IDepthFilter*									AsDepth() const;
	virtual IKernel3x3Filter*								AsKernel3x3() const;

protected:
	IViewport*												_viewport;
	anim::IAnimationSystem*									_animationSystem;
	P(gfx::IPostProcessRenderObject)						_filter;
	P(gfx::IParameterSet)									_params;
	P(gfx::IRect)											_scissor;
	lang::Rect												_rect;
};


#include "ViewportFilterImpl.inl"


} // view


} // synkro


#endif // _SYNKRO_VIEW_VIEWPORTFILTERIMPL_
