#include "App.h"


//------------------------------------------------------------------------------

using namespace synkro::audio;
using namespace synkro::core;
using namespace synkro::gfx;
using namespace synkro::img;
using namespace synkro::input;
using namespace synkro::io;
using namespace synkro::lang;
using namespace synkro::math;
using namespace synkro::over;
using namespace synkro::scene;

//------------------------------------------------------------------------------


App::App() :
	_synkro( SynkroCreate(SYNKRO_VERSION, this) ),
	_running( true ),
	_dial( nullptr )
{
}

App::~App()
{
	delete _dial;
}

void App::Run()
{
	// Create configuration.
	Configure();

	// Create main window.
	String mode; _config->Get( Param::GraphicsDisplayMode, &mode );
	_displayModeWindowed = DisplayMode( mode, false );
	DisplayMode::GetMode( 0, _displayModeFullscreen );
	_displayModeFullscreen.Fullscreen = true;
	_synkro->GetWindowSystem()->CreateWindow( false, false, L"Clock - Phase 05", 0, _displayModeWindowed.Width, _displayModeWindowed.Height );

	// Enter main loop.
	_synkro->Initialize( _config );
	_synkro->Run( _running );
}

void App::OnSynkroInitialize()
{
	_scene = _synkro->GetSceneManager()->CreateScene( L"Default", DebugMode::None, true );
	InitView();
	InitInput();
	InitOverlay();

	_camera->SetPosition( Vector3(0.0f, 24.0f, -36.0f) );
	_camera->LookAt( Vector3(0.0f, -3.0f, 0.0f) );

	_light = _scene->CreateDirectLight( nullptr, L"Light" );
	_light->SetDiffuseColor( Color::White );
	_light->SetAmbientColor( Color::Gray );
	_light->SetSpecularColor( Color::White );
	_light->LookAt( Vector3(10.0f, 3.0f, 0.0f) );

	PtrStream streamTick = _synkro->GetStreamSystem()->GetStream( L"tick.wav" );
	if ( streamTick == nullptr )
		throw FileNotFoundException( L"tick.wav" );
	PtrSound2D soundTick = _synkro->GetSoundManager()->LoadSound2D( streamTick );
	_dial = new Dial( _synkro, _scene, soundTick, 15.0f, Dial::DialMode::DIGITAL );
	_dial->Start();
}

void App::OnSynkroUpdate( Double delta )
{
	// Do nothing.
}

Bool App::OnSynkroException( const Exception& ex )
{
	return false;
}

Bool App::ListenKeyboardInput() const
{
	return true;
}

Bool App::OnKeyboardKeyDown( UInt device, const Key& key, Bool alt, Bool shift, Bool control )
{
	return false;
}

Bool App::OnKeyboardKeyUp( UInt device, const Key& key, Bool alt, Bool shift, Bool control )
{
	if ( key == Key::F1 )
	{
		_txtHints->Show( !_txtHints->IsVisible() );
		return true;
	}
	else if ( key == Key::F )
	{
		ToggleFullscreen();
		return true;
	}
	else if ( key == Key::X )
	{
		_running = false;
		return true;
	}
	else if ( key == Key::D )
	{
		_dial->SetMode( Dial::DialMode::DIGITAL );
		return true;
	}
	else if ( key == Key::A )
	{
		_dial->SetMode( Dial::DialMode::ANALOG );
		return true;
	}
	else if ( key == Key::S )
	{
		_dial->EnableSound( !_dial->IsSoundEnabled() );
		return true;
	}

	return false;
}

Bool App::OnKeyboardKeyPress( UInt device, Char key )
{
	return false;
}

void App::Configure()
{
	// Set configuration parameters.
	_config = _synkro->GetConfiguration()->Clone();
	_config->Set( Param::AnimationEnable, true );
	_config->Set( Param::AudioEnable, true );
	_config->Set( Param::AudioSystem, AudioSystem::DirectSound8 );
	_config->Set( Param::GraphicsSystem, GraphicsSystem::DirectX11 );
	_config->Set( Param::GraphicsDepthFormat, DepthFormat::D32F );
	_config->Set( Param::GraphicsDisplayMode, DisplayMode::Medium.Index() );
	_config->Set( Param::GraphicsSampleCount, CastUInt(8) );
	_config->Set( Param::GraphicsFullscreen, false );
	_config->Set( Param::UiEnable, false );
	_config->Set( Param::InputEnable, true );
	_config->Set( Param::InputSystem, InputSystem::DirectInput8 );
	_config->Set( Param::StreamPath, String(L"../../media") );
}

void App::InitView()
{
	// Setup camera.
	_camera = _scene->CreateCamera( nullptr, String::Empty );
	_camera->SetHorizontalFieldOfView( Math::ToRadians(45.0f) );
	_camera->SetAspect( _displayModeWindowed.AspectFactor() );
	_camera->SetFront( 0.1f );
	_camera->SetBack( 10000.0f );

	// Setup viewport.
	_viewport = _synkro->GetViewportManager()->GetViewport( _synkro->GetGraphicsSystem()->GetFrameWindow(0)->GetView(0) );
	_viewport->SetCamera( _camera );
	_viewport->SetColor( Color::BedazzledBlue );
}

void App::InitOverlay()
{
	_synkro->GetOverlayManager()->CreateFont( L"hint", _synkro->GetLanguage(), L"Arial", FontStyle::Bold, 10 );
	IFrameRenderWindowEx* window = _synkro->GetGraphicsSystem()->GetFrameWindow( 0 );
	IFont* font = _synkro->GetOverlayManager()->GetOverlay( window )->GetFont( L"hint" );
	_txtHelp = font->CreateText( Color::Yellow, Point(5, 5), L"Press F1 for help", Order::Highest, Order::Highest );
	String help = L"Toggle fullscreen: F\r\nDigital clock: D\r\nAnalog clock: A\r\nToggle sound: S\r\nExit: X";
	_txtHints = font->CreateText( Color::Yellow, Point(5, 25), help, Order::Highest, Order::Highest );
	_txtHints->Show( false );
}

void App::InitInput()
{
	_synkro->GetInputSystem()->CreateKeyboard( 0 );
	const Key keys[] = { Key::F1, Key::F, Key::D, Key::A, Key::S, Key::X };
	_synkro->GetInputSystem()->GetKeyboard(0)->ListenKeyUp( this, keys, sizeof(keys)/sizeof(keys[0]) );
}

void App::ToggleFullscreen()
{
	DisplayMode displayMode;
	_synkro->GetGraphicsSystem()->GetFrameWindow( 0 )->GetDisplayMode( displayMode );
	displayMode = (displayMode == _displayModeFullscreen) ? _displayModeWindowed : _displayModeFullscreen;
	_camera->SetAspect( displayMode.AspectFactor() );
	_synkro->GetGraphicsSystem()->GetFrameWindow( 0 )->SetDisplayMode( displayMode );
}
