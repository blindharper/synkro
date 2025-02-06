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
// Purpose: Logical mouse.
//==============================================================================
#include "config.h"
#include "Mouse.h"
#include "InputSystemEx.h"


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace input
{


Mouse::Mouse( BaseInputSystem* inputSystem, IMouse* mouse, UInt index ) :
	_clicks( A(ButtonEvent) ),
	_doubleClicks( A(ButtonEvent) ),
	_buttonDowns( A(ButtonEvent) ),
	_buttonUps( A(ButtonEvent) ),
	_axisMoves( A(AxisEvent) ),
	_inputSystem( inputSystem ),
	_mouse( mouse ),
	_listenClick( false ),
	_listenDoubleClick( false ),
	_listenButtonDown( false ),
	_listenButtonUp( false ),
	_listenAxisMove( false ),
	_index( index )
{
	Zero( _state.Buttons, sizeof(_state.Buttons) );
	Zero( _state.Axes, sizeof(_state.Axes) );
	Zero( _lastState.Buttons, sizeof(_lastState.Buttons) );
	Zero( _lastState.Axes, sizeof(_lastState.Axes) );
	_pressedButton = MouseButton::None; _lastMouseDown = 0.0;
}

Bool Mouse::Update( Double delta )
{
	_lastMouseDown += delta;

	// Remove old events.
	_clicks.Clear();
	_doubleClicks.Clear();
	_buttonDowns.Clear();
	_buttonUps.Clear();
	_axisMoves.Clear();

	// Save previous input state.
	Copy( _lastState.Buttons, _state.Buttons, SizeOf(_state.Buttons) );
	Copy( _lastState.Axes, _state.Axes, SizeOf(_state.Axes) );

	// Get new input state.
	_mouse->Update( delta );
	_mouse->GetState( _state );

	// Generate events.
	const Double DOUBLECLICK_INTERVAL = 0.7;
	static MouseButton buttons[] = { MouseButton::Left, MouseButton::Right, MouseButton::Middle, MouseButton::XButton1, MouseButton::XButton2 };
	static UInt buttonCount = SizeOf( buttons );
	for ( UInt b = 0; b < buttonCount; ++b )
	{
		MouseButton btn = buttons[b];
		if ( !(_lastState.Buttons[b] & 0x80) && (_state.Buttons[b] & 0x80) )
		{
			// Mouse Down.
			if ( _listenButtonDown )
			{
				_buttonDowns.Add( btn );
			}

			// Click.
			if ( _listenClick )
			{
				_clicks.Add( btn );
			}

			// DoubleClick.
			Bool doubleClicked = false;
			if ( _listenDoubleClick && (_pressedButton == btn) &&(_lastMouseDown < DOUBLECLICK_INTERVAL) )
			{
				_doubleClicks.Add( btn );
				doubleClicked = true;
			}

			// Remember the last pressed button.
			_pressedButton = doubleClicked ? MouseButton::None : btn;
			_lastMouseDown = 0.0;
		}
		else if ( (_lastState.Buttons[b] & 0x80) && !(_state.Buttons[b] & 0x80) )
		{
			// Mouse Up.
			if ( _listenButtonUp )
			{
				_buttonUps.Add( btn );
			}
		}
	}
	if ( _lastMouseDown >= DOUBLECLICK_INTERVAL )
	{
		_pressedButton = MouseButton::None;
		_lastMouseDown = 0.0;
	}

	// Axis move.
	if ( _listenAxisMove )
	{
		static Axis axes[] = { Axis::X, Axis::Y, Axis::Z };
		static UInt axisCount = SizeOf( axes );
		for ( UInt a = 0; a < axisCount; ++a )
		{
			if ( _state.Axes[a] != _lastState.Axes[a] )
			{
				_axisMoves.Add( AxisEvent(axes[a], _state.Axes[a]) );
			}
		}
	}

	return true;
}

void Mouse::ListenClick( MouseListener* listener, const MouseButton& buttons )
{
	assert( listener != nullptr );

	_inputSystem->ListenMouseClick( this, listener, buttons );
	_listenClick = true;
}

void Mouse::ListenDoubleClick( MouseListener* listener, const MouseButton& buttons )
{
	assert( listener != nullptr );

	_inputSystem->ListenMouseDoubleClick( this, listener, buttons );
	_listenDoubleClick = true;
}

void Mouse::ListenButtonDown( MouseListener* listener, const MouseButton& buttons )
{
	assert( listener != nullptr );

	_inputSystem->ListenMouseDown( this, listener, buttons );
	_listenButtonDown = true;
}

void Mouse::ListenButtonUp( MouseListener* listener, const MouseButton& buttons )
{
	assert( listener != nullptr );

	_inputSystem->ListenMouseUp( this, listener, buttons );
	_listenButtonUp = true;
}

void Mouse::ListenAxisMove( MouseListener* listener, const Axis& axis )
{
	assert( listener != nullptr );

	_inputSystem->ListenMouseAxisMove( this, listener, axis );
	_listenAxisMove = true;
}

UInt Mouse::GetNextClick( UInt event, const MouseButton& buttons, MouseButton& button, Bool handle )
{
	if ( (event != none) && handle )
	{
		_clicks[event].Handled = handle;
	}

	for ( UInt i = (event != none) ? event+1 : 0; i < _clicks.Size(); ++i )
	{
		if ( _clicks[i].Handled )
			continue;

		if ( (buttons == MouseButton::None) || _clicks[i].Button.IsSet(buttons) )
		{
			button = _clicks[i].Button;
			return i;
		}
	}

	return none;
}

UInt Mouse::GetNextDoubleClick( UInt event, const MouseButton& buttons, MouseButton& button, Bool handle )
{
	if ( (event != none) && handle )
	{
		_doubleClicks[event].Handled = handle;
	}

	for ( UInt i = (event != none) ? event+1 : 0; i < _doubleClicks.Size(); ++i )
	{
		if ( _doubleClicks[i].Handled )
			continue;

		if ( (buttons == MouseButton::None) || _doubleClicks[i].Button.IsSet(buttons) )
		{
			button = _doubleClicks[i].Button;
			return i;
		}
	}

	return none;
}

UInt Mouse::GetNextButtonDown( UInt event, const MouseButton& buttons, MouseButton& button, Bool handle )
{
	if ( (event != none) && handle )
	{
		_buttonDowns[event].Handled = handle;
	}

	for ( UInt i = (event != none) ? event+1 : 0; i < _buttonDowns.Size(); ++i )
	{
		if ( _buttonDowns[i].Handled )
			continue;

		if ( (buttons == MouseButton::None) || _buttonDowns[i].Button.IsSet(buttons) )
		{
			button = _buttonDowns[i].Button;
			return i;
		}
	}

	return none;
}

UInt Mouse::GetNextButtonUp( UInt event, const MouseButton& buttons, MouseButton& button, Bool handle )
{
	if ( (event != none) && handle )
	{
		_buttonUps[event].Handled = handle;
	}

	for ( UInt i = (event != none) ? event+1 : 0; i < _buttonUps.Size(); ++i )
	{
		if ( _buttonUps[i].Handled )
			continue;

		if ( (buttons == MouseButton::None) || _buttonUps[i].Button.IsSet(buttons) )
		{
			button = _buttonUps[i].Button;
			return i;
		}
	}

	return none;
}

UInt Mouse::GetNextAxisMove( UInt event, const Axis& axis, Int& delta, Bool handle )
{
	if ( (event != none) && handle )
	{
		_axisMoves[event].Handled = handle;
	}

	for ( UInt i = (event != none) ? event+1 : 0; i < _axisMoves.Size(); ++i )
	{
		if ( _axisMoves[i].Handled )
			continue;

		if ( (axis == Axis::Unknown) || (axis == _axisMoves[i].Object) )
		{
			delta = _axisMoves[i].Delta;
			return i;
		}
	}

	return none;
}


} // input


} // synkro
