#include "App.h"


//------------------------------------------------------------------------------

using namespace synkro::anim;
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
using namespace synkro::ui;
using namespace synkro::view;

//------------------------------------------------------------------------------


App::App() :
	_synkro( SynkroCreate(SYNKRO_VERSION, this) ),
	_deltaTime( 0.0 ),
	_orgFov( 45.0f ),
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
	_synkro->GetWindowSystem()->CreateWindow( false, false, L"Camera Control - Phase04", 0, _displayModeWindowed.Width, _displayModeWindowed.Height );

	// Enter main loop.
	_synkro->Initialize( _config );
	_synkro->Run( _running );
}

void App::OnSynkroInitialize()
{
	_window = _synkro->GetGraphicsSystem()->GetFrameWindow( 0 );
	InitInput();
	InitVirtualScene();
	InitScene();
	InitView();
	InitOverlay();
	InitUi();
}

void App::OnSynkroUpdate( Double delta )
{
	_deltaTime = delta;
}

Bool App::OnSynkroException( const Exception& ex )
{
	return false;
}

void App::OnAnimationStop( IAnimationController* sender )
{
	_btnLoadAnimation->Enable( true );
	_btnStartRecording->Enable( true );
}

void App::OnAnimationLoop( IAnimationController* sender )
{
	// Do nothing.
}

Bool App::ListenKeyboardInput() const
{
	return true;
}

