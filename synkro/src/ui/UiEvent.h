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
// Purpose: Defines user interface event types.
//==============================================================================
#ifndef _SYNKRO_UI_UIEVENT_
#define _SYNKRO_UI_UIEVENT_


#include "config.h"


namespace synkro
{


namespace ui
{


// User interface event types.
enum UiEvent
{
	UI_EVENT_NONE = 0,
	UI_EVENT_CLICK,
	UI_EVENT_DOUBLE_CLICK,
	UI_EVENT_VALUE_CHANGED,
};


} // ui


} // synkro


#endif // _SYNKRO_UI_UIEVENT_
