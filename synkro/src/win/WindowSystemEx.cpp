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
#include "config.h"
#include "WindowSystemEx.h"
#include <win/IWindowSystemFactory.h>
#include "FrameWindow.h"
#include "ViewWindow.h"
#include <core/Platform.h>


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::diag;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace win
{


WindowSystemEx::WindowSystemEx( Pointer module, ILog* log ) :
	_windows( A(IWindow*) ),
	_frameWindows( A(P(FrameWindow)) ),
	_factory( nullptr ),
	_module( module ),
	Logger( log, LogFacility::WindowSystem )
{
	LogInfo( MessagePriority::Lowest, Formatter::Format(L"Creating window system...") );
}

WindowSystemEx::~WindowSystemEx()
{
	LogInfo( MessagePriority::Lowest, Formatter::Format(L"Destroying window system...") );
}

Bool WindowSystemEx::Update( Double delta )
{
	for ( UInt i = 0; i < _windows.Size(); ++i )
	{
		if ( !_windows[i]->Update() )
			return false;
	}

	// Prevent eating CPU time.
	Platform::Sleep( 0 );

	return true;
}

IFrameWindow* WindowSystemEx::CreateWindow( Bool popup, Bool sizeable, const String& title, UInt icon, UInt width, UInt height )
{
	FrameWindow* window = new FrameWindow( _windowSystem->CreateWindow(popup, sizeable, title, icon, width, height) );
	_frameWindows.Add( window );
	_windows.Add( window );
	return window;
}

IFrameWindow* WindowSystemEx::CreateWindow( IMonitor* monitor )
{
	for ( UInt i = 0; i < _frameWindows.Size(); ++i )
	{
		if ( _frameWindows[i]->GetMonitor() == monitor )
			return _frameWindows[i];
	}

	FrameWindow* window = new FrameWindow( _windowSystem->CreateWindow(monitor) );
	_frameWindows.Add( window );
	_windows.Add( window );
	return window;
}

IFrameWindow* WindowSystemEx::CreateWindow( Pointer handle )
{
	FrameWindow* window = new FrameWindow( _windowSystem->CreateWindow(handle) );
	_frameWindows.Add( window );
	_windows.Add( window );
	return window;
}

IViewWindow* WindowSystemEx::CreateWindow( IFrameWindow* parent, Int left, Int top, UInt width, UInt height )
{
	for ( UInt i = 0; i < _frameWindows.Size(); ++i )
	{
		if ( _frameWindows[i] == parent )
		{
			IViewWindowEx* window = new ViewWindow( _windowSystem->CreateWindow(parent, left, top, width, height) );
			_frameWindows[i]->AddWindow( window );
			return window;
		}
	}
	
	return nullptr;
}

IIconWindow* WindowSystemEx::CreateWindow( UInt icon, const String& hint )
{
	if ( _iconWindow == nullptr )
	{
		_iconWindow = _windowSystem->CreateWindow( icon, hint );
		_windows.Add( _iconWindow );
	}
	return _iconWindow;
}

void WindowSystemEx::Initialize( IWindowSystemFactory* factory )
{
	// Re-create window system, if needed.
	if ( factory != _factory )
	{
		_factory = factory;
		_windowSystem = _factory->Create( _module, _log );
	}
}

void WindowSystemEx::Finalize()
{
	_windows.Clear();
	_frameWindows.Clear();
	_iconWindow = nullptr;
}


} // win


} // synkro
