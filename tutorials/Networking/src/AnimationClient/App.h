#ifndef __APP__
#define __APP__


#include <synkro.h>


using namespace synkro;


class App :
	public core::SynkroListener,
	public net::NetworkListener,
	public core::TimerListener
{
public:
	// Constructor & destructor.
	App();

	// Runs the application.
	void													Run();

	// SynkroListener methods.
	void													OnSynkroInitialize();
	void													OnSynkroUpdate( Double delta );
	Bool													OnSynkroException( const lang::Exception& ex );

	// NetworkListener network.
	Bool													OnNetworkEvent( UInt device, UShort peer, UInt address, UShort port, const net::NetworkMessage* message, UInt size );

	// TimerListener methods.
	void													OnTimerTick( UInt timer );

private:
	Bool													_running;
	gfx::DisplayMode										_displayModeWindowed;
	PtrSynkro												_synkro;
	PtrConfiguration										_config;
	PtrFrameRenderWindowEx									_window;
	PtrSceneEx												_scene;
	PtrCamera												_camera;
	PtrViewport												_viewport;
	PtrTriangleMesh											_tiny;
	PtrSkeletonAnimationController							_skeletonCtrl;
	PtrNetworkPeer											_client;
	PtrNetworkPeer											_server;
	UInt													_timer;
	lang::String											_animationSet;

	void													Configure();
	void													InitScene();
	void													InitView();
	void													InitNetwork();
	io::IStream*											GetStream( const lang::String& name );
};


#endif // __APP__
