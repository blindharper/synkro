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
// Purpose: Sqlite API.
//==============================================================================
#ifndef _SYNKRO_DB_SQLITE_
#define _SYNKRO_DB_SQLITE_


#include "config.h"
#include <lang/DataType.h>
#include <db/SortOrder.h>
#include <db/CombinationType.h>
#include <db/ComparisonType.h>


extern "C"
{
#include <sqlite/sqlite3.h>
}


namespace synkro
{


namespace db
{


typedef int (sqlite_callback) (void*,int,char**,char**);


// Sqlite API.
class Sqlite
{
public:
	static void												Prepare( sqlite3* db, const lang::String& sql, sqlite3_stmt** stmt );
	static void												Execute( sqlite3* db, const lang::String& sql, sqlite_callback callback = nullptr, void* ctx = NULL );
	static lang::DataType									ToType( const lang::String& type );
	static const Char*										ToString( const lang::DataType& type );
	static const Char*										ToString( const SortOrder& order );
	static const Char*										ToString( const CombinationType& combination );
	static const Char*										ToString( const ComparisonType& comparison );
	static const Char*										ToString( int error );
};


} // db


} // synkro


#endif // _SYNKRO_DB_SQLITE_
