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
// Purpose: Defines animation controller for color filter.
//==============================================================================
#ifndef _SYNKRO_VIEW_ICOLORFILTERANIMATIONCONTROLLER_
#define _SYNKRO_VIEW_ICOLORFILTERANIMATIONCONTROLLER_


#include "config.h"
#include <view/IViewportFilterAnimationController.h>


namespace synkro
{


namespace view
{


/**
 * Animation controller for color filter.
 */
iface IColorFilterAnimationController :
	public IViewportFilterAnimationController
{
public:
	/**
	 * Creates keyframed track controlling filter's color.
	 * @return Created color track.
	 * @exception BadArgumentException Color track already exists.
	 */
	virtual anim::IKeyframedColorTrack*						CreateColorTrack() = 0;

	/**
	 * Creates procedural track controlling filter's color.
	 * @param type Track type.
	 * @return Created color track.
	 * @exception BadArgumentException Color track already exists.
	 */
	virtual anim::IProceduralColorTrack*					CreateColorTrack( const anim::AnimationTrack& type ) = 0;
};


} // view


} // synkro


#endif // _SYNKRO_VIEW_ICOLORFILTERANIMATIONCONTROLLER_
