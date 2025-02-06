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
// Purpose: Implements Sqlite UPDATE query.
//==============================================================================
#include "config.h"
#include "SqliteUpdateQuery.h"


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace db
{


SqliteUpdateQuery::SqliteUpdateQuery( sqlite3* db, IDataTable* table ) :
	UpdateQueryImpl<IUpdateQuery>( table ),
	SqliteBaseQueryImpl<SqliteBaseQuery>( db )
{
}

void SqliteUpdateQuery::Execute()
{
	// Prepare statement.
	if ( _dirty )
	{
		Finalize();
		UInt idx = 1;
		_string.Clear();
		MapIterator<String, Variant> it = _values.Begin();
		for ( ; it != _values.End(); ++it )
		{
			if ( _string.GetLength() > 0 )
			{
				_string.Append( L", " );
			}
			_string.Append( String::Format(L"{0} = ?{1}", it.Key(), idx++) );
		}
		String filter = Evaluate( _filter );
		_sql = String::Format( L"UPDATE {0} SET {1}{2}", _table->GetName(), _string.GetString(), filter );
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
			throw DatabaseException( L"Failed to update database.", _sql, Sqlite::ToString(rc) );
	}
}


} // db


} // synkro
