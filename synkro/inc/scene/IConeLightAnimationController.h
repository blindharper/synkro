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
// Purpose: Defines animation controller for cone light node.
//==============================================================================
#ifndef _SYNKRO_SCENE_ICONELIGHTANIMATIONCONTROLLER_
#define _SYNKRO_SCENE_ICONELIGHTANIMATIONCONTROLLER_


#include "config.h"
#include <scene/ILightAnimationController.h>


namespace synkro
{


namespace scene
{


/**
 * Animation controller for cone light node.
 */
iface IConeLightAnimationController :
	public ILightAnimationController
{
public:
	/**
	 * Creates keyframed track controlling light range.
	 * @return Created range track.
	 * @exception BadArgumentException Range track already exists.
	 */
	virtual anim::IKeyframedFloatTrack*						CreateRangeTrack() = 0;

	/**
	 * Creates procedural track controlling light range.
	 * @param type Track type.
	 * @return Created range track.
	 * @exception BadArgumentException Range track already exists.
	 */
	virtual anim::IProceduralFloatTrack*					CreateRangeTrack( const anim::AnimationTrack& type ) = 0;

	/**
	 * Creates keyframed track controlling cone's inner angle.
	 * @return Created inner angle track.
	 * @exception BadArgumentException Inner angle track already exists.
	 */
	virtual anim::IKeyframedFloatTrack*						CreateInnerAngleTrack() = 0;

	/**
	 * Creates procedural track controlling cone's inner angle.
	 * @param type Track type.
	 * @return Created inner angle track.
	 * @exception BadArgumentException Inner angle track already exists.
	 */
	virtual anim::IProceduralFloatTrack*					CreateInnerAngleTrack( const anim::AnimationTrack& type ) = 0;

	/**
	 * Creates keyframed track controlling cone's outer angle.
	 * @return Created outer angle track.
	 * @exception BadArgumentException Outer angle track already exists.
	 */
	virtual anim::IKeyframedFloatTrack*						CreateOuterAngleTrack() = 0;

	/**
	 * Creates procedural track controlling cone's outer angle.
	 * @param type Track type.
	 * @return Created outer angle track.
	 * @exception BadArgumentException Outer angle track already exists.
	 */
	virtual anim::IProceduralFloatTrack*					CreateOuterAngleTrack( const anim::AnimationTrack& type ) = 0;

	/**
	 * Creates keyframed track controlling light falloff.
	 * @return Created falloff track.
	 * @exception BadArgumentException Falloff track already exists.
	 */
	virtual anim::IKeyframedFloatTrack*						CreateFalloffTrack() = 0;

	/**
	 * Creates procedural track controlling light falloff.
	 * @param type Track type.
	 * @return Created falloff track.
	 * @exception BadArgumentException Falloff track already exists.
	 */
	virtual anim::IProceduralFloatTrack*					CreateFalloffTrack( const anim::AnimationTrack& type ) = 0;
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_ICONELIGHTANIMATIONCONTROLLER_