Bool App::OnKeyboardKeyDown( UInt device, const Key& key, Bool alt, Bool shift, Bool control )
{
	const Float MOVE_SPEED = shift ? 300.0f : 100.0f;
	const Float dx = _deltaTime*MOVE_SPEED;

	if ( key == Key::Up )
	{
		Matrix4x4 trans;
		_camera->GetWorldTransform( trans );
		Vector3 dir = trans.Forward();
		dir.y = 0.0f;
		_camera->SetPosition( trans.Translation()+dir*dx );
		return true;
	}
	else if ( key == Key::Down )
	{
		Matrix4x4 trans;
		_camera->GetWorldTransform( trans );
		Vector3 dir = trans.Forward();
		dir.y = 0.0f;
		_camera->SetPosition( trans.Translation()-dir*dx );
		return true;
	}
	else if ( key == Key::Left )
	{
		Matrix4x4 trans;
		_camera->GetWorldTransform( trans );
		Vector3 dir = trans.Right();
		dir.y = 0.0f;
		_camera->SetPosition( trans.Translation()-dir*dx );
		return true;
	}
	else if ( key == Key::Right )
	{
		Matrix4x4 trans;
		_camera->GetWorldTransform( trans );
		Vector3 dir = trans.Right();
		dir.y = 0.0f;
		_camera->SetPosition( trans.Translation()+dir*dx );
		return true;
	}

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
	else if ( key == Key::T )
	{
		_filterGrayscale->Enable( !_filterGrayscale->IsEnabled() );
		_txt->SetColor( !_filterGrayscale->IsEnabled() ? Color::Yellow : Color::DimGray );
		return true;
	}
	else if ( key == Key::D )
	{
		_day = !_day;
		PtrImage imageSky = GetImage( _day ? L"Spherical_Panorama_2560px.jpg" : L"space.jpg" );
		_scene->SetSky( imageSky, 10000.0f );
		_light->Enable( _day );
		return true;
	}
	else if ( key == Key::S )
	{
		_sound->Enable( !_sound->IsEnabled() );
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

Bool App::ListenMouseInput() const
{
	return true;
}

Bool App::OnMouseClick( UInt device, const MouseButton& buttons )
{
	return false;
}

Bool App::OnMouseDoubleClick( UInt device, const MouseButton& buttons )
{
	return false;
}

Bool App::OnMouseButtonDown( UInt device, const MouseButton& buttons )
{
	return false;
}

Bool App::OnMouseButtonUp( UInt device, const MouseButton& buttons )
{
	return false;
}

Bool App::OnMouseAxisMove( UInt device, const Axis& axis, Int delta )
{
	const Float ROTATE_SPEED = Math::ToRadians( 0.04f );
	const Float da = CastFloat( delta ) * ROTATE_SPEED;

	if ( axis == Axis::X )
	{
		const Float yaw = _camera->GetOrientationYaw();
		_camera->SetOrientationYaw( yaw+da );
		return true;
	}
	else if ( axis == Axis::Y )
	{
		const Float pitch = _camera->GetOrientationPitch();
		_camera->SetOrientationPitch( pitch+da );
		return true;
	}

	return false;
}

Bool App::ListenArcballInput() const
{
	return true;
}

Bool App::OnArcballOriented( const Quaternion& orientation )
{
	return false;
}

Bool App::OnArcballZoom( Int delta )
{
	_camera->SetHorizontalFieldOfView( Math::ToRadians(_orgFov -= 0.005f*CastFloat(delta)) );
	return true;
}

Bool App::OnUiClick( IWidget* sender )
{
	if ( sender == _btnLoadAnimation )
	{
		PtrStreamDirectory dirAnimations = _synkro->GetStreamSystem()->BuildDirectory( L"../../media" );
		_animStream = dirAnimations->CreateStream( L"camera.xma" );
		_animationSet = _synkro->GetAnimationSystem()->LoadAnimation( _animStream );
		_animation = _animationSet->GetAnimation( L"CameraMove" );
		_btnPlayAnimation->Enable( true );
		return true;
	}
	else if ( sender == _btnStartRecording )
	{
		if ( _ctrlRecord == nullptr )
		{
			_animationSet = _synkro->GetAnimationSystem()->CreateAnimationSet( L"CameraControl" );
			_animation = _animationSet->CreateAnimation( L"CameraMove" );
			_ctrlRecord = _camera->CreateRecordController( _animation );
			_ctrlRecord->CreatePositionTrack();
			_ctrlRecord->CreateOrientationTrack();
			_ctrlRecord->CreateFieldOfViewTrack();
			_ctrlRecord->SetStep( 0.5 );
		}
		_ctrlRecord->Start( true );
		_btnStopRecording->Enable( true );
		return true;
	}
	else if ( sender == _btnStopRecording )
	{
		if ( _ctrlRecord->GetState() == ControllerState::Active )
		{
			_ctrlRecord->Start( false );
			PtrStreamDirectory dirAnimations = _synkro->GetStreamSystem()->BuildDirectory( L"../../media" );
			_animStream = dirAnimations->CreateStream( L"camera.xma" );
			_animationSet->SaveAsync( _animStream );
			_btnStartRecording->Enable( true );
			_btnPlayAnimation->Enable( true );
			return true;
		}
	}
	else if ( sender == _btnPlayAnimation )
	{
		PtrNodeAnimationController ctrl = _camera->CreateAnimationController( _animation, this );
		if ( _animation != nullptr )
		{
			ctrl->SetAnimation( _animation );
		}
		_btnLoadAnimation->Enable( false );
		_btnStartRecording->Enable( false );
		ctrl->Reset();
		ctrl->Start( true );
		return true;
	}

	return false;
}

Bool App::OnUiDoubleClick( IWidget* sender )
{
	return false;
}

Bool App::OnUiValueChanged( IWidget* sender )
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
	_config->Set( Param::InputEnable, true );
	_config->Set( Param::InputSystem, InputSystem::DirectInput8 );
	_config->Set( Param::StreamPath, String(L"../../media") );
	_config->Set( Param::UiEnable, true );
	_config->Set( Param::UiFontSize, CastUInt(8) );
	_config->Set( Param::UiThemeName, ThemeName::Glass );
	_config->Set( Param::UiColorWidgetNormal, Color::RoyalBlue );
	_config->Set( Param::UiColorTextNormal, Color::White );
	_config->Set( Param::UiColorTextActive, Color::Cyan );
	_config->Set( Param::UiColorTextHovered, Color::Yellow );
}

void App::InitVirtualScene()
{
	_sceneTV = _synkro->GetSceneManager()->CreateScene( L"TV", DebugMode::None, true );
	_cameraTV = _sceneTV->CreateCamera( nullptr, String::Empty );
	_cameraTV->SetHorizontalFieldOfView( Math::ToRadians(45.0f) );
	_cameraTV->SetAspect( 1.0f );
	_cameraTV->SetFront( 0.1f );
	_cameraTV->SetBack( 10000.0f );
	_cameraTV->SetPosition( Vector3(0.0f, 24.0f, -236.0f) );
	_cameraTV->LookAt( Vector3::Origin );

	_sun = _sceneTV->CreateDirectLight( nullptr, L"Sun" );
	_sun->SetDiffuseColor( Color::White );
	_sun->SetSpecularColor( Color::White );
	_sun->LookAt( Vector3(-10.0f, -3.0f, 0.0f) );

	_materialEarth = _synkro->GetMaterialManager()->CreateOpaqueMaterial( LightingModel::Gouraud );
	_materialEarth->SetDiffuseColor( Color::DimGray );
	_materialEarth->SetSpecularColor( Color::DimGray );
	_materialEarth->SetSpecularPower( 32 );
	_materialEarth->GetDiffuseMap()->SetImage( GetImage(L"earthmap1k.jpg") );

	constexpr Float EARTH_RADIUS = 40.0f;
	_earth = _sceneTV->CreateTriangleMesh( nullptr, L"earth", _materialEarth, nullptr );
	_synkro->GetSceneManager()->BuildMesh( _earth, MeshBuilder::Ellipsoid, Vector4(EARTH_RADIUS, EARTH_RADIUS, EARTH_RADIUS, 0.0f), Size(40, 40), Matrix4x4::Identity );
	_earth->SetPosition( Vector3::Origin );

	PtrNodeAnimationController earthCtrl = _earth->CreateAnimationController(nullptr, nullptr);
	IWaveFloatTrack* trackYaw = earthCtrl->CreateOrientationYawTrack( AnimationTrack::FloatWave )->AsWave();
	trackYaw->SetType( WaveType::SawtoothUp );
	trackYaw->SetAmplitude( Math::TwoPi );
	trackYaw->SetFrequency( 0.125f );
	earthCtrl->SetMode( AnimationMode::Loop );
	earthCtrl->SetSpeed( 0.3 );
	earthCtrl->Start( true );

	// Create virtual window.
	IVirtualRenderWindow* wnd = _synkro->GetGraphicsSystem()->CreateRenderWindow( 990.0f, 560.0f, _window->GetPixelFormat(), _window->GetSampleCount(), 0 );
	_viewportTV = _synkro->GetViewportManager()->CreateViewport( wnd->GetView(), _cameraTV );
	_filterGrayscale = _viewportTV->CreateFilter( ViewportFilter::Grayscale );
	_filterGrayscale->Enable( false );

	// Create TV overlay.
	_synkro->GetOverlayManager()->CreateFont( L"string", _synkro->GetLanguage(), L"Arial", FontStyle::Bold, 60 );
	IOverlay* overlay = _synkro->GetOverlayManager()->CreateOverlay( wnd );
	IFont* font = overlay->GetFont( L"string" );
	_txt = font->CreateText(Color::Yellow, Point(4, 400), String(L"SYNKRO tutorials version ").Append(Version::Current.ToString()), Order::Highest, Order::Highest);
	_txt->SetOpacity(0.5f);
	ITextAnimationController* ctrlTxt = _txt->CreateAnimationController( nullptr, nullptr );
	Size sz; font->GetTextSize( _txt->GetText(), sz );
	IKeyframedFloatTrack* trackPosition = ctrlTxt->CreateLocationXTrack();
	trackPosition->SetKey( 0.0, (Float)wnd->GetWidth() );
	trackPosition->SetKey( 6.0, -(Float)sz.Width );
	ctrlTxt->SetMode( AnimationMode::Loop );
	ctrlTxt->Start( true );

	// Create screen material.
	_materialScreen = _synkro->GetMaterialManager()->CreateOpaqueMaterial( LightingModel::Gouraud );
	_materialScreen->SetAmbientColor( Color::White );
	_materialScreen->SetDiffuseColor( Color::White );
	_materialScreen->SetEmissiveColor( Color::White );
	_materialScreen->GetDiffuseMap()->SetImage( _synkro->GetImageManager()->CreateImage(wnd->GetTarget()) );
}

void App::InitScene()
{
	_scene = _synkro->GetSceneManager()->CreateScene( L"Default", DebugMode::None, true );

	// Setup camera.
	_camera = _scene->CreateCamera( nullptr, String::Empty );
	_camera->SetHorizontalFieldOfView( Math::ToRadians(45.0f) );
	_camera->SetAspect( _displayModeWindowed.AspectFactor() );
	_camera->SetPosition( Vector3(0.0f, -900.0f, 0.0f) );
	_camera->SetFront( 0.1f );
	_camera->SetBack( 20000.0f );
	_camera->SetOrientation( Quaternion(Vector3::Y, 0.0f) );

	// Create sky.
	PtrImage imageSky = GetImage( L"Spherical_Panorama_2560px.jpg" );
	_scene->SetSky( imageSky, 10000.0f );
	_day = true;

	// Create materials.
	PtrImage imageCheckers = GetImage( L"checkers.jpg" );
	_materialFloor = _synkro->GetMaterialManager()->CreateOpaqueMaterial( LightingModel::Gouraud );
	_materialFloor->GetDiffuseMap()->SetImage( imageCheckers );
	_materialFloor->SetTilingHorizontal( 8 );
	_materialFloor->SetTilingVertical( 8 );

	// Create floor.
	Matrix4x4 trans;
	constexpr Float FLOOR_SIZE = 2000.0f;
	trans.SetTranslation( Vector3(0.0f, -1000.0f, 0.0f) );
	_floor = _scene->CreateTriangleMesh( nullptr, L"Floor", _materialFloor, nullptr );
	_synkro->GetSceneManager()->BuildMesh( _floor, MeshBuilder::Plane, Vector4(FLOOR_SIZE, FLOOR_SIZE, 0.0f, 0.0f), Size(16, 0), trans );

	// Create light source.
	_light = _scene->CreateDirectLight( nullptr, L"Light" );
	_light->SetAmbientColor( Color::DimGray );
	_light->SetDiffuseColor( Color::White );
	_light->LookAt( Vector3(0.0f, 1.0f, 0.0f) );

	// Create sound source.
	IStream* streamSound = GetStream( L"MusicMono.wav" );
	_sound = _scene->CreateConeSound( nullptr, L"Sound", streamSound );
	_sound->SetPositionY( -1000.0f );
	_sound->SetMinDistance( 100.0f );
	_sound->SetMaxDistance( 1000.0f );
	_sound->SetInnerAngle( Math::ToRadians(45.0f) );
	_sound->SetOuterAngle( Math::ToRadians(45.0f) );
	_sound->LookAt( Vector3(0.0f, 0.0f, -300.0f) );
	_sound->Enable( true );

	// Create TV sets.
	PtrStream streamTV = GetStream( L"Television.obj" );
	_tv = _scene->LoadMesh( streamTV, nullptr, nullptr, TV_COUNT )->AsBatch();

	Matrix4x4 transPosition;
	Matrix4x4 transRotation;
	Matrix4x4 transRotation2;
	Matrix4x4 transRotation3;
	Matrix4x4 transScale;
	transPosition.SetTranslation( Vector3(0.0f, -1000.0f, -950.0f) );
	transRotation.SetOrientation( Vector3::X, Math::ToRadians(-90.0f) );
	_tvSets[0] = _tv->CreateInstance( _floor, transPosition*transRotation, Color::Red );

	transPosition.SetTranslation( Vector3(0.0f, -1000.0f, 950.0f) );
	transRotation.SetOrientation( Vector3::X, Math::ToRadians(-90.0f) );
	transRotation2.SetOrientation( Vector3::Z, Math::ToRadians(180.0f) );
	_tvSets[1] = _tv->CreateInstance( _floor, transPosition*transRotation*transRotation2, Color::Lime );

	transPosition.SetTranslation( Vector3(950.0f, -1000.0f, 0.0f) );
	transRotation.SetOrientation( Vector3::X, Math::ToRadians(-90.0f) );
	transRotation2.SetOrientation( Vector3::Z, Math::ToRadians(-90.0f) );
	_tvSets[2] = _tv->CreateInstance( _floor, transPosition*transRotation*transRotation2, Color::RoyalBlue );

	transPosition.SetTranslation( Vector3(-950.0f, -1000.0f, 0.0f) );
	transRotation.SetOrientation( Vector3::X, Math::ToRadians(-90.0f) );
	transRotation2.SetOrientation( Vector3::Z, Math::ToRadians(90.0f) );
	_tvSets[3] = _tv->CreateInstance( _floor, transPosition*transRotation*transRotation2, Color::Yellow );

	// Create TV screens.
	transScale.SetScale( 0.175f );
	_screen = _scene->CreateTriangleMeshBatch( _materialScreen, nullptr, TV_COUNT );
	_synkro->GetSceneManager()->BuildMesh( _screen, MeshBuilder::Plane, Vector4(280.0f, 495.0f, 0.0f, 0.0f), Size(16, 0), transScale );

	transPosition.SetTranslation( Vector3(0.0f, -958.0f, -948.0f) );
	transRotation.SetOrientation( Vector3::X, Math::ToRadians(90.0f) );
	transRotation2.SetOrientation( Vector3::Y, Math::ToRadians(-90.0f) );
	_screens[0] = _screen->CreateInstance( _floor, transPosition*transRotation*transRotation2, Color::White );

	transPosition.SetTranslation( Vector3(0.0f, -958.0f, 948.0f) );
	transRotation.SetOrientation( Vector3::X, Math::ToRadians(-90.0f) );
	transRotation2.SetOrientation( Vector3::Y, Math::ToRadians(90.0f) );
	_screens[1] = _screen->CreateInstance( _floor, transPosition*transRotation*transRotation2, Color::White );

	transPosition.SetTranslation( Vector3(948.0f, -958.0f, 0.0f) );
	transRotation.SetOrientation( Vector3::Y, Math::ToRadians(180.0f) );
	transRotation2.SetOrientation( Vector3::Z, Math::ToRadians(-90.0f) );
	_screens[2] = _screen->CreateInstance( _floor, transPosition*transRotation*transRotation2, Color::White );

	transPosition.SetTranslation( Vector3(-948.0f, -958.0f, 0.0f) );
	transRotation.SetOrientation( Vector3::Z, Math::ToRadians(-90.0f) );
	_screens[3] = _screen->CreateInstance( _floor, transPosition*transRotation, Color::White );
}

void App::InitView()
{
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
	String help = L"Toggle fullscreen: F\r\nColored/B&W TV: T\r\nDay/Night: D\r\nEnable/disable sound: S\r\nExit: X";
	_txtHints = font->CreateText( Color::Yellow, Point(5, 25), help, Order::Highest, Order::Highest );
	_txtHints->Show( false );
}

void App::InitInput()
{
	_synkro->GetInputSystem()->CreateMouse( 0 );
	_synkro->GetInputSystem()->CreateKeyboard( 0 );
	const Key keys[] = { Key::F1, Key::F, Key::T, Key::D, Key::S, Key::X };
	
	IKeyboardEx* keyboard = _synkro->GetInputSystem()->GetKeyboard( 0 );
	keyboard->ListenKeyUp( this, keys, sizeof(keys)/sizeof(keys[0]) );
	keyboard->ListenKeyDown( this, Key::Up, false );
	keyboard->ListenKeyDown( this, Key::Down, false );
	keyboard->ListenKeyDown( this, Key::Left, false );
	keyboard->ListenKeyDown( this, Key::Right, false );

	IMouseEx* mouse = _synkro->GetInputSystem()->GetMouse( 0 );
	mouse->ListenAxisMove( this, Axis::X );
	mouse->ListenAxisMove( this, Axis::Y );

	_synkro->GetInputSystem()->CreateArcball( mouse, _synkro->GetWindowSystem()->GetFrameWindow(0) );
	_synkro->GetInputSystem()->GetArcball()->ListenZoom( this );
}

void App::InitUi()
{
	const Size szBtn( 150, 25 );
	Int widgetLeft = _window->GetWidth() - szBtn.Width - 5;
	_synkro->GetUi()->Listen( this );

	_btnLoadAnimation = CreateButton( Point(widgetLeft, 10), L"[L]oad Animation", Anchor::TopRight, HotKey(Key::L, true) );
	_btnStartRecording = CreateButton( Point(widgetLeft, 40), L"[R]ecord Animation", Anchor::TopRight, HotKey(Key::R, true) );
	_btnStopRecording = CreateButton( Point(widgetLeft, 70), L"[S]top recording", Anchor::TopRight, HotKey(Key::S, true) );
	_btnStopRecording->Enable( false );
	_btnPlayAnimation = CreateButton( Point(widgetLeft, 100), L"[P]lay Animation", Anchor::TopRight, HotKey(Key::P, true) );
	_btnPlayAnimation->Enable( false );
}

IButton* App::CreateButton( const Point& location, const String& text, const Anchor& anchor, const HotKey& hotkey )
{
	PtrButton button = _synkro->GetUi()->CreateButton( nullptr, none, location, Size(), text, Color::Transparent );
	button->SetAnchor( anchor );
	button->SetHotKey( hotkey );
	return button;
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
