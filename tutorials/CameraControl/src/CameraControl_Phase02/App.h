#ifndef __APP__
#define __APP__


#include <synkro.h>


//------------------------------------------------------------------------------

using namespace synkro;

//------------------------------------------------------------------------------


class App :
	public core::SynkroListener,
	public input::KeyboardListener
{
public:
	// Constructor.
	App();

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
	Double													_deltaTime;
	Float													_orgFov;
	Bool													_running;
	gfx::DisplayMode										_displayModeWindowed;
	gfx::DisplayMode										_displayModeFullscreen;
	PtrSynkro												_synkro;
	PtrConfiguration										_config;
	PtrFrameRenderWindowEx									_window;
	PtrSceneEx												_scene;
	PtrCamera												_camera;
	PtrViewport												_viewport;
	PtrDirectLight											_light;
	PtrOpaqueMaterial										_materialFloor;
	PtrTriangleMesh											_floor;
	PtrText													_txtHelp;
	PtrText													_txtHints;

	void													Configure();
	void													InitScene();
	void													InitView();
	void													InitOverlay();
	void													InitInput();
	img::IImage*											GetImage( const lang::String& name );
	io::IStream*											GetStream( const lang::String& name );
	void													ToggleFullscreen();
};


#endif // __APP__
