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
// Purpose: Generic database implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE DatabaseImpl<T>::DatabaseImpl() :
	_tables( A(P(IDataTable)) ),
	_tableIndices( A(IndexEntry) )
{
}

template <class T>
SYNKRO_INLINE DatabaseImpl<T>::~DatabaseImpl()
{
}

template <class T>
SYNKRO_INLINE UInt DatabaseImpl<T>::GetTableCount() const
{
	return _tables.Size();
}

template <class T>
SYNKRO_INLINE IDataTable* DatabaseImpl<T>::GetTable( UInt index ) const
{
	assert( index < _tables.Size() );

	if ( index >= _tables.Size() )
		throw lang::OutOfRangeException( index, _tables.Size() );

	return _tables[index];
}

template <class T>
SYNKRO_INLINE IDataTable* DatabaseImpl<T>::GetTable( const lang::String& name ) const
{
	return _tableIndices.ContainsKey(name) ? GetTable( _tableIndices[name] ) : nullptr;
}
