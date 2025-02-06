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
// Purpose: Defines configuration parameter type.
//==============================================================================
#ifndef _SYNKRO_CORE_PARAMTYPE_
#define _SYNKRO_CORE_PARAMTYPE_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace core
{


/**
 * Configuration parameter type.
 */
SYNKRO_ENUM_BEGIN( ParamType )
	/** String value. */
	SYNKRO_ENUM_CONST( ParamType, String )
	
	/** String list. */
	SYNKRO_ENUM_CONST( ParamType, List )
	
	/** Whole number. */
	SYNKRO_ENUM_CONST( ParamType, Integer )
	
	/** Logical value. */
	SYNKRO_ENUM_CONST( ParamType, Boolean )
	
	/** Bit flags. */
	SYNKRO_ENUM_CONST( ParamType, Flag )
	
	/** Enumeration. */
	SYNKRO_ENUM_CONST( ParamType, Enumeration )

	/** Color value. */
	SYNKRO_ENUM_CONST( ParamType, Color )
SYNKRO_ENUM_END()


} // core


} // synkro


#endif // _SYNKRO_CORE_PARAMTYPE_
