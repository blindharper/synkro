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
// Purpose: Defines line mesh node.
//==============================================================================
#ifndef _SYNKRO_SCENE_ILINEMESH_
#define _SYNKRO_SCENE_ILINEMESH_


#include "config.h"
#include <scene/IMesh.h>
#include <scene/ColorMode.h>
#include <lang/Range.h>
#include <img/Color.h>


namespace synkro
{


namespace scene
{


/**
 * Line mesh node.
 */
iface ILineMesh :
	public IMesh
{
public:
	/**
	 * Creates line list primitive.
	 * @param name Primitive name. Set to String::Null to create base primitive.
	 * @param vertexCount Total number of vertices in the list.
	 * @param indexCount Number of vertex indices.
	 * @param adjacency Indicates whether the list contains adjacency information.
	 * @param colorMode Indicates whether the elements should contain color attribute.
	 * @param transform Line list transformation.
	 * @return Created line list.
	 * @exception InvalidOperationException name is String::Null and base primitive already exists.
	 */
	virtual ILineSet*										CreateLineList( const lang::String& name, UInt vertexCount, UInt indexCount, Bool adjacency, const ColorMode& colorMode, const math::Matrix4x4& transform ) = 0;

	/**
	 * Creates line list primitive in 4D.
	 * @param name Primitive name. Set to String::Null to create base primitive.
	 * @param vertexCount Total number of vertices in the list.
	 * @param indexCount Number of vertex indices.
	 * @param adjacency Indicates whether the list contains adjacency information.
	 * @param colorMode Indicates whether the elements should contain color attribute.
	 * @param transform Line list transformation.
	 * @return Created line list.
	 * @exception InvalidOperationException name is String::Null and base primitive already exists.
	 */
	virtual ILineSet*										CreateLineList4D( const lang::String& name, UInt vertexCount, UInt indexCount, Bool adjacency, const ColorMode& colorMode, const math::Matrix4x4& transform ) = 0;

	/**
	 * Creates line strip primitive.
	 * @param name Primitive name. Set to String::Null to create base primitive.
	 * @param vertexCount Total number of vertices in the strip.
	 * @param indexCount Number of vertex indices.
	 * @param adjacency Indicates whether the strip contains adjacency information.
	 * @param colorMode Indicates whether the elements should contain color attribute.
	 * @param transform Line strip transformation.
	 * @return Created line strip.
	 * @exception InvalidOperationException name is String::Null and base primitive already exists.
	 */
	virtual ILineSet*										CreateLineStrip( const lang::String& name, UInt vertexCount, UInt indexCount, Bool adjacency, const ColorMode& colorMode, const math::Matrix4x4& transform ) = 0;

	/**
	 * Creates line set primitive as a reference to base primitive.
	 * @param name Primitive name.
	 * @param range Range of the base primitive elements to include in this primitive.
	 * @return Created line set.
	 * @exception InvalidOperationException Base primitive does not exist.
	 */
	virtual ILineSet*										CreateLineSet( const lang::String& name, const lang::Range& range ) = 0;

	/**
	 * Sets the color for all mesh's primitives.
	 * @param color Color to assign to primitives.
	 */
	virtual void											SetColor( const img::Color& color ) = 0;

	/**
	 * Casts mesh to line mesh batch.
	 * @return Non-null for line mesh batch, nullptr otherwise.
	 */
	virtual ILineMeshBatch*									AsBatch() const = 0;
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_ILINEMESH_
