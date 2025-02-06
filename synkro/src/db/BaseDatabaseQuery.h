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
// Purpose: Defines base database query.
//==============================================================================
#ifndef _SYNKRO_DB_BASEDATABASEQUERY_
#define _SYNKRO_DB_BASEDATABASEQUERY_


#include "config.h"
#include <lang/String.h>


namespace synkro
{


namespace db
{


// Base database query.
class BaseDatabaseQuery
{
public:
	virtual void											ValidateColumn( const lang::String& name ) = 0;
	virtual void											ValidateFilter( IDataFilter* filter ) = 0;
};


} // db


} // synkro


#endif // _SYNKRO_DB_BASEDATABASEQUERY_
