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
// Purpose: Defines switch widget.
//==============================================================================
#ifndef _SYNKRO_UI_ISWITCH_
#define _SYNKRO_UI_ISWITCH_


#include "config.h"
#include <ui/IWidget.h>


namespace synkro
{


namespace ui
{


/**
 * Switch widget.
 */
iface ISwitch :
	public IWidget
{
public:
	/**
	 * Turns the switch on or off.
	 * @param on Set to true turn on the switch, set to false to turn it off.
	 */
	virtual void											Turn( Bool on ) = 0;

	/** 
	 * Sets or removes switch highlight.
	 * @param highlight Set to true to highlight switch, set to false to remove highlight.
	 */
	virtual void											Highlight( Bool highlight ) = 0;

	/**
	 * Sets the text that is displayed on the switch.
	 * @param text Switch text.
	 */
	virtual void											SetText( const lang::String& text ) = 0;
	
	/**
	 * Tests if the switch is selected.
	 */
	virtual Bool											IsOn() const = 0;

	/**
	 * Retrieves switch highlighted state.
	 * @return True if the switch is highlighted, false otherwise.
	 */
	virtual Bool											IsHighlighted() const = 0;

	/**
	 * Retrieves switch text.
	 */
	virtual lang::String									GetText() const = 0;
};


} // ui


} // synkro


#endif // _SYNKRO_UI_ISWITCH_
