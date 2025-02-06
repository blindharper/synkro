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
// Purpose: Logical keyboard.
//==============================================================================
#include "config.h"
#include "Keyboard.h"


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace input
{


Keyboard::Keyboard( BaseInputSystem* inputSystem, IKeyboard* keyboard, UInt index ) :
	_keyDowns( A(KeyEvent) ),
	_keyUps( A(KeyEvent) ),
	_keyPresses( A(KeyPressEvent) ),
	_inputSystem( inputSystem ),
	_keyboard( keyboard ),
	_listenKeyDown( false ),
	_listenKeyUp( false ),
	_listenKeyPress( false ),
	_index( index )
{
	Zero( _state.Keys, sizeof(_state.Keys) );
	Zero( _lastState.Keys, sizeof(_lastState.Keys) );
	_pressedKey = Key::Unknown; _lastKeyDown = 0.0; _firstKeyDown = 0.0;
}

Bool Keyboard::Update( Double delta )
{
	_lastKeyDown += delta;
	_firstKeyDown += delta;

	// Remove old events.
	_keyDowns.Clear();
	_keyUps.Clear();
	_keyPresses.Clear();

	// Save previous input state.
	Copy( _lastState.Keys, _state.Keys, SizeOf(_state.Keys) );

	// Get new input state.
	_keyboard->Update( delta );
	_keyboard->GetState( _state );

	// Generate events.
	const Bool alt = _keyboard->IsKeyDown( Key::LeftAlt ) || _keyboard->IsKeyDown( Key::RightAlt );
	const Bool ctrl = _keyboard->IsKeyDown( Key::LeftControl ) || _keyboard->IsKeyDown( Key::RightControl );
	const Bool shift = _keyboard->IsKeyDown( Key::LeftShift ) || _keyboard->IsKeyDown( Key::RightShift );

	const Byte start = CastByte( Key::Unknown+1 );
	const Byte end = CastByte( Key::Alt );

	for ( Byte k = start; k <= end; ++k )
	{
		if ( !(_lastState.Keys[k] & 0x80) && (_state.Keys[k] & 0x80) )
		{
			const Key key = _keyboard->ToKey( k );

			// Key Press.
			if ( _listenKeyPress )
			{
				const char ch = _keyboard->ToChar( k, shift );
				if ( (ch > 0) && (ch < 128) )
				{
					_keyPresses.Add( ch );
				}
			}

			// Remember last key press time.
			if ( key != _pressedKey )
			{
				_firstKeyDown = 0.0;
			}
			_pressedKey = key;
			_lastKeyDown = 0.0;

			// Key Down.
			if ( _listenKeyDown )
			{
				_keyDowns.Add( KeyEvent(key, alt, shift, ctrl, key, _firstKeyDown, _lastKeyDown) );
			}
		}
		else if ( (_lastState.Keys[k] & 0x80) && (_state.Keys[k] & 0x80) )
		{
			const Key key = _keyboard->ToKey( k );

			if ( (_pressedKey == key) && (_firstKeyDown >= 0.5) )
			{
				if ( _lastKeyDown >= 0.1 )
				{
					// Key Press.
					if ( _listenKeyPress )
					{
						const char ch = _keyboard->ToChar( k, shift );
						if ( (ch > 0) && (ch < 128) )
						{
							_keyPresses.Add( ch );
						}
					}

					// Remember last key press time.
					_lastKeyDown = 0.0;
				}
			}

			// Key Down.
			if ( _listenKeyDown )
			{
				_keyDowns.Add( KeyEvent(key, alt, shift, ctrl, key, _firstKeyDown, _lastKeyDown) );
			}
		}
		else if ( (_lastState.Keys[k] & 0x80) && !(_state.Keys[k] & 0x80) )
		{
			// Key Up.
			if ( _listenKeyUp )
			{
				const Key key = _keyboard->ToKey( k );
				_keyUps.Add( KeyEvent(key, alt, shift, ctrl, Key::Unknown, 0.0, 0.0) );
			}
			_pressedKey = Key::Unknown;
		}
	}

	return true;
}

void Keyboard::ListenKeyDown( KeyboardListener* listener, const Key* keys, UInt count, Bool discrete )
{
	assert( listener != nullptr );

	for ( UInt i = 0; i < count; ++i )
	{
		_inputSystem->ListenKeyDown( this, listener, keys[i], discrete );
	}
	_listenKeyDown = true;
}

void Keyboard::ListenKeyDown( KeyboardListener* listener, const Key& key, Bool discrete )
{
	assert( listener != nullptr );

	_inputSystem->ListenKeyDown( this, listener, key, discrete );
	_listenKeyDown = true;
}

void Keyboard::ListenKeyUp( KeyboardListener* listener, const Key* keys, UInt count )
{
	assert( listener != nullptr );

	for ( UInt i = 0; i < count; ++i )
	{
		_inputSystem->ListenKeyUp( this, listener, keys[i] );
	}
	_listenKeyUp = true;
}

void Keyboard::ListenKeyUp( KeyboardListener* listener, const Key& key )
{
	assert( listener != nullptr );

	_inputSystem->ListenKeyUp( this, listener, key );
	_listenKeyUp = true;
}

void Keyboard::ListenKeyPress( KeyboardListener* listener )
{
	assert( listener != nullptr );

	_inputSystem->ListenKeyPress( this, listener );
	_listenKeyPress = true;
}

UInt Keyboard::GetNextKeyDown( UInt event, const Key& key, Bool& alt, Bool& shift, Bool& control, Key& pressedKey, Double& firstKeyDown, Double& lastKeyDown, Bool handle )
{
	if ( (event != none) && handle )
	{
		_keyDowns[event].Handled = handle;
	}

	for ( UInt i = (event != none) ? event+1 : 0; i < _keyDowns.Size(); ++i )
	{
		if ( _keyDowns[i].Handled )
			continue;

		if ( (key == Key::Unknown) || (key == _keyDowns[i].Object) )
		{
			alt = _keyDowns[i].Alt;
			shift = _keyDowns[i].Shift;
			control = _keyDowns[i].Control;
			pressedKey = _keyDowns[i].PressedKey;
			firstKeyDown = _keyDowns[i].FirstKeyDown;
			lastKeyDown = _keyDowns[i].LastKeyDown;
			return i;
		}
	}

	return none;
}

UInt Keyboard::GetNextKeyUp( UInt event, const Key& key, Bool& alt, Bool& shift, Bool& control, Bool handle )
{
	if ( (event != none) && handle )
	{
		_keyUps[event].Handled = handle;
	}

	for ( UInt i = (event != none) ? event+1 : 0; i < _keyUps.Size(); ++i )
	{
		if ( _keyUps[i].Handled )
			continue;

		if ( (key == Key::Unknown) || (key == _keyUps[i].Object) )
		{
			alt = _keyUps[i].Alt;
			shift = _keyUps[i].Shift;
			control = _keyUps[i].Control;
			return i;
		}
	}

	return none;
}

UInt Keyboard::GetNextKeyPress( UInt event, Char& key, Bool handle )
{
	if ( (event != none) && handle )
	{
		_keyPresses[event].Handled = handle;
	}

	for ( UInt i = (event != none) ? event+1 : 0; i < _keyPresses.Size(); ++i )
	{
		if ( !_keyPresses[i].Handled )
		{
			key = _keyPresses[i].KeyChar;
			return i;
		}
	}

	return none;
}


} // input


} // synkro
