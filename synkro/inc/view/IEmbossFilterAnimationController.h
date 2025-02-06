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
// Purpose: Defines animation controller for emboss filter.
//==============================================================================
#ifndef _SYNKRO_VIEW_IEMBOSSFILTERANIMATIONCONTROLLER_
#define _SYNKRO_VIEW_IEMBOSSFILTERANIMATIONCONTROLLER_


#include "config.h"
#include <view/IKernel3x3FilterAnimationController.h>


namespace synkro
{


namespace view
{


/**
 * Animation controller for emboss filter.
 */
iface IEmbossFilterAnimationController :
	public IKernel3x3FilterAnimationController
{
public:
	/**
	 * Creates keyframed track controlling emboss light angle.
	 * @return Created angle track.
	 * @exception BadArgumentException Angle track already exists.
	 */
	virtual anim::IKeyframedFloatTrack*						CreateAngleTrack() = 0;

	/**
	 * Creates keyframed track controlling emboss depth.
	 * @return Created depth track.
	 * @exception BadArgumentException Depth track already exists.
	 */
	virtual anim::IKeyframedFloatTrack*						CreateDepthTrack() = 0;

	/**
	 * Creates procedural track controlling emboss depth.
	 * @param type Track type.
	 * @return Created depth track.
	 * @exception BadArgumentException Depth track already exists.
	 */
	virtual anim::IProceduralFloatTrack*					CreateDepthTrack( const anim::AnimationTrack& type ) = 0;
};


} // view


} // synkro


#endif // _SYNKRO_VIEW_IEMBOSSFILTERANIMATIONCONTROLLER_
