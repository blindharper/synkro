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
// Purpose: Defines abstract node record controller.
//==============================================================================
#ifndef _SYNKRO_SCENE_INODERECORDCONTROLLER_
#define _SYNKRO_SCENE_INODERECORDCONTROLLER_


#include "config.h"
#include <anim/IRecordAnimationController.h>


namespace synkro
{


namespace scene
{


/**
 * Record controller for an abstract scene node.
 */
iface INodeRecordController :
	public anim::IRecordAnimationController
{
public:
	/**
	 * Creates a track containing node transformation.
	 */
	virtual anim::IKeyframedMatrix4x4Track*					CreateTransformTrack() = 0;

	/**
	 * Creates a track containing node position.
	 */
	virtual anim::IKeyframedVector3Track*					CreatePositionTrack() = 0;

	/**
	 * Creates a track containing node orientation.
	 */
	virtual anim::IKeyframedQuaternionTrack*				CreateOrientationTrack() = 0;

	/**
	 * Creates a track containing node scale.
	 */
	virtual anim::IKeyframedVector3Track*					CreateScaleTrack() = 0;
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_INODERECORDCONTROLLER_
