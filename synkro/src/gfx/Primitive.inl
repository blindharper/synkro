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
// Purpose: Logical primitive.
//==============================================================================
SYNKRO_INLINE UInt Primitive::Draw( UInt startElement, UInt elementCount, UInt startInstance, UInt instanceCount )
{
	return _primitive->Draw( startElement, elementCount, startInstance, instanceCount );
}

SYNKRO_INLINE UInt Primitive::Draw()
{
	return _primitive->Draw();
}

SYNKRO_INLINE void Primitive::Resize( UInt vertexCount, UInt indexCount, UInt instanceCount )
{
	return _primitive->Resize( vertexCount, indexCount, instanceCount );
}

SYNKRO_INLINE IProgram* Primitive::GetProgram() const
{
	return _program;
}

SYNKRO_INLINE IDataBufferSet* Primitive::GetInputBuffers() const
{
	return _primitive->GetInputBuffers();
}

SYNKRO_INLINE IDataBufferSet* Primitive::GetOutputBuffers() const
{
	return _primitive->GetOutputBuffers();
}

SYNKRO_INLINE IIndexBuffer* Primitive::GetIndexBuffer() const
{
	return _primitive->GetIndexBuffer();
}

SYNKRO_INLINE Bool Primitive::HasAdjacency() const
{
	return _primitive->HasAdjacency();
}

SYNKRO_INLINE IndexType Primitive::GetIndexType() const
{
	return _primitive->GetIndexType();
}

SYNKRO_INLINE PrimitiveType Primitive::GetType() const
{
	return _primitive->GetType();
}

SYNKRO_INLINE UInt Primitive::GetPointCount() const
{
	return _primitive->GetPointCount();
}

SYNKRO_INLINE UInt Primitive::GetVertexCount() const
{
	return _primitive->GetVertexCount();
}

SYNKRO_INLINE UInt Primitive::GetIndexCount() const
{
	return _primitive->GetIndexCount();
}

SYNKRO_INLINE UInt Primitive::GetInstanceCount() const
{
	return _primitive->GetInstanceCount();
}

SYNKRO_INLINE IDataStream* Primitive::GetIndexStream() const
{
	return _indexStream;
}
