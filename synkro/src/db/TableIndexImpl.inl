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
// Purpose: Generic database table index implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE TableIndexImpl<T>::TableIndexImpl( IDataTable* table, const lang::String& name, Bool unique, const lang::String* columns, UInt count ) :
	_columns( A(lang::String) ),
	_table( table ),
	_name( name ),
	_unique( unique )
{
	for ( UInt i = 0; i < count; ++i )
	{
		_columns.Add( columns[i] );
	}
}

template <class T>
SYNKRO_INLINE TableIndexImpl<T>::~TableIndexImpl()
{
}

template <class T>
SYNKRO_INLINE UInt TableIndexImpl<T>::GetColumnCount() const
{
	return _columns.Size();
}

template <class T>
SYNKRO_INLINE lang::String TableIndexImpl<T>::GetColumn( UInt index ) const
{
	assert( index < _columns.Size() );

	if ( index >= _columns.Size() )
		throw lang::OutOfRangeException( index, _columns.Size() );

	return _columns[index];
}

template <class T>
SYNKRO_INLINE IDataTable* TableIndexImpl<T>::GetTable() const
{
	return _table;
}

template <class T>
SYNKRO_INLINE lang::String TableIndexImpl<T>::GetName() const
{
	return _name;
}

template <class T>
SYNKRO_INLINE Bool TableIndexImpl<T>::IsUnique() const
{
	return _unique;
}
