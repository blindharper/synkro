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
// Purpose: Defines hot key.
//==============================================================================
#ifndef _SYNKRO_UI_HOTKEY_
#define _SYNKRO_UI_HOTKEY_


#include "config.h"
#include <input/Key.h>


namespace synkro
{


namespace ui
{


/** 
 * A keystroke that fires widget's default event.
 */
class SYNKRO_API HotKey
{
public:
	/**
	 * Default keystroke.
	 */
	static const HotKey										None;

	/**
	 * Creates a keystroke consisting of a primary key plus optional Control, Shift and Alt keys.
	 * @param key Primary keystroke key.
	 * @param control Indicates whether the keystroke includes Control key.
	 * @param shift Indicates whether the keystroke includes Shift key.
	 * @param alt Indicates whether the keystroke includes Alt key.
	 */
	HotKey( const input::Key& key, Bool control, Bool shift, Bool alt );

	/**
	 * Creates a keystroke consisting of a primary key plus optional Control and Shift keys.
	 * @param key Primary keystroke key.
	 * @param control Indicates whether the keystroke includes Control key.
	 * @param shift Indicates whether the keystroke includes Shift key.
	 */
	HotKey( const input::Key& key, Bool control, Bool shift );

	/**
	 * Creates a keystroke consisting of a primary key plus an optional Control key.
	 * @param key Primary keystroke key.
	 * @param control Indicates whether the keystroke includes Control key.
	 */
	HotKey( const input::Key& key, Bool control );

	/**
	 * Creates a keystroke consisting of a single key.
	 * @param key Primary keystroke key.
	 */
	HotKey( const input::Key& key );

	/**
	 * Creates default keystroke.
	 */
	HotKey();

	/**
	 * Returns true if two keystrokes are equal.
	 */
	Bool													operator==( const HotKey& other ) const;

	/**
	 * Returns true if two keystrokes are not equal.
	 */
	Bool													operator!=( const HotKey& other ) const;

	/**
	 * Primary keystroke key.
	 */
	input::Key												Key;

	/**
	 * Indicates if the Control key is pressed.
	 */
	Bool													Control;

	/**
	 * Indicates if the Shift key is pressed.
	 */
	Bool													Shift;

	/**
	 * Indicates if the Alt key is pressed.
	 */
	Bool													Alt;
};


} // ui


} // synkro


#endif // _SYNKRO_UI_HOTKEY_
