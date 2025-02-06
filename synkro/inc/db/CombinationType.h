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
// Purpose: Defines data filter combination types.
//==============================================================================
#ifndef _SYNKRO_DB_COMBINATIONTYPE_
#define _SYNKRO_DB_COMBINATIONTYPE_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace db
{


/**
 * Data filter combination types.
 */
SYNKRO_ENUM_BEGIN( CombinationType )
	/** Combines data filters with AND operator. */
	SYNKRO_ENUM_CONST( CombinationType, And )

	/** Combines data filters with OR operator. */
	SYNKRO_ENUM_CONST( CombinationType, Or )
SYNKRO_ENUM_END()


} // db


} // synkro


#endif // _SYNKRO_DB_COMBINATIONTYPE_
