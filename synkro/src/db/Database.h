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
// Purpose: Implements logical database.
//==============================================================================
#ifndef _SYNKRO_DB_DATABASE_
#define _SYNKRO_DB_DATABASE_


#include "config.h"
#include "DatabaseImpl.h"
#include <db/IDatabase.h>
#include "BaseDatabase.h"


namespace synkro
{


namespace db
{


// Logical database implementation.
class Database :
	public DatabaseImpl<IDatabase>,
	public BaseDatabase
{
public:
	// Constructor.
	Database( IDatabase* db );

	// IDatabase methods.
	IDataTable*												CreateTable( const lang::String& name, const TableColumn* columns, UInt count );

	// BaseDatabase methods.
	void													RemoveTable( IDataTable* table );

private:
	P(IDatabase)											_db;
};


} // db


} // synkro


#endif // _SYNKRO_DB_DATABASE_
