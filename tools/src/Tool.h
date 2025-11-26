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
#ifndef __TOOL__
#define __TOOL__


#include <synkro.h>


// Demo entry point.
#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
#	define SYNKRO_PROJECT( cmd )						\
	int APIENTRY WinMain( HINSTANCE, HINSTANCE, LPSTR cmd, int )
#elif ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_LINUX )
#	define SYNKRO_PROJECT( cmd )						\
	int main( int argc, char* cmd[] )
#endif // ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::audio;
using namespace synkro::core;
using namespace synkro::diag;
using namespace synkro::gfx;
using namespace synkro::img;
using namespace synkro::input;
using namespace synkro::io;
using namespace synkro::lang;
using namespace synkro::mat;
using namespace synkro::math;
using namespace synkro::over;
using namespace synkro::scene;
using namespace synkro::sound;
using namespace synkro::ui;
using namespace synkro::view;
using namespace synkro::win;
using namespace synkro;

//------------------------------------------------------------------------------


// Base GUI tool application.
class Tool :
	public SynkroListener,
	public KeyboardListener,
	public ArcballListener,
	public UiListener
{
public:
	// Initializes SDK and tool.
	Tool( const Char* title, Bool lit = false );

	// Terminates the tool.
	void													Exit();

	// Runs the tool.
	void													Run();

protected:
	virtual void											Configure( IConfiguration* config ) {}
	virtual void											Init() {}
	virtual void											InitUi( IUiEx* ui ) {}

	// SynkroListener methods.
	virtual void											OnSynkroInitialize();
	virtual void											OnSynkroUpdate( Double delta );
	virtual Bool											OnSynkroException( const lang::Exception& ex );

	// KeyboardListener methods.
	virtual Bool											ListenKeyboardInput() const;
	virtual Bool											OnKeyboardKeyDown( UInt device, const input::Key& key, Bool alt, Bool shift, Bool control );
	virtual Bool											OnKeyboardKeyUp( UInt device, const input::Key& key, Bool alt, Bool shift, Bool control );
	virtual Bool											OnKeyboardKeyPress( UInt device, Char key );

	// ArcballListener methods.
	virtual Bool											ListenArcballInput() const;
	virtual Bool											OnArcballOriented( const math::Quaternion& orientation );
	virtual Bool											OnArcballZoom( Int delta );

	// UiListener methods.
	virtual Bool											OnUiClick( IWidget* sender );
	virtual Bool											OnUiDoubleClick( IWidget* sender );
	virtual Bool											OnUiValueChanged( IWidget* sender );

	// Tool methods.
	IButton*												CreateButton( const Point& location, const String& text, const Anchor& anchor );
	IButton*												CreateButton( const Point& location, const String& text );
	IEdit*													CreateEdit( const Point& location, const String& text );
	ILabel*													CreateLabel( const Point& location, const String& text );
	ISlider*												CreateSlider( const Point& location, UInt minPosition, UInt maxPosition, UInt position );
	ISound2D*												CreateSound( const lang::String& name );
	ISound2D*												CreateSound( io::IStream* stream );

	Bool													_running;
	Bool													_lit;
	DisplayMode												_displayMode;
	Float													_orgFov;
	PtrSynkro												_synkro;
	PtrConfiguration										_config;
	PtrSceneEx												_scene;
	PtrCamera												_camera;
	PtrViewport												_viewport;

	String													_title;

private:
	void													ConfigureInternal();
	void													InitView();
	void													InitUiInternal();
	void													InitInput();
};


#endif // __TOOL__
