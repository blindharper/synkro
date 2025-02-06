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
// Purpose: Defines content alignment.
//==============================================================================
#include "config.h"
#include <db/ComparisonType.h>
#include <internal/Enum.h>


namespace synkro
{


namespace db
{


SYNKRO_DEFINE_CONST( ComparisonType, Unknown,				0 )
SYNKRO_DEFINE_CONST( ComparisonType, Is,					1 )
SYNKRO_DEFINE_CONST( ComparisonType, IsNot,					2 )
SYNKRO_DEFINE_CONST( ComparisonType, Equal,					3 )
SYNKRO_DEFINE_CONST( ComparisonType, NotEqual,				4 )
SYNKRO_DEFINE_CONST( ComparisonType, LessThan,				5 )
SYNKRO_DEFINE_CONST( ComparisonType, LessThanOrEqual,		6 )
SYNKRO_DEFINE_CONST( ComparisonType, GreaterThan,			7 )
SYNKRO_DEFINE_CONST( ComparisonType, GreaterThanOrEqual,	8 )


} // db


} // synkro
