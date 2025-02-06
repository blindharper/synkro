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
// Purpose: Defines animation controller for omni light node.
//==============================================================================
#ifndef _SYNKRO_SCENE_IOMNILIGHTANIMATIONCONTROLLER_
#define _SYNKRO_SCENE_IOMNILIGHTANIMATIONCONTROLLER_


#include "config.h"
#include <scene/ILightAnimationController.h>


namespace synkro
{


namespace scene
{


/**
 * Animation controller for omni light node.
 */
iface IOmniLightAnimationController :
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
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_IOMNILIGHTANIMATIONCONTROLLER_
