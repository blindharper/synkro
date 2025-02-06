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
// Purpose: Defines animation controller for text pool.
//==============================================================================
#ifndef _SYNKRO_OVER_ITEXTPOOLANIMATIONCONTROLLER_
#define _SYNKRO_OVER_ITEXTPOOLANIMATIONCONTROLLER_


#include "config.h"
#include <anim/IPlaybackAnimationController.h>


namespace synkro
{


namespace over
{


/**
 * Animation controller for text pool.
 */
iface ITextPoolAnimationController :
	public anim::IPlaybackAnimationController
{
public:
	/**
	 * Creates keyframed track controlling pool offset.
	 */
	virtual anim::IKeyframedPointTrack*						CreateOffsetTrack() = 0;
};


} // over


} // synkro


#endif // _SYNKRO_OVER_ITEXTPOOLANIMATIONCONTROLLER_
