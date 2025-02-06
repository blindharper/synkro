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
// Purpose: 'db' namespace includes.
//==============================================================================
#ifndef _SYNKRO_DB_
#define _SYNKRO_DB_


#include <db/IInsertQuery.h>
#include <db/IUpdateQuery.h>
#include <db/ISelectQuery.h>
#include <db/IDeleteQuery.h>
#include <db/IDataCursor.h>
#include <db/IDataFilter.h>
#include <db/IDatabase.h>
#include <db/IDataTable.h>
#include <db/ITableIndex.h>
#include <db/IDatabaseSystemEx.h>
#include <db/IDatabaseSystemFactory.h>
#include <db/DatabaseSystem.h>
#include <db/DatabaseException.h>


#define PtrInsertQuery P(synkro::db::IInsertQuery)
#define PtrUpdateQuery P(synkro::db::IUpdateQuery)
#define PtrSelectQuery P(synkro::db::ISelectQuery)
#define PtrDeleteQuery P(synkro::db::IDeleteQuery)
#define PtrDataCursor P(synkro::db::IDataCursor)
#define PtrDataFilter P(synkro::db::IDataFilter)
#define PtrDatabase P(synkro::db::IDatabase)
#define PtrDataTable P(synkro::db::IDataTable)
#define PtrTableIndex P(synkro::db::ITableIndex)


namespace synkro
{


/**
 * The 'db' namespace contains interfaces for working with databases.
 * They allow for creation of database tables and making various
 * queries to them without any knowledge of SQL language.
 */
namespace db
{
} // db


} // synkro


#endif // _SYNKRO_DB_
