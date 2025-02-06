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
// Purpose: Defines data type.
//==============================================================================
#include "config.h"
#include <lang/DataType.h>
#include <internal/Enum.h>
#include "DataTypeConst.h"


namespace synkro
{


namespace lang
{


SYNKRO_DEFINE_CONST( DataType, Unknown,		DATA_TYPE_UNKNOWN )
SYNKRO_DEFINE_CONST( DataType, Integer,		DATA_TYPE_INTEGER )
SYNKRO_DEFINE_CONST( DataType, Float,		DATA_TYPE_FLOAT )
SYNKRO_DEFINE_CONST( DataType, String,		DATA_TYPE_STRING )
SYNKRO_DEFINE_CONST( DataType, DateTime,	DATA_TYPE_DATE_TIME )
SYNKRO_DEFINE_CONST( DataType, Blob,		DATA_TYPE_BLOB )


} // lang


} // synkro
