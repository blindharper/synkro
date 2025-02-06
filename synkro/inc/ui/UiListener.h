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
// Purpose: Defines user interface listener.
//==============================================================================
#ifndef _SYNKRO_UI_UILISTENER_
#define _SYNKRO_UI_UILISTENER_


#include "config.h"


namespace synkro
{


namespace ui
{


/**
 * User interface listener.
 */
iface UiListener
{
public:
	/**
	 * Handles mouse click.
	 * @param sender Event sender.
	 * @return True if the event has been handled, false otherwise.
	 */
	virtual Bool											OnUiClick( IWidget* sender ) = 0;

	/**
	 * Handles mouse double click.
	 * @param sender Event sender.
	 * @return True if the event has been handled, false otherwise.
	 */
	virtual Bool											OnUiDoubleClick( IWidget* sender ) = 0;

	/**
	 * Handles "value changed" event.
	 * @param sender Event sender.
	 * @return True if the event has been handled, false otherwise.
	 */
	virtual Bool											OnUiValueChanged( IWidget* sender ) = 0;
};


} // ui


} // synkro


#endif // _SYNKRO_UI_UILISTENER_
