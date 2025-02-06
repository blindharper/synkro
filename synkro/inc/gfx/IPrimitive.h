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
// Purpose: Defines visual primitive.
//==============================================================================
#ifndef _SYNKRO_GFX_IPRIMITIVE_
#define _SYNKRO_GFX_IPRIMITIVE_


#include "config.h"
#include <core/IObject.h>
#include <gfx/IndexType.h>
#include <gfx/PrimitiveType.h>


namespace synkro
{


namespace gfx
{


/**
 * Visual primitive.
 */
iface IPrimitive :
	public core::IObject
{
public:
	/**
	 * Draws primitive the specified number of times.
	 * @param startElement Element at which to start drawing.
	 * @param elementCount Number of elements to draw.
	 * @param startInstance Instance at which to start drawing.
	 * @param instanceCount Number of instances to draw.
	 * @return Number of drawn primitives.
	 */
	virtual UInt											Draw( UInt startElement, UInt elementCount, UInt startInstance, UInt instanceCount ) = 0;

	/**
	 * Draws primitive to the rendering target.
	 * @return Number of drawn primitives.
	 */
	virtual UInt											Draw() = 0;
	
	/**
	 * Modifies primitive buffers capacity.
	 * @param vertexCount Number of vertices in the primitive.
	 * @param indexCount Number of indices in the primitive.
	 * @param instanceCount Maximum number of instances the primitive can hold.
	 */
	virtual void											Resize( UInt vertexCount, UInt indexCount, UInt instanceCount ) = 0;

	/**
	 * Retrieves program that draws the primitive.
	 */
	virtual IProgram*										GetProgram() const = 0;

	/**
	 * Retrieves input buffers.
	 */
	virtual IDataBufferSet*									GetInputBuffers() const = 0;

	/**
	 * Retrieves output buffers.
	 */
	virtual IDataBufferSet*									GetOutputBuffers() const = 0;

	/**
	 * Retrieves index buffer.
	 */
	virtual IIndexBuffer*									GetIndexBuffer() const = 0;

	/**
	 * Indicates whether the primitive data contain adjacency information.
	 */
	virtual Bool											HasAdjacency() const = 0;

	/**
	 * Retrieves index type.
	 */
	virtual IndexType										GetIndexType() const = 0;

	/**
	 * Retrieves primitive type.
	 */
	virtual PrimitiveType									GetType() const = 0;

	/**
	 * Retrieves the number of control points in a patch primitive.
	 */
	virtual UInt											GetPointCount() const = 0;

	/**
	 * Retrieves the number of vertices in the primitive.
	 */
	virtual UInt											GetVertexCount() const = 0;

	/**
	 * Retrieves the number of indices.
	 */
	virtual UInt											GetIndexCount() const = 0;

	/**
	 * Retrieves maximum number of instances the primitive can hold.
	 */
	virtual UInt											GetInstanceCount() const = 0;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_IPRIMITIVE_
