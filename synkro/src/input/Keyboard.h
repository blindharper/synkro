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
#ifndef _SYNKRO_INPUT_KEYBOARD_
#define _SYNKRO_INPUT_KEYBOARD_


#include "config.h"
#include <core/ObjectImpl.h>
#include <input/IKeyboardEx.h>
#include <lang/Vector.h>
#include "BaseInputSystem.h"


namespace synkro
{


namespace input
{


// Logical keyboard. Generates input events.
class Keyboard :
	public core::ObjectImpl<IKeyboardEx>
{
public:
	// Constructor.
	Keyboard( BaseInputSystem* inputSystem, IKeyboard* keyboard, UInt index );

	// IInputDevice methods.
	Bool													Update( Double delta );

	// IKeyboard methods.
	Bool													IsKeyDown( const Key& key ) const;
	Bool													IsKeyUp( const Key& key ) const;
	Key														ToKey( Byte code ) const;
	char													ToChar( Byte code, Bool shift ) const;
	void													GetState( KeyboardState& state ) const;
	void													GetDesc( KeyboardDesc& desc ) const;

	// IKeyboardEx methods.
	void													ListenKeyDown( KeyboardListener* listener, const Key* keys, UInt count, Bool discrete );
	void													ListenKeyDown( KeyboardListener* listener, const Key& key, Bool discrete );
	void													ListenKeyUp( KeyboardListener* listener, const Key* keys, UInt count );
	void													ListenKeyUp( KeyboardListener* listener, const Key& key );
	void													ListenKeyPress( KeyboardListener* listener );

	// Other methods.
	UInt													GetNextKeyDown( UInt event, const Key& key, Bool& alt, Bool& shift, Bool& control, Key& pressedKey, Double& firstKeyDown, Double& lastKeyDown, Bool handle );
	UInt													GetNextKeyUp( UInt event, const Key& key, Bool& alt, Bool& shift, Bool& control, Bool handle );
	UInt													GetNextKeyPress( UInt event, Char& key, Bool handle );
	UInt													GetIndex() const;

private:
	struct KeyEvent
	{
		KeyEvent( const Key& key, Bool alt, Bool shift, Bool control, const Key& pressedKey, Double firstKeyDown, Double lastKeyDown ) :
			Object( key ),
			Alt( alt ),
			Shift( shift ),
			Control( control ),
			PressedKey( pressedKey ),
			FirstKeyDown( firstKeyDown ),
			LastKeyDown( lastKeyDown ),
			Handled( false )
		{
		}

		KeyEvent() :
			Object( Key::Unknown ),
			Alt( false ),
			Shift( false ),
			Control( false ),
			PressedKey( Key::Unknown ),
			FirstKeyDown( 0.0 ),
			LastKeyDown( 0.0 ),
			Handled( false )
		{
		}

		Key				Object;
		Bool			Alt;
		Bool			Shift;
		Bool			Control;
		Key				PressedKey;
		Double			FirstKeyDown;
		Double			LastKeyDown;
		Bool			Handled;
	};

	struct KeyPressEvent
	{
		KeyPressEvent( Char key ) :
			KeyChar( key ),
			Handled( false )
		{
		}

		KeyPressEvent() :
			Handled( false )
		{
		}

		Char			KeyChar;
		Bool			Handled;
	};

	BaseInputSystem*										_inputSystem;
	P(IKeyboard)											_keyboard;
	KeyboardState											_state;
	KeyboardState											_lastState;
	Key														_pressedKey;
	Double													_lastKeyDown;
	Double													_firstKeyDown;
	
	lang::Vector<KeyEvent>									_keyDowns;
	lang::Vector<KeyEvent>									_keyUps;
	lang::Vector<KeyPressEvent>								_keyPresses;

	Bool													_listenKeyDown;
	Bool													_listenKeyUp;
	Bool													_listenKeyPress;
	UInt													_index;
};


#include "Keyboard.inl"


} // input


} // synkro


#endif // _SYNKRO_INPUT_KEYBOARD_
