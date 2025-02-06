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
// Purpose: Defines Animation controller for skeleton.
//==============================================================================
#ifndef _SYNKRO_SCENE_ISKELETONANIMATIONCONTROLLER_
#define _SYNKRO_SCENE_ISKELETONANIMATIONCONTROLLER_


#include "config.h"
#include <anim/IPlaybackAnimationController.h>


namespace synkro
{


namespace scene
{


/**
 * Animation controller for skeleton.
 */
iface ISkeletonAnimationController :
	public anim::IPlaybackAnimationController
{
public:
	/**
	 * Sets active animation set by index.
	 * @param index Animation set index.
	 * @exception BadArgumentException Animation set not found.
	 */
	virtual void											SetAnimationSet( UInt index ) = 0;

	/**
	 * Sets active animation set by name.
	 * @param name Animation set name.
	 * @exception BadArgumentException Animation set not found.
	 */
	virtual void											SetAnimationSet( const lang::String& name ) = 0;

	/**
	 * Sets weight of a particular animation set.
	 * @param name Animation set name.
	 * @param weight New animation set weight.
	 * @param delta Time interval in which to apply the weight.
	 */
	virtual void											SetAnimationSetWeight( const lang::String& name, Float weight, Double delta ) = 0;

	/**
	 * Retrieves weight of a particular animation set.
	 * @param name Animation set name.
	 */
	virtual Float											GetAnimationSetWeight( const lang::String& name ) const = 0;
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_ISKELETONANIMATIONCONTROLLER_
