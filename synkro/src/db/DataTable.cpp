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
#include "config.h"
#include "DataTable.h"
#include "TableIndex.h"
#include "InsertQuery.h"
#include "UpdateQuery.h"
#include "SelectQuery.h"
#include "DeleteQuery.h"


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace db
{


DataTable::DataTable( BaseDatabase* db, IDataTable* table ) :
	DataTableImpl<IDataTable>( table->GetName() ),
	_db( db ),
	_table( table )
{
	// Create wrapper indexes.
	for ( UInt i = 0; i < _table->GetIndexCount(); ++i )
	{
		ITableIndex* index = new TableIndex( this, _table->GetIndex(i) );
		_indexIndices[index->GetName()] = _indexes.Size();
		_indexes.Add( index );
	}
}

ITableIndex* DataTable::CreateIndex( const String& name, Bool unique, const String* columns, UInt count )
{
	// Try returning existing index.
	ITableIndex* index = GetIndex( name );
	if ( index != nullptr )
		return index;

	// Create new index.
	index = new TableIndex( this, _table->CreateIndex(name, unique, columns, count) );
	_indexIndices[name] = _indexes.Size();
	_indexes.Add( index );

	return index;
}

IInsertQuery* DataTable::CreateInsertQuery()
{
	return new InsertQuery( this, _table->CreateInsertQuery() );
}

IUpdateQuery* DataTable::CreateUpdateQuery()
{
	return new UpdateQuery( this, _table->CreateUpdateQuery() );
}

ISelectQuery* DataTable::CreateSelectQuery()
{
	return new SelectQuery( this, _table->CreateSelectQuery() );
}

IDeleteQuery* DataTable::CreateDeleteQuery()
{
	return new DeleteQuery( this, _table->CreateDeleteQuery() );
}

void DataTable::Delete()
{
	_table->Delete();
	AsBaseDatabase( _db )->RemoveTable( this );
}

UInt DataTable::GetRowCount()
{
	return _table->GetRowCount();
}

UInt DataTable::GetColumnCount() const
{
	return _table->GetColumnCount();
}

void DataTable::GetColumn( UInt index, TableColumn& column ) const
{
	_table->GetColumn( index, column );
}

void DataTable::GetColumn( const String& name, TableColumn& column ) const
{
	_table->GetColumn( name, column );
}

void DataTable::RemoveIndex( ITableIndex* index )
{
	_indexIndices.Remove( index->GetName() );
	_indexes.Remove( index );
}


} // db


} // synkro
