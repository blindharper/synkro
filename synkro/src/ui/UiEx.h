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
#ifndef _SYNKRO_UI_UIEX_
#define _SYNKRO_UI_UIEX_


#include "config.h"
#include <core/ObjectImpl.h>
#include <core/IContext.h>
#include <ui/IUiFactory.h>
#include <ui/IUiEx.h>
#include <ui/UiListener.h>
#include <gfx/IBlendStateSet.h>
#include <gfx/IBlendState.h>
#include <input/KeyboardListener.h>
#include <input/MouseListener.h>
#include <win/WindowListener.h>
#include <lang/Formatter.h>
#include <lang/Vector.h>
#include <lang/Map.h>
#include "BaseUiEx.h"
#include "Cursor.h"
#include "Frame.h"
#include "Theme.h"
#include "UiReader.h"


namespace synkro
{


namespace ui
{


// Extended user interface.
class UiEx :
	public core::ObjectImpl<IUiEx>,
	public input::KeyboardListener,
	public input::MouseListener,
	public win::WindowListener,
	public BaseUiEx,
	public Logger
{
public:
	// Constructor & destructor.
	UiEx( diag::ILog* log );
	~UiEx();

	// ISystem methods.
	Bool													Update( Double delta );

	// IUi methods.
	IFrame*													CreateFrame( IFrame* parent, UInt id, const lang::Point& location, const lang::Size& size, Bool showBorder );
	IAccordion*												CreateAccordion( IFrame* parent, UInt id, const lang::Point& location, const lang::Size& size );
	IAngle*													CreateAngle( IFrame* parent, UInt id, const lang::Point& location, const img::Color& color );
	IButton*												CreateButton( IFrame* parent, UInt id, const lang::Point& location, const lang::Size& size, const lang::String& text, const img::Color& color );
	IDropList*												CreateDropList( IFrame* parent, UInt id, const lang::Point& location, const lang::Size& size, UInt capacity );
	IEdit*													CreateEdit( IFrame* parent, UInt id, const lang::Point& location, const lang::Size& size, const lang::String& text, const EditStyle& style );
	IList*													CreateList( IFrame* parent, UInt id, const lang::Point& location, const lang::Size& size, UInt capacity );
	IOption*												CreateOption( IFrame* parent, UInt id, const lang::Point& location, const lang::Size& size, const lang::String& text, Bool selected, const img::Color& color );
	IProgress*												CreateProgress( IFrame* parent, UInt id, const lang::Point& location, const lang::Size& size, const ProgressType& type, const img::Color& color );
	ISlider*												CreateSlider( IFrame* parent, UInt id, const lang::Point& location, const lang::Size& size, const Orientation& orientation, UInt minPosition, UInt maxPosition, const img::Color& color );
	ISwitch*												CreateSwitch( IFrame* parent, UInt id, const lang::Point& location, UInt width, const lang::String& text, Bool on, const img::Color& color );
	void													SetTheme( ITheme* theme );
	void													SetBackColor( const img::Color& color );
	ITheme*													GetTheme() const;
	void													GetBackColor( img::Color& color ) const;

	// IUiEx methods.
	void													Show( Bool show );
	void													Enable( Bool enable );
	void													SetThemeName( const ThemeName& theme );
	void													Listen( UiListener* listener );
	void													Load( io::IStream* stream );
	ILabel*													CreateLabel( IFrame* parent, UInt id, const lang::Point& location, const lang::Size& size, const lang::String& text );
	IPicture*												CreatePicture( IFrame* parent, UInt id, const lang::Point& location, const lang::Size& size, img::IImage* image );
	IFrame*													GetFrame( UInt id ) const;
	IWidget*												GetWidget( UInt id ) const;
	ICursor*												GetCursor() const;
	ThemeName												GetThemeName() const;
	Bool													IsVisible() const;
	Bool													IsEnabled() const;

	// KeyboardListener methods.
	Bool													ListenKeyboardInput() const;
	Bool													OnKeyboardKeyDown( UInt device, const input::Key& key, Bool alt, Bool shift, Bool control );
	Bool													OnKeyboardKeyUp( UInt device, const input::Key& key, Bool alt, Bool shift, Bool control );
	Bool													OnKeyboardKeyPress( UInt device, Char key );

	// MouseListener methods.
	Bool													ListenMouseInput() const;
	Bool													OnMouseClick( UInt device, const input::MouseButton& buttons );
	Bool													OnMouseDoubleClick( UInt device, const input::MouseButton& buttons );
	Bool													OnMouseButtonDown( UInt device, const input::MouseButton& buttons );
	Bool													OnMouseButtonUp( UInt device, const input::MouseButton& buttons );
	Bool													OnMouseAxisMove( UInt device, const input::Axis& axis, Int delta );

	// WindowListener methods.
	void													OnWindowResize( UInt window, UInt width, UInt height );
	void													OnWindowCommand( UInt window, UInt command );
	void													OnWindowActivate( UInt window, Bool active );
	Bool													OnWindowClosing( UInt window );

	// BaseUiEx methods.
	gfx::IOverlayRenderObject*								CreateObject( const gfx::PrimitiveType& type, const gfx::IndexType& indexType, UInt vertexCount, UInt indexCount, UInt order );
	void													ActivateWidget( BaseWidget* widget );
	void													RegisterHotKey( const HotKey& hotkey );
	void													ListenKeyDown( const input::Key* keys, UInt count, Bool discrete );
	void													ListenKeyDown( const input::Key& key, Bool discrete );
	void													ListenKeyUp( const input::Key* keys, UInt count );
	void													ListenKeyUp( const input::Key& key );
	void													ListenKeyPress();
	void													ListenMouseDoubleClick( const input::MouseButton& buttons );
	void													ListenMouseAxisMove( const input::Axis& axis );
	void													FireEvent( UiEvent event, BaseWidget* widget );
	void													DoListen( UiListener* listener );
	over::ISprite*											CreateSprite( img::IImage* image, const lang::Point& location, const lang::Size& size );
	over::IQuad*											CreateQuad( const over::Order& groupOrder, const over::Order& order, const lang::Point& location, const lang::Size& size, const img::Color& color );
	over::IFont*											GetFont() const;
	ITheme*													GetThemeEx() const;

	// Other methods.
	void													Activate( BaseWidget* widget );
	void													Initialize( IUiFactory* factory, core::IContext* context, const core::Language& language, UInt fontSize );
	void													Finalize();
	void													InitInput();
	void													Create( const ThemeName& themeName, const img::Color* widgetColors, const img::Color* textColors, UInt count );
	BaseWidget*												FindWidgetAt( IFrame* frame, const lang::Point& location ) const;
	BaseWidget*												GetWidgetAt( const lang::Point& location ) const;
	void													AddThemeLibrary( io::IStreamDirectory* dir );

private:
	typedef lang::MapPair<UInt, P(Theme)>					ThemeEntry;

	IUiFactory*												_factory;
	P(IUi)													_ui;
	P(Frame)												_root;
	P(Cursor)												_cursor;
	P(gfx::IProgram)										_program;
	ThemeName												_themeName;
	P(Theme)												_theme;
	mutable img::PixelFormat								_pixelFormat;
	win::IFrameWindowEx*									_window;
	core::IContext*											_context;
	gfx::IGraphicsSystemEx*									_graphicsSystem;
	input::IInputSystemEx*									_inputSystem;
	anim::IAnimationSystem*									_animationSystem;
	io::IStreamSystemEx*									_streamSystem;
	img::IImageManager*										_imageManager;
	over::IOverlayManager*									_overlayManager;
	over::IOverlay*											_overlay;
	over::IFont*											_font;
	P(gfx::IBlendStateSet)									_blendStates;
	lang::Vector<img::Color>								_widgetColors;
	lang::Vector<img::Color>								_textColors;
	lang::Vector<UiListener*>								_listeners;
	lang::Map<UInt, P(Theme)>								_themes;
	BaseWidget*												_hoveredWidget;
	BaseWidget*												_activeWidget;
	BaseWidget*												_downWidget;
	Bool													_visible;
	Bool													_enabled;
	Double													_deltaTime;
	Double													_idlePeriod;

	void													InputDetected();
	void													MoveFocus( Bool forward );
	void													FireClickEvent( IWidget* sender );
	void													FireDoubleClickEvent( IWidget* sender );
	void													FireValueChangedEvent( IWidget* sender );
	Bool													HandleHotkey( IFrame* frame, const HotKey& hotkey );
	IFrame*													FindFrame( IFrame* frame, UInt id ) const;
	IWidget*												FindWidget( IFrame* frame, UInt id ) const;
	img::IImage*											LoadThemeImage( io::IStreamDirectory* dir, const lang::String& imageName, const lang::String& alphaName ) const;
	lang::Size												GetSize( const lang::Size& size, const lang::Size& defaultSize ) const;
	void													CreateWidget( IFrame* parent, UiReader& rd );
	Frame*													GetParentFrame( IFrame* parent );
};


#include "UiEx.inl"


} // ui


} // synkro


#endif // _SYNKRO_UI_UIEX_
