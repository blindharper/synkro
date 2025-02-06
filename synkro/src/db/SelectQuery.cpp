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
// Purpose: Implements logical SELECT query.
//==============================================================================
#include "config.h"
#include "SelectQuery.h"
#include "DataCursor.h"


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace db
{


SelectQuery::SelectQuery( IDataTable* table, ISelectQuery* query ) :
	BaseDatabaseQueryImpl<BaseDatabaseQuery>( table ),
	_query( query )
{
}

IDataCursor* SelectQuery::GetCursor() const
{
	if ( _cursor == nullptr )
	{
		_cursor = (_query->GetCursor() != nullptr) ? new DataCursor( _query->GetCursor() ) : nullptr;
	}
	return _cursor;
}


} // db


} // synkro
