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
// Purpose: Defines a batch of line mesh nodes.
//==============================================================================
#ifndef _SYNKRO_SCENE_ILINEMESHBATCH_
#define _SYNKRO_SCENE_ILINEMESHBATCH_


#include "config.h"
#include <scene/ILineMesh.h>


namespace synkro
{


namespace scene
{


/**
 * Batch of line mesh nodes.
 */
iface ILineMeshBatch :
	public ILineMesh
{
public:
	/**
	 * Creates an instance of the mesh.
	 * @param parent Parent node.
	 * @param transform Instance transformation.
	 * @param color Instance color.
	 * @return Created instance.
	 * @exception InvalidOperationException Batch capacity is exceeded.
	 */
	virtual ILineMesh*										CreateInstance( INode* parent, const math::Matrix4x4& transform, const img::Color& color ) = 0;

	/**
	 * Removes previously created instance by index.
	 * @param index Instance index.
	 */
	virtual void											RemoveInstance( UInt index ) = 0;

	/**
	 * Sets the range of active mesh instances.
	 * @param range Instance range.
	 */
	virtual void											SetRange( const lang::Range& range ) = 0;

	/**
	 * Sets instance transformation.
	 * @param index Instance index.
	 * @param transform Instance transformation.
	 */
	virtual void											SetInstanceTransform( UInt index, const math::Matrix4x4& transform ) = 0;

	/**
	 * Sets instance color.
	 * @param index Instance index.
	 * @param color Instance color.
	 */
	virtual void											SetInstanceColor( UInt index, const img::Color& color ) = 0;

	/**
	 * Retrieves the number of allocated mesh instances.
	 */
	virtual UInt											GetCapacity() const = 0;

	/**
	 * Retrieves the number of created mesh instances.
	 */
	virtual UInt											GetInstanceCount() const = 0;

	/**
	 * Retrieves instance by index.
	 * @param index Index of the instance to retrieve.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual ILineMesh*										GetInstance( UInt index ) const = 0;

	/**
	 * Retrieves the range of active mesh instances.
	 * @param [out] range Instance range.
	 */
	virtual void											GetRange( lang::Range& range ) const = 0;
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_ILINEMESHBATCH_
