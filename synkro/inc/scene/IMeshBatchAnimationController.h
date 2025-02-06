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
// Purpose: Defines mesh batch animation controller.
//==============================================================================
#ifndef _SYNKRO_SCENE_IMESHBATCHANIMATIONCONTROLLER_
#define _SYNKRO_SCENE_IMESHBATCHANIMATIONCONTROLLER_


#include "config.h"
#include <scene/INodeAnimationController.h>


namespace synkro
{


namespace scene
{


/**
 * Animation controller for triangle mesh batch.
 */
iface IMeshBatchAnimationController :
	public INodeAnimationController
{
public:
	/**
	 * Creates keyframed track controlling active instance range.
	 */
	virtual anim::IKeyframedRangeTrack*						CreateRangeTrack() = 0;
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_IMESHBATCHANIMATIONCONTROLLER_
