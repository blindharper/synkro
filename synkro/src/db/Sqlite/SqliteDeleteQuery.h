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
#ifndef _SYNKRO_DB_SQLITEDELETEQUERY_
#define _SYNKRO_DB_SQLITEDELETEQUERY_


#include "config.h"
#include <db/DeleteQueryImpl.h>
#include <db/IDeleteQuery.h>
#include "SqliteBaseQueryImpl.h"
#include "SqliteBaseQuery.h"


namespace synkro
{


namespace db
{


// Sqlite DELETE query implementation.
class SqliteDeleteQuery :
	public DeleteQueryImpl<IDeleteQuery>,
	public SqliteBaseQueryImpl<SqliteBaseQuery>
{
public:
	// Constructor.
	SqliteDeleteQuery( sqlite3* db, IDataTable* table );

	// IDatabaseQuery methods.
	void													Execute();
};


} // db


} // synkro


#endif // _SYNKRO_DB_SQLITEDELETEQUERY_
