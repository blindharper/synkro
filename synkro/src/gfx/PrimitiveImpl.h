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
// Purpose: Generic primitive implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_PRIMITIVEIMPL_
#define _SYNKRO_GFX_PRIMITIVEIMPL_


#include "config.h"
#include <core/ObjectImpl.h>
#include <gfx/GraphicsException.h>
#include <gfx/IndexType.h>
#include <gfx/IProgram.h>
#include <gfx/IProgramStage.h>
#include <gfx/IDataBufferSet.h>
#include <gfx/IIndexBuffer.h>
#include <gfx/PrimitiveType.h>


namespace synkro
{


namespace gfx
{


// Generic primitive implementation.
template <class T>
class PrimitiveImpl :
	public core::ObjectImpl<T>
{
public:
	// Constructor & destructor.
	PrimitiveImpl( IProgram* program, const IndexType& indexType, const PrimitiveType& type, UInt vertexCount, UInt indexCount, UInt instanceCount, UInt pointCount, Bool adjacency );
	virtual ~PrimitiveImpl();

	// IPrimitive methods.
	virtual IProgram*										GetProgram() const;
	virtual IDataBufferSet*									GetInputBuffers() const;
	virtual IDataBufferSet*									GetOutputBuffers() const;
	virtual IIndexBuffer*									GetIndexBuffer() const;
	virtual Bool											HasAdjacency() const;
	virtual IndexType										GetIndexType() const;
	virtual PrimitiveType									GetType() const;
	virtual UInt											GetPointCount() const;
	virtual UInt											GetVertexCount() const;
	virtual UInt											GetIndexCount() const;
	virtual UInt											GetInstanceCount() const;

protected:
	IProgram*												_program;
	P(IDataBufferSet)										_inputBuffers;
	P(IDataBufferSet)										_outputBuffers;
	P(IIndexBuffer)											_indexBuffer;
	Bool													_adjacency;
	IndexType												_indexType;
	PrimitiveType											_type;
	UInt													_pointCount;
	UInt													_vertexCount;
	UInt													_indexCount;
	UInt													_instanceCount;
};


#include "PrimitiveImpl.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_PRIMITIVEIMPL_
