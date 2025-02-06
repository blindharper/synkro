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
// Purpose: Implements Sqlite database table.
//==============================================================================
#include "config.h"
#include "SqliteDataTable.h"
#include "SqliteTableIndex.h"
#include "SqliteInsertQuery.h"
#include "SqliteUpdateQuery.h"
#include "SqliteSelectQuery.h"
#include "SqliteDeleteQuery.h"
#include <lang/StringBuilder.h>


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace db
{


SqliteDataTable::SqliteDataTable( BaseDatabase* owner, sqlite3* db, const String& name, const TableColumn* columns, UInt count, Bool create ) :
	DataTableImpl<IDataTable>( name ),
	_owner( owner ),
	_db( db )
{
	// Build columns list.
	StringBuilder string;
	for ( UInt i = 0; i < count; ++i )
	{
		TableColumn col = columns[i];
		_columnIndices[col.Name] = _columns.Size();
		_columns.Add( col );
		if ( !create )
			continue;

		if ( string.GetLength() > 0 )
		{
			string.Append( L", " );
		}
		string.Append( col.Name );
		string.Append( L' ' );
		string.Append( Sqlite::ToString(col.Type) );

		if ( !col.Nullable )
		{
			string.Append( L" NOT NULL" );
		}
		if ( col.Unique )
		{
			string.Append( L" UNIQUE" );
		}
		if ( col.Primary )
		{
			string.Append( L" PRIMARY KEY" );
		}
	}
	String list = string.GetString();

	// Build columns list.
	string.Clear();
	if ( create )
	{
		for ( UInt i = 0; i < count; ++i )
		{
			TableColumn col = columns[i];
			if ( !col.ForeignTable.IsEmpty() && !col.ForeignColumn.IsEmpty() )
			{
				string.Append( String::Format(L", FOREIGN KEY({0}) REFERENCES {1}({2}) ON DELETE RESTRICT", col.Name, col.ForeignTable, col.ForeignColumn) );
			}
		}
	}
	String foreign = string.GetString();

	if ( create )
	{
		String sql = String::Format( L"CREATE TABLE {0}({1}{2})", name, list, foreign );
		Sqlite::Execute( _db, sql );
	}
}

ITableIndex* SqliteDataTable::CreateIndex( const String& name, Bool unique, const String* columns, UInt count )
{
	ITableIndex* index = new SqliteTableIndex( _db, this, name, unique, columns, count, true );
	_indexIndices[name] = _indexes.Size();
	_indexes.Add( index );
	return index;
}

IInsertQuery* SqliteDataTable::CreateInsertQuery()
{
	return new SqliteInsertQuery( _db, this );
}

IUpdateQuery* SqliteDataTable::CreateUpdateQuery()
{
	return new SqliteUpdateQuery( _db, this );
}

ISelectQuery* SqliteDataTable::CreateSelectQuery()
{
	return new SqliteSelectQuery( _db, this );
}

IDeleteQuery* SqliteDataTable::CreateDeleteQuery()
{
	return new SqliteDeleteQuery( _db, this );
}

void SqliteDataTable::Delete()
{
	// Call base implementation.
	DataTableImpl<IDataTable>::Delete();

	String sql = String::Format( L"DROP TABLE {0}", _name );
	Sqlite::Execute( _db, sql );
	AsBaseDatabase( _owner )->RemoveTable( this );
}

UInt SqliteDataTable::GetRowCount()
{
	P(ISelectQuery) select = CreateSelectQuery();
	select->SelectCount();
	select->Execute();
	IDataCursor* cursor = select->GetCursor();
	if ( cursor->Read() )
	{
		Variant count = cursor->GetValue( L"count" );
		return CastInt(count);
	}
	return 0;
}

void SqliteDataTable::RemoveIndex( ITableIndex* index )
{
	_indexIndices.Remove( index->GetName() );
	_indexes.Remove( index );
}

void SqliteDataTable::AddIndex( const String& name, Bool unique, const String* columns, UInt count )
{
	ITableIndex* index = new SqliteTableIndex( _db, this, name, unique, columns, count, false );
	_indexIndices[name] = _indexes.Size();
	_indexes.Add( index );
}


} // db


} // synkro
