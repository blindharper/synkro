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
// Purpose: Defines camera node record controller.
//==============================================================================
#ifndef _SYNKRO_SCENE_ICAMERARECORDCONTROLLER_
#define _SYNKRO_SCENE_ICAMERARECORDCONTROLLER_


#include "config.h"
#include <scene/INodeRecordController.h>


namespace synkro
{


namespace scene
{


/**
 * Record controller for a camera node.
 */
iface ICameraRecordController :
	public INodeRecordController
{
public:
	/**
	 * Creates a track containing camera field of view.
	 */
	virtual anim::IKeyframedFloatTrack*						CreateFieldOfViewTrack() = 0;
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_ICAMERARECORDCONTROLLER_
