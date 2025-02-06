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
// Purpose: Defines abstract mesh scene node.
//==============================================================================
#ifndef _SYNKRO_SCENE_IMESH_
#define _SYNKRO_SCENE_IMESH_


#include "config.h"
#include <scene/INode.h>


namespace synkro
{


namespace scene
{


/**
 * Mesh node. Used as a container for visual geometry.
 */
iface IMesh :
	public INode
{
public:
	/** 
	 * Sets mesh visibility.
	 * @param show Set to true to make mesh visible, set to false to hide it.
	 */
	virtual void											Show( Bool show ) = 0;

	/**
	 * Retrieves the total number of subsets in the mesh.
	 */
	virtual UInt											GetSubsetCount() const = 0;

	/**
	 * Retrieves subset name by index.
	 * @param index Index of the subset to retrieve.
	 * @exception OutOfRangeException Index is out of range.
	 * @return Requested subset name.
	 */
	virtual lang::String									GetSubsetName( UInt index ) const = 0;

	/**
	 * Retrieves subset by index.
	 * @param index Index of the subset to retrieve.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual IPrimitive*										GetSubset( UInt index ) const = 0;

	/**
	 * Retrieves subset by name.
	 * @param name Name of the subset to retrieve.
	 * @return Requested subset, if one is found or null otherwise.
	 */
	virtual IPrimitive*										GetSubset( const lang::String& name ) const = 0;

	/**
	 * Retrieves mesh's center of masses.
	 * @param [out] center Mesh's center.
	 */
	virtual void											GetCenter( math::Vector3& center ) const = 0;

	/**
	 * Returns union of mesh's primitives bounding spheres.
	 * @return Mesh bounding sphere.
	 */
	virtual Float											GetBoundSphere() const = 0;

	/**
	 * Retrieves mesh visibility.
	 * @return True if mesh is visible, or false otherwise.
	 */
	virtual Bool											IsVisible() const = 0;

	/**
	 * Casts mesh to point mesh.
	 * @return Non-null for point mesh, nullptr otherwise.
	 */
	virtual IPointMesh*										AsPoint() const = 0;

	/**
	 * Casts mesh to line mesh.
	 * @return Non-null for line mesh, nullptr otherwise.
	 */
	virtual ILineMesh*										AsLine() const = 0;

	/**
	 * Casts mesh to triangle mesh.
	 * @return Non-null for triangle mesh, nullptr otherwise.
	 */
	virtual ITriangleMesh*									AsTriangle() const = 0;
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_IMESH_
