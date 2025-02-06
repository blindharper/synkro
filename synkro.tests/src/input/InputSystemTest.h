#include <win/IWindowSystemFactory.h>
#include <win/WindowSystemEx.h>
#include <input/IInputSystemFactory.h>
#include <input/InputSystemEx.h>
#include <input/JoystickButton.h>
#include <input/KeyboardListener.h>
#include <input/MouseListener.h>
#include <input/JoystickListener.h>
#include <stdio.h>


//------------------------------------------------------------------------------

using namespace synkro;
using namespace synkro::core;
using namespace synkro::input;
using namespace synkro::lang;
using namespace synkro::math;
using namespace synkro::mem;
using namespace synkro::win;

//------------------------------------------------------------------------------

class InputSystemTest :
	public KeyboardListener,
	public MouseListener,
	public JoystickListener
{
public:
	InputSystemTest( Pointer module, const String& name, IWindowSystemFactory* factWindowSys, IInputSystemFactory* factInputSys ) :
		_module( module ),
		_name( name ),
		_factWindowSys( factWindowSys ),
		_factInputSys( factInputSys )
	{
	}

	void Run()
	{
		P(WindowSystemEx) ws = new WindowSystemEx( _module, nullptr );
		ws->Initialize( _factWindowSys );
		P(IFrameWindow) wnd = ws->CreateWindow( false, false, _name, 0, 800, 600 );
		P(InputSystemEx) is = new InputSystemEx( _module, nullptr );
		is->Initialize( _factInputSys, ws );
		_inputSystem = is;

		is->CreateKeyboard( 0 );
		IKeyboardEx* keyboard = is->GetKeyboard( 0 );
		keyboard->ListenKeyDown( this, Key::Return, true );
		keyboard->ListenKeyPress( this );

		is->CreateMouse( 0 );
		IMouseEx* mouse = is->GetMouse( 0 );
		mouse->ListenClick( this, MouseButton::None );
		mouse->ListenDoubleClick( this, MouseButton::None );
		mouse->ListenButtonDown( this, MouseButton::Left );
		mouse->ListenButtonUp( this, MouseButton::Left );
		mouse->ListenAxisMove( this, Axis::Z );

		if ( is->GetTotalJoystickCount() > 0 )
		{
			is->CreateJoystick( 0 );
		}
		IJoystickEx* joystick = (is->GetJoystickCount() > 0) ? is->GetJoystick( 0 ) : nullptr;
		if ( joystick != nullptr )
		{
			joystick->ListenButtonDown( this, JoystickButton::Unknown );
			joystick->ListenAxisMove( this, Axis::Unknown );
		}

		while ( ws->Update(0.05) )
		{
			is->Update( 0.05 );

			String txt( L"Keys:" );
			for ( UInt k = 0; k < 256; ++k )
			{
				Key key(k);
				if ( keyboard->IsKeyDown(key) )
					txt = txt.Append( key.ToString()+L"|" );
			}

			if ( mouse != nullptr )
			{
				txt = txt.Append( L" Mouse:" );
				if ( mouse->IsButtonDown(MouseButton::Left) )
					txt = txt.Append( L"L" );
				if ( mouse->IsButtonDown(MouseButton::Middle) )
					txt = txt.Append( L"M" );
				if ( mouse->IsButtonDown(MouseButton::Right) )
					txt = txt.Append( L"R" );

				static Long x = 0;
				txt = txt.Append( L" X-Axis: " );
				x += mouse->GetAxisMovement( Axis::X );
				txt = txt.Append( String((Int)x) );

				static Long y = 0;
				txt = txt.Append( L" Y-Axis: " );
				y += mouse->GetAxisMovement( Axis::Y );
				txt = txt.Append( String((Int)y) );
				
				static Long z = 0;
				txt = txt.Append( L" Z-Axis: " );
				z += mouse->GetAxisMovement( Axis::Z );
				txt = txt.Append( String((Int)z) );
			}

			if ( joystick != nullptr )
			{
				txt = txt.Append( L" JX-Axis: " );
				txt = txt.Append( String(joystick->GetAxisMovement( Axis::X )) );

				txt = txt.Append( L" JY-Axis: " );
				txt = txt.Append( String(joystick->GetAxisMovement( Axis::Y )) );

				txt = txt.Append( L" JZ-Axis: " );
				txt = txt.Append( String(joystick->GetAxisMovement( Axis::Z )) );
			}

			wnd->SetTitle( txt );
		}
	}

	Bool ListenKeyboardInput() const
	{
		return true;
	}

	Bool OnKeyboardKeyDown( UInt device, const Key& key, Bool alt, Bool shift, Bool control )
	{
		printf( "RETURN\r\n" );
		return true;
	}

	Bool OnKeyboardKeyUp( UInt device, const Key& key, Bool alt, Bool shift, Bool control )
	{
		return false;
	}

	Bool OnKeyboardKeyPress( UInt device, Char key )
	{
		char buf[8] = {};
		memset( buf, 0, 8 );
		buf[0] = (char)key;
		buf[1] = 0;
		printf( "%s", buf );
		return true;
	}

	Bool ListenMouseInput() const
	{
		return true;
	}
	
	Bool OnMouseClick( UInt device, const MouseButton& buttons )
	{
		printf( "Mouse Click " );
		if ( _inputSystem->GetMouse()->IsButtonDown(MouseButton::Left) )
			printf( "Left" );
		else if ( _inputSystem->GetMouse()->IsButtonDown(MouseButton::Right) )
			printf( "Right" );
		else if ( _inputSystem->GetMouse()->IsButtonDown(MouseButton::Middle) )
			printf( "Middle" );

		printf( "\r\n" );
		return true;
	}

	Bool OnMouseDoubleClick( UInt device, const MouseButton& buttons )
	{
		printf( "Mouse Double Click\r\n" );
		return true;
	}

	Bool OnMouseButtonDown( UInt device, const MouseButton& buttons )
	{
		printf( "Mouse Button Down\r\n" );
		return true;
	}
	
	Bool OnMouseButtonUp( UInt device, const MouseButton& buttons )
	{
		printf( "Mouse Button Up\r\n" );
		return true;
	}

	Bool OnMouseAxisMove( UInt device, const Axis& axis, Int delta )
	{
		char buf[200] = {};
		axis.ToString().GetBytes(buf, 200);
		printf( "Mouse Axis Move. Axis = %s. Delta = %d\r\n", buf, delta );
		return true;
	}

	Bool ListenJoystickInput() const
	{
		return true;
	}

	Bool OnJoystickButtonDown( UInt device, const JoystickButton& button )
	{
		printf( "Joystick Button Down. Button = %d\r\n", button.Value() );
		return true;
	}

	Bool OnJoystickButtonUp( UInt device, const JoystickButton& button )
	{
		return false;
	}

	Bool OnJoystickAxisMove( UInt device, const Axis& axis, Int delta )
	{
		char buf[200] = {};
		axis.ToString().GetBytes(buf, 200);
		printf( "Joystick Axis Move. Axis = %s. Delta = %d\r\n", buf, delta );
		return true;
	}

private:
	Pointer					_module;
	String					_name;
	IInputSystemEx*			_inputSystem;
	IWindowSystemFactory*	_factWindowSys;
	IInputSystemFactory*	_factInputSys;
};
