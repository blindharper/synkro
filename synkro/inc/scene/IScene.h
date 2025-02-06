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
// Purpose: Defines 3D scene.
//==============================================================================
#ifndef _SYNKRO_SCENE_ISCENE_
#define _SYNKRO_SCENE_ISCENE_


#include "config.h"
#include <core/IObject.h>
#include <lang/String.h>
#include <math/Vector3.h>


namespace synkro
{


namespace scene
{


/**
 * 3D scene.
 */
iface IScene :
	public core::IObject
{
public:
	/**
	 * Creates triangle mesh node with the given name.
	 * @param parent Parent node.
	 * @param name Node name.
	 * @param material Mesh material.
	 * @param skeleton Optional skeleton to assign to mesh.
	 * @return Created node.
	 */
	virtual ITriangleMesh*									CreateTriangleMesh( INode* parent, const lang::String& name, mat::IVisualMaterial* material, ISkeleton* skeleton ) = 0;

	/**
	 * Creates a batch of triangle mesh nodes.
	 * @param material Mesh material.
	 * @param skeleton Optional skeleton to assign to mesh.
	 * @param capacity Number of mesh instances to allocate.
	 * @return Created mesh batch.
	 */
	virtual ITriangleMeshBatch*								CreateTriangleMeshBatch( mat::IVisualMaterial* material, ISkeleton* skeleton, UInt capacity ) = 0;

	/**
	 * Picks a mesh that is hit by the given ray.
	 * @param origin Coordinate of ray origin.
	 * @param direction Ray direction.
	 * @param [out] distance Distance at which ray intersects the mesh.
	 * @return Picked mesh, if one is found, or null otherwise.
	 */
	virtual ITriangleMesh*									PickMesh( const math::Vector3& origin, const math::Vector3& direction, Float* distance ) const = 0;

	/**
	 * Retrieves underlying rendering queue.
	 */
	virtual gfx::ISceneRenderQueue*							GetRenderQueue() const = 0;

	/**
	 * Indicates whether the scene is lit.
	 */
	virtual Bool											IsLit() const = 0;
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_ISCENE_
