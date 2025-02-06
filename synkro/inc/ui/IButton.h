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
// Purpose: Defines button widget.
//==============================================================================
#ifndef _SYNKRO_UI_IBUTTON_
#define _SYNKRO_UI_IBUTTON_


#include "config.h"
#include <ui/IWidget.h>


namespace synkro
{


namespace ui
{


/**
 * Button widget.
 */
iface IButton :
	public IWidget
{
public:
	/** 
	 * Presses or unpresses button.
	 * @param press Set to true to press button, set to false to unpress it.
	 */
	virtual void											Press( Bool press ) = 0;

	/** 
	 * Sets or removes button highlight.
	 * @param highlight Set to true to highlight button, set to false to remove highlight.
	 */
	virtual void											Highlight( Bool highlight ) = 0;

	/**
	 * Sets the text that is displayed on the button.
	 * @param text Button text.
	 */
	virtual void											SetText( const lang::String& text ) = 0;

	/**
	 * Retrieves button pressed state.
	 * @return True if the button is pressed, false otherwise.
	 */
	virtual Bool											IsPressed() const = 0;

	/**
	 * Retrieves button highlighted state.
	 * @return True if the button is highlighted, false otherwise.
	 */
	virtual Bool											IsHighlighted() const = 0;

	/**
	 * Retrieves button text.
	 */
	virtual lang::String									GetText() const = 0;
};


} // ui


} // synkro


#endif // _SYNKRO_UI_IBUTTON_
