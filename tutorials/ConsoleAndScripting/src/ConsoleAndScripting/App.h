#ifndef __APP__
#define __APP__


#include "Universe.h"


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
	PtrFrameRenderWindowEx									_window;
	PtrViewport												_viewport;
	PtrScriptMachine										_scriptMachine;
	Universe*												_universe;

	void													Configure();
	void													InitView();
	void													InitScripting();
	img::IImage*											GetImage( const lang::String& name );
	io::IStream*											GetStream( const lang::String& name );
};


#endif // __APP__
