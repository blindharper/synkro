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
// Purpose: Defines configuration parameter type constant values.
//==============================================================================
#ifndef _SYNKRO_CORE_PARAMTYPECONST_
#define _SYNKRO_CORE_PARAMTYPECONST_


#include "config.h"


namespace synkro
{


namespace core
{


// Parameter type constant values.
enum ParamTypeConst
{
	PARAM_TYPE_STRING		= 1,
	PARAM_TYPE_LIST			= 2,
	PARAM_TYPE_INTEGER		= 3,
	PARAM_TYPE_BOOLEAN		= 4,
	PARAM_TYPE_FLAG			= 5,
	PARAM_TYPE_ENUMERATION	= 6,
	PARAM_TYPE_COLOR		= 7,
};


} // core


} // synkro


#endif // _SYNKRO_CORE_PARAMTYPECONST_
