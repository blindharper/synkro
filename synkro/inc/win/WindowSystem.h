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
// Purpose: Defines window system types.
//==============================================================================
#ifndef _SYNKRO_WIN_WINDOWSYSTEM_
#define _SYNKRO_WIN_WINDOWSYSTEM_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace win
{


/**
 * Window system types.
 */
SYNKRO_ENUM_BEGIN( WindowSystem )
	/** Custom window system. */
	SYNKRO_ENUM_CONST( WindowSystem, Custom )

	/** Win32 window system. */
	SYNKRO_ENUM_CONST( WindowSystem, Win32 )
SYNKRO_ENUM_END()


} // win


} // synkro


#endif // _SYNKRO_WIN_WINDOWSYSTEM_
