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
// Purpose: Defines base Sqlite query.
//==============================================================================
#ifndef _SYNKRO_DB_SQLITEBASEQUERY_
#define _SYNKRO_DB_SQLITEBASEQUERY_


#include "config.h"
#include <lang/Variant.h>
#include <lang/Map.h>


namespace synkro
{


namespace db
{


// Base Sqlite query.
class SqliteBaseQuery
{
public:
	virtual lang::String									Evaluate( IDataFilter* filter ) const = 0;
	virtual void											Bind( const lang::MapCI<lang::String, lang::Variant>& values ) = 0;
};


} // db


} // synkro


#endif // _SYNKRO_DB_SQLITEBASEQUERY_
