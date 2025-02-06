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
#include "config.h"
#include "Win32WindowSystem.h"
#include "Win32FrameWindow.h"
#include "Win32ViewWindow.h"
#include "Win32IconWindow.h"
#include <win/Monitor.h>


//------------------------------------------------------------------------------

using namespace synkro::diag;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace win
{


static BOOL CALLBACK EnumMonitor( HMONITOR hMonitor, HDC hdcMonitor, LPRECT lprcMonitor, LPARAM dwData )
{
	Win32WindowSystem* sys = reinterpret_cast<Win32WindowSystem*>( dwData );
	sys->AddMonitor( hMonitor );
	return TRUE;
}


#define IDI_SYNKRO 100


//------------------------------------------------------------------------------


Win32WindowSystem::Win32WindowSystem( Pointer module, ILog* log ) :
	WindowSystemImpl<IWindowSystem>( log ),
	_module( module )
{
	// Enumerate display monitors.
	LogInfo( MessagePriority::Low, Formatter::Format(L"Enumerating display monitors...") );
	::EnumDisplayMonitors( nullptr, nullptr, EnumMonitor, (LPARAM)this );
	LogInfo( MessagePriority::Low, Formatter::Format(L"{0} display monitor(s) found.", _monitors.Size()) );
}

IFrameWindow* Win32WindowSystem::CreateWindow( Bool popup, Bool sizeable, const String& title, UInt icon, UInt width, UInt height )
{
	return new Win32FrameWindow( popup, sizeable, title, DoLoadIcon(icon), width, height );
}

IFrameWindow* Win32WindowSystem::CreateWindow( IMonitor* monitor )
{
	return new Win32FrameWindow( monitor );
}

IFrameWindow* Win32WindowSystem::CreateWindow( Pointer handle )
{
	return new Win32FrameWindowStub( handle );
}

IViewWindow* Win32WindowSystem::CreateWindow( IFrameWindow* parent, Int left, Int top, UInt width, UInt height )
{
	return new Win32ViewWindow( parent, left, top, width, height );
}

IIconWindow* Win32WindowSystem::CreateWindow( UInt icon, const String& hint )
{
	return new Win32IconWindow( DoLoadIcon(icon), hint );
}

void Win32WindowSystem::AddMonitor( HMONITOR hMonitor )
{
	MONITORINFOEX info;
	Zero( &info );
	info.cbSize = sizeof( info );
	if ( ::GetMonitorInfo(hMonitor, &info) != 0 )
	{
		// Get monitor orientation.
		MonitorOrientation orientation;
		DEVMODE mode;
		Zero( &mode );
		mode.dmSize = sizeof(mode);
		if ( ::EnumDisplaySettingsEx(info.szDevice, ENUM_CURRENT_SETTINGS, &mode, 0) != 0 )
		{
			if ( mode.dmFields & DM_DISPLAYORIENTATION )
			{
				switch ( mode.dmDisplayOrientation )
				{
					case DMDO_90:	orientation = MonitorOrientation::Portrait; break;
					case DMDO_180:	orientation = MonitorOrientation::LandscapeFlipped; break;
					case DMDO_270:	orientation = MonitorOrientation::PortraitFlipped; break;
					default:		orientation = MonitorOrientation::Landscape; break;
				}
			}
		}

		// Create monitor.
		const Point location( info.rcMonitor.left, info.rcMonitor.top );
		const Size size( info.rcMonitor.right-info.rcMonitor.left, info.rcMonitor.bottom-info.rcMonitor.top );
		IMonitor* monitor = new Monitor( (Pointer)hMonitor, info.szDevice, location, size, orientation );
		_monitors.Add( monitor );
		LogInfo( MessagePriority::Low, Formatter::Format(L"Found monitor {0,q}", String(info.szDevice)) );

		// See if this is a primary monitor.
		if ( info.dwFlags & MONITORINFOF_PRIMARY )
		{
			_monitor = monitor;
		}
	}
}

UInt Win32WindowSystem::DoLoadIcon( UInt icon )
{
	return (icon == 0) ? (UInt)::LoadIcon( (HINSTANCE)_module, MAKEINTRESOURCE(IDI_SYNKRO) ) : icon;
}


} // win


} // synkro
