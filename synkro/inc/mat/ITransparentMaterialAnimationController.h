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
// Purpose: Defines animation controller for transparent material.
//==============================================================================
#ifndef _SYNKRO_MAT_ITRANSPARENTMATERIALANIMATIONCONTROLLER_
#define _SYNKRO_MAT_ITRANSPARENTMATERIALANIMATIONCONTROLLER_


#include "config.h"
#include <mat/ISimpleMaterialAnimationController.h>


namespace synkro
{


namespace mat
{


/**
 * Animation controller for transparent material.
 */
iface ITransparentMaterialAnimationController :
	public ISimpleMaterialAnimationController
{
public:
	/**
	 * Creates keyframed track controlling material's opacity.
	 * @return Created opacity track.
	 * @exception BadArgumentException Opacity track already exists.
	 */
	virtual anim::IKeyframedFloatTrack*						CreateOpacityTrack() = 0;

	/**
	 * Creates procedural track controlling material's opacity.
	 * @param type Track type.
	 * @return Created opacity track.
	 * @exception BadArgumentException Opacity track already exists.
	 */
	virtual anim::IProceduralFloatTrack*					CreateOpacityTrack( const anim::AnimationTrack& type ) = 0;

	/**
	 * Creates expression track controlling material's opacity.
	 * @param script Expression script.
	 * @return Created opacity track.
	 */
	virtual anim::IExpressionFloatTrack*					CreateOpacityTrack( anim::IExpressionScript* script ) = 0;

	/**
	 * Creates expression track controlling material's opacity.
	 * @param expression Expression text.
	 * @return Created opacity track.
	 */
	virtual anim::IExpressionFloatTrack*					CreateOpacityTrack( const lang::String& expression ) = 0;
};


} // mat


} // synkro


#endif // _SYNKRO_MAT_ITRANSPARENTMATERIALANIMATIONCONTROLLER_
