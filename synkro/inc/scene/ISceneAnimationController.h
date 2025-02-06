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
// Purpose: Defines animation controller for scene.
//==============================================================================
#ifndef _SYNKRO_SCENE_ISCENEANIMATIONCONTROLLER_
#define _SYNKRO_SCENE_ISCENEANIMATIONCONTROLLER_


#include "config.h"
#include <anim/IPlaybackAnimationController.h>


namespace synkro
{


namespace scene
{


/**
 * Animation controller for a scene.
 */
iface ISceneAnimationController :
	public anim::IPlaybackAnimationController
{
public:
	/**
	 * Creates keyframed track controlling scene ambient light color.
	 * @return Created ambient light color track.
	 * @exception BadArgumentException Ambient light color track already exists.
	 */
	virtual anim::IKeyframedColorTrack*						CreateAmbientLightColorTrack() = 0;

	/**
	 * Creates procedural track controlling scene ambient light color.
	 * @param type Track type.
	 * @return Created ambient light color track.
	 * @exception BadArgumentException Ambient light color track already exists.
	 */
	virtual anim::IProceduralColorTrack*					CreateAmbientLightColorTrack( const anim::AnimationTrack& type ) = 0;

	/**
	 * Creates expression track controlling scene ambient light color.
	 * @param script Expression script.
	 * @return Created ambient color track.
	 * @exception BadArgumentException Ambient color track already exists.
	 */
	virtual anim::IExpressionColorTrack*					CreateAmbientLightColorTrack( anim::IExpressionScript* script ) = 0;

	/**
	 * Creates expression track controlling scene ambient light color.
	 * @param expression Expression text.
	 * @return Created ambient color track.
	 * @exception BadArgumentException Ambient color track already exists.
	 */
	virtual anim::IExpressionColorTrack*					CreateAmbientLightColorTrack( const lang::String& expression ) = 0;

	/**
	 * Creates keyframed track controlling scene ambient light intensity.
	 * @return Created ambient light intensity track.
	 * @exception BadArgumentException Ambient light intensity track already exists.
	 */
	virtual anim::IKeyframedFloatTrack*						CreateAmbientLightIntensityTrack() = 0;

	/**
	 * Creates procedural track controlling scene ambient light intensity.
	 * @param type Track type.
	 * @return Created ambient light intensity track.
	 * @exception BadArgumentException Ambient light intensity track already exists.
	 */
	virtual anim::IProceduralFloatTrack*					CreateAmbientLightIntensityTrack( const anim::AnimationTrack& type ) = 0;

	/**
	 * Creates expression track controlling scene ambient light intensity.
	 * @param script Expression script.
	 * @return Created intensity track.
	 * @exception BadArgumentException Intensity track already exists.
	 */
	virtual anim::IExpressionFloatTrack*					CreateAmbientLightIntensityTrack( anim::IExpressionScript* script ) = 0;

	/**
	 * Creates expression track controlling scene ambient light intensity.
	 * @param expression Expression text.
	 * @return Created intensity track.
	 * @exception BadArgumentException Intensity track already exists.
	 */
	virtual anim::IExpressionFloatTrack*					CreateAmbientLightIntensityTrack( const lang::String& expression ) = 0;
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_ISCENEANIMATIONCONTROLLER_
