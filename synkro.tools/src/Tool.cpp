//==============================================================================
// This file is a part of the Synkro Project.
// 
// Copyright (c) Nobody. No rights reserved :)
//
// The contents herein is the property of the Mankind.
// Use, distribution and modification of this source code
// is encouraged without any permission from the Synkro Project.
// Website: http://synkro.org Email: mailto:info@synkro.org
//
// Purpose: Defines base GUI tool application.
//==============================================================================
#include "Tool.h"


Tool::Tool( const Char* title, Bool lit ) :
	_synkro( SynkroCreate(SYNKRO_VERSION, this) ),
	_running( true ),
	_lit( lit ),
	_title( title ),
	_orgFov( 10.0f )
{
}

void Tool::Exit()
{
	_running = false;
}

void Tool::Run()
{
	// Create configuration.
	ConfigureInternal();
	Configure( _config );

	// Create main window.
	String mode; _config->Get( Param::GraphicsDisplayMode, &mode );
	_displayMode = DisplayMode( mode, false );
	String title = String::Format( L"{0} - Synkro {1}", _title, Version::Current.ToString() );
	_synkro->GetWindowSystem()->CreateWindow( false, false, title, 0, _displayMode.Width, _displayMode.Height );

	_synkro->Initialize( _config );
	_synkro->Run( _running );
}

void Tool::OnSynkroInitialize()
{
	_scene = _synkro->GetSceneManager()->CreateScene( L"Default", DebugMode::None, _lit );
	InitView();
	InitInput();
	Init();
	InitUiInternal();
}

void Tool::OnSynkroUpdate( Double delta )
{
	// Do nothing.
}

Bool Tool::OnSynkroException( const Exception& ex )
{
	return false;
}

Bool Tool::ListenKeyboardInput() const
{
	return true;
}

Bool Tool::OnKeyboardKeyDown( UInt device, const Key& key, Bool alt, Bool shift, Bool control )
{
	return false;
}

Bool Tool::OnKeyboardKeyUp( UInt device, const Key& key, Bool alt, Bool shift, Bool control )
{
	return false;
}

Bool Tool::OnKeyboardKeyPress( UInt device, Char key )
{
	return true;
}

Bool Tool::ListenArcballInput() const
{
	return true;
}

Bool Tool::OnArcballOriented( const Quaternion& orientation )
{
	return false;
}

Bool Tool::OnArcballZoom( Int delta )
{
	_camera->SetHorizontalFieldOfView( Math::ToRadians(_orgFov -= 0.005f*CastFloat(delta)) );
	return true;
}

Bool Tool::OnUiClick( IWidget* sender )
{
	return false;
}

Bool Tool::OnUiDoubleClick( IWidget* sender )
{
	return false;
}

Bool Tool::OnUiValueChanged( IWidget* sender )
{
	return false;
}

IButton* Tool::CreateButton( const Point& location, const String& text, const Anchor& anchor )
{
	IButton* button = _synkro->GetUi()->CreateButton( nullptr, none, location, Size(), text, Color::Transparent );
	button->SetAnchor( anchor );
	return button;
}

IButton* Tool::CreateButton( const Point& location, const String& text )
{
	return CreateButton( location, text, Anchor::TopRight );
}

IEdit* Tool::CreateEdit( const Point& location, const String& text )
{
	return _synkro->GetUi()->CreateEdit( nullptr, none, location, Size(), text, EditStyle::Normal );
}

ILabel* Tool::CreateLabel( const Point& location, const String& text )
{
	ILabel* label = _synkro->GetUi()->CreateLabel( nullptr, none, location, Size(), text );
	label->SetAnchor( Anchor::TopRight );
	return label;
}

ISlider* Tool::CreateSlider( const Point& location, UInt minPosition, UInt maxPosition, UInt position )
{
	ISlider* slider = _synkro->GetUi()->CreateSlider( nullptr, none, location, Size(), Orientation::Horizontal, minPosition, maxPosition, Color::Transparent );
	slider->SetPosition( position );
	slider->SetAnchor( Anchor::TopRight );
	return slider;
}

ISound2D* Tool::CreateSound( const String& name )
{
	IStream* stream = _synkro->GetStreamSystem()->GetStream( name );
	return CreateSound( stream );
}

ISound2D* Tool::CreateSound( IStream* stream )
{
	_synkro->GetAudioSystem()->CreatePlayer( 0 );
	return _synkro->GetSoundManager()->LoadSound2D( stream );
}

void Tool::ConfigureInternal()
{
	_config = _synkro->GetConfiguration()->Clone();
	_config->Set( Param::AnimationEnable, true );
	_config->Set( Param::CoreThreadPoolCapacity, CastUInt(8) );
	_config->Set( Param::GraphicsSystem, GraphicsSystem::DirectX11 );
	_config->Set( Param::GraphicsDepthFormat, DepthFormat::D32F );
	_config->Set( Param::GraphicsDisplayMode, DisplayMode::GetModeCount()-1 );
	_config->Set( Param::GraphicsFullscreen, false );
	_config->Set( Param::GraphicsProgramCache, String(L"..\\..\\programs") );
	_config->Set( Param::InputEnable, true );
	_config->Set( Param::InputSystem, InputSystem::DirectInput8 );
	_config->Set( Param::UiEnable, true );
	_config->Set( Param::UiThemeName, ThemeName::Flat );
}

void Tool::InitView()
{
	_camera = _scene->CreateCamera( nullptr, String::Empty );
	_camera->SetHorizontalFieldOfView( Math::ToRadians(_orgFov) );
	_camera->SetAspect( _displayMode.AspectFactor() );
	_camera->SetFront( 0.1f );
	_camera->SetBack( 10000.0f );

	_viewport = _synkro->GetViewportManager()->GetViewport( _synkro->GetGraphicsSystem()->GetFrameWindow(0)->GetView(0) );
	_viewport->SetCamera( _camera );
	_viewport->SetColor( Color::DimGray );
}

void Tool::InitUiInternal()
{
	_synkro->GetUi()->Listen( this );
	InitUi( _synkro->GetUi() );
}

void Tool::InitInput()
{
	_synkro->GetInputSystem()->CreateKeyboard( 0 );
	_synkro->GetInputSystem()->CreateMouse( 0 );
	IMouseEx* mouse = _synkro->GetInputSystem()->GetMouse( 0 );
	_synkro->GetInputSystem()->CreateArcball( mouse, _synkro->GetWindowSystem()->GetFrameWindow(0) );
	_synkro->GetInputSystem()->GetArcball()->ListenOrientation( this );
	_synkro->GetInputSystem()->GetArcball()->ListenZoom( this );
}
