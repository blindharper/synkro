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
// Purpose: Implements Sqlite database table index.
//==============================================================================
#ifndef _SYNKRO_DB_SQLITETABLEINDEX_
#define _SYNKRO_DB_SQLITETABLEINDEX_


#include "config.h"
#include <db/TableIndexImpl.h>
#include <db/ITableIndex.h>
#include "Sqlite.h"


namespace synkro
{


namespace db
{


// Sqlite database table index implementation.
class SqliteTableIndex :
	public TableIndexImpl<ITableIndex>
{
public:
	// Constructor.
	SqliteTableIndex( sqlite3* db, IDataTable* table, const lang::String& name, Bool unique, const lang::String* columns, UInt count, Bool create );

	// ITableIndex methods.
	void													Delete();

private:
	sqlite3*												_db;
};


} // db


} // synkro


#endif // _SYNKRO_DB_SQLITETABLEINDEX_
