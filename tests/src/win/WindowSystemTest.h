#include <win/IWindowSystemFactory.h>
#include <win/WindowSystemEx.h>
#include <win/WindowListener.h>
#include <win/FrameWindow.h>
#include <core/ObjectImpl.h>
#include <stdio.h>


//------------------------------------------------------------------------------

using namespace synkro;
using namespace synkro::core;
using namespace synkro::lang;
using namespace synkro::mem;
using namespace synkro::win;

//------------------------------------------------------------------------------


class WindowSystemTest :
	public WindowListener
{
public:
	WindowSystemTest( Pointer module, const String& title, IWindowSystemFactory* factWindowSys ) :
		_module( module ),
		_title( title ),
		_running( true ),
		_factWindowSys( factWindowSys )
	{
	}

	void Run()
	{
		_windowSystem = new WindowSystemEx( _module, nullptr );
		_windowSystem->Initialize( _factWindowSys );
		_windowSystem->CreateWindow( false, true, _title, 0, 640, 480 );
		IFrameWindowEx* wnd = _windowSystem->GetFrameWindow( 0 );
		IViewWindow* view = _windowSystem->CreateWindow( wnd, 50, 120, 300, 200 );
		IViewWindow* view2 = _windowSystem->CreateWindow( wnd, 400, 10, 100, 400 );
		IIconWindow* icon = _windowSystem->CreateWindow( 0, _title );
		icon->AddMenuItem( 100, 100, L"Command 1" );
		icon->AddMenuItem( 200, 200, L"Command 2" );
		icon->AddMenuItem( 300, 300, L"Exit" );
		icon->Listen( this );
		wnd->Listen( this );

		while ( _running && _windowSystem->Update(0.001) )
		{
			;
		}
	}

	void OnWindowResize( UInt window, UInt width, UInt height )
	{
		String title = String::Format( L"Width: {0}, Height: {1}", width, height );
		_windowSystem->GetFrameWindow( 0 )->SetTitle( title );
	}

	void OnWindowCommand( UInt window, UInt command )
	{
		switch ( command )
		{
			case 100:
				_windowSystem->GetFrameWindow( 0 )->SetTitle( L"Command 1" );
				break;

			case 200:
				_windowSystem->GetFrameWindow( 0 )->SetTitle( L"Command 2" );
				break;

			case 300:
				_running = false;
				_windowSystem->GetFrameWindow( 0 )->Activate();
				break;
		}
	}

	void OnWindowActivate( UInt window, Bool active )
	{
		_windowSystem->GetFrameWindow( 0 )->SetTitle( active ? L"Active" : L"Inactive" );
	}

	Bool OnWindowClosing( UInt window )
	{
		return Platform::Question( L"Close Window", L"Are you sure you want to quit?" );
	}

private:
	Pointer					_module;
	String					_title;
	Bool					_running;
	IWindowSystemFactory*	_factWindowSys;
	P(WindowSystemEx)		_windowSystem;
};
