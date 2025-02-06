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
// Purpose: Implements logical database table.
//==============================================================================
#ifndef _SYNKRO_DB_DATATABLE_
#define _SYNKRO_DB_DATATABLE_


#include "config.h"
#include "DataTableImpl.h"
#include <db/IDataTable.h>
#include "BaseDataTable.h"
#include "BaseDatabase.h"


namespace synkro
{


namespace db
{


// Logical database table implementation.
class DataTable :
	public DataTableImpl<IDataTable>,
	public BaseDataTable
{
public:
	// Constructor.
	DataTable( BaseDatabase* db, IDataTable* table );

	// IDataTable methods.
	ITableIndex*											CreateIndex( const lang::String& name, Bool unique, const lang::String* columns, UInt count );
	IInsertQuery*											CreateInsertQuery();
	IUpdateQuery*											CreateUpdateQuery();
	ISelectQuery*											CreateSelectQuery();
	IDeleteQuery*											CreateDeleteQuery();
	void													Delete();
	UInt													GetRowCount();
	UInt													GetColumnCount() const;
	void													GetColumn( UInt index, TableColumn& column ) const;
	void													GetColumn( const lang::String& name, TableColumn& column ) const;

	// BaseDataTable methods.
	void													RemoveIndex( ITableIndex* index );

private:
	BaseDatabase*											_db;
	P(IDataTable)											_table;
};


} // db


} // synkro


#endif // _SYNKRO_DB_DATATABLE_
