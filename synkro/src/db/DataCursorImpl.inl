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
// Purpose: Generic data cursor implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE DataCursorImpl<T>::DataCursorImpl( const lang::Vector<TableColumn>& columns ) :
	_columns( columns ),
	_record( A(ValueEntry) )
{
	for ( UInt i = 0; i < columns.Size(); ++i )
	{
		_record[columns[i].Name] = lang::Variant::Null;
	}
}

template <class T>
SYNKRO_INLINE DataCursorImpl<T>::~DataCursorImpl()
{
}

template <class T>
SYNKRO_INLINE lang::Variant DataCursorImpl<T>::GetValue( const lang::String& column ) const
{
	if ( _record.IsEmpty() )
		throw DatabaseException( L"No record is available." );

	if ( !_record.ContainsKey(column) )
		throw DatabaseException( String::Format(L"Invalid column name: {0,q}", column) );

	return _record[column];
}
