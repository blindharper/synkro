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
#ifndef _SYNKRO_INPUT_JOYSTICK_
#define _SYNKRO_INPUT_JOYSTICK_


#include "config.h"
#include <core/ObjectImpl.h>
#include <input/IJoystickEx.h>
#include <lang/Vector.h>
#include "BaseInputSystem.h"


namespace synkro
{


namespace input
{


// Logical joystick. Generates input events.
class Joystick :
	public core::ObjectImpl<IJoystickEx>
{
public:
	// Constructor.
	Joystick( BaseInputSystem* inputSystem, IJoystick* joystick, UInt index );

	// IInputDevice methods.
	Bool													Update( Double delta );

	// IJoystick methods.
	Bool													IsButtonDown( const JoystickButton& button ) const;
	Bool													IsButtonUp( const JoystickButton& button ) const;
	Int														GetAxisMovement( const Axis& axis ) const;
	void													GetState( JoystickState& state ) const;
	void													GetDesc( JoystickDesc& desc ) const;

	// IJoystickEx methods.
	void													ListenButtonDown( JoystickListener* listener, const JoystickButton& button );
	void													ListenButtonUp( JoystickListener* listener, const JoystickButton& button );
	void													ListenAxisMove( JoystickListener* listener, const Axis& axis );

	// Other methods.
	UInt													GetNextButtonDown( UInt event, const JoystickButton& buttons, JoystickButton& button, Bool handle );
	UInt													GetNextButtonUp( UInt event, const JoystickButton& buttons, JoystickButton& button, Bool handle );
	UInt													GetNextAxisMove( UInt event, const Axis& axis, Int& delta, Bool handle );
	UInt													GetIndex() const;

private:
	struct ButtonEvent
	{
		ButtonEvent( const JoystickButton& button ) :
			Button( button ),
			Handled( false )
		{
		}

		ButtonEvent() :
			Handled( false )
		{
		}

		JoystickButton		Button;
		Bool				Handled;
	};

	struct AxisEvent
	{
		AxisEvent( const Axis& axis, Int delta ) :
			Object( axis ),
			Delta( delta ),
			Handled( false )
		{
		}

		AxisEvent() :
			Delta( 0 ),
			Handled( false )
		{
		}

		Axis	Object;
		Int		Delta;
		Bool	Handled;
	};

	BaseInputSystem*										_inputSystem;
	P(IJoystick)											_joystick;
	JoystickState											_state;
	JoystickState											_lastState;

	lang::Vector<ButtonEvent>								_buttonDowns;
	lang::Vector<ButtonEvent>								_buttonUps;
	lang::Vector<AxisEvent>									_axisMoves;

	Bool													_listenButtonDown;
	Bool													_listenButtonUp;
	Bool													_listenAxisMove;
	UInt													_index;
};


#include "Joystick.inl"


} // input


} // synkro


#endif // _SYNKRO_INPUT_JOYSTICK_
