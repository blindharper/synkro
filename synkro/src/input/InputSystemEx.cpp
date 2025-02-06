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
#include "config.h"
#include "InputSystemEx.h"
#include "Arcball.h"
#include <input/IInputSystemFactory.h>
#include <input/KeyboardListener.h>
#include <input/MouseListener.h>
#include <input/JoystickListener.h>
#include <input/ArcballListener.h>


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::diag;
using namespace synkro::lang;
using namespace synkro::math;
using namespace synkro::win;

//------------------------------------------------------------------------------


namespace synkro
{


namespace input
{


InputSystemEx::InputSystemEx( Pointer module, ILog* log ) :
	_module( module ),
	_factory( nullptr ),
	_keyboards( A(P(Keyboard)) ),
	_mice( A(P(Mouse)) ),
	_joysticks( A(P(Joystick)) ),
	_keyboardListeners( A(KeyboardListenerDesc) ),
	_mouseListeners( A(MouseListenerDesc) ),
	_joystickListeners( A(JoystickListenerDesc) ),
	_arcballListeners( A(ArcballListenerDesc) ),
	Logger( log, LogFacility::InputSystem )
{
	LogInfo( MessagePriority::Lowest, Formatter::Format(L"Creating input system...") );
}

InputSystemEx::~InputSystemEx()
{
	LogInfo( MessagePriority::Lowest, Formatter::Format(L"Destroying input system...") );
}

Bool InputSystemEx::Update( Double delta )
{
	SynkroProfile( "InputSystemEx.Update" );

	// Update keyboards.
	SynkroProfileBegin( "InputSystemEx.Update.Keyboards" );
	_keyboards.Each( *this, delta );
	SynkroProfileEnd()

	// Update mice.
	SynkroProfileBegin( "InputSystemEx.Update.Mice" );
	_mice.Each( *this, delta );
	SynkroProfileEnd()

	// Update joysticks.
	SynkroProfileBegin( "InputSystemEx.Update.Joysticks" );
	_joysticks.Each( *this, delta );
	SynkroProfileEnd()

	ProcessKeyboardEvents();
	ProcessMouseEvents();
	ProcessJoystickEvents();

	// Update arcball after hardware mouse events have been handled.
	SynkroProfileBegin( "InputSystemEx.Update.Arcball" );
	if ( _arcball != nullptr )
	{
		_arcball->Update( delta );
	}
	SynkroProfileEnd()

	ProcessArcballEvents();

	return true;
}

IMouse* InputSystemEx::CreateMouse( UInt index )
{
	for ( UInt i = 0; _mice.Size(); ++i )
	{
		if ( _mice[i]->GetIndex() == index )
			return (IMouse*)_mice[i].AsPtr();
	}

	Mouse* mouse = new Mouse( this, _inputSystem->CreateMouse(index), index );
	_mice.Add( mouse );
	return (IMouse*)mouse;
}

IJoystick* InputSystemEx::CreateJoystick( UInt index )
{
	for ( UInt i = 0; _joysticks.Size(); ++i )
	{
		if ( _joysticks[i]->GetIndex() == index )
			return (IJoystick*)_joysticks[i].AsPtr();
	}

	Joystick* joystick = new Joystick( this, _inputSystem->CreateJoystick(index), index );
	_joysticks.Add( joystick );
	return (IJoystick*)joystick;
}

IKeyboard* InputSystemEx::CreateKeyboard( UInt index )
{
	for ( UInt i = 0; _keyboards.Size(); ++i )
	{
		if ( _keyboards[i]->GetIndex() == index )
			return (IKeyboard*)_keyboards[i].AsPtr();
	}

	Keyboard* keyboard = new Keyboard( this, _inputSystem->CreateKeyboard(index), index );
	_keyboards.Add( keyboard );
	return (IKeyboard*)keyboard;
}

IArcball* InputSystemEx::CreateArcball( IMouseEx* mouse, IWindow* window )
{
	assert( mouse != nullptr );
	assert( window != nullptr );

	if ( mouse == nullptr )
		throw BadArgumentException( L"Failed to create arcball. Mouse is not specified.", L"mouse" );

	if ( window == nullptr )
		throw BadArgumentException( L"Failed to create arcball. Window is not specified.", L"window" );

	return _arcball = new Arcball( this, mouse, window );
}

void InputSystemEx::ListenKeyDown( IKeyboardEx* keyboard, KeyboardListener* listener, const Key& key, Bool discrete )
{
	UInt device = ((Keyboard*)keyboard)->GetIndex();
	KeyboardListenerDesc* desc = GetListener( listener );
	for ( UInt i = 0; i < desc->Events.Size(); ++i )
	{
		if ( (desc->Events[i].Device == device) && (desc->Events[i].Type == EVENT_KEY_DOWN) && (desc->Events[i].KeyObject == key) )
		{
			desc->Events[i].Discrete = discrete;
			return;
		}
	}
	desc->Events.Add( KeyboardEvent(device, EVENT_KEY_DOWN, key, discrete) );
}

void InputSystemEx::ListenKeyUp( IKeyboardEx* keyboard, KeyboardListener* listener, const Key& key )
{
	UInt device = ((Keyboard*)keyboard)->GetIndex();
	KeyboardListenerDesc* desc = GetListener( listener );
	for ( UInt i = 0; i < desc->Events.Size(); ++i )
	{
		if ( (desc->Events[i].Device == device) && (desc->Events[i].Type == EVENT_KEY_UP) && (desc->Events[i].KeyObject == key) )
			return;
	}
	desc->Events.Add( KeyboardEvent(device, EVENT_KEY_UP, key) );
}

void InputSystemEx::ListenKeyPress( IKeyboardEx* keyboard, KeyboardListener* listener )
{
	UInt device = ((Keyboard*)keyboard)->GetIndex();
	KeyboardListenerDesc* desc = GetListener( listener );
	for ( UInt i = 0; i < desc->Events.Size(); ++i )
	{
		if ( (desc->Events[i].Device == device) && (desc->Events[i].Type == EVENT_KEY_PRESS) )
			return;
	}
	desc->Events.Add( KeyboardEvent(device, EVENT_KEY_PRESS, Key::Unknown) );
}

void InputSystemEx::ListenMouseClick( IMouseEx* mouse, MouseListener* listener, const MouseButton& buttons )
{
	UInt device = ((Mouse*)mouse)->GetIndex();
	MouseListenerDesc* desc = GetListener( listener );
	for ( UInt i = 0; i < desc->Events.Size(); ++i )
	{
		if ( (desc->Events[i].Device == device) && (desc->Events[i].Type == EVENT_MOUSE_CLICK) && (desc->Events[i].Buttons.IsSet(buttons)) )
			return;
	}
	desc->Events.Add( MouseEvent(device, EVENT_MOUSE_CLICK, buttons) );
}

void InputSystemEx::ListenMouseDoubleClick( IMouseEx* mouse, MouseListener* listener, const MouseButton& buttons )
{
	UInt device = ((Mouse*)mouse)->GetIndex();
	MouseListenerDesc* desc = GetListener( listener );
	for ( UInt i = 0; i < desc->Events.Size(); ++i )
	{
		if ( (desc->Events[i].Device == device) && (desc->Events[i].Type == EVENT_MOUSE_DOUBLE_CLICK) && (desc->Events[i].Buttons.IsSet(buttons)) )
			return;
	}
	desc->Events.Add( MouseEvent(device, EVENT_MOUSE_DOUBLE_CLICK, buttons) );
}

void InputSystemEx::ListenMouseDown( IMouseEx* mouse, MouseListener* listener, const MouseButton& buttons )
{
	UInt device = ((Mouse*)mouse)->GetIndex();
	MouseListenerDesc* desc = GetListener( listener );
	for ( UInt i = 0; i < desc->Events.Size(); ++i )
	{
		if ( (desc->Events[i].Device == device) && (desc->Events[i].Type == EVENT_MOUSE_DOWN) && (desc->Events[i].Buttons.IsSet(buttons)) )
			return;
	}
	desc->Events.Add( MouseEvent(device, EVENT_MOUSE_DOWN, buttons) );
}

void InputSystemEx::ListenMouseUp( IMouseEx* mouse, MouseListener* listener, const MouseButton& buttons )
{
	UInt device = ((Mouse*)mouse)->GetIndex();
	MouseListenerDesc* desc = GetListener( listener );
	for ( UInt i = 0; i < desc->Events.Size(); ++i )
	{
		if ( (desc->Events[i].Device == device) && (desc->Events[i].Type == EVENT_MOUSE_UP) && (desc->Events[i].Buttons.IsSet(buttons)) )
			return;
	}
	desc->Events.Add( MouseEvent(device, EVENT_MOUSE_UP, buttons) );
}

void InputSystemEx::ListenMouseAxisMove( IMouseEx* mouse, MouseListener* listener, const Axis& axis )
{
	UInt device = ((Mouse*)mouse)->GetIndex();
	MouseListenerDesc* desc = GetListener( listener );
	for ( UInt i = 0; i < desc->Events.Size(); ++i )
	{
		if ( (desc->Events[i].Device == device) && (desc->Events[i].Type == EVENT_MOUSE_AXIS_MOVE) && (desc->Events[i].AxisObject == axis) )
			return;
	}
	desc->Events.Add( MouseEvent(device, EVENT_MOUSE_AXIS_MOVE, axis) );
}

void InputSystemEx::ListenJoystickDown( IJoystickEx* joystick, JoystickListener* listener, const JoystickButton& button )
{
	UInt device = ((Joystick*)joystick)->GetIndex();
	JoystickListenerDesc* desc = GetListener( listener );
	for ( UInt i = 0; i < desc->Events.Size(); ++i )
	{
		if ( (desc->Events[i].Device == device) && (desc->Events[i].Type == EVENT_JOYSTICK_DOWN) && (desc->Events[i].Button == button) )
			return;
	}
	desc->Events.Add( JoystickEvent(device, EVENT_JOYSTICK_DOWN, button) );
}

void InputSystemEx::ListenJoystickUp( IJoystickEx* joystick, JoystickListener* listener, const JoystickButton& button )
{
	UInt device = ((Joystick*)joystick)->GetIndex();
	JoystickListenerDesc* desc = GetListener( listener );
	for ( UInt i = 0; i < desc->Events.Size(); ++i )
	{
		if ( (desc->Events[i].Device == device) && (desc->Events[i].Type == EVENT_JOYSTICK_UP) && (desc->Events[i].Button == button) )
			return;
	}
	desc->Events.Add( JoystickEvent(device, EVENT_JOYSTICK_UP, button) );
}

void InputSystemEx::ListenJoystickAxisMove( IJoystickEx* joystick, JoystickListener* listener, const Axis& axis )
{
	UInt device = ((Joystick*)joystick)->GetIndex();
	JoystickListenerDesc* desc = GetListener( listener );
	for ( UInt i = 0; i < desc->Events.Size(); ++i )
	{
		if ( (desc->Events[i].Device == device) && (desc->Events[i].Type == EVENT_JOYSTICK_AXIS_MOVE) && (desc->Events[i].AxisObject == axis) )
			return;
	}
	desc->Events.Add( JoystickEvent(device, EVENT_JOYSTICK_AXIS_MOVE, axis) );
}

void InputSystemEx::ListenArcballRotate( IArcball* arcball, ArcballListener* listener )
{
	ArcballListenerDesc* desc = GetListener( listener );
	for ( UInt i = 0; i < desc->Events.Size(); ++i )
	{
		if ( desc->Events[i].Type == EVENT_ARCBALL_ORIENT )
			return;
	}
	desc->Events.Add( ArcballEvent(EVENT_ARCBALL_ORIENT) );
}

void InputSystemEx::ListenArcballZoom( IArcball* arcball, ArcballListener* listener )
{
	ArcballListenerDesc* desc = GetListener( listener );
	for ( UInt i = 0; i < desc->Events.Size(); ++i )
	{
		if ( desc->Events[i].Type == EVENT_ARCBALL_ZOOM )
			return;
	}
	desc->Events.Add( ArcballEvent(EVENT_ARCBALL_ZOOM) );
}

void InputSystemEx::Initialize( IInputSystemFactory* factory, IWindowSystemEx* windowSystem )
{
	// Re-create input system, if needed.
	if ( factory != _factory )
	{
		_factory = factory;
		_inputSystem = nullptr;
		_inputSystem = factory->Create( _module, windowSystem, _log );
	}
}

void InputSystemEx::Finalize()
{
	_arcball = nullptr;
	_keyboardListeners.Clear();
	_mouseListeners.Clear();
	_joystickListeners.Clear();
	_arcballListeners.Clear();
	_keyboards.Clear();
	_mice.Clear();
	_joysticks.Clear();
}

InputSystemEx::KeyboardListenerDesc* InputSystemEx::GetListener( KeyboardListener* listener )
{
	KeyboardListenerDesc* desc = nullptr;
	for ( UInt i = 0; i < _keyboardListeners.Size(); ++i )
	{
		if ( _keyboardListeners[i].Listener == listener )
		{
			desc = _keyboardListeners.Get( i );
			break;
		}
	}
	if ( desc == nullptr )
	{
		_keyboardListeners.Add( KeyboardListenerDesc(listener) );
		desc = _keyboardListeners.Last();
	}
	return desc;
}

InputSystemEx::MouseListenerDesc* InputSystemEx::GetListener( MouseListener* listener )
{
	MouseListenerDesc* desc = nullptr;
	for ( UInt i = 0; i < _mouseListeners.Size(); ++i )
	{
		if ( _mouseListeners[i].Listener == listener )
		{
			desc = _mouseListeners.Get( i );
			break;
		}
	}
	if ( desc == nullptr )
	{
		_mouseListeners.Add( MouseListenerDesc(listener) );
		desc = _mouseListeners.Last();
	}
	return desc;
}

InputSystemEx::JoystickListenerDesc* InputSystemEx::GetListener( JoystickListener* listener )
{
	JoystickListenerDesc* desc = nullptr;
	for ( UInt i = 0; i < _joystickListeners.Size(); ++i )
	{
		if ( _joystickListeners[i].Listener == listener )
		{
			desc = _joystickListeners.Get( i );
			break;
		}
	}
	if ( desc == nullptr )
	{
		_joystickListeners.Add( JoystickListenerDesc(listener) );
		desc = _joystickListeners.Last();
	}
	return desc;
}

InputSystemEx::ArcballListenerDesc* InputSystemEx::GetListener( ArcballListener* listener )
{
	ArcballListenerDesc* desc = nullptr;
	for ( UInt i = 0; i < _arcballListeners.Size(); ++i )
	{
		if ( _arcballListeners[i].Listener == listener )
		{
			desc = _arcballListeners.Get( i );
			break;
		}
	}
	if ( desc == nullptr )
	{
		_arcballListeners.Add( ArcballListenerDesc(listener) );
		desc = _arcballListeners.Last();
	}
	return desc;
}

void InputSystemEx::ProcessKeyboardEvents()
{
	// Update listeners in reverse order.
	SynkroProfile( "InputSystemEx.ProcessKeyboardEvents" );
	const UInt cnt = _keyboardListeners.Size();
	for ( UInt i = 0; i < cnt; ++i )
	{
		// See if the listener is active.
		KeyboardListenerDesc& desc = _keyboardListeners[cnt-1-i];
		if ( !desc.Listener->ListenKeyboardInput() )
			continue;

		UInt event = none; Bool handled = false; Bool alt; Bool shift; Bool control;
		Key pressedKey = Key::Unknown; Double firstKeyDown = 0.0; Double lastKeyDown = 0.0;
		for ( UInt e = 0; e < desc.Events.Size(); ++e )
		{
			const KeyboardEvent& evt = desc.Events[e];
			Keyboard* keyboard = _keyboards[evt.Device];

			switch ( desc.Events[e].Type )
			{
				case EVENT_KEY_DOWN:
				{
					const Key key = evt.KeyObject;
					if ( (event = keyboard->GetNextKeyDown(none, key, alt, shift, control, pressedKey, firstKeyDown, lastKeyDown, false)) != none )
					{
						do
						{
							Bool notify = true;
							if ( evt.Discrete )
							{
								notify = (firstKeyDown == 0.0) || ((pressedKey == key) && (firstKeyDown >= 0.5) && (lastKeyDown >= 0.1));
							}

							// Notify listener, if needed.
							handled = notify ? desc.Listener->OnKeyboardKeyDown( evt.Device, key, alt, shift, control ) : false;
						}
						while( (event = keyboard->GetNextKeyDown(event, key, alt, shift, control, pressedKey, firstKeyDown, lastKeyDown, handled)) != none );
					}
				}
				break;

				case EVENT_KEY_UP:
				{
					const Key key = desc.Events[e].KeyObject;
					if ( (event = keyboard->GetNextKeyUp(none, key, alt, shift, control, false)) != none )
					{
						do
						{
							// Notify listener.
							handled = desc.Listener->OnKeyboardKeyUp( desc.Events[e].Device, key, alt, shift, control );
						}
						while( (event = keyboard->GetNextKeyUp(event, key, alt, shift, control, handled)) != none );
					}
				}
				break;

				case EVENT_KEY_PRESS:
				{
					Char key;
					if ( (event = keyboard->GetNextKeyPress(none, key, false)) != none )
					{
						do
						{
							// Notify listener.
							handled = desc.Listener->OnKeyboardKeyPress( desc.Events[e].Device, key );
						}
						while( (event = keyboard->GetNextKeyPress(event, key, handled)) != none );
					}
				}
				break;
			}
		}
	}
}

void InputSystemEx::ProcessMouseEvents()
{
	// Update listeners in reverse order.
	SynkroProfile( "InputSystemEx.ProcessMouseEvents" );
	const UInt cnt = _mouseListeners.Size();
	for ( UInt i = 0; i < cnt; ++i )
	{
		// See if the listener is active.
		MouseListenerDesc& desc = _mouseListeners[cnt-1-i];
		if ( !desc.Listener->ListenMouseInput() )
			continue;

		UInt event = none; Bool handled = false;
		for ( UInt e = 0; e < desc.Events.Size(); ++e )
		{
			Mouse* mouse = _mice[desc.Events[e].Device];
			MouseButton button;

			switch ( desc.Events[e].Type )
			{
				case EVENT_MOUSE_CLICK:
				{
					const MouseButton buttons = desc.Events[e].Buttons;
					if ( (event = mouse->GetNextClick(none, buttons, button, false)) != none )
					{
						do
						{
							// Notify listener.
							handled = desc.Listener->OnMouseClick( desc.Events[e].Device, button );
						}
						while( (event = mouse->GetNextClick(event, buttons, button, handled)) != none );
					}
				}
				break;

				case EVENT_MOUSE_DOUBLE_CLICK:
				{
					const MouseButton buttons = desc.Events[e].Buttons;
					if ( (event = mouse->GetNextDoubleClick(none, buttons, button, false)) != none )
					{
						do
						{
							// Notify listener.
							handled = desc.Listener->OnMouseDoubleClick( desc.Events[e].Device, button );
						}
						while( (event = mouse->GetNextDoubleClick(event, buttons, button, handled)) != none );
					}
				}
				break;

				case EVENT_MOUSE_DOWN:
				{
					const MouseButton buttons = desc.Events[e].Buttons;
					if ( (event = mouse->GetNextButtonDown(none, buttons, button, false)) != none )
					{
						do
						{
							// Notify listener.
							handled = desc.Listener->OnMouseButtonDown( desc.Events[e].Device, button );
						}
						while( (event = mouse->GetNextButtonDown(event, buttons, button, handled)) != none );
					}
				}
				break;

				case EVENT_MOUSE_UP:
				{
					const MouseButton buttons = desc.Events[e].Buttons;
					if ( (event = mouse->GetNextButtonUp(none, buttons, button, false)) != none )
					{
						do
						{
							// Notify listener.
							handled = desc.Listener->OnMouseButtonUp( desc.Events[e].Device, button );
						}
						while( (event = mouse->GetNextButtonUp(event, buttons, button, handled)) != none );
					}
				}
				break;

				case EVENT_MOUSE_AXIS_MOVE:
				{
					Int delta;
					const Axis axis = desc.Events[e].AxisObject;
					if ( (mouse->GetNextAxisMove(none, axis, delta, false)) != none )
					{
						do
						{
							// Notify listener.
							handled = desc.Listener->OnMouseAxisMove( desc.Events[e].Device, axis, delta );
						}
						while( (event = mouse->GetNextAxisMove(event, axis, delta, handled)) != none );
					}
				}
				break;
			}
		}
	}
}

void InputSystemEx::ProcessJoystickEvents()
{
	// Update listeners in reverse order.
	SynkroProfile( "InputSystemEx.ProcessJoystickEvents" );
	const UInt cnt = _joystickListeners.Size();
	for ( UInt i = 0; i < cnt; ++i )
	{
		// See if the listener is active.
		JoystickListenerDesc& desc = _joystickListeners[cnt-1-i];
		if ( !desc.Listener->ListenJoystickInput() )
			continue;

		UInt event = none; Bool handled = false;
		for ( UInt e = 0; e < desc.Events.Size(); ++e )
		{
			Joystick* joystick = _joysticks[desc.Events[e].Device];
			JoystickButton button;

			switch ( desc.Events[e].Type )
			{
				case EVENT_JOYSTICK_DOWN:
				{
					const JoystickButton buttons = desc.Events[e].Button;
					if ( (event = joystick->GetNextButtonDown(none, buttons, button, false)) != none )
					{
						do
						{
							// Notify listener.
							handled = desc.Listener->OnJoystickButtonDown( desc.Events[e].Device, button );
						}
						while( (event = joystick->GetNextButtonDown(event, buttons, button, handled)) != none );
					}
				}
				break;

				case EVENT_JOYSTICK_UP:
				{
					const JoystickButton buttons = desc.Events[e].Button;
					if ( (event = joystick->GetNextButtonUp(none, buttons, button, false)) != none )
					{
						do
						{
							// Notify listener.
							handled = desc.Listener->OnJoystickButtonUp( desc.Events[e].Device, button );
						}
						while( (event = joystick->GetNextButtonUp(event, buttons, button, handled)) != none );
					}
				}
				break;

				case EVENT_JOYSTICK_AXIS_MOVE:
				{
					Int delta;
					const Axis axis = desc.Events[e].AxisObject;
					event = joystick->GetNextAxisMove(none, axis, delta, false);
					if ( event != none )
					{
						do
						{
							// Notify listener.
							handled = desc.Listener->OnJoystickAxisMove( desc.Events[e].Device, axis, delta );
						}
						while( (event = joystick->GetNextAxisMove(event, axis, delta, handled)) != none );
					}
				}
				break;
			}
		}
	}
}

void InputSystemEx::ProcessArcballEvents()
{
	SynkroProfile( "InputSystemEx.ProcessArcballEvents" );
	const UInt cnt = _arcballListeners.Size();
	for ( UInt i = 0; i < cnt; ++i )
	{
		ArcballListenerDesc& desc = _arcballListeners[cnt-1-i];
		UInt event = none; Bool handled = false;

		// See if the listener is active.
		if ( !desc.Listener->ListenArcballInput() )
			continue;

		// Handle events.
		for ( UInt e = 0; e < desc.Events.Size(); ++e )
		{
			switch ( desc.Events[e].Type )
			{
				case EVENT_ARCBALL_ORIENT:
				{
					Quaternion orientation;
					if ( (event = _arcball->GetNextOrientation(none, orientation, false)) != none )
					{
						do
						{
							// Notify listener.
							handled = desc.Listener->OnArcballOriented( orientation );
						}
						while( (event = _arcball->GetNextOrientation(event, orientation, handled)) != none );
					}
				}
				break;

				case EVENT_ARCBALL_ZOOM:
				{
					Int delta;
					if ( (event = _arcball->GetNextZoom(none, delta, false)) != none )
					{
						do
						{
							// Notify listener.
							handled = desc.Listener->OnArcballZoom( delta );
						}
						while( (event = _arcball->GetNextZoom(event, delta, handled)) != none );
					}
				}
				break;
			}
		}
	}
}


} // input


} // synkro
