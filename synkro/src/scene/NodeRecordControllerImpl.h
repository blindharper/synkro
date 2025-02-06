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
// Purpose: Generic node record controller implementation.
//==============================================================================
#ifndef _SYNKRO_SCENE_NODERECORDCONTROLLERIMPL_
#define _SYNKRO_SCENE_NODERECORDCONTROLLERIMPL_


#include "config.h"
#include <anim/RecordControllerImpl.h>
#include <scene/INodeRecordController.h>
#include <scene/INode.h>
#include <scene/NodeProperty.h>
#include <anim/IKeyframedBoolTrack.h>
#include <anim/IKeyframedVector3Track.h>
#include <anim/IKeyframedMatrix4x4Track.h>
#include <anim/IKeyframedQuaternionTrack.h>


namespace synkro
{


namespace scene
{


// Generic node record controller implementation.
template <class T>
class NodeRecordControllerImpl :
	public anim::RecordControllerImpl<T>
{
public:
	// Constructors & destructor.
	NodeRecordControllerImpl( INode* node, anim::IAnimationSystem* animationSystem, anim::IAnimation* animation );
	virtual ~NodeRecordControllerImpl();

	// IController methods.
	virtual void											Update( Double delta );

	// INodeRecordController methods.
	virtual anim::IKeyframedMatrix4x4Track*					CreateTransformTrack();
	virtual anim::IKeyframedVector3Track*					CreatePositionTrack();
	virtual anim::IKeyframedQuaternionTrack*				CreateOrientationTrack();
	virtual anim::IKeyframedVector3Track*					CreateScaleTrack();

protected:
	INode*													_node;
	P(anim::IKeyframedMatrix4x4Track)						_trackTransform;
	P(anim::IKeyframedVector3Track)							_trackPosition;
	P(anim::IKeyframedQuaternionTrack)						_trackOrientation;
	P(anim::IKeyframedVector3Track)							_trackScale;
};


#include "NodeRecordControllerImpl.inl"


} // scene


} // synkro


#endif // _SYNKRO_SCENE_NODERECORDCONTROLLERIMPL_
