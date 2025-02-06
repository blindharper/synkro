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
// Purpose: Defines script parameter data types.
//==============================================================================
#ifndef _SYNKRO_SCRIPT_SCRIPTPARAMTYPE_
#define _SYNKRO_SCRIPT_SCRIPTPARAMTYPE_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace script
{


/**
 * Script parameter data types.
 */
SYNKRO_ENUM_BEGIN( ScriptParamType )
	/** Unknown data type. */
	SYNKRO_ENUM_CONST( ScriptParamType, Unknown )

	/** Logical data type. */
	SYNKRO_ENUM_CONST( ScriptParamType, Boolean )

	/** Numeric data type. */
	SYNKRO_ENUM_CONST( ScriptParamType, Number )

	/** String data type. */
	SYNKRO_ENUM_CONST( ScriptParamType, String )

	/** Object type. */
	SYNKRO_ENUM_CONST( ScriptParamType, Object )
SYNKRO_ENUM_END()


} // script


} // synkro


#endif // _SYNKRO_SCRIPT_SCRIPTPARAMTYPE_
