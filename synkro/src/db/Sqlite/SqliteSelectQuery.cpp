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
// Purpose: Implements Sqlite SELECT query.
//==============================================================================
#include "config.h"
#include "SqliteSelectQuery.h"
#include "SqliteDataCursor.h"


//------------------------------------------------------------------------------

using namespace synkro::db;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace db
{


SqliteSelectQuery::SqliteSelectQuery( sqlite3* db, IDataTable* table ) :
	SelectQueryImpl<ISelectQuery>( table ),
	SqliteBaseQueryImpl<SqliteBaseQuery>( db ),
	_allColumns( A(TableColumn) ),
	_selectedColumns( A(TableColumn) )
{
}

void SqliteSelectQuery::Execute()
{
	// Prepare statement.
	Bool all = (_columns.Size() == 1) && (_columns.Begin().Key() == L"*");
	if ( _dirty )
	{
		Finalize();
		_selectedColumns.Clear();
		Bool count = (_columns.Size() == 1) && (_columns.Begin().Key() == L"COUNT(*) AS count");
		if ( count )
		{
			_selectedColumns.Add( TableColumn(L"count", DataType::Integer) );
		}

		_string.Clear();
		SetIterator<String> it = _columns.Begin();
		for ( ; it != _columns.End(); ++it )
		{
			if ( _string.GetLength() > 0 )
			{
				_string.Append( L", " );
			}
			_string.Append( it.Key() );
			if ( !count && !all )
			{
				TableColumn column;
				_table->GetColumn( it.Key(), column );
				_selectedColumns.Add( TableColumn(column.Name, column.Type) );
			}
		}
		String columns = _string.GetString();

		_string.Clear();
		MapIterator<String, SortOrder> itSort = _sortColumns.Begin();
		for ( ; itSort != _sortColumns.End(); ++itSort )
		{
			if ( _string.GetLength() > 0 )
			{
				_string.Append( L", " );
			}
			_string.Append( String::Format(L" BY {0} {1}", itSort.Key(), Sqlite::ToString(itSort.Value())) );
		}
		String sortColumns = _string.GetString();
		if ( !sortColumns.IsEmpty() )
		{
			sortColumns = String::Format( L" ORDER{0}", sortColumns );
		}

		String filter = Evaluate( _filter );
		String distinct = _unique ? L" DISTINCT" : String::Empty;
		String sql = String::Format( L"SELECT{0} {1} FROM {2}{3}{4}", distinct, columns, _table->GetName(), filter, sortColumns );
		Sqlite::Prepare( _db, sql, &_stmt );
		_dirty = false;
	}

	// Prepare selected columns descriptors.
	if ( all && _allColumns.IsEmpty() )
	{
		TableColumn column;
		for ( UInt i = 0; i < _table->GetColumnCount(); ++i )
		{
			_table->GetColumn( i, column );
			_allColumns.Add( TableColumn(column.Name, column.Type) );
		}
	}

	// Create cursor.
	_cursor = new SqliteDataCursor( _stmt, all ? _allColumns : _selectedColumns );
}

void SqliteSelectQuery::Reset()
{
	// Call base implementation.
	SelectQueryImpl<ISelectQuery>::Reset();

	_cursor = nullptr;
}


} // db


} // synkro
