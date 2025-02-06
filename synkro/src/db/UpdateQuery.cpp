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
// Purpose: Implements logical UPDATE query.
//==============================================================================
#include "config.h"
#include "UpdateQuery.h"


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace db
{


UpdateQuery::UpdateQuery( IDataTable* table, IUpdateQuery* query ) :
	BaseDatabaseQueryImpl<BaseDatabaseQuery>( table ),
	_query( query )
{
}


} // db


} // synkro
