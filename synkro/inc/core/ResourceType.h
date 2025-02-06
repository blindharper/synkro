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
// Purpose: Defines resource type.
//==============================================================================
#ifndef _SYNKRO_CORE_RESOURCETYPE_
#define _SYNKRO_CORE_RESOURCETYPE_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace core
{


/**
 * Resource type.
 */
SYNKRO_ENUM_BEGIN( ResourceType )
	/** Unknown resource. */
	SYNKRO_ENUM_CONST( ResourceType, Unknown )

	/** Graphics device program. */
	SYNKRO_ENUM_CONST( ResourceType, GraphicsProgram )

	/** User interface theme. */
	SYNKRO_ENUM_CONST( ResourceType, UiTheme )
SYNKRO_ENUM_END()


} // core


} // synkro


#endif // _SYNKRO_CORE_RESOURCETYPE_
