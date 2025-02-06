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
// Purpose: Generic implementation of animation controller for viewport filter.
//==============================================================================
#ifndef _SYNKRO_VIEW_VIEWPORTFILTERANIMATIONCONTROLLERIMPL_
#define _SYNKRO_VIEW_VIEWPORTFILTERANIMATIONCONTROLLERIMPL_


#include "config.h"
#include <anim/PlaybackControllerImpl.h>
#include "ViewportFilterProperty.h"


namespace synkro
{


namespace view
{


// Generic implementation of animation controller for viewport filter.
template <class T>
class ViewportFilterAnimationControllerImpl :
	public anim::PlaybackControllerImpl<T>
{
public:
	// Constructor & destructor.
	ViewportFilterAnimationControllerImpl( IViewportFilter* filter, anim::IAnimationSystem* animationSystem, anim::IAnimation* animation, anim::AnimationListener* listener );
	virtual ~ViewportFilterAnimationControllerImpl();

	// IController methods.
	virtual void											Update( Double delta );

	// IAnimationController methods.
	virtual void											SetAnimation( anim::IAnimation* animation );

	// IViewportFilterAnimationController methods.
	virtual anim::IKeyframedRectTrack*						CreateRectTrack();
	virtual IColorFilterAnimationController*				AsColor() const;
	virtual IFogFilterAnimationController*					AsFog() const;
	virtual IKernel3x3FilterAnimationController*			AsKernel3x3() const;
	virtual ISimpleFilterAnimationController*				AsSimple() const;

protected:
	IViewportFilter*										_filter;
	anim::IAnimationRectTrack*								_trackRect;
};


#include "ViewportFilterAnimationControllerImpl.inl"


} // view


} // synkro


#endif // _SYNKRO_VIEW_VIEWPORTFILTERANIMATIONCONTROLLERIMPL_
