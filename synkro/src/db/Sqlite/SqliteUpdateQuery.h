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
#ifndef _SYNKRO_DB_SQLITEUPDATEQUERY_
#define _SYNKRO_DB_SQLITEUPDATEQUERY_


#include "config.h"
#include <db/UpdateQueryImpl.h>
#include <db/IUpdateQuery.h>
#include "SqliteBaseQueryImpl.h"
#include "SqliteBaseQuery.h"


namespace synkro
{


namespace db
{


// Sqlite UPDATE query implementation.
class SqliteUpdateQuery :
	public UpdateQueryImpl<IUpdateQuery>,
	public SqliteBaseQueryImpl<SqliteBaseQuery>
{
public:
	// Constructor.
	SqliteUpdateQuery( sqlite3* db, IDataTable* table );

	// IDatabaseQuery methods.
	void													Execute();
};


} // db


} // synkro


#endif // _SYNKRO_DB_SQLITEUPDATEQUERY_
