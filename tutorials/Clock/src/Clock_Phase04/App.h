#ifndef __APP__
#define __APP__


#include "Dial.h"


//------------------------------------------------------------------------------

using namespace synkro;

//------------------------------------------------------------------------------


class App :
	public core::SynkroListener
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

private:
	Bool													_running;
	gfx::DisplayMode										_displayModeWindowed;
	PtrSynkro												_synkro;
	PtrConfiguration										_config;
	PtrSceneEx												_scene;
	PtrCamera												_camera;
	PtrDirectLight											_light;
	PtrViewport												_viewport;

	Dial*													_dial;

	void													Configure();
	void													InitView();
};


#endif // __APP__
