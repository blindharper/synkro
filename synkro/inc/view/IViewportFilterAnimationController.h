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
// Purpose: Defines animation controller for viewport filter.
//==============================================================================
#ifndef _SYNKRO_VIEW_IVIEWPORTFILTERANIMATIONCONTROLLER_
#define _SYNKRO_VIEW_IVIEWPORTFILTERANIMATIONCONTROLLER_


#include "config.h"
#include <anim/IPlaybackAnimationController.h>


namespace synkro
{


namespace view
{


/**
 * Animation controller for viewport filter.
 */
iface IViewportFilterAnimationController :
	public anim::IPlaybackAnimationController
{
public:
	/**
	 * Creates keyframed track controlling filter's clipping rectangle.
	 */
	virtual anim::IKeyframedRectTrack*						CreateRectTrack() = 0;

	/**
	 * Casts filter controller to color controller.
	 * @return Non-null for color controller, nullptr otherwise.
	 */
	virtual IColorFilterAnimationController*				AsColor() const = 0;

	/**
	 * Casts filter controller to fog controller.
	 * @return Non-null for fog controller, nullptr otherwise.
	 */
	virtual IFogFilterAnimationController*					AsFog() const = 0;

	/**
	 * Casts filter controller to 3x3-kernel controller.
	 * @return Non-null for 3x3-kernel controller, nullptr otherwise.
	 */
	virtual IKernel3x3FilterAnimationController*			AsKernel3x3() const = 0;

	/**
	 * Casts filter controller to simple controller.
	 * @return Non-null for simple controller, nullptr otherwise.
	 */
	virtual ISimpleFilterAnimationController*				AsSimple() const = 0;
};


} // view


} // synkro


#endif // _SYNKRO_VIEW_IVIEWPORTFILTERANIMATIONCONTROLLER_
