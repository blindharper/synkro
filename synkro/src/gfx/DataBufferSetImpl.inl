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
// Purpose: Generic data buffer set implementation.
//==============================================================================
template <class T, class B>
SYNKRO_INLINE DataBufferSetImpl<T, B>::DataBufferSetImpl() :
	_buffers( A(P(B)) )
{
}

template <class T, class B>
SYNKRO_INLINE DataBufferSetImpl<T, B>::~DataBufferSetImpl()
{
}

template <class T, class B>
SYNKRO_INLINE UInt DataBufferSetImpl<T, B>::GetSize() const
{
	return _buffers.Size();
}

template <class T, class B>
SYNKRO_INLINE IDataBuffer* DataBufferSetImpl<T, B>::Get( UInt index ) const
{
	assert( index < _buffers.Size() );

	if ( index >= _buffers.Size() )
		throw lang::OutOfRangeException( index, _buffers.Size() );

	return (IDataBuffer*)(_buffers[index]);
}
