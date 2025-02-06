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
#include "config.h"
#include "Database.h"
#include "DataTable.h"


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace db
{


Database::Database( IDatabase* db ) :
	_db( db )
{
	// Create wrapper tables.
	for ( ULong i = 0; i < db->GetTableCount(); ++i )
	{
		IDataTable* table = new DataTable( this, db->GetTable(i) );
		_tableIndices[table->GetName()] = _tables.Size();
		_tables.Add( table );
	}
}

IDataTable* Database::CreateTable( const String& name, const TableColumn* columns, UInt count )
{
	// Try returning existing table.
	IDataTable* table = GetTable( name );
	if ( table != nullptr )
		return table;

	// Create new table.
	table = new DataTable( this, _db->CreateTable(name, columns, count) );
	_tableIndices[name] = _tables.Size();
	_tables.Add( table );

	return table;
}

void Database::RemoveTable( IDataTable* table )
{
	_tableIndices.Remove( table->GetName() );
	_tables.Remove( table );
}


} // db


} // synkro
