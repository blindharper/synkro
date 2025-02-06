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
// Purpose: Defines data values comparison types.
//==============================================================================
#ifndef _SYNKRO_DB_COMPARISONTYPE_
#define _SYNKRO_DB_COMPARISONTYPE_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace db
{


/**
 * Data values comparison types.
 */
SYNKRO_ENUM_BEGIN( ComparisonType )
	/** Unknown comparison type. */
	SYNKRO_ENUM_CONST( ComparisonType, Unknown )

	/** "IS" comparison. Applies to Null value. */
	SYNKRO_ENUM_CONST( ComparisonType, Is )

	/** "IS NOT" comparison. Applies to Null value. */
	SYNKRO_ENUM_CONST( ComparisonType, IsNot )

	/** Equality comparison. */
	SYNKRO_ENUM_CONST( ComparisonType, Equal )
	
	/** Not equal comparison. */
	SYNKRO_ENUM_CONST( ComparisonType, NotEqual )

	/** Less than comparison. */
	SYNKRO_ENUM_CONST( ComparisonType, LessThan )

	/** Less than or equal to comparison. */
	SYNKRO_ENUM_CONST( ComparisonType, LessThanOrEqual )

	/** Greater than comparison. */
	SYNKRO_ENUM_CONST( ComparisonType, GreaterThan )

	/** Greater than or equal to comparison. */
	SYNKRO_ENUM_CONST( ComparisonType, GreaterThanOrEqual )
SYNKRO_ENUM_END()


} // db


} // synkro


#endif // _SYNKRO_DB_COMPARISONTYPE_
