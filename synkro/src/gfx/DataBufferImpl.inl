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
// Purpose: Generic data buffer implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE DataBufferImpl<T>::DataBufferImpl( const DataUsage& usage, const DataAccess& access, UInt stride, UInt size ) :
	_data( nullptr ),
	_usage( usage ),
	_access( access ),
	_stride( stride ),
	_size( size )
{
}

template <class T>
SYNKRO_INLINE DataBufferImpl<T>::~DataBufferImpl()
{
}

template <class T>
SYNKRO_INLINE void DataBufferImpl<T>::SetData( const Byte* data, UInt size, UInt offset, UInt start, UInt count )
{
	assert( data != nullptr );
	assert( _data != nullptr );

	Byte* dst = _data + offset + _stride*start;

	if ( _stride == size )
	{
		Copy( dst, data, size*count );
	}
	else
	{
		for ( UInt i = 0; i < count; ++i )
		{
			Copy( dst + i*_stride, data + i*size, size );
		}
	}
}

template <class T>
SYNKRO_INLINE void DataBufferImpl<T>::GetData( Byte* data, UInt size, UInt offset, UInt start, UInt count )
{
	assert( data != nullptr );
	assert( _data != nullptr );

	Byte* src = _data + offset + _stride*start;

	if ( _stride == size )
	{
		Copy( data, src, size*count );
	}
	else
	{
		for ( UInt i = 0; i < count; ++i )
		{
			Copy( data + i*_stride, src + i*size, size );
		}
	}
}

template <class T>
SYNKRO_INLINE UInt DataBufferImpl<T>::GetStride() const
{
	return _stride;
}

template <class T>
SYNKRO_INLINE UInt DataBufferImpl<T>::GetSize() const
{
	return _size;
}
