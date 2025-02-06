//==============================================================================
// Purpose: Defines base demo application.
//==============================================================================
#include "Demo.h"


Bool Demo::s_editConfig = false;

Demo::Demo( const Char* title ) :
	_synkro( SynkroCreate(SYNKRO_VERSION, this) ),
	_running( true ),
	_title( title ),
	_orgFov( 45.0f )
{
}

void Demo::EditConfig( Bool edit )
{
	s_editConfig = edit;
}

void Demo::Exit()
{
	_running = false;
}

void Demo::Run()
{
	// Create configuration.
	ConfigureInternal();
	Configure( _config );

	// Override user configuration with _DemoConfig.txt, if one is found.
	PtrStream cfg = _synkro->GetStreamSystem()->CreateStream( L"_DemoConfig.txt" );
	if ( cfg->Exists() )
	{
		_config->Load( cfg );
	}

	// Optionally show configuration editor.
	if ( s_editConfig && !_synkro->Configure(_config) )
		return;

	// Create main window.
	String mode; _config->Get( Param::GraphicsDisplayMode, &mode );
	_displayModeWindowed = DisplayMode( mode, false );
	DisplayMode::GetMode( 0, _displayModeFullscreen );
	_displayModeFullscreen.Fullscreen = true;
	String title = String::Format( L"{0} - Synkro {1}", _title, Version::Current.ToString() );
	_synkro->GetWindowSystem()->CreateWindow( false, false, title, 0, _displayModeWindowed.Width, _displayModeWindowed.Height );

	// Initialize and run the application.
	_synkro->Initialize( _config );
	_synkro->Run( _running );
}

DebugMode Demo::GetDebugMode() const
{
	return DebugMode::None;
}

Bool Demo::IsLit() const
{
	return false;
}

void Demo::OnSynkroInitialize()
{
	_window = _synkro->GetGraphicsSystem()->GetFrameWindow( 0 );
	_synkro->GetWindowSystem()->GetFrameWindow( 0 )->Listen( this );
	_scene = _synkro->GetSceneManager()->CreateScene( L"Default", GetDebugMode(), IsLit() );
	CreateShotTexture();
	InitInputInternal();
	InitScene();
	InitViewInternal();
	InitUiInternal();
}

void Demo::OnSynkroUpdate( Double delta )
{
	RenderViewStats viewStats;
	_viewport->GetView()->GetStats( viewStats );

	Double frameTime = 0.0;
	if ( viewStats.FramesPerSecond > 0.0f )
	{
		frameTime = CastDouble( 1000.0/viewStats.FramesPerSecond );
	}

	GraphicsStats stats;
	_synkro->GetGraphicsSystem()->GetStats( stats );
	String s = String::Format( L"Objects: {0}\r\nTriangles: {1}\r\nState changes: {2}\r\nFrame time: {3,0.000} ms\r\nFPS: {4,0.00}", stats.ObjectCount, stats.PrimitiveCount, stats.StateChangeCount, frameTime, viewStats.FramesPerSecond );
	_txtStats->SetText( s );

	if ( _window->GetTarget() != nullptr )
	{
		_window->SetTarget( nullptr );
		PtrStreamDirectory dirShots = _synkro->GetStreamSystem()->BuildDirectory( L"../../shots" );
		_shotStream = dirShots->CreateStream( GetShotName() );
		_shot = _synkro->GetImageManager()->CreateImage( _shotTexture );
		_shot->SaveAsync( _shotStream, PixelFormat::R8G8B8 );
	}
}

Bool Demo::OnSynkroException( const Exception& ex )
{
	return false;
}

Bool Demo::ListenKeyboardInput() const
{
	return true;
}

Bool Demo::OnKeyboardKeyDown( UInt device, const Key& key, Bool alt, Bool shift, Bool control )
{
	if ( key == Key::Escape )
	{
		if ( _poolCreditsCtrl != nullptr )
		{
			_poolCreditsCtrl->Start( false );
		}
		return true;
	}
	return false;
}

