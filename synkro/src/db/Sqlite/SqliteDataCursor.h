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
// Purpose: Implements Sqlite data cursor.
//==============================================================================
#ifndef _SYNKRO_DB_SQLITEDATACURSOR_
#define _SYNKRO_DB_SQLITEDATACURSOR_


#include "config.h"
#include <db/DataCursorImpl.h>
#include <db/IDataCursor.h>
#include "Sqlite.h"


namespace synkro
{


namespace db
{


// Sqlite data cursor implementation.
class SqliteDataCursor :
	public DataCursorImpl<IDataCursor>
{
public:
	// Constructor.
	SqliteDataCursor( sqlite3_stmt* stmt, const lang::Vector<TableColumn>& columns );

	// IDataCursor methods.
	Bool													Read();

private:
	sqlite3_stmt*											_stmt;
};


} // db


} // synkro


#endif // _SYNKRO_DB_SQLITEDATACURSOR_
