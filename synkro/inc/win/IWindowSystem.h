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
// Purpose: Defines window system.
//==============================================================================
#ifndef _SYNKRO_WIN_IWINDOWSYSTEM_
#define _SYNKRO_WIN_IWINDOWSYSTEM_


#include "config.h"
#include <core/ISystem.h>
#include <lang/String.h>


#undef CreateWindow
#define CreateWindow CreateWindow


namespace synkro
{


namespace win
{


/**
 * Window system. Creates application windows.
 */
iface IWindowSystem :
	public core::ISystem
{
public:
	/**
	 * Creates frame window.
	 * @param popup Specifies whether the window has border.
	 * @param sizeable Specifies whether the window size can be changed.
	 * @param title Window title. Displayed in the title bar.
	 * @param icon Handle to icon.
	 * @param width Window width.
	 * @param height Window height.
	 * @exception Exception Failed to create window.
	 */
	virtual IFrameWindow*									CreateWindow( Bool popup, Bool sizeable, const lang::String& title, UInt icon, UInt width, UInt height ) = 0;

	/**
	 * Creates frame window in the specified monitor.
	 * @param monitor Monitor containing the window.
	 * @exception Exception Failed to create window.
	 */
	virtual IFrameWindow*									CreateWindow( IMonitor* monitor ) = 0;

	/**
	 * Creates frame window from an existing handle.
	 * @param handle Window handle.
	 * @exception Exception Invalid window handle.
	 */
	virtual IFrameWindow*									CreateWindow( Pointer handle ) = 0;

	/**
	 * Creates a view window.
	 * @param parent Parent window.
	 * @param left Left window coordinate.
	 * @param top Top window coordinate.
	 * @param width Window width.
	 * @param height Window height.
	 * @exception BadArgumentException Parent is null.
	 * @exception Exception Failed to create window.
	 */
	virtual IViewWindow*									CreateWindow( IFrameWindow* parent, Int left, Int top, UInt width, UInt height ) = 0;

	/**
	 * Creates an icon window.
	 * @param icon Handle to icon.
	 * @param hint Window hint.
	 * @exception Exception Failed to create window.
	 */
	virtual IIconWindow*									CreateWindow( UInt icon, const lang::String& hint ) = 0;

	/**
	 * Retrieves the total number of monitors.
	 */
	virtual UInt											GetMonitorCount() const = 0;

	/**
	 * Retrieves monitor by index.
	 * @param index Monitor index.
	 * @return Requested monitor.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual IMonitor*										GetMonitor( UInt index ) const = 0;

	/**
	 * Retrieves primary monitor.
	 */
	virtual IMonitor*										GetMonitor() const = 0;
};


} // win


} // synkro


#endif // _SYNKRO_WIN_IWINDOWSYSTEM_
