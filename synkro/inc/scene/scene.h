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
// Purpose: 'scene' namespace includes.
//==============================================================================
#ifndef _SYNKRO_SCENE_
#define _SYNKRO_SCENE_


#include <scene/ICamera.h>
#include <scene/ICurve.h>
#include <scene/IFog.h>
#include <scene/IFogAnimationController.h>
#include <scene/IOmniLight.h>
#include <scene/IConeLight.h>
#include <scene/IDirectLight.h>
#include <scene/ILineMeshBatch.h>
#include <scene/IPointMeshBatch.h>
#include <scene/ITriangleMeshBatch.h>
#include <scene/IMeshBatchAnimationController.h>
#include <scene/ISkeleton.h>
#include <scene/ISkeletonAnimationController.h>
#include <scene/IPointSet.h>
#include <scene/IPointSetAnimationController.h>
#include <scene/ILineSet.h>
#include <scene/ILineSetAnimationController.h>
#include <scene/ITriangleSet.h>
#include <scene/IMeshCodec.h>
#include <scene/IMeshCodecFactory.h>
#include <scene/ISceneAnimationController.h>
#include <scene/ILookAtConstraint.h>
#include <scene/IParentConstraint.h>
#include <scene/IConeLightAnimationController.h>
#include <scene/IOmniLightAnimationController.h>
#include <scene/ICameraAnimationController.h>
#include <scene/IPrimitive.h>
#include <scene/ISceneManager.h>
#include <scene/ISceneEx.h>
#include <scene/IOmniSound.h>
#include <scene/IConeSound.h>
#include <scene/ISoundAnimationController.h>
#include <scene/ICameraRecordController.h>
#include <scene/MeshBuilder.h>


#define PtrCamera P(synkro::scene::ICamera)
#define PtrCameraRecordController P(synkro::scene::ICameraRecordController)
#define PtrCurve P(synkro::scene::ICurve)
#define PtrConeLight P(synkro::scene::IConeLight)
#define PtrConeSound P(synkro::scene::IConeSound)
#define PtrDirectLight P(synkro::scene::IDirectLight)
#define PtrOmniLight P(synkro::scene::IOmniLight)
#define PtrFog P(synkro::scene::IFog)
#define PtrFogAnimationController P(synkro::scene::IFogAnimationController)
#define PtrLineMesh P(synkro::scene::ILineMesh)
#define PtrTriangleMesh P(synkro::scene::ITriangleMesh)
#define PtrTriangleMeshBatch P(synkro::scene::ITriangleMeshBatch)
#define PtrNodeAnimationController P(synkro::scene::INodeAnimationController)
#define PtrNode P(synkro::scene::INode)
#define PtrLightAnimationController P(synkro::scene::ILightAnimationController)
#define PtrLookAtConstraint P(synkro::scene::ILookAtConstraint)
#define PtrParentConstraint P(synkro::scene::IParentConstraint)
#define PtrSceneEx P(synkro::scene::ISceneEx)
#define PtrSkeleton P(synkro::scene::ISkeleton)
#define PtrSkeletonAnimationController P(synkro::scene::ISkeletonAnimationController)


namespace synkro
{


/**
 * The 'scene' namespace contains interfaces
 * which define and manipulate objects in 3D space.
 */
namespace scene
{
} // scene


} // synkro


#endif // _SYNKRO_SCENE_
