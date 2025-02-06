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
// Purpose: Defines Animation controller for text.
//==============================================================================
#ifndef _SYNKRO_OVER_ITEXTANIMATIONCONTROLLER_
#define _SYNKRO_OVER_ITEXTANIMATIONCONTROLLER_


#include "config.h"
#include <anim/IPlaybackAnimationController.h>


namespace synkro
{


namespace over
{


/**
 * Animation controller for text.
 */
iface ITextAnimationController :
	public anim::IPlaybackAnimationController
{
public:
	/**
	 * Creates keyframed track controlling text location.
	 */
	virtual anim::IKeyframedPointTrack*						CreateLocationTrack() = 0;

	/**
	 * Creates keyframed track controlling text location's X coordinate.
	 */
	virtual anim::IKeyframedFloatTrack*						CreateLocationXTrack() = 0;

	/**
	 * Creates procedural track controlling text location's X coordinate.
	 * @param type Track type.
	 */
	virtual anim::IProceduralFloatTrack*					CreateLocationXTrack( const anim::AnimationTrack& type ) = 0;

	/**
	 * Creates keyframed track controlling text location's Y coordinate.
	 */
	virtual anim::IKeyframedFloatTrack*						CreateLocationYTrack() = 0;

	/**
	 * Creates procedural track controlling text location's X coordinate.
	 * @param type Track type.
	 */
	virtual anim::IProceduralFloatTrack*					CreateLocationYTrack( const anim::AnimationTrack& type ) = 0;

	/**
	 * Creates keyframed track controlling text clipping rectangle.
	 */
	virtual anim::IKeyframedRectTrack*						CreateRectTrack() = 0;

	/**
	 * Creates keyframed track controlling text orientation.
	 */
	virtual anim::IKeyframedFloatTrack*						CreateOrientationTrack() = 0;

	/**
	 * Creates procedural track controlling text orientation.
	 * @param type Track type.
	 */
	virtual anim::IProceduralFloatTrack*					CreateOrientationTrack( const anim::AnimationTrack& type ) = 0;

	/**
	 * Creates keyframed track controlling text scale.
	 */
	virtual anim::IKeyframedFloatTrack*						CreateScaleTrack() = 0;

	/**
	 * Creates procedural track controlling text scale.
	 * @param type Track type.
	 */
	virtual anim::IProceduralFloatTrack*					CreateScaleTrack( const anim::AnimationTrack& type ) = 0;

	/**
	 * Creates keyframed track controlling text's color gradient.
	 */
	virtual anim::IKeyframedColorGradientTrack*				CreateColorGradientTrack() = 0;

	/**
	 * Creates keyframed track controlling text's color.
	 */
	virtual anim::IKeyframedColorTrack*						CreateColorTrack() = 0;

	/**
	 * Creates procedural track controlling text's color.
	 * @param type Track type.
	 */
	virtual anim::IProceduralColorTrack*					CreateColorTrack( const anim::AnimationTrack& type ) = 0;

	/**
	 * Creates keyframed track controlling text opacity.
	 */
	virtual anim::IKeyframedFloatTrack*						CreateOpacityTrack() = 0;

	/**
	 * Creates procedural track controlling text opacity.
	 * @param type Track type.
	 */
	virtual anim::IProceduralFloatTrack*					CreateOpacityTrack( const anim::AnimationTrack& type ) = 0;

	/**
	 * Creates keyframed track controlling text visibility.
	 */
	virtual anim::IKeyframedBoolTrack*						CreateVisibilityTrack() = 0;
};


} // over


} // synkro


#endif // _SYNKRO_OVER_ITEXTANIMATIONCONTROLLER_
