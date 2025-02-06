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
// Purpose: Defines sprite animation controller.
//==============================================================================
#ifndef _SYNKRO_OVER_ISPRITEANIMATIONCONTROLLER_
#define _SYNKRO_OVER_ISPRITEANIMATIONCONTROLLER_


#include "config.h"
#include <anim/IPlaybackAnimationController.h>


namespace synkro
{


namespace over
{


/**
 * Sprite animation controller.
 */
iface ISpriteAnimationController :
	public anim::IPlaybackAnimationController
{
public:
	/**
	 * Creates keyframed track controlling sprite location.
	 */
	virtual anim::IKeyframedPointTrack*						CreateLocationTrack() = 0;

	/**
	 * Creates keyframed track controlling sprite location's X coordinate.
	 */
	virtual anim::IKeyframedFloatTrack*						CreateLocationXTrack() = 0;

	/**
	 * Creates procedural track controlling sprite location's X coordinate.
	 * @param type Track type.
	 */
	virtual anim::IProceduralFloatTrack*					CreateLocationXTrack( const anim::AnimationTrack& type ) = 0;

	/**
	 * Creates keyframed track controlling sprite location's Y coordinate.
	 */
	virtual anim::IKeyframedFloatTrack*						CreateLocationYTrack() = 0;

	/**
	 * Creates procedural track controlling sprite location's X coordinate.
	 * @param type Track type.
	 */
	virtual anim::IProceduralFloatTrack*					CreateLocationYTrack( const anim::AnimationTrack& type ) = 0;

	/**
	 * Creates keyframed track controlling sprite size.
	 */
	virtual anim::IKeyframedSizeTrack*						CreateSizeTrack() = 0;

	/**
	 * Creates keyframed track controlling sprite orientation.
	 */
	virtual anim::IKeyframedFloatTrack*						CreateOrientationTrack() = 0;

	/**
	 * Creates procedural track controlling sprite orientation.
	 * @param type Track type.
	 */
	virtual anim::IProceduralFloatTrack*					CreateOrientationTrack( const anim::AnimationTrack& type ) = 0;

	/**
	 * Creates keyframed track controlling sprite opacity.
	 */
	virtual anim::IKeyframedFloatTrack*						CreateOpacityTrack() = 0;

	/**
	 * Creates procedural track controlling sprite opacity.
	 * @param type Track type.
	 */
	virtual anim::IProceduralFloatTrack*					CreateOpacityTrack( const anim::AnimationTrack& type ) = 0;

	/**
	 * Creates keyframed track controlling sprite's image frame.
	 */
	virtual anim::IKeyframedFloatRectTrack*					CreateFrameTrack() = 0;

	/**
	 * Creates keyframed track controlling sprite visibility.
	 */
	virtual anim::IKeyframedBoolTrack*						CreateVisibilityTrack() = 0;
};


} // over


} // synkro


#endif // _SYNKRO_OVER_ISPRITEANIMATIONCONTROLLER_
