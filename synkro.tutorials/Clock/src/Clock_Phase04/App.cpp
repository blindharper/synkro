#include "App.h"


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::gfx;
using namespace synkro::img;
using namespace synkro::lang;
using namespace synkro::math;
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
	_synkro->GetWindowSystem()->CreateWindow( false, false, L"Clock - Phase 04", 0, _displayModeWindowed.Width, _displayModeWindowed.Height );

	// Enter main loop.
	_synkro->Initialize( _config );
	_synkro->Run( _running );
}

void App::OnSynkroInitialize()
{
	_scene = _synkro->GetSceneManager()->CreateScene( L"Default", DebugMode::None, true );
	InitView();

	_camera->SetPosition( Vector3(0.0f, 24.0f, -36.0f) );
	_camera->LookAt( Vector3(0.0f, -3.0f, 0.0f) );

	_light = _scene->CreateDirectLight( nullptr, L"Light" );
	_light->SetDiffuseColor( Color::White );
	_light->SetAmbientColor( Color::Gray );
	_light->SetSpecularColor( Color::White );
	_light->LookAt( Vector3(10.0f, 3.0f, 0.0f) );

	_dial = new Dial( _synkro, _scene, 15.0f, Dial::DialMode::DIGITAL );
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

void App::Configure()
{
	// Set configuration parameters.
	_config = _synkro->GetConfiguration()->Clone();
	_config->Set( Param::AnimationEnable, true );
	_config->Set( Param::GraphicsSystem, GraphicsSystem::DirectX11 );
	_config->Set( Param::GraphicsDepthFormat, DepthFormat::D32F );
	_config->Set( Param::GraphicsDisplayMode, DisplayMode::Medium.Index() );
	_config->Set( Param::GraphicsSampleCount, CastUInt(8) );
	_config->Set( Param::GraphicsFullscreen, false );
	_config->Set( Param::UiEnable, false );
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