Bool Demo::OnKeyboardKeyUp( UInt device, const Key& key, Bool alt, Bool shift, Bool control )
{
	if ( key == Key::F8 )
	{
		_synkro->GetUi()->GetCursor()->Show( false );
		_window->SetTarget( _shotTexture );
		return true;
	}
	return false;
}

Bool Demo::OnKeyboardKeyPress( UInt device, Char key )
{
	return false;
}

Bool Demo::ListenMouseInput() const
{
	return false;
}

Bool Demo::OnMouseClick( UInt device, const MouseButton& buttons )
{
	return false;
}

Bool Demo::OnMouseDoubleClick( UInt device, const MouseButton& buttons )
{
	return false;
}

Bool Demo::OnMouseButtonDown( UInt device, const MouseButton& buttons )
{
	return false;
}

Bool Demo::OnMouseButtonUp( UInt device, const MouseButton& buttons )
{
	return false;
}

Bool Demo::OnMouseAxisMove( UInt device, const Axis& axis, Int delta )
{
	return false;
}

Bool Demo::ListenArcballInput() const
{
	return false;
}

Bool Demo::OnArcballOriented( const Quaternion& orientation )
{
	return false;
}

Bool Demo::OnArcballZoom( Int delta )
{
	_camera->SetHorizontalFieldOfView( Math::ToRadians(_orgFov -= 0.005f*CastFloat(delta)) );
	return true;
}

void Demo::OnAnimationStop( IAnimationController* sender )
{
	if ( sender == _poolCreditsCtrl )
	{
		ShowCredits( false );
	}
}

void Demo::OnAnimationLoop( IAnimationController* sender )
{
	// Do nothing.
}

Bool Demo::OnUiClick( IWidget* sender )
{
	if ( sender == _btnFullscreen )
	{
		ToggleFullscreen();
		return true;
	}
	else if ( sender == _btnCredits )
	{
		CreateCredits();
		ShowCredits( true );
		return true;
	}
	else if ( sender == _btnExit )
	{
		Exit();
		return true;
	}

	return false;
}

Bool Demo::OnUiDoubleClick( IWidget* sender )
{
	return false;
}

Bool Demo::OnUiValueChanged( IWidget* sender )
{
	return false;
}

void Demo::OnWindowResize( UInt window, UInt width, UInt height )
{
	// Do nothing.
}

void Demo::OnWindowCommand( UInt window, UInt command )
{
	// Do nothing.
}

void Demo::OnWindowActivate( UInt window, Bool active )
{
	// Do nothing.
}

Bool Demo::OnWindowClosing( UInt window )
{
	return (_poolCreditsCtrl == nullptr) || (_poolCreditsCtrl->GetState() == ControllerState::Inactive);
}

ITriangleMesh* Demo::CreateTorus( INode* parent, IVisualMaterial* material, Float radiusMinor, Float radiusMajor, UInt ringCount, UInt sideCount, const Matrix4x4& transform, const Vector3& position )
{
	ITriangleMesh* torus = _scene->CreateTriangleMesh( parent, String::Empty, material, nullptr );
	_synkro->GetSceneManager()->BuildMesh( torus, MeshBuilder::Torus, Vector4(radiusMinor, radiusMajor, 0.0f, 0.0f), Size(ringCount, sideCount), transform );
	torus->SetPosition( position );
	return torus;
}

ITriangleMesh* Demo::CreateCone( INode* parent, IVisualMaterial* material, Float radius, Float height, UInt stackCount, UInt sliceCount, const Matrix4x4& transform, const Vector3& position )
{
	ITriangleMesh* cone = _scene->CreateTriangleMesh( parent, String::Empty, material, nullptr );
	_synkro->GetSceneManager()->BuildMesh( cone, MeshBuilder::Cone, Vector4(radius, height, 0.0f, 0.0f), Size(stackCount, sliceCount), transform );
	cone->SetPosition( position );
	return cone;
}

