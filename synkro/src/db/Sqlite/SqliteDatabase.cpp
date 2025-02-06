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
// Purpose: Implements Sqlite database.
//==============================================================================
#include "config.h"
#include "SqliteDatabase.h"
#include "SqliteDataTable.h"


//------------------------------------------------------------------------------

using namespace synkro::db;
using namespace synkro::io;
using namespace synkro::lang;
using namespace synkro;

//------------------------------------------------------------------------------


static int master_callback( void* ctx, int argc, char** argv, char** colName )
{
	Vector<String>* tables = (Vector<String>*)ctx;
	tables->Add( argv[0] );
	return 0;
}

static int table_callback( void* ctx, int argc, char** argv, char** colName )
{
	Vector<TableColumn>* columns = (Vector<TableColumn>*)ctx;
	columns->Add( TableColumn(argv[1], Sqlite::ToType(argv[2]), false, (argv[3][0] != '1'), (argv[5][0] == '1')) );
	return 0;
}

static int foreign_callback( void* ctx, int argc, char** argv, char** colName )
{
	Vector<TableColumn>* columns = (Vector<TableColumn>*)ctx;
	for ( UInt i = 0; i < columns->Size(); ++i )
	{
		TableColumn* col = columns->Get( i );
		if ( col->Name.EqualsTo(argv[3], true) )
		{
			col->ForeignTable = String( argv[2] );
			col->ForeignColumn = String( argv[4] );
			break;
		}
	}	
	return 0;
}

static int index_callback( void* ctx, int argc, char** argv, char** colName )
{
	MapCI<String, Bool>* indexes = (MapCI<String, Bool>*)ctx;
	indexes->Put( argv[1], (argv[2][0] == '1') );
	return 0;
}

static int index_info_callback( void* ctx, int argc, char** argv, char** colName )
{
	Vector<String>* indexColumns = (Vector<String>*)ctx;
	indexColumns->Add( argv[2] );
	return 0;
}


namespace synkro
{


namespace db
{


SqliteDatabase::SqliteDatabase( IStream* stream ) :
	_db( nullptr )
{
	assert( stream != nullptr );

	// Open database.
	const int rc = sqlite3_open( stream, &_db );
	if ( rc != SQLITE_OK )
		throw DatabaseException( L"Failed to open database.", String::Empty, Sqlite::ToString(rc) );

	// Read db schema.
	String sql = L"SELECT name, type FROM sqlite_master WHERE (type = 'table')";
	Vector<String> tables( A(String) );
	Sqlite::Execute( _db, sql, master_callback, (void*)&tables );

	// Create table definitions.
	typedef MapPair<String, Bool> IndexEntry;
	MapCI<String, Bool> indexes( A(IndexEntry) );
	typedef MapPair<String, String> StringEntry;
	MapCI<String, String> indexColumnList( A(StringEntry) );
	Vector<String> indexColumns( A(String) );
	Vector<TableColumn> columns( A(TableColumn) );
	for ( UInt i = 0; i < tables.Size(); ++i )
	{
		String name = tables[i];

		columns.Clear();
		sql = String::Format( L"PRAGMA table_info({0})", name );
		Sqlite::Execute( _db, sql, table_callback, (void*)&columns );

		sql = String::Format( L"PRAGMA foreign_key_list({0})", name );
		Sqlite::Execute( _db, sql, foreign_callback, (void*)&columns );

		indexes.Clear();
		sql = String::Format( L"PRAGMA index_list({0})", name );
		Sqlite::Execute( _db, sql, index_callback, (void*)&indexes );

		MapIterator<String, Bool> itIndex = indexes.Begin();
		for ( ; itIndex != indexes.End() ; ++itIndex )
		{
			indexColumns.Clear();
			Bool unique = itIndex.Value();
			sql = String::Format( L"PRAGMA index_info({0})", itIndex.Key() );
			Sqlite::Execute( _db, sql, index_info_callback, (void*)&indexColumns );
			if ( !itIndex.Key().StartsWith(L"sqlite_", true) )
			{
				indexColumnList[itIndex.Key()] = String( indexColumns.Begin(), indexColumns.Size(), L"|" );
			}

			// Set table column Unique flag.
			for ( UInt c = 0; c < columns.Size(); ++c )
			{
				TableColumn* col = columns.Get( c );
				if ( indexColumns.Contains(col->Name) )
				{
					col->Unique = unique;
				}
			}
		}

		SqliteDataTable* table = new SqliteDataTable( this, _db, name, columns.Begin(), columns.Size(), false );
		_tableIndices[name] = _tables.Size();
		_tables.Add( table );

		itIndex = indexes.Begin();
		for ( ; itIndex != indexes.End() ; ++itIndex )
		{
			if ( !itIndex.Key().StartsWith(L"sqlite_", true) )
			{
				indexColumns.Clear();
				String columnList = indexColumnList[itIndex.Key()];
				const UInt count = columnList.EntryCount( L'|' );
				for ( UInt c = 0; c < count; ++c )
				{
					indexColumns.Add( columnList.Entry(c, L'|') );
				}
				table->AddIndex( itIndex.Key(), itIndex.Value(), indexColumns.Begin(), indexColumns.Size() );
			}
		}
	}
}

SqliteDatabase::~SqliteDatabase()
{
	sqlite3_close( _db );
}

IDataTable* SqliteDatabase::CreateTable( const String& name, const TableColumn* columns, UInt count )
{
	IDataTable* table = new SqliteDataTable( this, _db, name, columns, count, true );
	_tableIndices[name] = _tables.Size();
	_tables.Add( table );
	return table;
}

void SqliteDatabase::RemoveTable( IDataTable* table )
{
	_tableIndices.Remove( table->GetName() );
	_tables.Remove( table );
}


} // db


} // synkro
