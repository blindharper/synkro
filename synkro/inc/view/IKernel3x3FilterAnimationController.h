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
// Purpose: Defines animation controller for 3x3 kernel filter.
//==============================================================================
#ifndef _SYNKRO_VIEW_IKERNEL3X3FILTERANIMATIONCONTROLLER_
#define _SYNKRO_VIEW_IKERNEL3X3FILTERANIMATIONCONTROLLER_


#include "config.h"
#include <view/IViewportFilterAnimationController.h>


namespace synkro
{


namespace view
{


/**
 * Animation controller for 3x3 kernel filter.
 */
iface IKernel3x3FilterAnimationController :
	public IViewportFilterAnimationController
{
public:
	/**
	 * Creates keyframed track controlling filter's pass count.
	 */
	virtual anim::IKeyframedIntTrack*						CreatePassCountTrack() = 0;

	/**
	 * Casts filter controller to emboss controller.
	 * @return Non-null for emboss controller, nullptr otherwise.
	 */
	virtual IEmbossFilterAnimationController*				AsEmboss() const = 0;
};


} // view


} // synkro


#endif // _SYNKRO_VIEW_IKERNEL3X3FILTERANIMATIONCONTROLLER_
