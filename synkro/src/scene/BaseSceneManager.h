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
// Purpose: Defines base scene manager.
//==============================================================================
#ifndef _SYNKRO_SCENE_BASESCENEMANAGER_
#define _SYNKRO_SCENE_BASESCENEMANAGER_


#include "config.h"
#include <scene/MeshCodec.h>
#include <core/DataMode.h>
#include <math/Matrix4x4.h>


namespace synkro
{


namespace scene
{


// Base scene manager.
class BaseSceneManager
{
public:
	virtual ITriangleMesh*									LoadMesh( IScene* scene, io::IStream* stream, mat::IVisualMaterial* material, ISkeleton* skeleton, UInt instanceCapacity, const MeshCodec& type ) = 0;
	virtual void											SaveMesh( const ITriangleMesh* mesh, io::IStream* stream, const core::DataMode& mode, const MeshCodec& type ) = 0;
	virtual void											SaveSkeleton( const ISkeleton* skeleton, io::IStream* stream, const core::DataMode& mode, const MeshCodec& type ) = 0;
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_BASESCENEMANAGER_
