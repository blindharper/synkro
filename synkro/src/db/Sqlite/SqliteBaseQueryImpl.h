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
// Purpose: Generic Sqlite base query implementation.
//=============================================================================
#ifndef _SYNKRO_DB_SQLITEBASEQUERYIMPL_
#define _SYNKRO_DB_SQLITEBASEQUERYIMPL_


#include "config.h"
#include "Sqlite.h"
#include <lang/Formatter.h>
#include <lang/Variant.h>
#include <lang/Map.h>
#include <lang/Ptr.h>
#include <lang/StringBuilder.h>
#include <lang/DataTypeConst.h>
#include <io/BinaryReader.h>
#include <db/DatabaseException.h>


namespace synkro
{


namespace db
{


// Generic Sqlite base query implementation.
template <class T>
class SqliteBaseQueryImpl :
	public T
{
public:
	// Constructor and destructor.
	SqliteBaseQueryImpl( sqlite3* db );
	virtual ~SqliteBaseQueryImpl();
	
	// SqliteBaseQuery methods.
	virtual lang::String									Evaluate( IDataFilter* filter ) const;
	virtual void											Bind( const lang::MapCI<lang::String, lang::Variant>& values );

protected:
	sqlite3*												_db;
	sqlite3_stmt*											_stmt;
	lang::String											_sql;
	lang::StringBuilder										_string;

	lang::String											EvaluateFilter( IDataFilter* filter ) const;
	void													Finalize();
	void													ReadString( const lang::String& value, lang::Vector<Byte>& bytes );
	void													ReadBlob( io::IStream* blob, lang::Vector<Byte>& bytes );
};


#include "SqliteBaseQueryImpl.inl"


} // db


} // synkro


#endif // _SYNKRO_DB_SQLITEBASEQUERYIMPL_