ITriangleMesh* Demo::CreateCylinder( INode* parent, IVisualMaterial* material, Float radius, Float height, UInt stackCount, UInt sliceCount, const Matrix4x4& transform, const Vector3& position )
{
	ITriangleMesh* cylinder = _scene->CreateTriangleMesh( parent, String::Empty, material, nullptr );
	_synkro->GetSceneManager()->BuildMesh( cylinder, MeshBuilder::Cylinder, Vector4(radius, height, 0.0f, 0.0f), Size(stackCount, sliceCount), transform );
	cylinder->SetPosition( position );
	return cylinder;
}

ITriangleMesh* Demo::CreateEllipsoid( INode* parent, IVisualMaterial* material, Float radiusX, Float radiusY, Float radiusZ, UInt stackCount, UInt sliceCount, const Matrix4x4& transform, const Vector3& position )
{
	ITriangleMesh* ellipsoid = _scene->CreateTriangleMesh( parent, String::Empty, material, nullptr );
	_synkro->GetSceneManager()->BuildMesh( ellipsoid, MeshBuilder::Ellipsoid, Vector4(radiusX, radiusY, radiusZ, 0.0f), Size(stackCount, sliceCount), transform );
	ellipsoid->SetPosition( position );
	return ellipsoid;
}

ITriangleMesh* Demo::CreateSphere( INode* parent, IVisualMaterial* material, Float radius, UInt stackCount, UInt sliceCount, const Matrix4x4& transform, const Vector3& position )
{
	return CreateEllipsoid( parent, material, radius, radius, radius, stackCount, sliceCount, transform, position );
}

ITriangleMesh* Demo::CreatePyramid( INode* parent, IVisualMaterial* material, Float width, Float depth, Float height, const Matrix4x4& transform, const Vector3& position )
{
	ITriangleMesh* pyramid = _scene->CreateTriangleMesh( parent, String::Empty, material, nullptr );
	_synkro->GetSceneManager()->BuildMesh( pyramid, MeshBuilder::Pyramid, Vector4(width, depth, height, 0.0f), Size(), transform );
	pyramid->SetPosition( position );
	return pyramid;
}

ITriangleMesh* Demo::CreateBox( INode* parent, IVisualMaterial* material, Float width, Float height, Float depth, const Matrix4x4& transform, const Vector3& position )
{
	ITriangleMesh* box = _scene->CreateTriangleMesh( parent, String::Empty, material, nullptr );
	_synkro->GetSceneManager()->BuildMesh( box, MeshBuilder::Box, Vector4(width, height, depth, 0.0f), Size(), transform );
	box->SetPosition( position );
	return box;
}

ITriangleMesh* Demo::CreateCube( INode* parent, IVisualMaterial* material, Float side, const Matrix4x4& transform, const Vector3& position )
{
	ITriangleMesh* cube = _scene->CreateTriangleMesh( parent, String::Empty, material, nullptr );
	_synkro->GetSceneManager()->BuildMesh( cube, MeshBuilder::Box, Vector4(side, side, side, 0.0f), Size(), transform );
	cube->SetPosition( position );
	return cube;
}

ITriangleMesh* Demo::CreatePlane( INode* parent, IVisualMaterial* material, Float width, Float depth, UInt segmentCount, const Matrix4x4& transform, const Vector3& position )
{
	ITriangleMesh* plane = _scene->CreateTriangleMesh( parent, String::Empty, material, nullptr );
	_synkro->GetSceneManager()->BuildMesh( plane, MeshBuilder::Plane, Vector4(width, depth, 0.0f, 0.0f), Size(segmentCount, 0), transform );
	plane->SetPosition( position );
	return plane;
}

IAngle* Demo::CreateAngle( UInt id, const Point& location, const Color& color )
{
	IAngle* angle = _synkro->GetUi()->CreateAngle( nullptr, id, location, color );
	angle->SetAnchor( Anchor::TopRight );
	return angle;
}

IAngle* Demo::CreateAngle( UInt id, const Point& location )
{
	return CreateAngle( id, location, Color::Transparent );
}

