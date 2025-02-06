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
template <class T>
SYNKRO_INLINE PrimitiveImpl<T>::PrimitiveImpl( IProgram* program, const IndexType& indexType, const PrimitiveType& type, UInt vertexCount, UInt indexCount, UInt instanceCount, UInt pointCount, Bool adjacency ) :
	_program( program ),
	_adjacency( adjacency ),
	_indexType( indexType ),
	_type( type ),
	_pointCount( pointCount ),
	_vertexCount( vertexCount ),
	_indexCount( indexCount ),
	_instanceCount( instanceCount ),
	_indexBuffer( nullptr )
{
}

template <class T>
SYNKRO_INLINE PrimitiveImpl<T>::~PrimitiveImpl()
{
}

template <class T>
SYNKRO_INLINE IProgram* PrimitiveImpl<T>::GetProgram() const
{
	return _program;
}

template <class T>
SYNKRO_INLINE IDataBufferSet* PrimitiveImpl<T>::GetInputBuffers() const
{
	return _inputBuffers;
}

template <class T>
SYNKRO_INLINE IDataBufferSet* PrimitiveImpl<T>::GetOutputBuffers() const
{
	return _outputBuffers;
}

template <class T>
SYNKRO_INLINE IIndexBuffer* PrimitiveImpl<T>::GetIndexBuffer() const
{
	return _indexBuffer;
}

template <class T>
SYNKRO_INLINE Bool PrimitiveImpl<T>::HasAdjacency() const
{
	return _adjacency;
}

template <class T>
SYNKRO_INLINE IndexType PrimitiveImpl<T>::GetIndexType() const
{
	return _indexType;
}

template <class T>
SYNKRO_INLINE PrimitiveType PrimitiveImpl<T>::GetType() const
{
	return _type;
}

template <class T>
SYNKRO_INLINE UInt PrimitiveImpl<T>::GetPointCount() const
{
	return _pointCount;
}

template <class T>
SYNKRO_INLINE UInt PrimitiveImpl<T>::GetVertexCount() const
{
	return _vertexCount;
}

template <class T>
SYNKRO_INLINE UInt PrimitiveImpl<T>::GetIndexCount() const
{
	return _indexCount;
}

template <class T>
SYNKRO_INLINE UInt PrimitiveImpl<T>::GetInstanceCount() const
{
	return _instanceCount;
}
