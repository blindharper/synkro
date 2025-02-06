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
// Purpose: Defines animation controller for fog effect.
//==============================================================================
#ifndef _SYNKRO_SCENE_IFOGANIMATIONCONTROLLER_
#define _SYNKRO_SCENE_IFOGANIMATIONCONTROLLER_


#include "config.h"
#include <anim/IPlaybackAnimationController.h>


namespace synkro
{


namespace scene
{


/**
 * Animation controller for fog effect.
 */
iface IFogAnimationController :
	public anim::IPlaybackAnimationController
{
public:
	/**
	 * Creates keyframed track controlling fog color.
	 * @return Created color track.
	 * @exception BadArgumentException Color track already exists.
	 */
	virtual anim::IKeyframedColorTrack*						CreateColorTrack() = 0;

	/**
	 * Creates procedural track controlling fog color.
	 * @param type Track type.
	 * @return Created color track.
	 * @exception BadArgumentException Color track already exists.
	 */
	virtual anim::IProceduralColorTrack*					CreateColorTrack( const anim::AnimationTrack& type ) = 0;

	/**
	 * Creates keyframed track controlling fog density.
	 * @return Created density track.
	 * @exception BadArgumentException Density track already exists.
	 */
	virtual anim::IKeyframedFloatTrack*						CreateDensityTrack() = 0;

	/**
	 * Creates procedural track controlling fog density.
	 * @param type Track type.
	 * @return Created density track.
	 * @exception BadArgumentException Density track already exists.
	 */
	virtual anim::IProceduralFloatTrack*					CreateDensityTrack( const anim::AnimationTrack& type ) = 0;

	/**
	 * Creates keyframed track controlling fog start distance.
	 * @return Created start track.
	 * @exception BadArgumentException Start track already exists.
	 */
	virtual anim::IKeyframedFloatTrack*						CreateStartTrack() = 0;

	/**
	 * Creates procedural track controlling fog start distance.
	 * @param type Track type.
	 * @return Created start track.
	 * @exception BadArgumentException Start track already exists.
	 */
	virtual anim::IProceduralFloatTrack*					CreateStartTrack( const anim::AnimationTrack& type ) = 0;

	/**
	 * Creates keyframed track controlling fog end distance.
	 * @return Created end track.
	 * @exception BadArgumentException End track already exists.
	 */
	virtual anim::IKeyframedFloatTrack*						CreateEndTrack() = 0;

	/**
	 * Creates procedural track controlling fog end distance.
	 * @param type Track type.
	 * @return Created end track.
	 * @exception BadArgumentException End track already exists.
	 */
	virtual anim::IProceduralFloatTrack*					CreateEndTrack( const anim::AnimationTrack& type ) = 0;
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_IFOGANIMATIONCONTROLLER_
