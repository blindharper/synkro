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
// Purpose: Defines widget states.
//==============================================================================
#ifndef _SYNKRO_UI_WIDGETSTATE_
#define _SYNKRO_UI_WIDGETSTATE_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace ui
{


/**
 * Widget states.
 */
SYNKRO_ENUM_BEGIN( WidgetState )
	/** Widget is in normal state. */
	SYNKRO_ENUM_CONST( WidgetState, Normal )

	/** Widget has input focus. */
	SYNKRO_ENUM_CONST( WidgetState, Active )

	/** Mouse is above the widget. */
	SYNKRO_ENUM_CONST( WidgetState, Hovered )

	/** Widget is disabled. */
	SYNKRO_ENUM_CONST( WidgetState, Disabled )
SYNKRO_ENUM_END()


} // ui


} // synkro


#endif // _SYNKRO_UI_WIDGETSTATE_
