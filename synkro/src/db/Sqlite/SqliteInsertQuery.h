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
#ifndef _SYNKRO_DB_SQLITEINSERTQUERY_
#define _SYNKRO_DB_SQLITEINSERTQUERY_


#include "config.h"
#include <db/InsertQueryImpl.h>
#include <db/IInsertQuery.h>
#include "SqliteBaseQueryImpl.h"
#include "SqliteBaseQuery.h"


namespace synkro
{


namespace db
{


// Sqlite INSERT query implementation.
class SqliteInsertQuery :
	public InsertQueryImpl<IInsertQuery>,
	public SqliteBaseQueryImpl<SqliteBaseQuery>
{
public:
	// Constructor.
	SqliteInsertQuery( sqlite3* db, IDataTable* table );

	// IDatabaseQuery methods.
	void													Execute();
	UInt													GetRowID() const;
};


} // db


} // synkro


#endif // _SYNKRO_DB_SQLITEINSERTQUERY_
