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
// Purpose: Defines base database table.
//==============================================================================
#ifndef _SYNKRO_DB_BASEDATATABLE_
#define _SYNKRO_DB_BASEDATATABLE_


#include "config.h"


namespace synkro
{


namespace db
{


// Base database table.
class BaseDataTable
{
public:
	virtual void											RemoveIndex( ITableIndex* index ) = 0;
};


// Casts object to BaseDataTable.
#define AsBaseDataTable( OBJ ) dynamic_cast<BaseDataTable*>( OBJ )


} // db


} // synkro


#endif // _SYNKRO_DB_BASEDATATABLE_
