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
#ifndef _SYNKRO_DB_SQLITEDATABASE_
#define _SYNKRO_DB_SQLITEDATABASE_


#include "config.h"
#include <db/DatabaseImpl.h>
#include <db/IDatabase.h>
#include <db/BaseDatabase.h>
#include "Sqlite.h"


namespace synkro
{


namespace db
{


// Sqlite database implementation.
class SqliteDatabase :
	public DatabaseImpl<IDatabase>,
	public BaseDatabase
{
public:
	// Constructor & destructor.
	SqliteDatabase( io::IStream* stream );
	~SqliteDatabase();

	// IDatabase methods.
	IDataTable*												CreateTable( const lang::String& name, const TableColumn* columns, UInt count );

	// BaseDatabase methods.
	void													RemoveTable( IDataTable* table );

private:
	sqlite3*												_db;
};


} // db


} // synkro


#endif // _SYNKRO_DB_SQLITEDATABASE_
