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
#ifndef _SYNKRO_DB_SQLITESELECTQUERY_
#define _SYNKRO_DB_SQLITESELECTQUERY_


#include "config.h"
#include <db/SelectQueryImpl.h>
#include <db/ISelectQuery.h>
#include "SqliteBaseQueryImpl.h"
#include "SqliteBaseQuery.h"


namespace synkro
{


namespace db
{


// Sqlite SELECT query implementation.
class SqliteSelectQuery :
	public SelectQueryImpl<ISelectQuery>,
	public SqliteBaseQueryImpl<SqliteBaseQuery>
{
public:
	// Constructor.
	SqliteSelectQuery( sqlite3* db, IDataTable* table );

	// IDatabaseQuery methods.
	void													Execute();
	void													Reset();

private:
	lang::Vector<TableColumn>								_allColumns;
	lang::Vector<TableColumn>								_selectedColumns;
};


} // db


} // synkro


#endif // _SYNKRO_DB_SQLITESELECTQUERY_
