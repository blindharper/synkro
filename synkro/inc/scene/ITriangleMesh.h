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
// Purpose: Defines triangle mesh node.
//==============================================================================
#ifndef _SYNKRO_SCENE_ITRIANGLEMESH_
#define _SYNKRO_SCENE_ITRIANGLEMESH_


#include "config.h"
#include <scene/IMesh.h>
#include <scene/MeshCodec.h>
#include <core/DataMode.h>
#include <lang/Range.h>
#include <img/Color.h>


namespace synkro
{


namespace scene
{


/**
 * Triangle mesh node.
 */
iface ITriangleMesh :
	public IMesh
{
public:
	/**
	 * Creates triangle list primitive.
	 * @param name Primitive name. Set to String::Null to create base primitive.
	 * @param vertexCount Total number of vertices in the list.
	 * @param indexCount Number of vertex indices.
	 * @param adjacency Indicates whether the list contains adjacency information.
	 * @param transform Triangle list transformation.
	 * @return Created triangle list.
	 * @exception InvalidOperationException name is String::Null and base primitive already exists.
	 */
	virtual ITriangleSet*									CreateTriangleList( const lang::String& name, UInt vertexCount, UInt indexCount, Bool adjacency, const math::Matrix4x4& transform ) = 0;

	/**
	 * Creates triangle strip primitive.
	 * @param name Primitive name. Set to String::Null to create base primitive.
	 * @param vertexCount Total number of vertices in the strip.
	 * @param indexCount Number of vertex indices.
	 * @param adjacency Indicates whether the strip contains adjacency information.
	 * @param transform Triangle strip transformation.
	 * @return Created triangle strip.
	 * @exception InvalidOperationException name is String::Null and base primitive already exists.
	 */
	virtual ITriangleSet*									CreateTriangleStrip( const lang::String& name, UInt vertexCount, UInt indexCount, Bool adjacency, const math::Matrix4x4& transform ) = 0;

	/**
	 * Creates triangle set primitive.
	 * @param name Primitive name.
	 * @param range Range of the base primitive elements to include in this primitive.
	 * @return Created triangle set.
	 * @exception InvalidOperationException name is String::Null and base primitive already exists.
	 */
	virtual ITriangleSet*									CreateTriangleSet( const lang::String& name, const lang::Range& range ) = 0;

	/**
	 * Saves mesh to the stream in the given format.
	 * @param stream Stream to which to save mesh.
	 * @param mode Data mode to save data in.
	 * @param type Mesh codec type.
	 */
	virtual void											Save( io::IStream* stream, const core::DataMode& mode, const MeshCodec& type ) = 0;

	/**
	 * Saves mesh to the stream in the given format. Mesh type is guessed from stream name.
	 * @param stream Stream to which to save mesh.
	 * @param mode Data mode to save data in.
	 */
	virtual void											Save( io::IStream* stream, const core::DataMode& mode ) = 0;

	/**
	 * Retrieves mesh skeleton.
	 */
	virtual ISkeleton*										GetSkeleton() const = 0;

	/**
	 * Retrieves mesh material.
	 */
	virtual mat::IVisualMaterial*							GetMaterial() const = 0;

	/**
	 * Retrieves scene holding the node.
	 * @return Scene holding the node.
	 */
	virtual IScene*											GetScene() const = 0;

	/**
	 * Casts mesh to triangle mesh batch.
	 * @return Non-null for triangle mesh batch, nullptr otherwise.
	 */
	virtual ITriangleMeshBatch*								AsBatch() const = 0;
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_ITRIANGLEMESH_
