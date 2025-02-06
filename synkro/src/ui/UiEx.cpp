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
// Purpose: Extended user interface.
//==============================================================================
#include "config.h"
#include "UiEx.h"
#include "Accordion.h"
#include "Angle.h"
#include "Button.h"
#include "DropList.h"
#include "Edit.h"
#include "Label.h"
#include "List.h"
#include "Option.h"
#include "Picture.h"
#include "Progress.h"
#include "Slider.h"
#include "Switch.h"
#include "ThemeReader.h"
#include <gfx/IGraphicsSystemEx.h>
#include <gfx/IGraphicsDeviceEx.h>
#include <gfx/IFrameRenderWindowEx.h>
#include <gfx/IOverlayRenderQueue.h>
#include <gfx/IProgram.h>
#include <gfx/IProgramStage.h>
#include <io/IStreamSystemEx.h>
#include <input/IInputSystemEx.h>
#include <input/IKeyboardEx.h>
#include <input/IMouseEx.h>
#include <img/IImageManager.h>
#include <over/IOverlayManager.h>
#include <io/IStream.h>
#include <io/IStreamDirectory.h>
#include <win/IWindowSystemEx.h>
#include <win/IFrameWindowEx.h>
#include <lang/Stack.h>


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::core;
using namespace synkro::diag;
using namespace synkro::gfx;
using namespace synkro::img;
using namespace synkro::io;
using namespace synkro::input;
using namespace synkro::lang;
using namespace synkro::math;
using namespace synkro::over;
using namespace synkro::win;

//------------------------------------------------------------------------------


// Casts object to IWidget.
#define AsWidget( OBJ ) dynamic_cast<IWidget*>( OBJ )


