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
// Purpose: Implements Sqlite DELETE query.
//==============================================================================
#include "config.h"
#include "SqliteDeleteQuery.h"


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace db
{


SqliteDeleteQuery::SqliteDeleteQuery( sqlite3* db, IDataTable* table ) :
	DeleteQueryImpl<IDeleteQuery>( table ),
	SqliteBaseQueryImpl<SqliteBaseQuery>( db )
{
}

void SqliteDeleteQuery::Execute()
{
	// Prepare statement.
	if ( _dirty )
	{
		Finalize();
		String filter = Evaluate( _filter );
		_sql = String::Format( L"DELETE FROM {0}{1}", _table->GetName(), filter );
		Sqlite::Prepare( _db, _sql, &_stmt );
		_dirty = false;
	}

	// Execute statement.
	int rc = SQLITE_OK;
	while ( (rc = sqlite3_step(_stmt)) != SQLITE_DONE )
	{
		if ( rc != SQLITE_OK )
			throw DatabaseException( L"Failed to delete records from database.", _sql, Sqlite::ToString(rc) );
	}
}


} // db


} // synkro