IButton* Demo::CreateButton( UInt id, const Point& location, const String& text, const Anchor& anchor, const HotKey& hotkey, const Color& color )
{
	IButton* button = _synkro->GetUi()->CreateButton( nullptr, id, location, Size(), text, color );
	button->SetAnchor( anchor );
	button->SetHotKey( hotkey );
	return button;
}

IButton* Demo::CreateButton( UInt id, const Point& location, const String& text, const Anchor& anchor, const HotKey& hotkey )
{
	IButton* button = _synkro->GetUi()->CreateButton( nullptr, id, location, Size(), text, Color::Transparent );
	button->SetAnchor( anchor );
	button->SetHotKey( hotkey );
	return button;
}

IButton* Demo::CreateButton( const Point& location, const String& text, const Anchor& anchor, const HotKey& hotkey )
{
	return CreateButton( none, location, text, anchor, hotkey );
}

IButton* Demo::CreateButton( const Point& location, const String& text, const Anchor& anchor )
{
	return CreateButton( location, text, anchor, HotKey::None );
}

IButton* Demo::CreateButton( const Point& location, const String& text )
{
	return CreateButton( location, text, Anchor::TopRight );
}

IEdit* Demo::CreateEdit( const Point& location, const String& text )
{
	return _synkro->GetUi()->CreateEdit( nullptr, none, location, Size(150, 25), text, EditStyle::Normal );
}

ILabel* Demo::CreateLabel( const Point& location, const Size& size, const String& text )
{
	ILabel* label = _synkro->GetUi()->CreateLabel( nullptr, none, location, size, text );
	label->SetAnchor( Anchor::TopRight );
	return label;
}

ILabel* Demo::CreateLabel( const Point& location, const String& text )
{
	return CreateLabel( location, Size(150, 20), text );
}

ISlider* Demo::CreateSlider( UInt id, const Point& location, UInt minPosition, UInt maxPosition, UInt position, const Color& color )
{
	ISlider* slider = _synkro->GetUi()->CreateSlider( nullptr, id, location, Size(150, 20), Orientation::Horizontal, minPosition, maxPosition, color );
	slider->SetPosition( position );
	slider->SetAnchor( Anchor::TopRight );
	return slider;
}

ISlider* Demo::CreateSlider( UInt id, const Point& location, UInt minPosition, UInt maxPosition, UInt position )
{
	return CreateSlider( id, location, minPosition, maxPosition, position, Color::Transparent );
}

IOption* Demo::CreateOption( UInt id, const Point& location, const String& text, Pointer data, Bool selected, const Color& color )
{
	IOption* option = _synkro->GetUi()->CreateOption( nullptr, id, location, Size(150, 20), text, selected, color );
	option->SetData( data );
	option->SetAnchor( Anchor::TopRight );
	return option;
}

IOption* Demo::CreateOption( UInt id, const Point& location, const String& text, Pointer data, Bool selected )
{
	return CreateOption( id, location, text, data, selected, Color::Transparent );
}

ISwitch* Demo::CreateSwitch( UInt id, const Point& location, UInt width, const String& text, Bool on )
{
	ISwitch* sw = _synkro->GetUi()->CreateSwitch( nullptr, id, location, width, text, on, Color::Transparent );
	sw->SetAnchor( Anchor::TopRight );
	return sw;
}

ISwitch* Demo::CreateSwitch( const Point& location, UInt width, const String& text, Bool on )
{
	return CreateSwitch( none, location, width, text, on );
}

IDropList* Demo::CreateDropList( const Point& location, const Size& size )
{
	IDropList* list = _synkro->GetUi()->CreateDropList( nullptr, none, location, size, 0 );
	list->SetAnchor( Anchor::TopRight );
	return list;
}

IImage* Demo::GetImage( const String& name, const PixelFormat& format )
{
	return GetImage( GetStream(name), format );
}

IImage* Demo::GetImage( const String& name )
{
	return GetImage( GetStream(name) );
}

