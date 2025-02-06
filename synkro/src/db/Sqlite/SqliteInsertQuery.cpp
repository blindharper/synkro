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
// Purpose: Implements Sqlite INSERT query.
//==============================================================================
#include "config.h"
#include "SqliteInsertQuery.h"


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace db
{


SqliteInsertQuery::SqliteInsertQuery( sqlite3* db, IDataTable* table ) :
	InsertQueryImpl<IInsertQuery>( table ),
	SqliteBaseQueryImpl<SqliteBaseQuery>( db )
{
}

void SqliteInsertQuery::Execute()
{
	// Prepare statement.
	if ( _dirty )
	{
		Finalize();
		
		_string.Clear();
		MapIterator<String, Variant> it = _values.Begin();
		for ( ; it != _values.End(); ++it )
		{
			if ( _string.GetLength() > 0 )
			{
				_string.Append( L", " );
			}
			_string.Append( it.Key() );
		}
		String columns = _string.GetString();

		_string.Clear();
		for ( UInt i = 0; i < _values.Size(); ++i )
		{
			if ( _string.GetLength() > 0 )
			{
				_string.Append( L", " );
			}
			_string.Append( String::Format(L"?{0}", i+1) );
		}
		String values = _string.GetString();

		_sql = String::Format( L"INSERT INTO {0} ({1}) VALUES ({2})", _table->GetName(), columns, values );
		Sqlite::Prepare( _db, _sql, &_stmt );
		_dirty = false;
	}

	// Bind parameters.
	Bind( _values );

	// Execute statement.
	int rc = SQLITE_OK;
	while ( (rc = sqlite3_step(_stmt)) != SQLITE_DONE )
	{
		if ( rc != SQLITE_OK )
			throw DatabaseException( L"Failed to insert a record to database.", _sql, Sqlite::ToString(rc) );
	}
}

UInt SqliteInsertQuery::GetRowID() const
{
	return CastULong( sqlite3_last_insert_rowid(_db) );
}


} // db


} // synkro
