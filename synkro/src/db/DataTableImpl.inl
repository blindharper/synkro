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
// Purpose: Generic database table implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE DataTableImpl<T>::DataTableImpl( const lang::String& name ) :
	_columns( A(TableColumn) ),
	_columnIndices( A(IndexEntry) ),
	_indexes( A(P(ITableIndex)) ),
	_indexIndices( A(IndexEntry) ),
	_name( name )
{
}

template <class T>
SYNKRO_INLINE DataTableImpl<T>::~DataTableImpl()
{
}

template <class T>
SYNKRO_INLINE void DataTableImpl<T>::Delete()
{
	while ( _indexes.Size() > 0 )
	{
		_indexes.Last()->AsPtr()->Delete();
	}
}

template <class T>
SYNKRO_INLINE UInt DataTableImpl<T>::GetColumnCount() const
{
	return _columns.Size();
}

template <class T>
SYNKRO_INLINE void DataTableImpl<T>::GetColumn( UInt index, TableColumn& column ) const
{
	assert( index < _columns.Size() );

	if ( index >= _columns.Size() )
		throw lang::OutOfRangeException( index, _columns.Size() );

	column = _columns[index];
}

template <class T>
SYNKRO_INLINE void DataTableImpl<T>::GetColumn( const lang::String& name, TableColumn& column ) const
{
	if ( !_columnIndices.ContainsKey(name) )
		throw lang::BadArgumentException( L"Unknown column name.", L"name", name );

	GetColumn( _columnIndices[name], column );
}

template <class T>
SYNKRO_INLINE UInt DataTableImpl<T>::GetIndexCount() const
{
	return _indexes.Size();
}

template <class T>
SYNKRO_INLINE ITableIndex* DataTableImpl<T>::GetIndex( UInt index ) const
{
	assert( index < _indexes.Size() );

	if ( index >= _indexes.Size() )
		throw lang::OutOfRangeException( index, _indexes.Size() );

	return _indexes[index];
}

template <class T>
SYNKRO_INLINE ITableIndex* DataTableImpl<T>::GetIndex( const lang::String& name ) const
{
	return _indexIndices.ContainsKey(name) ? GetIndex( _indexIndices[name] ) : nullptr;
}

template <class T>
SYNKRO_INLINE lang::String DataTableImpl<T>::GetName() const
{
	return _name;
}