IImage* Demo::GetImage( IStream* stream, const PixelFormat& format )
{
	PixelFormat fmt = format;
	return _synkro->GetImageManager()->LoadImage( stream, fmt );
}

IImage* Demo::GetImage( IStream* stream )
{
	return GetImage( stream, _window->GetClientPixelFormat() );
}

IImage* Demo::GetImage( IStreamSet* streams )
{
	PixelFormat fmt = _window->GetClientPixelFormat();
	return _synkro->GetImageManager()->LoadImageAsync( streams, fmt, nullptr );
}

IStream* Demo::GetStream( const String& name )
{
	IStream* stream = _synkro->GetStreamSystem()->GetStream( name );
	if ( stream == nullptr )
		throw FileNotFoundException( name );
	return stream;
}

IStreamSet* Demo::GetStreams( const String& dirName, const String& pattern )
{
	IStreamDirectory* dir = _synkro->GetStreamSystem()->GetDirectory( dirName );
	if ( dir == nullptr )
		throw FileNotFoundException( dirName );

	IStreamSet* streams = dir->GetStreams( pattern );
	if ( streams->GetSize() == 0 )
		throw Exception( String::Format(L"Directory {0,q} is empty", dirName) );

	return streams;
}

void Demo::ConfigureInternal()
{
	// Find second biggest screen mode with matching aspect.
	DisplayMode displayMode;
	DisplayMode displayModePrimary;
	DisplayMode::GetMode( 0, displayModePrimary );
	const UInt cnt = DisplayMode::GetModeCount( displayModePrimary.AspectRatio );
	DisplayMode::GetMode( cnt > 1 ? 1 : 0, displayModePrimary.AspectRatio, displayMode );

	// Set configuration parameters.
	_config = _synkro->GetConfiguration()->Clone();
	_config->Set( Param::AnimationEnable, true );
	_config->Set( Param::AudioEnable, true );
	_config->Set( Param::AudioSystem, AudioSystem::DirectSound8 );
	_config->Set( Param::CoreThreadPoolCapacity, CastUInt(8) );
	_config->Set( Param::GraphicsDepthFormat, DepthFormat::D32F );
	_config->Set( Param::GraphicsDisplayMode, displayMode.Index() );
	_config->Set( Param::GraphicsFullscreen, false );
	_config->Set( Param::GraphicsProgramCache, String(L"../../programs") );
	_config->Set( Param::GraphicsSampleCount, CastUInt(8) );
	_config->Set( Param::GraphicsVsync, true );
	_config->Set( Param::UiEnable, true );
	_config->Set( Param::UiFontSize, CastUInt(8) );
	_config->Set( Param::UiThemeName, ThemeName::Flat );
	_config->Set( Param::UiColorWidgetNormal, Color::RoyalBlue );
	_config->Set( Param::UiColorTextNormal, Color::White );
	_config->Set( Param::UiColorTextActive, Color::Cyan );
	_config->Set( Param::UiColorTextHovered, Color::Yellow );
	_config->Set( Param::InputEnable, true );
	_config->Set( Param::InputSystem, InputSystem::DirectInput8 );
	_config->Set( Param::LogFileName, String(L"_DemoLog.html") );
	_config->Set( Param::LogFilePlain, false );
	_config->Set( Param::LogFileAppend, false );
	_config->Set( Param::LogLevel, LogLevel::Extensive );
	_config->Set( Param::LogMode, LogMode::All );
	_config->Set( Param::StreamPath, String(L"../../media") );
}

void Demo::InitViewInternal()
{
	_camera = _scene->CreateCamera( nullptr, String::Empty );
	_camera->SetHorizontalFieldOfView( Math::ToRadians(_orgFov) );
	_camera->SetAspect( _displayModeWindowed.AspectFactor() );
	_camera->SetFront( 0.1f );
	_camera->SetBack( 10000.0f );

	_viewport = _synkro->GetViewportManager()->GetViewport( _window->GetView(0) );
	_viewport->SetColor( Color::DirectXDemo );
	InitView();
	if ( _viewport->GetCamera() == nullptr )
	{
		_viewport->SetCamera( _camera );
	}
}

