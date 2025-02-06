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
// Purpose: Implements logical database table index.
//==============================================================================
#include "config.h"
#include "TableIndex.h"
#include "BaseDataTable.h"


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace db
{


TableIndex::TableIndex( IDataTable* table, ITableIndex* index ) :
	TableIndexImpl<ITableIndex>( table, index->GetName(), index->IsUnique(), nullptr, 0 ),
	_index( index )
{
	for ( UInt i = 0; i < index->GetColumnCount(); ++i )
	{
		_columns.Add( index->GetColumn(i) );
	}
}

void TableIndex::Delete()
{
	_index->Delete();
	AsBaseDataTable( _table )->RemoveIndex( this );
}

UInt TableIndex::GetColumnCount() const
{
	return _index->GetColumnCount();
}

String TableIndex::GetColumn( UInt index ) const
{
	return _index->GetColumn( index );
}


} // db


} // synkro
