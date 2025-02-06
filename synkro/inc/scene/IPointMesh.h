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
// Purpose: Defines point mesh node.
//==============================================================================
#ifndef _SYNKRO_SCENE_IPOINTMESH_
#define _SYNKRO_SCENE_IPOINTMESH_


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
 * Point mesh node.
 */
iface IPointMesh :
	public IMesh
{
public:
	/**
	 * Creates point list primitive.
	 * @param name Primitive name. Set to String::Null to create base primitive.
	 * @param count Total number of points in the list.
	 * @param size Point size, in pixels.
	 * @param colorMode Indicates whether the points should contain color attribute.
	 * @param transform Point list transformation.
	 * @return Created point list.
	 * @exception InvalidOperationException name is String::Null and base primitive already exists.
	 */
	virtual IPointSet*										CreatePointList( const lang::String& name, UInt count, Float size, const ColorMode& colorMode, const math::Matrix4x4& transform ) = 0;

	/**
	 * Creates point list primitive as a reference to base primitive.
	 * @param name Primitive name.
	 * @param range Range of the base primitive elements to include in this primitive.
	 * @return Created point set.
	 * @exception InvalidOperationException Base primitive does not exist.
	 */
	virtual IPointSet*										CreatePointSet( const lang::String& name, const lang::Range& range ) = 0;

	/**
	 * Sets the color for all mesh's primitives.
	 * @param color Color to assign to primitives.
	 */
	virtual void											SetColor( const img::Color& color ) = 0;

	/**
	 * Casts mesh to point mesh batch.
	 * @return Non-null for point mesh batch, nullptr otherwise.
	 */
	virtual IPointMeshBatch*								AsBatch() const = 0;
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_IPOINTMESH_
