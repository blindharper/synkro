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
// Purpose: Defines data mode.
//==============================================================================
#ifndef _SYNKRO_CORE_DATAMODE_
#define _SYNKRO_CORE_DATAMODE_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace core
{


/**
 * Data mode.
 */
SYNKRO_ENUM_BEGIN( DataMode )
	/** Unknown data. */
	SYNKRO_ENUM_CONST( DataMode, Unknown )

	/** Text data. */
	SYNKRO_ENUM_CONST( DataMode, Text )

	/** Binary data. */
	SYNKRO_ENUM_CONST( DataMode, Binary )

	/** Creates data mode from string. */
	DataMode( const lang::String& mode );
SYNKRO_ENUM_END()


} // core


} // synkro


#endif // _SYNKRO_CORE_DATAMODE_
