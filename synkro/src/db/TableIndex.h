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
#ifndef _SYNKRO_DB_TABLEINDEX_
#define _SYNKRO_DB_TABLEINDEX_


#include "config.h"
#include "TableIndexImpl.h"
#include <db/ITableIndex.h>


namespace synkro
{


namespace db
{


// Logical database table index implementation.
class TableIndex :
	public TableIndexImpl<ITableIndex>
{
public:
	// Constructor.
	TableIndex( IDataTable* table, ITableIndex* index );

	// ITableIndex methods.
	void													Delete();
	UInt													GetColumnCount() const;
	lang::String											GetColumn( UInt index ) const;

private:
	P(ITableIndex)											_index;
};


} // db


} // synkro


#endif // _SYNKRO_DB_TABLEINDEX_
