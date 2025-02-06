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
// Purpose: Logical joystick.
//==============================================================================
#include "config.h"
#include "Joystick.h"


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace input
{


Joystick::Joystick( BaseInputSystem* inputSystem, IJoystick* joystick, UInt index ) :
	_buttonDowns( A(ButtonEvent) ),
	_buttonUps( A(ButtonEvent) ),
	_axisMoves( A(AxisEvent) ),
	_inputSystem( inputSystem ),
	_joystick( joystick ),
	_listenButtonDown( false ),
	_listenButtonUp( false ),
	_listenAxisMove( false ),
	_index( index )
{
	Zero( _state.Buttons, sizeof(_state.Buttons) );
	Zero( _state.Axes, sizeof(_state.Axes) );
	Zero( _lastState.Buttons, sizeof(_lastState.Buttons) );
	Zero( _lastState.Axes, sizeof(_lastState.Axes) );
}

Bool Joystick::Update( Double delta )
{
	// Remove old events.
	_buttonDowns.Clear();
	_buttonUps.Clear();
	_axisMoves.Clear();

	// Save previous input state.
	Copy( _lastState.Buttons, _state.Buttons, SizeOf(_state.Buttons) );
	Copy( _lastState.Axes, _state.Axes, SizeOf(_state.Axes) );

	// Get new input state.
	_joystick->Update( delta );
	_joystick->GetState( _state );

	// Generate events.
	const UInt start = CastUInt( JoystickButton::Unknown );
	const UInt end = CastUInt( JoystickButton::Button32 );
	for ( UInt b = start; b < end; ++b )
	{
		if ( !(_lastState.Buttons[b] & 0x80) && (_state.Buttons[b] & 0x80) )
		{
			// Joystick Down.
			if ( _listenButtonDown )
			{
				JoystickButton button = JoystickButton( b+1 );
				_buttonDowns.Add( button );
			}
		}
		else if ( (_lastState.Buttons[b] & 0x80) && !(_state.Buttons[b] & 0x80) )
		{
			// Joystick Up.
			if ( _listenButtonUp )
			{
				JoystickButton button = JoystickButton( b );
				_buttonUps.Add( button );
			}
		}
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

void Joystick::ListenButtonDown( JoystickListener* listener, const JoystickButton& button )
{
	assert( listener != nullptr );

	_inputSystem->ListenJoystickDown( this, listener, button );
	_listenButtonDown = true;
}

void Joystick::ListenButtonUp( JoystickListener* listener, const JoystickButton& button )
{
	assert( listener != nullptr );

	_inputSystem->ListenJoystickUp( this, listener, button );
	_listenButtonUp = true;
}

void Joystick::ListenAxisMove( JoystickListener* listener, const Axis& axis )
{
	assert( listener != nullptr );

	_inputSystem->ListenJoystickAxisMove( this, listener, axis );
	_listenAxisMove = true;
}

UInt Joystick::GetNextButtonDown( UInt event, const JoystickButton& buttons, JoystickButton& button, Bool handle )
{
	if ( (event != none) && handle )
	{
		_buttonDowns[event].Handled = handle;
	}

	for ( UInt i = (event != none) ? event+1 : 0; i < _buttonDowns.Size(); ++i )
	{
		if ( _buttonDowns[i].Handled )
			continue;

		if ( (buttons == JoystickButton::Unknown) || (buttons == _buttonDowns[i].Button) )
		{
			button = _buttonDowns[i].Button;
			return i;
		}
	}

	return none;
}

UInt Joystick::GetNextButtonUp( UInt event, const JoystickButton& buttons, JoystickButton& button, Bool handle )
{
	if ( (event != none) && handle )
	{
		_buttonUps[event].Handled = handle;
	}

	for ( UInt i = (event != none) ? event+1 : 0; i < _buttonUps.Size(); ++i )
	{
		if ( _buttonUps[i].Handled )
			continue;

		if ( (buttons == JoystickButton::Unknown) || (buttons == _buttonUps[i].Button) )
		{
			button = _buttonUps[i].Button;
			return i;
		}
	}

	return none;
}

UInt Joystick::GetNextAxisMove( UInt event, const Axis& axis, Int& delta, Bool handle )
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
