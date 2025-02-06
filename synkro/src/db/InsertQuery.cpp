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
// Purpose: Implements logical INSERT query.
//==============================================================================
#include "config.h"
#include "InsertQuery.h"


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace db
{


InsertQuery::InsertQuery( IDataTable* table, IInsertQuery* query ) :
	BaseDatabaseQueryImpl<BaseDatabaseQuery>( table ),
	_query( query )
{
}


} // db


} // synkro
