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
// Purpose: Defines Animation controller for line set.
//==============================================================================
#ifndef _SYNKRO_SCENE_ILINESETANIMATIONCONTROLLER_
#define _SYNKRO_SCENE_ILINESETANIMATIONCONTROLLER_


#include "config.h"
#include <scene/IPrimitiveAnimationController.h>


namespace synkro
{


namespace scene
{


/**
 * Animation controller for line set.
 */
iface ILineSetAnimationController :
	public IPrimitiveAnimationController
{
public:
	/**
	 * Creates keyframed track controlling line set color.
	 * @return Created color track.
	 * @exception BadArgumentException color track already exists.
	 */
	virtual anim::IKeyframedColorTrack*						CreateColorTrack() = 0;

	/**
	 * Creates procedural track controlling line set color.
	 * @param type Track type.
	 * @return Created color track.
	 * @exception BadArgumentException color track already exists.
	 */
	virtual anim::IProceduralColorTrack*					CreateColorTrack( const anim::AnimationTrack& type ) = 0;

	/**
	 * Creates expression track controlling line set color.
	 * @param script Expression script.
	 * @return Created diffuse color track.
	 * @exception BadArgumentException color track already exists.
	 */
	virtual anim::IExpressionColorTrack*					CreateColorTrack( anim::IExpressionScript* script ) = 0;

	/**
	 * Creates expression track controlling line set color.
	 * @param expression Expression text.
	 * @return Created diffuse color track.
	 * @exception BadArgumentException color track already exists.
	 */
	virtual anim::IExpressionColorTrack*					CreateColorTrack( const lang::String& expression ) = 0;
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_ILINESETANIMATIONCONTROLLER_
