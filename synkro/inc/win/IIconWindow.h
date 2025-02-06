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
// Purpose: Defines icon window.
//==============================================================================
#ifndef _SYNKRO_WIN_IICONWINDOW_
#define _SYNKRO_WIN_IICONWINDOW_


#include "config.h"
#include <win/IWindow.h>
#include <lang/String.h>


namespace synkro
{


namespace win
{


/**
 * Icon window.
 */
iface IIconWindow :
	public IWindow
{
public:
	/**
	 * Registers window event listener.
	 * @param listener Event listener.
	 */
	virtual void											Listen( WindowListener* listener ) = 0;

	/**
	 * Adds an item to the window menu.
	 * @param id Menu item identifier.
	 * @param icon Icon identifier.
	 * @param text Menu item text. Null string denotes separator.
	 */
	virtual void											AddMenuItem( UInt id, UInt icon, const lang::String& text ) = 0;

	/**
	 * Sets window icon.
	 * @param icon Handle to icon.
	 */
	virtual void											SetIcon( UInt icon ) = 0;

	/**
	 * Sets the text that is displayed when mouse pointer is placed over the window.
	 * @param hint New window hint.
	 */
	virtual void											SetHint( const lang::String& hint ) = 0;

	/**
	 * Retrieves window icon.
	 */
	virtual UInt											GetIcon() const = 0;

	/**
	 * Retrieves window hint.
	 */
	virtual lang::String									GetHint() const = 0;
};


} // win


} // synkro


#endif // _SYNKRO_WIN_IICONWINDOW_
