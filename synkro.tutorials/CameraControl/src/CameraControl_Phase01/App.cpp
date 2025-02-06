#include "App.h"


//------------------------------------------------------------------------------

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

//------------------------------------------------------------------------------


App::App() :
	_synkro( SynkroCreate(SYNKRO_VERSION, this) ),
	_running( true )
{
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
	_synkro->GetWindowSystem()->CreateWindow( false, false, L"Camera Control - Phase01", 0, _displayModeWindowed.Width, _displayModeWindowed.Height );

	// Enter main loop.
	_synkro->Initialize( _config );
	_synkro->Run( _running );
}

void App::OnSynkroInitialize()
{
	_window = _synkro->GetGraphicsSystem()->GetFrameWindow( 0 );
	InitScene();
	InitView();
	InitInput();
	InitOverlay();
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
	_config->Set( Param::GraphicsSystem, GraphicsSystem::DirectX11 );
	_config->Set( Param::GraphicsDepthFormat, DepthFormat::D32F );
	_config->Set( Param::GraphicsDisplayMode, DisplayMode::Medium.Index() );
	_config->Set( Param::GraphicsSampleCount, CastUInt(8) );
	_config->Set( Param::GraphicsFullscreen, false );
	_config->Set( Param::InputEnable, true );
	_config->Set( Param::InputSystem, InputSystem::DirectInput8 );
	_config->Set( Param::StreamPath, String(L"../../media") );
	_config->Set( Param::UiEnable, false );
}

void App::InitScene()
{
	_scene = _synkro->GetSceneManager()->CreateScene( L"Default", DebugMode::None, true );

	// Create sky.
	PtrImage imageSky = GetImage( L"Spherical_Panorama_2560px.jpg" );
	_scene->SetSky( imageSky, 10000.0f );

	// Create materials.
	PtrImage imageCheckers = GetImage( L"checkers.jpg" );
	_materialFloor = _synkro->GetMaterialManager()->CreateOpaqueMaterial( LightingModel::Gouraud );
	_materialFloor->GetDiffuseMap()->SetImage( imageCheckers );
	_materialFloor->SetTilingHorizontal( 8 );
	_materialFloor->SetTilingVertical( 8 );

	// Create floor.
	constexpr Float FLOOR_SIZE = 1000.0f;
	_floor = _scene->CreateTriangleMesh( nullptr, L"Floor", _materialFloor, nullptr );
	_synkro->GetSceneManager()->BuildMesh( _floor, MeshBuilder::Plane, Vector4(FLOOR_SIZE, FLOOR_SIZE, 0.0f, 0.0f), Size(16, 0), Matrix4x4::Identity );

	// Create light source.
	_light = _scene->CreateDirectLight( nullptr, L"Light" );
	_light->SetAmbientColor( Color::DimGray );
	_light->SetDiffuseColor( Color::White );
	_light->LookAt( Vector3(0.0f, 1.0f, 0.0f) );
}

void App::InitView()
{
	// Setup camera.
	_camera = _scene->CreateCamera( nullptr, String::Empty );
	_camera->SetHorizontalFieldOfView( Math::ToRadians(45.0f) );
	_camera->SetAspect( _displayModeWindowed.AspectFactor() );
	_camera->SetPosition( Vector3(0.0f, 50.0f, -300.0f) );
	_camera->SetFront( 0.1f );
	_camera->SetBack( 20000.0f );
	_camera->SetOrientation( Quaternion(Vector3::Y, 0.0f) );

	// Setup viewport.
	_viewport = _synkro->GetViewportManager()->GetViewport( _synkro->GetGraphicsSystem()->GetFrameWindow(0)->GetView(0) );
	_viewport->SetCamera( _camera );
}

void App::InitOverlay()
{
	_synkro->GetOverlayManager()->CreateFont( L"hint", _synkro->GetLanguage(), L"Arial", FontStyle::Bold, 10 );
	IFrameRenderWindowEx* window = _synkro->GetGraphicsSystem()->GetFrameWindow( 0 );
	IFont* font = _synkro->GetOverlayManager()->GetOverlay( window )->GetFont( L"hint" );
	_txtHelp = font->CreateText( Color::Yellow, Point(5, 5), L"Press F1 for help", Order::Highest, Order::Highest );
	String help = L"Toggle fullscreen: F\r\nExit: X";
	_txtHints = font->CreateText( Color::Yellow, Point(5, 25), help, Order::Highest, Order::Highest );
	_txtHints->Show( false );
}

void App::InitInput()
{
	_synkro->GetInputSystem()->CreateKeyboard( 0 );
	const Key keys[] = { Key::F1, Key::F, Key::X };
	_synkro->GetInputSystem()->GetKeyboard(0)->ListenKeyUp( this, keys, sizeof(keys)/sizeof(keys[0]) );
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

void App::ToggleFullscreen()
{
	DisplayMode displayMode;
	_synkro->GetGraphicsSystem()->GetFrameWindow( 0 )->GetDisplayMode( displayMode );
	displayMode = (displayMode == _displayModeFullscreen) ? _displayModeWindowed : _displayModeFullscreen;
	_camera->SetAspect( displayMode.AspectFactor() );
	_synkro->GetGraphicsSystem()->GetFrameWindow( 0 )->SetDisplayMode( displayMode );
}
