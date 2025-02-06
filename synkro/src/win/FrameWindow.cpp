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
// Purpose: Frame window implementation.
//==============================================================================
#include "config.h"
#include "FrameWindow.h"


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace win
{


FrameWindow::FrameWindow( IFrameWindow* window ) :
	_listeners( A(WindowListener*) ),
	_windows( A(P(IViewWindowEx)) ),
	_window( window ),
	_active( _window->IsActive() ),
	_width( _window->GetWidth() ),
	_height( _window->GetHeight() )
{
}

Bool FrameWindow::Update()
{
	// Update underlying window.
	if ( !_window->Update() )
		return false;

	// Generate events.
	if ( _window->IsClosing() )
	{
		if ( FireClosingEvent() )
		{
			_window->Close();
			return false;
		}
	}

	const Bool active = _window->IsActive();
	if ( active != _active )
	{
		_active = active;
		FireActivateEvent( _active );
	}

	const UInt width = _window->GetWidth();
	const UInt height = _window->GetHeight();
	if ( (width != _width) || (height != _height) )
	{
		_width = width; _height = height;
		FireResizeEvent( _width, _height );
	}

	return true;
}

void FrameWindow::Listen( WindowListener* listener )
{
	assert( listener != nullptr );

	if ( !_listeners.Contains(listener) )
	{
		_listeners.Add( listener );
	}
}

Bool FrameWindow::FireClosingEvent()
{
	for ( UInt i = 0; i < _listeners.Size(); ++i )
	{
		if ( !_listeners[i]->OnWindowClosing(_window->GetHandle()) )
			return false;
	}
	return true;
}

void FrameWindow::FireActivateEvent( Bool active )
{
	for ( UInt i = 0; i < _listeners.Size(); ++i )
	{
		_listeners[i]->OnWindowActivate( _window->GetHandle(), active );
	}
}

void FrameWindow::FireResizeEvent( UInt width, UInt height )
{
	for ( UInt i = 0; i < _listeners.Size(); ++i )
	{
		_listeners[i]->OnWindowResize( _window->GetHandle(), width, height );
	}
}


} // win


} // synkro