namespace synkro
{


namespace ui
{


UiEx::UiEx( ILog* log ) :
	_widgetColors( A(Color) ),
	_textColors( A(Color) ),
	_listeners( A(UiListener*) ),
	_themes( A(ThemeEntry) ),
	_factory( nullptr ),
	_window( nullptr ),
	_inputSystem( nullptr ),
	_animationSystem( nullptr ),
	_streamSystem( nullptr ),
	_imageManager( nullptr ),
	_overlayManager( nullptr ),
	_overlay( nullptr ),
	_font( nullptr ),
	_hoveredWidget( nullptr ),
	_activeWidget( nullptr ),
	_downWidget( nullptr ),
	_visible( true ),
	_enabled( true ),
	_deltaTime( 0.0 ),
	_idlePeriod( 0.0 ),
	Logger( log, LogFacility::UserInterface )
{
	LogInfo( MessagePriority::Lowest, Formatter::Format(L"Creating user interface...") );
}

UiEx::~UiEx()
{
	LogInfo( MessagePriority::Lowest, Formatter::Format(L"Destroying user interface...") );
}

Bool UiEx::Update( Double delta )
{
	_deltaTime = delta;

	// Control cursor visibility.
	constexpr Double IDLE_PERIOD = 10.0;
	_idlePeriod += delta;
	_cursor->Show( _visible && (_idlePeriod < IDLE_PERIOD) );

	// Re-apply theme if it's changed.
	if ( _theme->IsDirty() )
	{
		SetTheme( _theme );
		_theme->Validate();
	}

	// Update underlying UI.
	return _ui->Update( delta );
}

IFrame* UiEx::CreateFrame( IFrame* parent, UInt id, const Point& location, const Size& size, Bool showBorder )
{
	Frame* frameParent = GetParentFrame( parent );
	return new Frame( id, frameParent, _ui->CreateFrame(frameParent->GetInnerFrame(), none, location, GetSize(size, Size(100, 100)), showBorder) );
}

IAccordion* UiEx::CreateAccordion( IFrame* parent, UInt id, const Point& location, const Size& size )
{
	Frame* frameParent = GetParentFrame( parent );
	return new Accordion( this, id, frameParent, _ui->CreateAccordion(frameParent->GetInnerFrame(), none, location, size) );
}

IAngle* UiEx::CreateAngle( IFrame* parent, UInt id, const Point& location, const Color& color )
{
	Frame* frameParent = GetParentFrame( parent );
	return new Angle( this, id, frameParent, _ui->CreateAngle(frameParent->GetInnerFrame(), none, location, color) );
}

IButton* UiEx::CreateButton( IFrame* parent, UInt id, const Point& location, const Size& size, const String& text, const Color& color )
{
	Frame* frameParent = GetParentFrame( parent );
	return new Button( this, id, frameParent, _ui->CreateButton(frameParent->GetInnerFrame(), none, location, GetSize(size, Size(150, 25)), text, color) );
}

IDropList* UiEx::CreateDropList( IFrame* parent, UInt id, const Point& location, const Size& size, UInt capacity )
{
	Frame* frameParent = GetParentFrame( parent );
	return new DropList( this, id, frameParent, _ui->CreateDropList(frameParent->GetInnerFrame(), none, location, GetSize(size, Size(200, 25)), capacity) );
}

IEdit* UiEx::CreateEdit( IFrame* parent, UInt id, const Point& location, const Size& size, const String& text, const EditStyle& style )
{
	Frame* frameParent = GetParentFrame( parent );
	return new Edit( this, id, frameParent, _ui->CreateEdit(frameParent->GetInnerFrame(), none, location, GetSize(size, Size(200, 25)), text, style), style );
}

IList* UiEx::CreateList( IFrame* parent, UInt id, const Point& location, const Size& size, UInt capacity )
{
	Frame* frameParent = GetParentFrame( parent );
	return new List( this, id, frameParent, _ui->CreateList(frameParent->GetInnerFrame(), none, location, GetSize(size, Size(100, 200)), capacity) );
}

IOption* UiEx::CreateOption( IFrame* parent, UInt id, const Point& location, const Size& size, const String& text, Bool selected, const Color& color )
{
	Frame* frameParent = GetParentFrame( parent );
	return new Option( this, id, frameParent, _ui->CreateOption(frameParent->GetInnerFrame(), none, location, GetSize(size, Size(150, 25)), text, selected, color), selected );
}

IProgress* UiEx::CreateProgress( IFrame* parent, UInt id, const Point& location, const Size& size, const ProgressType& type, const Color& color )
{
	Frame* frameParent = GetParentFrame( parent );
	return new Progress( this, id, frameParent, _ui->CreateProgress(frameParent->GetInnerFrame(), none, location, GetSize(size, Size(100, 20)), type, color) );
}

ISlider* UiEx::CreateSlider( IFrame* parent, UInt id, const Point& location, const Size& size, const Orientation& orientation, UInt minPosition, UInt maxPosition, const Color& color )
{
	assert( minPosition <= maxPosition );

	if ( minPosition > maxPosition )
		throw BadArgumentException( L"Minimum position cannot be greater than the maximum one.", L"minPosition" );

	Frame* frameParent = GetParentFrame( parent );
	return new Slider( this, id, frameParent, _ui->CreateSlider(frameParent->GetInnerFrame(), none, location, GetSize(size, Size(150, 25)), orientation, minPosition, maxPosition, color) );
}

ISwitch* UiEx::CreateSwitch( IFrame* parent, UInt id, const Point& location, UInt width, const String& text, Bool on, const Color& color )
{
	Frame* frameParent = GetParentFrame( parent );
	return new Switch( this, id, frameParent, _ui->CreateSwitch(frameParent->GetInnerFrame(), none, location, width, text, on, color), on );
}

void UiEx::Show( Bool show )
{
	_visible = show;
	_root->Show( show );
	_cursor->Show( show );
}

void UiEx::Enable( Bool enable )
{
	_enabled = enable;
	if ( !enable )
	{
		_downWidget = nullptr;
		_hoveredWidget = nullptr;
	}
	if ( _activeWidget != nullptr )
	{
		AsWidget(_activeWidget)->Activate( enable );
	}
	_cursor->Show( enable );
}

void UiEx::SetThemeName( const ThemeName& theme )
{
	_themeName = theme;

	if ( !_themes.ContainsKey(_themeName) )
		throw Exception( String::Format(L"Failed to set user interface theme. Unknown theme: {0,q}.", _themeName.ToString()) );

	// Prepare theme.
	_theme = _themes[_themeName];
	_theme->Prepare();

	if ( _ui != nullptr )
	{
		SetTheme( _theme );
	}

	// Apply colors.
	for ( UInt i = 0; i < _widgetColors.Size(); ++i )
	{
		WidgetState state( i );
		_theme->SetWidgetColor( state, _widgetColors[i] );
		_theme->SetTextColor( state, _textColors[i] );
	}
}

void UiEx::Listen( UiListener* listener )
{
	assert( listener != nullptr );

	if ( !_listeners.Contains(listener) )
	{
		_listeners.Add( listener );
	}
}

void UiEx::Load( IStream* stream )
{
	Stack<IFrame*> parents( A(IFrame*) );
	UiReader rd( stream, _window->GetWidth(), _window->GetHeight() );
	while ( rd.Read() )
	{
		IFrame* parent = (parents.Size() > 0) ? parents.Top() : nullptr;
		if ( rd.GetType() == WIDGET_FRAME )
		{
			if ( rd.IsStart() )
			{
				IAccordion* accordion = (parent != nullptr) ? parent->AsAccordion() : nullptr;
				if ( accordion != nullptr )
				{
					IFrame* panel = accordion->CreatePanel( rd.GetString(L"caption") );
					parents.Push( panel );
				}
				else
				{
					parent = CreateFrame( parent, rd.GetID(), rd.GetLocation(), rd.GetSize(), rd.GetBool("border") );
					parents.Push( parent );
				}
			}
			else
			{
				parents.Pop();
			}
		}
		if ( rd.GetType() == WIDGET_ACCORDION )
		{
			if ( rd.IsStart() )
			{
				parent = CreateAccordion( parent, rd.GetID(), rd.GetLocation(), rd.GetSize() );
				parent->SetAnchor( rd.GetAnchor() );
				parents.Push( parent );
			}
			else
			{
				parents.Pop();
			}
		}
		else if ( rd.GetType() != WIDGET_NONE )
		{
			CreateWidget( parent, rd );
		}
	}
}

ILabel* UiEx::CreateLabel( IFrame* parent, UInt id, const Point& location, const Size& size, const String& text )
{
	Frame* frameParent = GetParentFrame( parent );
	return new Label( this, frameParent, id, location, GetSize(size, Size(150, 25)), text );
}

IPicture* UiEx::CreatePicture( IFrame* parent, UInt id, const Point& location, const Size& size, IImage* image )
{
	Frame* frameParent = GetParentFrame( parent );
	return new Picture( this, frameParent, id, location, GetSize(size, Size(100, 100)), image );
}

IFrame* UiEx::GetFrame( UInt id ) const
{
	return (id != none) ? FindFrame( _root, id ) : nullptr;
}

IWidget* UiEx::GetWidget( UInt id ) const
{
	return (id != none) ? FindWidget( _root, id ) : nullptr;
}

Bool UiEx::ListenKeyboardInput() const
{
	return _visible && _enabled;
}

Bool UiEx::OnKeyboardKeyDown( UInt device, const Key& key, Bool alt, Bool shift, Bool control )
{
	InputDetected();

	if ( key == Key::Tab )
	{
		MoveFocus( !shift );
		return true;
	}

	if ( _activeWidget != nullptr )
	{
		IWidget* widget = AsWidget( _activeWidget );
		if ( widget->IsEnabled() )
		{
			const UiEvent event = _activeWidget->OnKeyDown( _deltaTime, key, alt, shift, control );
			FireEvent( event, _activeWidget );
		}
		return true;
	}

	return false;
}

Bool UiEx::OnKeyboardKeyUp( UInt device, const Key& key, Bool alt, Bool shift, Bool control )
{
	InputDetected();

	if ( key != Key::Space )
	{
		const HotKey hotkey( key, control, shift, alt );
		if ( HandleHotkey(_root, hotkey) )
			return true;
	}

	if ( _activeWidget != nullptr )
	{
		IWidget* widget = AsWidget( _activeWidget );
		if ( widget->IsEnabled() )
		{
			const UiEvent event = _activeWidget->OnKeyUp( key, alt, shift, control );
			FireEvent( event, _activeWidget );
		}
		return true;
	}

	return false;
}

Bool UiEx::OnKeyboardKeyPress( UInt device, Char key )
{
	InputDetected();

	if ( _activeWidget != nullptr )
	{
		IWidget* widget = AsWidget( _activeWidget );
		if ( widget->IsEnabled() )
		{
			const UiEvent event = _activeWidget->OnKeyPress( key );
			FireEvent( event, _activeWidget );
		}
		return true;
	}

	return false;
}

Bool UiEx::ListenMouseInput() const
{
	return _visible && _enabled;
}

Bool UiEx::OnMouseClick( UInt device, const MouseButton& buttons )
{
	InputDetected();
	if ( buttons.IsSet(MouseButton::Left) && (_hoveredWidget != nullptr) )
	{
		Activate( _hoveredWidget );
		Point loc; _cursor->GetLocation( loc );
		const UiEvent event = _activeWidget->OnMouseClick( loc );
		FireEvent( event, _activeWidget );
		return true;
	}
	return false;
}

Bool UiEx::OnMouseDoubleClick( UInt device, const MouseButton& buttons )
{
	InputDetected();
	if ( buttons.IsSet(MouseButton::Left) && (_hoveredWidget != nullptr) )
	{
		Activate( _hoveredWidget );
		_downWidget = _hoveredWidget;
		Point loc; _cursor->GetLocation( loc );
		const UiEvent event = _activeWidget->OnMouseDoubleClick( loc );
		FireEvent( event, _activeWidget );
		return true;
	}
	return false;
}

Bool UiEx::OnMouseButtonDown( UInt device, const MouseButton& buttons )
{
	InputDetected();
	if ( buttons.IsSet(MouseButton::Left) && (_hoveredWidget != nullptr) )
	{
		Point loc; _cursor->GetLocation( loc );
		_downWidget = _hoveredWidget;
		const UiEvent event = _downWidget->OnMouseDown( loc );
		FireEvent( event, _downWidget );
		Activate( _downWidget );
		return true;
	}

	ActivateWidget( nullptr );
	return false;
}

Bool UiEx::OnMouseButtonUp( UInt device, const MouseButton& buttons )
{
	InputDetected();
	if ( buttons.IsSet(MouseButton::Left) )
	{
		if ( _downWidget != nullptr )
		{
			const UiEvent event = _downWidget->OnMouseUp();
			FireEvent( event, _downWidget );
			_downWidget = nullptr;
			return true;
		}
	}
	return false;
}

Bool UiEx::OnMouseAxisMove( UInt device, const Axis& axis, Int delta )
{
	InputDetected();
	Point loc;
	if ( axis != Axis::Z )
	{
		// Reposition cursor.
		_cursor->GetLocation( loc );
		if ( axis == Axis::X )
		{
			loc.X = Clamp<Int>( loc.X+delta, 0L, _window->GetWidth()-1 );
		}
		else if ( axis == Axis::Y )
		{
			loc.Y = Clamp<Int>( loc.Y+delta, 0L, _window->GetHeight()-1 );
		}
		_cursor->SetLocation( loc );

		// Send events.
		BaseWidget* oldHoveredWidget = _hoveredWidget;
		_hoveredWidget = GetWidgetAt( loc );
		if ( (oldHoveredWidget != _hoveredWidget) && (oldHoveredWidget != nullptr) )
		{
			oldHoveredWidget->OnMouseMove( loc );
			oldHoveredWidget->OnMouseLeave();
		}
		if ( (oldHoveredWidget != _hoveredWidget) && (_hoveredWidget != nullptr) )
		{
			_hoveredWidget->OnMouseEnter();
			_hoveredWidget->OnMouseMove( loc );
		}
	}
	if ( _activeWidget != nullptr )
	{
		const UiEvent event = (axis == Axis::Z) ? _activeWidget->OnMouseScroll( delta ) : _activeWidget->OnMouseMove( loc );
		FireEvent( event, _activeWidget );
		return true;
	}
	return false;
}

void UiEx::OnWindowResize( UInt window, UInt width, UInt height )
{
	Size size; _root->GetSize( size );
	Point loc; _cursor->GetLocation( loc );
	_root->SetSize( Size(width, height) );
	const Point newLoc( CastFloat(loc.X)/CastFloat(size.Width)*CastFloat(width), CastFloat(loc.Y)/CastFloat(size.Height)*CastFloat(height) );
	_cursor->SetLocation( newLoc );
}

void UiEx::OnWindowCommand( UInt window, UInt command )
{
	// Do nothing.
}

void UiEx::OnWindowActivate( UInt window, Bool active )
{
	// Do nothing.
}

Bool UiEx::OnWindowClosing( UInt window )
{
	return true;
}

IOverlayRenderObject* UiEx::CreateObject( const PrimitiveType& type, const IndexType& indexType, UInt vertexCount, UInt indexCount, UInt order )
{
	IPrimitive* data = _graphicsSystem->GetDevice()->CreatePrimitive( _theme->GetProgram(), DataUsage::Dynamic, DataAccess::WriteOnly, type, indexType, vertexCount, indexCount, 0, 0, true, false );
	IOverlayRenderObject* obj = _graphicsSystem->GetFrameWindow(0)->GetOverlayQueue()->CreateObject( data );
	obj->SetOrder( order );
	obj->SetBlendStates( _blendStates );
	obj->SetFragmentResources( _theme->GetResources() );
	IParameterSet* params = _theme->GetProgram()->GetFragmentStage()->GetParameters()->Clone( obj->ID(), true );
	obj->SetFragmentParameters( params );
	return obj;
}

void UiEx::ActivateWidget( BaseWidget* widget )
{
	if ( (_activeWidget != nullptr) && (_activeWidget != widget) )
	{
		AsWidget(_activeWidget)->Activate( false );
	}
	_activeWidget = widget;
}

void UiEx::RegisterHotKey( const HotKey& hotkey )
{
	if ( hotkey.Key != Key::Unknown )
	{
		_inputSystem->GetKeyboard( 0 )->ListenKeyUp( this, hotkey.Key );
	}
}

void UiEx::ListenKeyDown( const Key* keys, UInt count, Bool discrete )
{
	_inputSystem->GetKeyboard( 0 )->ListenKeyDown( this, keys, count, discrete );
}

void UiEx::ListenKeyDown( const Key& key, Bool discrete )
{
	_inputSystem->GetKeyboard( 0 )->ListenKeyDown( this, key, discrete );
}

void UiEx::ListenKeyUp( const Key* keys, UInt count )
{
	_inputSystem->GetKeyboard( 0 )->ListenKeyUp( this, keys, count );
}

void UiEx::ListenKeyUp( const Key& key )
{
	_inputSystem->GetKeyboard( 0 )->ListenKeyUp( this, key );
}

void UiEx::ListenKeyPress()
{
	_inputSystem->GetKeyboard( 0 )->ListenKeyPress( this );
}

void UiEx::ListenMouseDoubleClick( const MouseButton& buttons )
{
	_inputSystem->GetMouse( 0 )->ListenDoubleClick( this, buttons );
}

void UiEx::ListenMouseAxisMove( const Axis& axis )
{
	_inputSystem->GetMouse( 0 )->ListenAxisMove( this, axis );
}

void UiEx::FireEvent( UiEvent event, BaseWidget* widget )
{
	IWidget* sender = AsWidget( widget );
	switch ( event )
	{
		case UI_EVENT_CLICK:
			FireClickEvent( sender );
			break;

		case UI_EVENT_DOUBLE_CLICK:
			FireDoubleClickEvent( sender );
			break;

		case UI_EVENT_VALUE_CHANGED:
			FireValueChangedEvent( sender );
			break;
	}
}

void UiEx::DoListen( UiListener* listener )
{
	Listen( listener );
}

ISprite* UiEx::CreateSprite( IImage* image, const Point& location, const Size& size )
{
	return _overlay->CreateSprite( image, location, size );
}

IQuad* UiEx::CreateQuad( const over::Order& groupOrder, const Order& order, const Point& location, const Size& size, const Color& color )
{
	return _overlay->CreateQuad( groupOrder, order, location, size, color );
}

void UiEx::Activate( BaseWidget* widget )
{
	AsWidget(widget)->Activate( true );
}

void UiEx::Initialize( IUiFactory* factory, IContext* context, const Language& language, UInt fontSize )
{
	_context = context;
	_graphicsSystem = context->GetGraphicsSystem();
	_inputSystem = context->GetInputSystem();
	_animationSystem = context->GetAnimationSystem();
	_streamSystem = context->GetStreamSystem();
	_imageManager = context->GetImageManager();
	_overlayManager = context->GetOverlayManager();

	// Create UI font.
	const String FONT_NAME( L"ui" );
	if ( _font == nullptr )
	{
		_overlayManager->CreateFont( FONT_NAME, language, L"Arial", FontStyle::Normal, fontSize );
	}

	if ( factory != _factory )
	{
		_factory = factory;
		_ui = nullptr;
		_program = _graphicsSystem->GetProgram( L"overlay.textured" );
		_window = context->GetWindowSystem()->GetFrameWindow( 0 );
		IRenderWindow* renderWindow = (IRenderWindow*)(IFrameRenderWindow*)_graphicsSystem->GetFrameWindow( 0 );
		_pixelFormat = renderWindow->GetClientPixelFormat();
		_overlay = _overlayManager->GetOverlay( renderWindow );
		_font = _overlay->GetFont( FONT_NAME );
		_blendStates = _graphicsSystem->GetDevice()->GetBlendStates()->Clone();
		_blendStates->Get( 0 )->Enable( true );
		_blendStates->Get( 0 )->SetSrcMode( BlendMode::SrcAlpha );
		_blendStates->Get( 0 )->SetDstMode( BlendMode::InvSrcAlpha );

		_inputSystem->CreateKeyboard( 0 );
		_inputSystem->CreateMouse( 0 );
		_window->Listen( this );
	}
}

void UiEx::Finalize()
{
	_ui = nullptr;
	_factory = nullptr;
}

void UiEx::InitInput()
{
	IKeyboardEx* keyboard = _inputSystem->GetKeyboard( 0 );
	keyboard->ListenKeyDown( this, Key::Tab, true );

	IMouseEx* mouse = _inputSystem->GetMouse( 0 );
	mouse->ListenAxisMove( this, Axis::X );
	mouse->ListenAxisMove( this, Axis::Y );
	mouse->ListenButtonDown( this, MouseButton::Left );
	mouse->ListenButtonUp( this, MouseButton::Left );
	mouse->ListenClick( this, MouseButton::Left );	
}

void UiEx::Create( const ThemeName& themeName, const Color* widgetColors, const Color* textColors, UInt count )
{
	_widgetColors.Clear();
	_textColors.Clear();
	_widgetColors.Add( widgetColors, count );
	_textColors.Add( textColors, count );
	SetThemeName( themeName );
	_ui = _factory->Create( _context, _theme, _log );
	_root = new Frame( none, nullptr, _ui->CreateFrame(nullptr, none, Point(0, 0), Size(_window->GetWidth(), _window->GetHeight()), false) );
	_cursor = new Cursor( this );
	_cursor->SetLocation( Point(_window->GetWidth()/2, _window->GetHeight()/2) );
}

BaseWidget* UiEx::FindWidgetAt( IFrame* frame, const Point& location ) const
{
	Rect rect;
	for ( UInt i = 0; i < frame->GetWidgetCount(); ++i )
	{
		IWidget* child = frame->GetWidget( i );
		if ( child->IsVisible() && child->IsEnabled() )
		{
			child->GetVisibleRect( rect );
			if ( rect.IsInside(location) )
				return AsBaseWidget( child );
		}
	}

	for ( UInt i = 0; i < frame->GetFrameCount(); ++i )
	{
		IFrame* child = frame->GetFrame( i );
		BaseWidget* widget = FindWidgetAt( child, location );
		if ( widget != nullptr )
			return widget;
	}

	return nullptr;
}

BaseWidget* UiEx::GetWidgetAt( const Point& location ) const
{
	return FindWidgetAt( _root, location );
}

void UiEx::AddThemeLibrary( IStreamDirectory* dir )
{
	ThemeReader rd( dir );
	while ( rd.Read() )
	{
		const ThemeName themeName( rd.GetName() );
		if ( !_themes.ContainsKey(themeName) )
		{
			P(IImage) image = LoadThemeImage( dir, rd.GetImage(), rd.GetAlpha() );
			_themes[themeName] = new Theme( rd, image, _program );
		}
	}
}

void UiEx::InputDetected()
{
	if ( _visible )
	{
		_idlePeriod = 0.0;
	}
}

void UiEx::MoveFocus( Bool forward )
{	
	IWidget* current = AsWidget( _activeWidget );
	IWidget* focus = forward ? _root->GetNextWidget( current ) : _root->GetPrevWidget( current );
	if ( focus == nullptr )
	{
		focus = forward ? _root->GetNextWidget( nullptr ) : _root->GetPrevWidget( nullptr );
	}
	if ( focus != nullptr )
	{
		focus->Activate( true );
	}
}

void UiEx::FireClickEvent( IWidget* sender )
{
	for ( UInt i = 0; i < _listeners.Size(); ++i )
	{
		if ( _listeners[i]->OnUiClick(sender) )
			break;
	}
}

void UiEx::FireDoubleClickEvent( IWidget* sender )
{
	for ( UInt i = 0; i < _listeners.Size(); ++i )
	{
		if ( _listeners[i]->OnUiDoubleClick(sender) )
			break;
	}
}

void UiEx::FireValueChangedEvent( IWidget* sender )
{
	for ( UInt i = 0; i < _listeners.Size(); ++i )
	{
		if ( _listeners[i]->OnUiValueChanged(sender) )
			break;
	}
}

Bool UiEx::HandleHotkey( IFrame* frame, const HotKey& hotkey )
{
	for ( UInt i = 0; i < frame->GetWidgetCount(); ++i )
	{
		IWidget* child = frame->GetWidget( i );
		if ( child->IsVisible() && child->IsEnabled() )
		{
			BaseWidget* widget = AsBaseWidget( child );
			if ( widget != nullptr )
			{
				const UiEvent event = widget->OnHotKey( hotkey );
				if ( event != UI_EVENT_NONE )
				{
					FireEvent( event, widget );
					return true;
				}
			}
		}
	}

	for ( UInt i = 0; i < frame->GetFrameCount(); ++i )
	{
		IFrame* child = frame->GetFrame( i );
		if ( HandleHotkey(child, hotkey) )
			return true;
	}

	return false;
}

IFrame* UiEx::FindFrame( IFrame* frame, UInt id ) const
{
	if ( frame->ID() == id )
		return frame;

	for ( UInt i = 0; i < frame->GetFrameCount(); ++i )
	{
		IFrame* child = FindFrame( frame->GetFrame(i), id );
		if ( child != nullptr )
			return child;
	}

	return nullptr;
}

IWidget* UiEx::FindWidget( IFrame* frame, UInt id ) const
{
	for ( UInt i = 0; i < frame->GetWidgetCount(); ++i )
	{
		IWidget* child = frame->GetWidget( i );
		if ( child->ID() == id )
			return child;
	}

	for ( UInt i = 0; i < frame->GetFrameCount(); ++i )
	{
		IFrame* child = frame->GetFrame( i );
		IWidget* widget = FindWidget( child, id );
		if ( widget != nullptr )
			return widget;
	}

	return nullptr;
}

IImage* UiEx::LoadThemeImage( IStreamDirectory* dir, const String& imageName, const String& alphaName ) const
{
	IImage* image = nullptr;

	IStream* streamColor = dir->GetStream( imageName );
	if ( streamColor != nullptr )
	{
		image = _imageManager->LoadImage( streamColor, _pixelFormat );
		IStream* streamAlpha = dir->GetStream( alphaName );
		if ( streamAlpha != nullptr )
		{
			PixelFormat pixelFormat = PixelFormat::A8;
			IImage* alpha = _imageManager->LoadImage( streamAlpha, pixelFormat );
			image->SetAlpha( alpha );
		}
		else
		{
			image->SetTransparentColor();
		}
	}

	return image;
}

Size UiEx::GetSize( const Size& size, const Size& defaultSize ) const
{
	return size.IsEmpty() ? defaultSize : size;
}

void UiEx::CreateWidget( IFrame* parent, UiReader& rd )
{
	const WidgetType type = rd.GetType();
	const UInt id = rd.GetID();
	const Point location = rd.GetLocation();
	const Size size = rd.GetSize();
	const String text = rd.GetText();
	const Color color = rd.GetColor();
	const Anchor anchor = rd.GetAnchor();
	const HotKey hotkey = rd.GetHotKey();
	const Pointer data = rd.GetData();
	IWidget* widget = nullptr;
	IImage* picture = nullptr;

	if ( type == WIDGET_PICTURE )
	{
		const String image = rd.GetString( L"image" );
		IStream* streamImage = !image.IsNullOrEmpty() ? _streamSystem->GetStream( image ) : nullptr;
		if ( streamImage != nullptr )
		{
			picture = _imageManager->LoadImage( streamImage, _pixelFormat );
		}
	}

	switch ( type )
	{
		case WIDGET_ANGLE:		widget = CreateAngle( parent, id, location, color ); break;
		case WIDGET_BUTTON:		widget = CreateButton( parent, id, location, size, text, color ); break;
		case WIDGET_DROPLIST:	widget = CreateDropList( parent, id, location, size, rd.GetUInt(L"capacity") ); break;
		case WIDGET_EDIT:		widget = CreateEdit( parent, id, location, size, text, rd.GetEditStyle() ); break;
		case WIDGET_LABEL:		widget = CreateLabel( parent, id, location, size, text ); break;
		case WIDGET_LIST:		widget = CreateList( parent, id, location, size, rd.GetUInt(L"capacity") ); break;
		case WIDGET_OPTION:		widget = CreateOption( parent, id, location, size, text, rd.GetBool(L"selected"), color ); break;
		case WIDGET_PICTURE:	widget = CreatePicture( parent, id, location, size, picture ); break;
		case WIDGET_PROGRESS:	widget = CreateProgress( parent, id, location, size, rd.GetProgressType(), color ); break;
		case WIDGET_SLIDER:		widget = CreateSlider( parent, id, location, size, rd.GetOrientation(), rd.GetUInt(L"min"), rd.GetUInt(L"max"), color ); break;
		case WIDGET_SWITCH:		widget = CreateSwitch( parent, id, location, size.Width, text, rd.GetBool(L"on"), color ); break;
	}

	if ( widget != nullptr )
	{
		widget->SetAnchor( anchor );
		widget->SetHotKey( hotkey );
		widget->SetData( data );
	}
}


} // ui


} // synkro
