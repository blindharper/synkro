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
// Purpose: Defines database table records sort order.
//==============================================================================
#ifndef _SYNKRO_DB_SORTORDER_
#define _SYNKRO_DB_SORTORDER_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace db
{


/**
 * Database table records sort order.
 */
SYNKRO_ENUM_BEGIN( SortOrder )
	/** Records are sorted in ascending order. */
	SYNKRO_ENUM_CONST( SortOrder, Asc )
	
	/** Records are sorted in descending order. */
	SYNKRO_ENUM_CONST( SortOrder, Desc )
SYNKRO_ENUM_END()


} // db


} // synkro


#endif // _SYNKRO_DB_SORTORDER_
