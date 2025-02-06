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
// Purpose: Implements Sqlite database table.
//==============================================================================
#ifndef _SYNKRO_DB_SQLITEDATATABLE_
#define _SYNKRO_DB_SQLITEDATATABLE_


#include "config.h"
#include <db/DataTableImpl.h>
#include <db/IDataTable.h>
#include <db/BaseDataTable.h>
#include <db/BaseDatabase.h>
#include "Sqlite.h"


namespace synkro
{


namespace db
{


// Sqlite database table implementation.
class SqliteDataTable :
	public DataTableImpl<IDataTable>,
	public BaseDataTable
{
public:
	// Constructor.
	SqliteDataTable( BaseDatabase* owner, sqlite3* db, const lang::String& name, const TableColumn* columns, UInt count, Bool create );

	// IDataTable methods.
	ITableIndex*											CreateIndex( const lang::String& name, Bool unique, const lang::String* columns, UInt count );
	IInsertQuery*											CreateInsertQuery();
	IUpdateQuery*											CreateUpdateQuery();
	ISelectQuery*											CreateSelectQuery();
	IDeleteQuery*											CreateDeleteQuery();
	void													Delete();
	UInt													GetRowCount();

	// BaseDataTable methods.
	void													RemoveIndex( ITableIndex* index );

	// Other methods.
	void													AddIndex( const lang::String& name, Bool unique, const lang::String* columns, UInt count );

private:
	BaseDatabase*											_owner;
	sqlite3*												_db;	
};


} // db


} // synkro


#endif // _SYNKRO_DB_SQLITEDATATABLE_
