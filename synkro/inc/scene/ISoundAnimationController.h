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
// Purpose: Defines animation controller for sound source node.
//==============================================================================
#ifndef _SYNKRO_SCENE_ISOUNDANIMATIONCONTROLLER_
#define _SYNKRO_SCENE_ISOUNDANIMATIONCONTROLLER_


#include "config.h"
#include <scene/INodeAnimationController.h>


namespace synkro
{


namespace scene
{


/**
 * Animation controller for sound source node.
 */
iface ISoundAnimationController :
	public INodeAnimationController
{
public:
	/**
	 * Creates keyframed track controlling sound inner volume.
	 * @return Created inner volume track.
	 * @exception BadArgumentException Inner volume track already exists.
	 */
	virtual anim::IKeyframedFloatTrack*						CreateInnerVolumeTrack() = 0;

	/**
	 * Creates procedural track controlling sound inner volume.
	 * @param type Track type.
	 * @return Created inner volume track.
	 * @exception BadArgumentException Inner volume track already exists.
	 */
	virtual anim::IProceduralFloatTrack*					CreateInnerVolumeTrack( const anim::AnimationTrack& type ) = 0;

	/**
	 * Creates keyframed track controlling sound outer volume.
	 * @return Created outer volume track.
	 * @exception BadArgumentException Outer volume track already exists.
	 */
	virtual anim::IKeyframedFloatTrack*						CreateOuterVolumeTrack() = 0;

	/**
	 * Creates procedural track controlling sound outer volume.
	 * @param type Track type.
	 * @return Created outer volume track.
	 * @exception BadArgumentException Outer volume track already exists.
	 */
	virtual anim::IProceduralFloatTrack*					CreateOuterVolumeTrack( const anim::AnimationTrack& type ) = 0;

	/**
	 * Creates keyframed track controlling sound availability.
	 */
	virtual anim::IKeyframedBoolTrack*						CreateAvailabilityTrack() = 0;
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_ISOUNDANIMATIONCONTROLLER_
