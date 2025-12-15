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
// Purpose: Implements extended window system.
//==============================================================================
#ifndef _SYNKRO_WIN_WINDOWSYSTEMEX_
#define _SYNKRO_WIN_WINDOWSYSTEMEX_


#include "config.h"
#include <core/ObjectImpl.h>
#include <win/IWindowSystemEx.h>
#include <win/IIconWindow.h>
#include "HostWindow.h"
#include "FrameWindow.h"


namespace synkro
{


namespace win
{


// Extended window system.
class WindowSystemEx :
	public core::ObjectImpl<IWindowSystemEx>,
	public Logger
{
public:
	// Constructor & destructor.
	WindowSystemEx( Pointer module, diag::ILog* log );
	~WindowSystemEx();

	// ISystem methods.
	Bool													Update( Double delta );

	// IWindowSystem methods.
	IFrameWindow*											CreateWindow( Bool popup, Bool sizeable, const lang::String& title, UInt icon, UInt width, UInt height );
	IFrameWindow*											CreateWindow( IMonitor* monitor );
	IHostWindow*											CreateWindow( Pointer handle );
	IViewWindow*											CreateWindow( IHostWindow* parent, Int left, Int top, UInt width, UInt height );
	IIconWindow*											CreateWindow( UInt icon, const lang::String& hint );
	UInt													GetMonitorCount() const;
	IMonitor*												GetMonitor( UInt index ) const;
	IMonitor*												GetMonitor() const;

	// IWindowSystemEx methods.
	IFrameWindowEx*											GetFrameWindow() const;
	IHostWindowEx*											GetHostWindow() const;
	IIconWindow*											GetIconWindow() const;

	// Other methods.
	void													Initialize( IWindowSystemFactory* factory );
	void													Finalize();

private:
	IWindowSystemFactory*									_factory;
	P(IWindowSystem)										_windowSystem;
	P(FrameWindow)											_frameWindow;
	P(HostWindow)											_hostWindow;
	P(IIconWindow)											_iconWindow;
	lang::Vector<IWindow*>									_windows;
	Pointer													_module;
};


#include "WindowSystemEx.inl"


} // win


} // synkro


#endif // _SYNKRO_WIN_WINDOWSYSTEMEX_
