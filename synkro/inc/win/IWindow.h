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
// Purpose: Defines base window.
//==============================================================================
#ifndef _SYNKRO_WIN_IWINDOW_
#define _SYNKRO_WIN_IWINDOW_


#include "config.h"
#include <core/IObject.h>


namespace synkro
{


namespace win
{


/**
 * Base window.
 */
iface IWindow :
	public core::IObject
{
public:
	/**
	 * Handles pending messages.
	 * @return True, if the window was successfully updated, false otherwise.
	 */
	virtual Bool											Update() = 0;

	/**
	 * Destroys the window.
	 */
	virtual void											Close() = 0;

	/**
	 * Sets window origin relative to its parent.
	 * @param left Window's horizontal coordinate.
	 * @param top Window's vertical coordinate.
	 */
	virtual void											SetPosition( Int left, Int top ) = 0;

	/**
	 * Sets window size.
	 * @param width New width of the window.
	 * @param height New height of the window.
	 */
	virtual void											SetSize( UInt width, UInt height ) = 0;

	/**
	 * Retrieves left window coordinate.
	 */
	virtual Int												GetLeft() const = 0;

	/**
	 * Retrieves top window coordinate.
	 */
	virtual Int												GetTop() const = 0;

	/**
	 * Retrieves window width.
	 */
	virtual UInt											GetWidth() const = 0;

	/**
	 * Retrieves window height.
	 */
	virtual UInt											GetHeight() const = 0;

	/**
	 * Retrieves unique window descriptor.
	 */
	virtual UInt											GetHandle() const = 0;

	/**
	 * Retrieves window dots per inches ratio.
	 */
	virtual UInt											GetDpi() const = 0;

	/**
	 * Indicates whether the window is currently active.
	 */
	virtual Bool											IsActive() const = 0;

	/**
	 * Indicates whether the window is about to be closed.
	 */
	virtual Bool											IsClosing() const = 0;
};


} // win


} // synkro


#endif // _SYNKRO_WIN_IWINDOW_
