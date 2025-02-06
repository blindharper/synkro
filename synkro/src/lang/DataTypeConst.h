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
// Purpose: Defines data type constant values.
//==============================================================================
#ifndef _SYNKRO_LANG_DATATYPECONST_
#define _SYNKRO_LANG_DATATYPECONST_


#include "config.h"


namespace synkro
{


namespace lang
{


// Data type constant values.
enum DataTypeConst
{
	DATA_TYPE_UNKNOWN	= 0,
	DATA_TYPE_INTEGER	= 1,
	DATA_TYPE_FLOAT		= 2,
	DATA_TYPE_STRING	= 3,
	DATA_TYPE_DATE_TIME	= 4,
	DATA_TYPE_BLOB		= 5,
};


} // lang


} // synkro


#endif // _SYNKRO_LANG_DATATYPECONST_
