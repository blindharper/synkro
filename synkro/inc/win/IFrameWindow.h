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
// Purpose: Defines frame window.
//==============================================================================
#ifndef _SYNKRO_WIN_IFRAMEWINDOW_
#define _SYNKRO_WIN_IFRAMEWINDOW_


#include "config.h"
#include <win/IWindow.h>
#include <lang/String.h>


namespace synkro
{


namespace win
{


/**
 * Top-level window. Used as a main application window.
 */
iface IFrameWindow :
	public IWindow
{
public:
	/**
	 * Centers the window in the desktop.
	 */
	virtual void											Center() = 0;

	/**
	 * Activates the window.
	 */
	virtual void											Activate() = 0;

	/**
	 * Sets text displayed in the window caption.
	 * @param title New window title.
	 */
	virtual void											SetTitle( const lang::String& title ) = 0;

	/** 
	 * Sets window popup state.
	 * @param popup Set to true to use window in fullscreen mode.
	 */
	virtual void											SetPopup( Bool popup ) = 0;

	/**
	 * Retrieves window icon.
	 */
	virtual UInt											GetIcon() const = 0;

	/**
	 * Retrieves window title.
	 */
	virtual lang::String									GetTitle() const = 0;

	/**
	 * Retrieves owner monitor.
	 */
	virtual IMonitor*										GetMonitor() const = 0;

	/**
	 * Indicates whether the window is in the popup state.
	 */
	virtual Bool											IsPopup() const = 0;

	/**
	 * Indicates whether the window is sizeable.
	 */
	virtual Bool											IsSizeable() const = 0;

	/**
	 * Indicates whether the window is meant for rendering.
	 */
	virtual Bool											IsRenderable() const = 0;
};


} // win


} // synkro


#endif // _SYNKRO_WIN_IFRAMEWINDOW_
