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
// Purpose: Generic 3x3-kernel filter implementation.
//==============================================================================
#ifndef _SYNKRO_VIEW_KERNEL3X3FILTERIMPL_
#define _SYNKRO_VIEW_KERNEL3X3FILTERIMPL_


#include "config.h"
#include <view/Filter/ViewportFilterImpl.h>
#include "Kernel3x3FilterAnimationController.h"
#include <math/Vector2.h>


namespace synkro
{


namespace view
{


// Generic 3x3-kernel filter implementation.
template <class T>
class Kernel3x3FilterImpl :
	public ViewportFilterImpl<T>
{
public:
	// Constructor.
	Kernel3x3FilterImpl( IViewport* viewport, anim::IAnimationSystem* animationSystem, gfx::IProgram* program );

	// IKernel3x3Filter methods.
	virtual void											SetPassCount( UInt count );
	virtual UInt											GetPassCount() const;
	virtual IKernel3x3Filter*								AsKernel3x3() const;
	virtual IEmbossFilter*									AsEmboss() const;
};


#include "Kernel3x3FilterImpl.inl"


} // view


} // synkro


#endif // _SYNKRO_VIEW_KERNEL3X3FILTERIMPL_
