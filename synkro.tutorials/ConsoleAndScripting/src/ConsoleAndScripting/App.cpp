#include "App.h"


//------------------------------------------------------------------------------

using namespace synkro::audio;
using namespace synkro::core;
using namespace synkro::gfx;
using namespace synkro::img;
using namespace synkro::input;
using namespace synkro::io;
using namespace synkro::lang;
using namespace synkro::mat;
using namespace synkro::math;
using namespace synkro::over;
using namespace synkro::scene;
using namespace synkro::script;

//------------------------------------------------------------------------------


App::App() :
	_synkro( SynkroCreate(SYNKRO_VERSION, this) ),
	_running( true ),
	_universe( nullptr )
{
}

App::~App()
{
	if ( _universe != nullptr )
		delete _universe;
}

void App::Run()
{
	// Create configuration.
	Configure();

	// Create main window.
	String mode; _config->Get( Param::GraphicsDisplayMode, &mode );
	_displayModeWindowed = DisplayMode( mode, false );
	_synkro->GetWindowSystem()->CreateWindow( false, false, L"Console And Scripting", 0, _displayModeWindowed.Width, _displayModeWindowed.Height );

	// Enter main loop.
	_synkro->Initialize( _config );
	_synkro->Run( _running );
}

void App::OnSynkroInitialize()
{
	_window = _synkro->GetGraphicsSystem()->GetFrameWindow( 0 );
	InitView();
	InitScripting();
}

void App::OnSynkroUpdate( Double delta )
{
	// Do nothing.
}

Bool App::OnSynkroException( const Exception& ex )
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
	_config->Set( Param::ConsoleEnable, true );
	_config->Set( Param::GraphicsSystem, GraphicsSystem::DirectX11 );
	_config->Set( Param::GraphicsDepthFormat, DepthFormat::D32F );
	_config->Set( Param::GraphicsDisplayMode, DisplayMode::Maximum.Index() );
	_config->Set( Param::GraphicsSampleCount, CastUInt(8) );
	_config->Set( Param::GraphicsFullscreen, false );
	_config->Set( Param::InputEnable, true );
	_config->Set( Param::InputSystem, InputSystem::DirectInput8 );
	_config->Set( Param::ScriptEnable, true );
	_config->Set( Param::ScriptSystem, ScriptSystem::Lua );
	_config->Set( Param::StreamPath, String(L"../../media") );
	_config->Set( Param::UiEnable, false );
}

void App::InitView()
{
	// Setup viewport.
	_viewport = _synkro->GetViewportManager()->GetViewport( _synkro->GetGraphicsSystem()->GetFrameWindow(0)->GetView(0) );
}

void App::InitScripting()
{
	_scriptMachine = _synkro->GetScriptSystem()->CreateMachine( L"universe" );
	_universe = new Universe( _synkro, _scriptMachine, _displayModeWindowed );
}

IImage* App::GetImage( const String& name )
{
	PixelFormat fmt = _window->GetClientPixelFormat();
	return _synkro->GetImageManager()->LoadImageAsync( GetStream(name), fmt, nullptr );
}

IStream* App::GetStream( const String& name )
{
	PtrStream stream = _synkro->GetStreamSystem()->GetStream( name );
	if ( stream == nullptr )
		throw FileNotFoundException( name );
	return stream;
}
