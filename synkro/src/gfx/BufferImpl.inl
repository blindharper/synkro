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
// Purpose: Generic buffer implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE BufferImpl<T>::BufferImpl( UInt size ) :
	_size( size )
{
}

template <class T>
SYNKRO_INLINE BufferImpl<T>::~BufferImpl()
{
}

template <class T>
SYNKRO_INLINE IBuffer* BufferImpl<T>::AsBuffer() const
{
	return (IBuffer*)this;
}

template <class T>
SYNKRO_INLINE UInt BufferImpl<T>::GetSize() const
{
	return _size;
}

template <class T>
SYNKRO_INLINE ITypedBuffer* BufferImpl<T>::AsTyped() const
{
	return nullptr;
}

template <class T>
SYNKRO_INLINE IStructuredBuffer* BufferImpl<T>::AsStructured() const
{
	return nullptr;
}
