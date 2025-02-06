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
#include "config.h"
#include "SqliteTableIndex.h"
#include <db/BaseDataTable.h>


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace db
{


SqliteTableIndex::SqliteTableIndex( sqlite3* db, IDataTable* table, const String& name, Bool unique, const String* columns, UInt count, Bool create ) :
	TableIndexImpl<ITableIndex>( table, name, unique, columns, count ),
	_db( db )
{
	if ( create )
	{
		String list( columns, count, L", " );
		String sql = String::Format( L"CREATE{0}INDEX {1} ON {2} ({3})", unique ? L" UNIQUE " : L" ", name, table->GetName(), list );
		Sqlite::Execute( _db, sql );
	}
}

void SqliteTableIndex::Delete()
{
	String sql = String::Format( L"DROP INDEX {0}", _name );
	Sqlite::Execute( _db, sql );
	AsBaseDataTable( _table )->RemoveIndex( this );
}


} // db


} // synkro
