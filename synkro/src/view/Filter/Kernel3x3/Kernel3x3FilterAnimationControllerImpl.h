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
// Purpose: Generic implementation of animation controller for kernel 3x3 filter.
//==============================================================================
#ifndef _SYNKRO_CORE_KERNEL3X3FILTERANIMATIONCONTROLLERIMPL_
#define _SYNKRO_CORE_KERNEL3X3FILTERANIMATIONCONTROLLERIMPL_


#include "config.h"
#include <view/Filter/ViewportFilterAnimationControllerImpl.h>
#include "Kernel3x3FilterProperty.h"


namespace synkro
{


namespace view
{


// Generic implementation of animation controller for kernel 3x3 filter.
template <class T>
class Kernel3x3FilterAnimationControllerImpl :
	public ViewportFilterAnimationControllerImpl<T>
{
public:
	// Constructor.
	Kernel3x3FilterAnimationControllerImpl( IKernel3x3Filter* kernel3x3Filter, anim::IAnimationSystem* animationSystem, anim::IAnimation* animation, anim::AnimationListener* listener );

	// IController methods.
	virtual void											Update( Double delta );

	// IAnimationController methods.
	virtual void											SetAnimation( anim::IAnimation* animation );

	// IViewportFilterAnimationController methods.
	virtual IKernel3x3FilterAnimationController*			AsKernel3x3() const;

	// IKernel3x3FilterAnimationController methods.
	virtual anim::IKeyframedIntTrack*						CreatePassCountTrack();
	virtual IEmbossFilterAnimationController*				AsEmboss() const;

protected:
	IKernel3x3Filter*										_kernel3x3Filter;
	anim::IAnimationIntTrack*								_trackPassCount;
};


#include "Kernel3x3FilterAnimationControllerImpl.inl"


} // view


} // synkro


#endif // _SYNKRO_CORE_KERNEL3X3FILTERANIMATIONCONTROLLERIMPL_
