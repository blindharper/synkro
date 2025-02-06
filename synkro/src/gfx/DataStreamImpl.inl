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
// Purpose: Generic data stream implementation.
//==============================================================================
template <class T, class V>
SYNKRO_INLINE DataStreamImpl<T, V>::DataStreamImpl( IDataBuffer* buffer, const DataStream& type, UInt offset, UInt length ) :
	_buffer( buffer ),
	_type( type ),
	_offset( offset ),
	_length( length ),
	_position( 0 )
{
}

template <class T, class V>
SYNKRO_INLINE DataStreamImpl<T, V>::~DataStreamImpl()
{
}

template <class T, class V>
SYNKRO_INLINE Bool DataStreamImpl<T, V>::Open( const io::OpenMode& mode )
{
	_position = 0;
	return _buffer->Map( mode.IsSet(io::OpenMode::Read) ? MapMode::Read : MapMode::Write );
}

template <class T, class V>
SYNKRO_INLINE void DataStreamImpl<T, V>::Close()
{
	_buffer->Unmap();
}

template <class T, class V>
SYNKRO_INLINE void DataStreamImpl<T, V>::SetPosition( UInt position )
{
	_position = position;
}

template <class T, class V>
SYNKRO_INLINE UInt DataStreamImpl<T, V>::GetPosition() const
{
	return _position;
}

template <class T, class V>
SYNKRO_INLINE UInt DataStreamImpl<T, V>::GetLength() const
{
	return _length;
}

template <class T, class V>
SYNKRO_INLINE DataStream DataStreamImpl<T, V>::GetType() const
{
	return _type;
}

template <class T, class V>
SYNKRO_INLINE void DataStreamImpl<T, V>::Read( typename V* data, UInt count )
{
	_buffer->GetData( (Byte*)data, sizeof(V), _offset, _position, count );
	_position += count;
}

template <class T, class V>
SYNKRO_INLINE void DataStreamImpl<T, V>::Write( const typename V* data, UInt count )
{
	_buffer->SetData( (const Byte*)data, sizeof(V), _offset, _position, count );
	_position += count;
}

template <class T, class V>
SYNKRO_INLINE void DataStreamImpl<T, V>::Set( const typename V& value, UInt count )
{
	for ( UInt i = 0; i < count; ++i )
	{
		_buffer->SetData( (const Byte*)&value, sizeof(V), _offset, _position+i, 1 );
	}
}
