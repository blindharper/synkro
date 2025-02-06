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
// Purpose: Defines animation controller for simple filter.
//==============================================================================
#ifndef _SYNKRO_VIEW_ISIMPLEFILTERANIMATIONCONTROLLER_
#define _SYNKRO_VIEW_ISIMPLEFILTERANIMATIONCONTROLLER_


#include "config.h"
#include <view/IViewportFilterAnimationController.h>


namespace synkro
{


namespace view
{


/**
 * Animation controller for simple filter.
 */
iface ISimpleFilterAnimationController :
	public IViewportFilterAnimationController
{
public:
	/**
	 * Creates keyframed track controlling filter's value.
	 */
	virtual anim::IKeyframedFloatTrack*						CreateValueTrack() = 0;

	/**
	 * Creates procedural track controlling filter's value.
	 * @param type Track type.
	 */
	virtual anim::IProceduralFloatTrack*					CreateValueTrack( const anim::AnimationTrack& type ) = 0;
};


} // view


} // synkro


#endif // _SYNKRO_VIEW_ISIMPLEFILTERANIMATIONCONTROLLER_
