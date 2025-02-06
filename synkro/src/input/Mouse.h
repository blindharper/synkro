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
#ifndef _SYNKRO_INPUT_MOUSE_
#define _SYNKRO_INPUT_MOUSE_


#include "config.h"
#include <core/ObjectImpl.h>
#include <input/IMouseEx.h>
#include <lang/Vector.h>
#include "BaseInputSystem.h"


namespace synkro
{


namespace input
{


// Logical mouse. Generates input events.
class Mouse :
	public core::ObjectImpl<IMouseEx>
{
public:
	// Constructor.
	Mouse( BaseInputSystem* inputSystem, IMouse* mouse, UInt index );

	// IInputDevice methods.
	Bool													Update( Double delta );

	// IMouse methods.
	Bool													IsButtonDown( const MouseButton& button ) const;
	Bool													IsButtonUp( const MouseButton& button ) const;
	Int														GetAxisMovement( const Axis& axis ) const;
	void													GetState( MouseState& state ) const;
	void													GetDesc( MouseDesc& desc ) const;

	// IMouseEx methods.
	void													ListenClick( MouseListener* listener, const MouseButton& buttons );
	void													ListenDoubleClick( MouseListener* listener, const MouseButton& buttons );
	void													ListenButtonDown( MouseListener* listener, const MouseButton& buttons );
	void													ListenButtonUp( MouseListener* listener, const MouseButton& buttons );
	void													ListenAxisMove( MouseListener* listener, const Axis& axis );

	// Other methods.
	UInt													GetNextClick( UInt event, const MouseButton& buttons, MouseButton& button, Bool handle );
	UInt													GetNextDoubleClick( UInt event, const MouseButton& buttons, MouseButton& button, Bool handle );
	UInt													GetNextButtonDown( UInt event, const MouseButton& buttons, MouseButton& button, Bool handle );
	UInt													GetNextButtonUp( UInt event, const MouseButton& buttons, MouseButton& button, Bool handle );
	UInt													GetNextAxisMove( UInt event, const Axis& axis, Int& delta, Bool handle );
	UInt													GetIndex() const;

private:
	struct ButtonEvent
	{
		ButtonEvent( const MouseButton& button ) :
			Button( button ),
			Handled( false )
		{
		}

		ButtonEvent() :
			Handled( false )
		{
		}

		MouseButton		Button;
		Bool			Handled;
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
	P(IMouse)												_mouse;
	MouseState												_state;
	MouseState												_lastState;
	MouseButton												_pressedButton;
	Double													_lastMouseDown;

	lang::Vector<ButtonEvent>								_clicks;
	lang::Vector<ButtonEvent>								_doubleClicks;
	lang::Vector<ButtonEvent>								_buttonDowns;
	lang::Vector<ButtonEvent>								_buttonUps;
	lang::Vector<AxisEvent>									_axisMoves;

	Bool													_listenClick;
	Bool													_listenDoubleClick;
	Bool													_listenButtonDown;
	Bool													_listenButtonUp;
	Bool													_listenAxisMove;
	UInt													_index;
};


#include "Mouse.inl"


} // input


} // synkro


#endif // _SYNKRO_INPUT_MOUSE_
