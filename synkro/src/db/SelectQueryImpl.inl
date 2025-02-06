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
// Purpose: Generic SELECT query implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE SelectQueryImpl<T>::SelectQueryImpl( IDataTable* table ) :
	DatabaseQueryImpl<T>( table ),
	_columns( A(ColumnEntry) ),
	_sortColumns( A(SortColumnEntry) ),
	_unique( false )
{
}

template <class T>
SYNKRO_INLINE SelectQueryImpl<T>::~SelectQueryImpl()
{
}

template <class T>
SYNKRO_INLINE void SelectQueryImpl<T>::Reset()
{
	SelectAll();
	SetFilter( nullptr );
	_sortColumns.Clear();
	_dirty = true;
}

template <class T>
SYNKRO_INLINE void SelectQueryImpl<T>::SelectAll()
{
	_columns.Clear();
	_columns.Put( L"*" );
	_dirty = true;
}

template <class T>
SYNKRO_INLINE void SelectQueryImpl<T>::SelectCount()
{
	_columns.Clear();
	_columns.Put( L"COUNT(*) AS count" );
	_dirty = true;
}

template <class T>
SYNKRO_INLINE void SelectQueryImpl<T>::SelectUnique( Bool unique )
{
	if ( unique != _unique )
	{
		_unique = unique;
		_dirty = true;
	}
}

template <class T>
SYNKRO_INLINE void SelectQueryImpl<T>::Select( const lang::String& column )
{
	if ( !_columns.Contains(column) )
	{
		_columns.Put( column );
		_dirty = true;
	}
}

template <class T>
SYNKRO_INLINE void SelectQueryImpl<T>::Sort( const lang::String& column, const SortOrder& order )
{
	if ( !_sortColumns.ContainsKey(column) )
	{
		_sortColumns[column] = order;
		_dirty = true;
	}
	else if ( _sortColumns[column] != order )
	{
		_dirty = true;
	}
}

template <class T>
SYNKRO_INLINE void SelectQueryImpl<T>::SetFilter( IDataFilter* filter )
{
	if ( filter != _filter )
	{
		_filter = filter;
		_dirty = true;
	}
}

template <class T>
SYNKRO_INLINE IDataFilter* SelectQueryImpl<T>::GetFilter() const
{
	return _filter;
}

template <class T>
SYNKRO_INLINE IDataCursor* SelectQueryImpl<T>::GetCursor() const
{
	return _cursor;
}
