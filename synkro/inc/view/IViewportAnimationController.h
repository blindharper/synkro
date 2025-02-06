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
// Purpose: Defines animation controller for viewport.
//==============================================================================
#ifndef _SYNKRO_VIEW_IVIEWPORTANIMATIONCONTROLLER_
#define _SYNKRO_VIEW_IVIEWPORTANIMATIONCONTROLLER_


#include "config.h"
#include <anim/IPlaybackAnimationController.h>


namespace synkro
{


namespace view
{


/**
 * Animation controller for viewport.
 */
iface IViewportAnimationController :
	public anim::IPlaybackAnimationController
{
public:
	/**
	 * Creates keyframed track controlling viewport location.
	 */
	virtual anim::IKeyframedPointTrack*						CreateLocationTrack() = 0;

	/**
	 * Creates keyframed track controlling viewport size.
	 */
	virtual anim::IKeyframedSizeTrack*						CreateSizeTrack() = 0;

	/**
	 * Creates keyframed track controlling viewport clipping rectangle.
	 */
	virtual anim::IKeyframedRectTrack*						CreateRectTrack() = 0;

	/**
	 * Creates keyframed track controlling viewport color.
	 * @return Created color track.
	 * @exception BadArgumentException Color track already exists.
	 */
	virtual anim::IKeyframedColorTrack*						CreateColorTrack() = 0;

	/**
	 * Creates procedural track controlling viewport color.
	 * @param type Track type.
	 * @return Created color track.
	 * @exception BadArgumentException Color track already exists.
	 */
	virtual anim::IProceduralColorTrack*					CreateColorTrack( const anim::AnimationTrack& type ) = 0;

	/**
	 * Creates keyframed track controlling viewport opacity.
	 */
	virtual anim::IKeyframedFloatTrack*						CreateOpacityTrack() = 0;

	/**
	 * Creates procedural track controlling viewport opacity.
	 * @param type Track type.
	 */
	virtual anim::IProceduralFloatTrack*					CreateOpacityTrack( const anim::AnimationTrack& type ) = 0;
};


} // view


} // synkro


#endif // _SYNKRO_VIEW_IVIEWPORTANIMATIONCONTROLLER_
