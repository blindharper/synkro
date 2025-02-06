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
// Purpose: Generic structured buffer implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE StructuredBufferImpl<T>::StructuredBufferImpl( UInt stride, UInt count ) :
	BufferImpl<T>( count ),
	_stride( stride )
{
}

template <class T>
SYNKRO_INLINE StructuredBufferImpl<T>::~StructuredBufferImpl()
{
}

template <class T>
SYNKRO_INLINE UInt StructuredBufferImpl<T>::GetStride() const
{
	return _stride;
}

template <class T>
SYNKRO_INLINE IStructuredBuffer* StructuredBufferImpl<T>::AsStructured() const
{
	return (IStructuredBuffer*)this;
}
