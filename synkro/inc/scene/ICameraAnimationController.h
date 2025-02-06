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
// Purpose: Defines animation controller for camera node.
//==============================================================================
#ifndef _SYNKRO_SCENE_ICAMERAANIMATIONCONTROLLER_
#define _SYNKRO_SCENE_ICAMERAANIMATIONCONTROLLER_


#include "config.h"
#include <scene/INodeAnimationController.h>


namespace synkro
{


namespace scene
{


/**
 * Animation controller for camera node.
 */
iface ICameraAnimationController :
	public INodeAnimationController
{
public:
	/**
	 * Creates keyframed track controlling camera's field of view.
	 * @return Created field of view track.
	 * @exception BadArgumentException Field of view track already exists.
	 */
	virtual anim::IKeyframedFloatTrack*						CreateFieldOfViewTrack() = 0;

	/**
	 * Creates procedural track controlling camera's field of view.
	 * @param type Track type.
	 * @return Created field of view track.
	 * @exception BadArgumentException Field of view track already exists.
	 */
	virtual anim::IProceduralFloatTrack*					CreateFieldOfViewTrack( const anim::AnimationTrack& type ) = 0;

	/**
	 * Creates expression track controlling camera's field of view.
	 * @param script Expression script.
	 * @return Created field of view track.
	 */
	virtual anim::IExpressionFloatTrack*					CreateFieldOfViewTrack( anim::IExpressionScript* script ) = 0;

	/**
	 * Creates expression track controlling camera's field of view.
	 * @param expression Expression text.
	 * @return Created field of view track.
	 */
	virtual anim::IExpressionFloatTrack*					CreateFieldOfViewTrack( const lang::String& expression ) = 0;
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_ICAMERAANIMATIONCONTROLLER_