void Demo::InitUiInternal()
{
	DisplayMode displayMode;
	GraphicsDeviceDesc desc;
	_synkro->GetGraphicsSystem()->GetDeviceDesc( 0, desc );
	_synkro->GetOverlayManager()->CreateFont( L"stats", _synkro->GetLanguage(), L"Arial", FontStyle::Bold, 10 );
	_window->GetDisplayMode( displayMode );
	Enum graphicsSystem; _config->Get( Param::GraphicsSystem, &graphicsSystem );
	IFont* font = _synkro->GetOverlayManager()->GetOverlay( _window )->GetFont( L"stats" );
	_txtDevice = font->CreateText( Color::Orange, Point(5, 5), desc.Name.Append(L" (").Append(((GraphicsSystem)graphicsSystem).ToString()).Append(L")"), Order::Highest, Order::Highest );
	_txtDisplayMode = font->CreateText( Color::Orange, Point(5, 22), displayMode.ToString(DisplayModeFormat::Aspect), Order::Highest, Order::Highest );
	_txtStats = font->CreateText( Color::Yellow, Point(5, 42), L"Triangles: 0", Order::Highest, Order::Highest );

	const Size szBtn(150, 25);
	_widgetLeft = _window->GetWidth() - szBtn.Width - 5;
	_btnFullscreen = CreateButton( Point(_widgetLeft, 5), L"Toggle [F]ullscreen", Anchor::TopRight, HotKey(Key::F, true) );
	_btnCredits = CreateButton( Point(_widgetLeft, 35), L"Cre[d]its", Anchor::TopRight, HotKey(Key::D, true) );
	_btnExit = CreateButton( Point(_widgetLeft, 65), L"E[x]it", Anchor::TopRight, HotKey(Key::X, true) );
	_synkro->GetUi()->Listen( this );
	InitUi();
}

void Demo::InitInputInternal()
{
	_synkro->GetInputSystem()->CreateKeyboard( 0 );
	_synkro->GetInputSystem()->GetKeyboard( 0 )->ListenKeyDown( this, Key::Escape, true );
	_synkro->GetInputSystem()->GetKeyboard( 0 )->ListenKeyUp( this, Key::F8 );
	_synkro->GetInputSystem()->CreateMouse( 0 );
	IMouseEx* mouse = _synkro->GetInputSystem()->GetMouse( 0 );
	_synkro->GetInputSystem()->CreateArcball( mouse, _synkro->GetWindowSystem()->GetFrameWindow(0) );
	_synkro->GetInputSystem()->GetArcball()->ListenOrientation( this );
	_synkro->GetInputSystem()->GetArcball()->ListenZoom( this );
	InitInput();
}

void Demo::ToggleFullscreen()
{
	DisplayMode displayMode;
	_window->GetDisplayMode( displayMode );
	displayMode = (displayMode == _displayModeFullscreen) ? _displayModeWindowed : _displayModeFullscreen;
	_txtDisplayMode->SetText( displayMode.ToString(DisplayModeFormat::Aspect) );
	_camera->SetAspect( displayMode.AspectFactor() );
	_window->SetDisplayMode( displayMode );
	CreateShotTexture();
	OnDisplayModeChanged( displayMode );
}

