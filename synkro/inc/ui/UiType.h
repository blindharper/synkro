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
// Purpose: Defines user interface types.
//==============================================================================
#ifndef _SYNKRO_UI_UITYPE_
#define _SYNKRO_UI_UITYPE_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace ui
{


/**
 * User interface types.
 */
SYNKRO_ENUM_BEGIN( UiType )
	/** Custom user interface. */
	SYNKRO_ENUM_CONST( UiType, Custom )

	/** Default user interface. */
	SYNKRO_ENUM_CONST( UiType, Default )
SYNKRO_ENUM_END()


} // ui


} // synkro


#endif // _SYNKRO_UI_UITYPE_
