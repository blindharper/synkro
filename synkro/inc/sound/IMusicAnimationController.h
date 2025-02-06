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
// Purpose: Defines animation controller for music track.
//==============================================================================
#ifndef _SYNKRO_SOUND_IMUSICANIMATIONCONTROLLER_
#define _SYNKRO_SOUND_IMUSICANIMATIONCONTROLLER_


#include "config.h"
#include <anim/IPlaybackAnimationController.h>


namespace synkro
{


namespace sound
{


/**
 * Music animation controller.
 */
iface IMusicAnimationController :
	public anim::IPlaybackAnimationController
{
public:
	/**
	 * Creates keyframed track controlling music volume.
	 */
	virtual anim::IKeyframedIntTrack*						CreateVolumeTrack() = 0;

	/**
	 * Creates keyframed track controlling music pan.
	 */
	virtual anim::IKeyframedIntTrack*						CreatePanTrack() = 0;
};


} // sound


} // synkro


#endif // _SYNKRO_SOUND_IMUSICANIMATIONCONTROLLER_
