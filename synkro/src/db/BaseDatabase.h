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
// Purpose: Defines base database.
//==============================================================================
#ifndef _SYNKRO_DB_BASEDATABASE_
#define _SYNKRO_DB_BASEDATABASE_


#include "config.h"


namespace synkro
{


namespace db
{


// Base database.
class BaseDatabase
{
public:
	virtual void											RemoveTable( IDataTable* table ) = 0;
};


// Casts object to BaseDatabase.
#define AsBaseDatabase( OBJ ) dynamic_cast<BaseDatabase*>( OBJ )


} // db


} // synkro


#endif // _SYNKRO_DB_BASEDATABASE_