void Demo::CreateCredits()
{
	// Create credits texts.
	String texts[] =
	{
		L"Idea & Programming", L"Eugene O. aka Blindharper", String::Null,
		L"3D Models", L"Microsoft Corporation", String::Null,
		L"Textures", L"Eugene O.", L"Lino Schmid", L"James Hastings-Trew", String::Null,
		L"Special Thanks", L"John R. Stokka",
	};
	const UInt cnt = sizeof(texts)/sizeof(texts[0]);

	const String fontName( L"Credits" );
	const Bool firstTime = (_soundCredits == nullptr);
	if ( firstTime )
	{
		// Load credits sound.
		PtrStream streamSound = GetStream( L"credits.wav" );
		_soundCredits = _synkro->GetSoundManager()->LoadSound2D( streamSound );
		_synkro->GetOverlayManager()->CreateFont( fontName, Language::English, L"Tahoma", FontStyle::Bold, 18 );
	}

	PtrOverlay overlay = _synkro->GetOverlayManager()->GetOverlay( _window );
	_fontCredits = overlay->GetFont( fontName );

	if ( firstTime )
	{
		UInt capacity = 0;
		for ( UInt i = 0; i < cnt; ++i )
		{
			capacity += texts[i].Length();
		}
		_poolCredits = overlay->CreateTextPool( _fontCredits, Order::Low, Order::Low, capacity );
		_poolCredits->SetOffset( Point(0, 0) );
	}

	// Calculate maximum text width.
	UInt maxWidth = 0; Size sz;
	for ( UInt i = 0; i < cnt; ++i )
	{
		String text = texts[i];
		if ( text == String::Null )
			continue;

		_fontCredits->GetTextSize( text, sz );
		if ( sz.Width > maxWidth )
			maxWidth = sz.Width;
	}

	// Fill in text pool.
	Int top = 0; Bool heading = true;
	Int space = 0; UInt s = 0;
	for ( UInt i = 0; i < cnt; ++i )
	{
		String text = texts[i];
		if ( text == String::Null )
		{
			heading = true;
			space = 20;
			++s;
			continue;
		}
		
		_fontCredits->GetTextSize( text, sz );
		top += sz.Height + space;
		if ( firstTime )
			_poolCredits->CreateText( heading ? Color::White : Color::Gray, Point( (maxWidth-sz.Width)/2, top ), text );
		else
			_poolCredits->GetText( i-s )->SetLocation( Point((maxWidth-sz.Width)/2, top) );
		
		if ( heading )
		{
			heading = false;
			space = 2;
		}
	}
	top += 40;

	// Set animation.
	Size szViewport; _viewport->GetSize( szViewport );
	_poolCreditsCtrl = _poolCredits->CreateAnimationController( nullptr, this );
	IKeyframedPointTrack* track = firstTime ? _poolCreditsCtrl->CreateOffsetTrack() : _poolCreditsCtrl->GetAnimation()->GetTrack( 0 )->AsPoint()->AsKeyframed();
	track->Clear();
	track->SetKey( 0.0, Point((szViewport.Width-maxWidth)/2, szViewport.Height) );
	track->SetKey( _soundCredits->GetLength(), Point((szViewport.Width-maxWidth)/2, -top) );
}

void Demo::ShowCredits( Bool show )
{
	if ( show )
		OnCredits( true );

	const UInt cnt = _synkro->GetViewportManager()->GetViewportCount();
	for ( UInt i = 0; i < cnt; ++i )
	{
		_synkro->GetViewportManager()->GetViewport( i )->Show( !show );
	}
	_synkro->GetUi()->Show( !show );

	_txtDevice->Show( !show );
	_txtDisplayMode->Show( !show );
	_txtStats->Show( !show );

	_poolCredits->Enable( show );
	_poolCreditsCtrl->Reset();
	_poolCreditsCtrl->Start( show );
	_soundCredits->Play( show );
	if ( show )
	{
		Size sz; _viewport->GetSize( sz );
		Point offset; _poolCredits->GetOffset( offset );
		offset.Y = sz.Height;
		_poolCredits->SetOffset( offset );
	}

	if ( !show )
		OnCredits( false );
}

void Demo::CreateShotTexture()
{
	_shotTexture = _synkro->GetGraphicsSystem()->GetDevice()->CreateRenderTexture( _window->GetWidth(), _window->GetHeight(), _window->GetPixelFormat(), 1, 0 );
}

String Demo::GetShotName()
{
	const DateTime dt;
	return String::Format( L"shot-{0,R}-{0,u}.jpg", dt );
}
