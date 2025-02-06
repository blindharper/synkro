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
// Purpose: Defines scene manager.
//==============================================================================
#ifndef _SYNKRO_SCENE_ISCENEMANAGER_
#define _SYNKRO_SCENE_ISCENEMANAGER_


#include "config.h"
#include <core/ISystem.h>
#include <lang/Size.h>
#include <math/Matrix4x4.h>
#include <scene/MeshCodec.h>
#include <scene/MeshBuilder.h>
#include <scene/DebugMode.h>
#include <scene/SceneType.h>


namespace synkro
{


namespace scene
{


/**
 * Scene manager.
 */
iface ISceneManager :
	public core::ISystem
{
public:
	/**
	 * Creates an empty scene of the given type.
	 * @param type Scene type.
	 * @param name Unique scene name.
	 * @param debugMode Indicates which debug geometry to display.
	 * @param lit Indicates whether to enable lighting in the scene.
	 * @return Created scene.
	 */
	virtual ISceneEx*										CreateScene( const SceneType& type, const lang::String& name, const DebugMode& debugMode, Bool lit ) = 0;

	/**
	 * Creates empty scene of default type.
	 * @param name Unique scene name.
	 * @param debugMode Indicates which debug geometry to display.
	 * @param lit Indicates whether to enable lighting in the scene.
	 * @return Created scene.
	 */
	virtual ISceneEx*										CreateScene( const lang::String& name, const DebugMode& debugMode, Bool lit ) = 0;

	/**
	 * Creates triangle mesh skeleton.
	 */
	virtual ISkeleton*										CreateSkeleton() = 0;

	/**
	 * Creates software triangle mesh with the given name.
	 * @param skeleton Optional skeleton to assign to mesh.
	 * @param subsetCount Expected number of subsets in the mesh.
	 * @return Created mesh.
	 */
	virtual ITriangleMesh*									CreateTriangleMesh( ISkeleton* skeleton, UInt subsetCount ) = 0;

	/**
	 * Loads skeleton from stream.
	 * @param stream Stream to load skeleton from.
	 * @param type Mesh codec type.
	 * @return Loaded skeleton.
	 */
	virtual ISkeleton*										LoadSkeleton( io::IStream* stream, const MeshCodec& type ) = 0;

	/**
	 * Loads skeleton from stream. Mesh codec type is guessed from stream name.
	 * @param stream Stream to load skeleton from.
	 * @return Loaded skeleton.
	 */
	virtual ISkeleton*										LoadSkeleton( io::IStream* stream ) = 0;

	/**
	 * Loads software mesh from a stream. Opens stream for reading and closes it after mesh is loaded.
	 * @param stream Stream from which to load mesh.
	 * @param skeleton Optional skeleton to assign to mesh.
	 * @param type Mesh codec type.
	 * @return Loaded mesh if succeeded, or null otherwise.
	 * @exception BadArgumentException Wrong mesh type.
	 */
	virtual ITriangleMesh*									LoadMesh( io::IStream* stream, ISkeleton* skeleton, const MeshCodec& type ) = 0;

	/**
	 * Loads software mesh from a stream. Opens stream for reading and closes it after mesh is loaded.
	 * @param stream Stream from which to load mesh.
	 * @param skeleton Optional skeleton to assign to mesh.
	 * @return Loaded mesh if succeeded, or null otherwise.
	 */
	virtual ITriangleMesh*									LoadMesh( io::IStream* stream, ISkeleton* skeleton ) = 0;

	/**
	 * Builds or re-builds line mesh's primitive with the given parameters.
	 * @param mesh Mesh to fill with geometry.
	 * @param type Mesh type.
	 * @param param1 Set of floating-point parameters.
	 * @param param2 Set of integer parameters.
	 * @param transform Geometry transformation.
	 */
	virtual void											BuildMesh( ILineMesh* mesh, const MeshBuilder& type, const math::Vector4& param1, const lang::Size& param2, const math::Matrix4x4& transform ) = 0;

	/**
	 * Builds or re-builds point mesh's primitive with the given parameters.
	 * @param mesh Mesh to fill with geometry.
	 * @param type Mesh type.
	 * @param param1 Set of floating-point parameters.
	 * @param param2 Set of integer parameters.
	 * @param transform Geometry transformation.
	 */
	virtual void											BuildMesh( IPointMesh* mesh, const MeshBuilder& type, const math::Vector4& param1, const lang::Size& param2, const math::Matrix4x4& transform ) = 0;

	/**
	 * Builds or re-builds triangle mesh's primitive with the given parameters.
	 * @param mesh Mesh to fill with geometry.
	 * @param type Mesh type.
	 * @param param1 Set of floating-point parameters.
	 * @param param2 Set of integer parameters.
	 * @param transform Geometry transformation.
	 */
	virtual void											BuildMesh( ITriangleMesh* mesh, const MeshBuilder& type, const math::Vector4& param1, const lang::Size& param2, const math::Matrix4x4& transform ) = 0;

	/**
	 * Retrieves the total number of scenes.
	 */
	virtual UInt											GetSceneCount() const = 0;

	/**
	 * Retrieves a scene by index.
	 * @param index Index of the scene to retrieve.
	 */
	virtual ISceneEx*										GetScene( UInt index ) const = 0;

	/**
	 * Retrieves a scene by name.
	 * @param name Name of the scene to retrieve.
	 */
	virtual ISceneEx*										GetScene( const lang::String& name ) const = 0;
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_ISCENEMANAGER_
