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
// Purpose: Generic mesh batch animation controller implementation.
//==============================================================================
#ifndef _SYNKRO_SCENE_MESHBATCHANIMATIONCONTROLLERIMPL_
#define _SYNKRO_SCENE_MESHBATCHANIMATIONCONTROLLERIMPL_


#include "config.h"
#include "NodeAnimationControllerImpl.h"
#include <scene/IMeshBatchAnimationController.h>
#include <scene/IPointMeshBatch.h>
#include <scene/ILineMeshBatch.h>
#include <scene/ITriangleMeshBatch.h>
#include "MeshBatchProperty.h"


namespace synkro
{


namespace scene
{


// Generic mesh batch animation controller implementation.
template <class T, class B>
class MeshBatchAnimationControllerImpl :
	public NodeAnimationControllerImpl<T>
{
public:
	// Constructor & destructor.
	MeshBatchAnimationControllerImpl( B* batch, anim::IAnimationSystem* animationSystem, anim::IAnimation* animation, anim::AnimationListener* listener );
	virtual ~MeshBatchAnimationControllerImpl();

	// IController methods.
	virtual void											Update( Double delta );

	// IAnimationController methods.
	virtual void											SetAnimation( anim::IAnimation* animation );

	// INodeAnimationController methods.
	virtual IMeshBatchAnimationController*					AsMeshBatch() const;

	// IMeshBatchAnimationController methods.
	virtual anim::IKeyframedRangeTrack*						CreateRangeTrack();

protected:
	B*														_batch;
	anim::IAnimationRangeTrack*								_trackRange;
};


#include "MeshBatchAnimationControllerImpl.inl"


typedef class MeshBatchAnimationControllerImpl<IMeshBatchAnimationController, IPointMeshBatch> PointMeshBatchAnimationController;
typedef class MeshBatchAnimationControllerImpl<IMeshBatchAnimationController, ILineMeshBatch> LineMeshBatchAnimationController;
typedef class MeshBatchAnimationControllerImpl<IMeshBatchAnimationController, ITriangleMeshBatch> TriangleMeshBatchAnimationController;


} // scene


} // synkro


#endif // _SYNKRO_SCENE_MESHBATCHANIMATIONCONTROLLERIMPL_
