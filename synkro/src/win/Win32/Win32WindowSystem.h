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
// Purpose: Win32 window system.
//==============================================================================
#ifndef _SYNKRO_WIN_WIN32WINDOWSYSTEM_
#define _SYNKRO_WIN_WIN32WINDOWSYSTEM_


#include "config.h"
#include <win/WindowSystemImpl.h>
#include <win/IWindowSystem.h>


namespace synkro
{


namespace win
{


// Win32 window system.
class Win32WindowSystem :
	public WindowSystemImpl<IWindowSystem>
{
public:
	// Constructor.
	Win32WindowSystem( Pointer module, diag::ILog* log );

	// IWindowSystem methods.
	IFrameWindow*											CreateWindow( Bool popup, Bool sizeable, const lang::String& title, UInt icon, UInt width, UInt height );
	IFrameWindow*											CreateWindow( IMonitor* monitor );
	IFrameWindow*											CreateWindow( Pointer handle );
	IViewWindow*											CreateWindow( IFrameWindow* parent, Int left, Int top, UInt width, UInt height );
	IIconWindow*											CreateWindow( UInt icon, const lang::String& hint );

	// Other methods.
	void													AddMonitor( HMONITOR hMonitor );
	UInt													DoLoadIcon( UInt icon );

private:
	Pointer													_module;
};


} // win


} // synkro


#endif // _SYNKRO_WIN_WIN32WINDOWSYSTEM_
