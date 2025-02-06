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
// Purpose: Defines viewport visualization mode.
//==============================================================================
#ifndef _SYNKRO_VIEW_VIEWMODE_
#define _SYNKRO_VIEW_VIEWMODE_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace view
{


/**
 * Viewport visualization mode.
 */
SYNKRO_ENUM_BEGIN( ViewMode )
	/** Displays color buffer. */
	SYNKRO_ENUM_CONST( ViewMode, Color )

	/** Displays alpha channel. */
	SYNKRO_ENUM_CONST( ViewMode, Alpha )

	/** Displays depth buffer. */
	SYNKRO_ENUM_CONST( ViewMode, Depth )

	/** Displays stencil buffer. */
	SYNKRO_ENUM_CONST( ViewMode, Stencil )
SYNKRO_ENUM_END()


} // view


} // synkro


#endif // _SYNKRO_VIEW_VIEWMODE_
