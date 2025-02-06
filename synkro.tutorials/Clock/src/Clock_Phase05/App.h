#ifndef __APP__
#define __APP__


#include "Dial.h"


//------------------------------------------------------------------------------

using namespace synkro;

//------------------------------------------------------------------------------


class App :
	public core::SynkroListener,
	public input::KeyboardListener
{
public:
	// Constructor & destructor.
	App();
	~App();

	// Runs the application.
	void													Run();

	// SynkroListener methods.
	void													OnSynkroInitialize();
	void													OnSynkroUpdate( Double delta );
	Bool													OnSynkroException( const lang::Exception& ex );

	// KeyboardListener methods.
	Bool													ListenKeyboardInput() const;
	Bool													OnKeyboardKeyDown( UInt device, const input::Key& key, Bool alt, Bool shift, Bool control );
	Bool													OnKeyboardKeyUp( UInt device, const input::Key& key, Bool alt, Bool shift, Bool control );
	Bool													OnKeyboardKeyPress( UInt device, Char key );

private:
	Bool													_running;
	gfx::DisplayMode										_displayModeWindowed;
	gfx::DisplayMode										_displayModeFullscreen;
	PtrSynkro												_synkro;
	PtrConfiguration										_config;
	PtrSceneEx												_scene;
	PtrCamera												_camera;
	PtrDirectLight											_light;
	PtrViewport												_viewport;
	PtrText													_txtHelp;
	PtrText													_txtHints;

	Dial*													_dial;

	void													Configure();
	void													InitView();
	void													InitOverlay();
	void													InitInput();
	void													ToggleFullscreen();
};


#endif // __APP__
