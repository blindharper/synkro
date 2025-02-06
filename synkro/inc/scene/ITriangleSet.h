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
// Purpose: Defines triangle set primitive.
//==============================================================================
#ifndef _SYNKRO_SCENE_ITRIANGLESET_
#define _SYNKRO_SCENE_ITRIANGLESET_


#include "config.h"
#include <scene/IPrimitive.h>
#include <math/Vector2.h>
#include <img/Color.h>


namespace synkro
{


namespace scene
{


/**
 * A collection of triangles.
 */
iface ITriangleSet :
	public IPrimitive
{
public:
	/**
	 * Begins setting bone weights.
	 * @return True if succeeded, false otherwise.
	 */
	virtual Bool											BeginSetBoneWeights() = 0;

	/**
	 * Commits bone weights.
	 */
	virtual void											EndSetBoneWeights() = 0;

	/**
	 * Sets vertex position coordinates.
	 * @param positions Array of vertex positions.
	 * @param start Index of the starting vertex.
	 * @param count Total number of vertices.
	 */
	virtual void											SetPositions( const math::Vector3* positions, UInt start, UInt count ) = 0;

	/**
	 * Sets vertex normals.
	 * @param normals Array of vertex normals.
	 * @param start Index of the starting vertex.
	 * @param count Total number of vertices.
	 */
	virtual void											SetNormals( const math::Vector3* normals, UInt start, UInt count ) = 0;

	/**
	 * Sets vertex colors.
	 * @param colors Array of vertex colors.
	 * @param start Index of the starting vertex.
	 * @param count Total number of vertices.
	 */
	virtual void											SetColors( const img::Color* colors, UInt start, UInt count ) = 0;

	/**
	 * Sets vertex 2D-texture coordinates.
	 * @param coords Array of texture coordinates.
	 * @param start Index of the starting vertex.
	 * @param count Total number of vertices.
	 */
	virtual void											SetTextureCoordinates( const math::Vector2* coords, UInt start, UInt count ) = 0;

	/**
	 * Sets indices.
	 * @param indices Index data.
	 * @param start Index of the starting vertex.
	 * @param count Total number of indices to set.
	 */
	virtual void											SetIndices( const UInt* indices, UInt start, UInt count ) = 0;

	/**
	 * Sets bone weights.
	 * @param index Index of the vertex for which to set weights.
	 * @param bones Array of bone indices.
	 * @param weights Array of bone weights.
	 * @param count Total number of weights.
	 */
	virtual void											SetBoneWeights( UInt index, const Byte* bones, const Float* weights, UInt count ) = 0;

	/**
	 * Sets bones transform matrices.
	 * @param transforms Array of bones transform matrices.
	 * @param count Total number of transform matrices.
	 */
	virtual void											SetBoneTransforms( const math::Matrix4x4* transforms, UInt count ) = 0;

	/**
	 * Retrieves vertex position coordinates.
	 * @param [out] positions Array of vertex positions.
	 * @param start Index of the starting vertex.
	 * @param count Total number of vertices.
	 * @return True if succeeded, or false otherwise.
	 */
	virtual Bool											GetPositions( math::Vector3* positions, UInt start, UInt count ) const = 0;

	/**
	 * Retrieves vertex normals.
	 * @param [out] normals Array of vertex normals.
	 * @param start Index of the starting vertex.
	 * @param count Total number of vertices.
	 * @return True if succeeded, or false otherwise.
	 */
	virtual Bool											GetNormals( math::Vector3* normals, UInt start, UInt count ) const = 0;

	/**
	 * Retrieves vertex colors.
	 * @param [out] colors Array of vertex colors.
	 * @param start Index of the starting vertex.
	 * @param count Total number of vertices.
	 * @return True if succeeded, or false otherwise.
	 */
	virtual Bool											GetColors( img::Color* colors, UInt start, UInt count ) const = 0;

	/**
	 * Retrieves vertex 2D-texture coordinates.
	 * @param [out] coords Array of texture coordinates.
	 * @param start Index of the starting vertex.
	 * @param count Total number of vertices.
	 * @return True if succeeded, or false otherwise.
	 */
	virtual Bool											GetTextureCoordinates( math::Vector2* coords, UInt start, UInt count ) const = 0;

	/**
	 * Retrieves indices.
	 * @param [out] indices Index data.
	 * @param start Index of the starting vertex.
	 * @param count Total number of indices to set.
	 * @return True if succeeded, or false otherwise.
	 */
	virtual Bool											GetIndices( UInt* indices, UInt start, UInt count ) const = 0;

	/**
	 * Retrieves underlying rendering object.
	 */
	virtual gfx::ISceneRenderObject*						GetRenderObject() const = 0;
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_ITRIANGLESET_
