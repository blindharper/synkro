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
// Purpose: Extended input system.
//=============================================================================
#ifndef _SYNKRO_INPUT_INPUTSYSTEMEX_
#define _SYNKRO_INPUT_INPUTSYSTEMEX_


#include "config.h"
#include <input/IInputSystemEx.h>
#include <input/IArcball.h>
#include "Keyboard.h"
#include "Mouse.h"
#include "Joystick.h"
#include "Arcball.h"
#include "BaseInputSystem.h"


namespace synkro
{


namespace input
{


// Extended input system.
class InputSystemEx :
	public core::ObjectImpl<IInputSystemEx>,
	public BaseInputSystem,
	public Logger
{
public:
	// Constructor & destructor.
	InputSystemEx( Pointer module, diag::ILog* log );
	~InputSystemEx();

	// ISystem methods.
	Bool													Update( Double delta );

	// IInputSystem methods.
	IMouse*													CreateMouse( UInt index );
	UInt													GetTotalMouseCount() const;
	void													GetMouseDesc( UInt index, MouseDesc& desc ) const;
	IJoystick*												CreateJoystick( UInt index );
	UInt													GetTotalJoystickCount() const;
	void													GetJoystickDesc( UInt index, JoystickDesc& desc ) const;
	IKeyboard*												CreateKeyboard( UInt index );
	UInt													GetTotalKeyboardCount() const;
	void													GetKeyboardDesc( UInt index, KeyboardDesc& desc ) const;

	// IInputSystemEx methods.
	IArcball*												CreateArcball( IMouseEx* mouse, win::IWindow* window );
	UInt													GetMouseCount() const;
	IMouseEx*												GetMouse( UInt index ) const;
	IMouseEx*												GetMouse() const;
	UInt													GetJoystickCount() const;
	IJoystickEx*											GetJoystick( UInt index ) const;
	IJoystickEx*											GetJoystick() const;
	UInt													GetKeyboardCount() const;
	IKeyboardEx*											GetKeyboard( UInt index ) const;
	IKeyboardEx*											GetKeyboard() const;
	IArcball*												GetArcball() const;

	// BaseInputSystem methods.
	void													ListenKeyDown( IKeyboardEx* keyboard, KeyboardListener* listener, const Key& key, Bool discrete );
	void													ListenKeyUp( IKeyboardEx* keyboard, KeyboardListener* listener, const Key& key );
	void													ListenKeyPress( IKeyboardEx* keyboard, KeyboardListener* listener );
	void													ListenMouseClick( IMouseEx* mouse, MouseListener* listener, const MouseButton& buttons );
	void													ListenMouseDoubleClick( IMouseEx* mouse, MouseListener* listener, const MouseButton& buttons );
	void													ListenMouseDown( IMouseEx* mouse, MouseListener* listener, const MouseButton& buttons );
	void													ListenMouseUp( IMouseEx* mouse, MouseListener* listener, const MouseButton& buttons );
	void													ListenMouseAxisMove( IMouseEx* mouse, MouseListener* listener, const Axis& axis );
	void													ListenJoystickDown( IJoystickEx* joystick, JoystickListener* listener, const JoystickButton& button );
	void													ListenJoystickUp( IJoystickEx* joystick, JoystickListener* listener, const JoystickButton& button );
	void													ListenJoystickAxisMove( IJoystickEx* joystick, JoystickListener* listener, const Axis& axis );
	void													ListenArcballRotate( IArcball* arcball, ArcballListener* listener );
	void													ListenArcballZoom( IArcball* arcball, ArcballListener* listener );

	// Other methods.
	void													Initialize( IInputSystemFactory* factory, win::IWindowSystemEx* windowSystem );
	void													Finalize();
	Bool													Call( IInputDevice* device, Double delta );

private:
	enum KeyboardEventType
	{
		EVENT_KEY_DOWN,
		EVENT_KEY_UP,
		EVENT_KEY_PRESS,
	};

	enum MouseEventType
	{
		EVENT_MOUSE_CLICK,
		EVENT_MOUSE_DOUBLE_CLICK,
		EVENT_MOUSE_DOWN,
		EVENT_MOUSE_UP,
		EVENT_MOUSE_AXIS_MOVE,
	};

	enum JoystickEventType
	{
		EVENT_JOYSTICK_DOWN,
		EVENT_JOYSTICK_UP,
		EVENT_JOYSTICK_AXIS_MOVE,
	};

	enum ArcballEventType
	{
		EVENT_ARCBALL_ORIENT,
		EVENT_ARCBALL_ZOOM,
	};

	struct KeyboardEvent
	{
		KeyboardEvent( UInt device, KeyboardEventType type, const Key& key, Bool discrete ) :
			Device( device ),
			Type( type ),
			KeyObject( key ),
			Discrete( discrete )
		{
		}

		KeyboardEvent( UInt device, KeyboardEventType type, const Key& key ) :
			Device( device ),
			Type( type ),
			KeyObject( key ),
			Discrete( false )
		{
		}

		KeyboardEvent() :
			Device( null ),
			Type( EVENT_KEY_UP ),
			KeyObject( Key::Unknown ),
			Discrete( false )
		{
		}

		UInt				Device;
		KeyboardEventType	Type;
		Key					KeyObject;
		Bool				Discrete;
	};

	struct MouseEvent
	{
		MouseEvent( UInt device, MouseEventType type, const MouseButton& buttons ) :
			Device( device ),
			Type( type ),
			Buttons( buttons ),
			AxisObject( Axis::Unknown )
		{
		}

		MouseEvent( UInt device, MouseEventType type, const Axis& axis ) :
			Device( device ),
			Type( type ),
			Buttons( MouseButton::None ),
			AxisObject( axis )
		{
		}

		MouseEvent( UInt device, MouseEventType type ) :
			Device( device ),
			Type( type ),
			Buttons( MouseButton::None ),
			AxisObject( Axis::Unknown )
		{
		}

		MouseEvent() :
			Device( null ),
			Type( EVENT_MOUSE_CLICK ),
			Buttons( MouseButton::None ),
			AxisObject( Axis::Unknown )
		{
		}

		UInt			Device;
		MouseEventType	Type;
		MouseButton		Buttons;
		Axis			AxisObject;
	};

	struct JoystickEvent
	{
		JoystickEvent( UInt device, JoystickEventType type, const JoystickButton& button ) :
			Device( device ),
			Type( type ),
			Button( button ),
			AxisObject( Axis::Unknown )
		{
		}

		JoystickEvent( UInt device, JoystickEventType type, const Axis& axis ) :
			Device( device ),
			Type( type ),
			Button( JoystickButton::Unknown ),
			AxisObject( axis )
		{
		}

		JoystickEvent() :
			Device( null ),
			Type( EVENT_JOYSTICK_DOWN ),
			Button( JoystickButton::Unknown ),
			AxisObject( Axis::Unknown )
		{
		}

		UInt				Device;
		JoystickEventType	Type;
		JoystickButton		Button;
		Axis				AxisObject;
	};

	struct ArcballEvent
	{
		ArcballEvent( ArcballEventType type ) :
			Type( type )
		{
		}

		ArcballEvent() :
			Type( EVENT_ARCBALL_ORIENT )
		{
		}

		ArcballEventType Type;
	};

	struct KeyboardListenerDesc
	{
		KeyboardListenerDesc( KeyboardListener* listener ) :
			Events( A(KeyboardEvent) ),
			Listener( listener )
		{
		}

		KeyboardListenerDesc( const KeyboardListenerDesc& other ) :
			Events( other.Events ),
			Listener( other.Listener )
		{
		}

		KeyboardListenerDesc() :
			Events( A(KeyboardEvent) ),
			Listener( nullptr )
		{
		}

		lang::Vector<KeyboardEvent>		Events;
		KeyboardListener*				Listener;
	};

	struct MouseListenerDesc
	{
		MouseListenerDesc( MouseListener* listener ) :
			Events( A(MouseEvent) ),
			Listener( listener )
		{
		}

		MouseListenerDesc( const MouseListenerDesc& other ) :
			Events( other.Events ),
			Listener( other.Listener )
		{
		}

		MouseListenerDesc() :
			Events( A(MouseEvent) ),
			Listener( nullptr )
		{
		}

		lang::Vector<MouseEvent>	Events;
		MouseListener*				Listener;
	};

	struct JoystickListenerDesc
	{
		JoystickListenerDesc( JoystickListener* listener ) :
			Events( A(JoystickEvent) ),
			Listener( listener )
		{
		}

		JoystickListenerDesc( const JoystickListenerDesc& other ) :
			Events( other.Events ),
			Listener( other.Listener )
		{
		}

		JoystickListenerDesc() :
			Events( A(JoystickEvent) ),
			Listener( nullptr )
		{
		}

		lang::Vector<JoystickEvent>	Events;
		JoystickListener*			Listener;
	};

	struct ArcballListenerDesc
	{
		ArcballListenerDesc( ArcballListener* listener ) :
			Events( A(ArcballEvent) ),
			Listener( listener )
		{
		}

		ArcballListenerDesc( const ArcballListenerDesc& other ) :
			Events( other.Events ),
			Listener( other.Listener )
		{
		}

		ArcballListenerDesc() :
			Events( A(ArcballEvent) ),
			Listener( nullptr )
		{
		}

		lang::Vector<ArcballEvent>	Events;
		ArcballListener*			Listener;
	};

	Pointer													_module;
	IInputSystemFactory*									_factory;
	P(IInputSystem)											_inputSystem;
	lang::Vector<P(Keyboard)>								_keyboards;
	lang::Vector<P(Mouse)>									_mice;
	lang::Vector<P(Joystick)>								_joysticks;
	P(Arcball)												_arcball;

	lang::Vector<KeyboardListenerDesc>						_keyboardListeners;
	lang::Vector<MouseListenerDesc>							_mouseListeners;
	lang::Vector<JoystickListenerDesc>						_joystickListeners;
	lang::Vector<ArcballListenerDesc>						_arcballListeners;

	KeyboardListenerDesc*									GetListener( KeyboardListener* listener );
	MouseListenerDesc*										GetListener( MouseListener* listener );
	JoystickListenerDesc*									GetListener( JoystickListener* listener );
	ArcballListenerDesc*									GetListener( ArcballListener* listener );
	void													ProcessKeyboardEvents();
	void													ProcessMouseEvents();
	void													ProcessJoystickEvents();
	void													ProcessArcballEvents();
};


#include "InputSystemEx.inl"


} // input


} // synkro


#endif // _SYNKRO_INPUT_INPUTSYSTEMEX_
