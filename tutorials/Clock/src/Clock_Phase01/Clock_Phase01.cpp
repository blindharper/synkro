#include <synkro.h>

#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
int APIENTRY WinMain( HINSTANCE, HINSTANCE, LPSTR, int )
#endif // ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
{
	// Create Synkro object.
	PtrSynkro synkro = synkro::SynkroCreate( SYNKRO_VERSION, nullptr );
	
	// Configure Synkro.
	PtrConfiguration config = synkro->GetConfiguration()->Clone();
	synkro::gfx::DisplayMode displayMode = synkro::gfx::DisplayMode::Minimum;
	config->Set( synkro::core::Param::GraphicsDisplayMode, displayMode.Index() );

	// Create application window.
	synkro->GetWindowSystem()->CreateWindow( false, false, L"Clock - Phase 01", 0, displayMode.Width, displayMode.Height );

	// Initialize synkro and run application.
	synkro::Bool running = true;
	synkro->Initialize( config );
	synkro->Run( running );

	return 0;
}
