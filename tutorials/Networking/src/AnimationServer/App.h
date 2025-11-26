#ifndef __APP__
#define __APP__


#include <synkro.h>
#include "../Networking.h"


using namespace synkro;


class App :
	public core::SynkroListener,
	public win::WindowListener,
	public net::NetworkListener
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

	// WindowListener methods.
	void													OnWindowResize( UInt window, UInt width, UInt height );
	void													OnWindowCommand( UInt window, UInt command );
	void													OnWindowActivate( UInt window, Bool active );
	Bool													OnWindowClosing( UInt window );

	// NetworkListener network.
	Bool													OnNetworkEvent( UInt device, UShort peer, UInt address, UShort port, const net::NetworkMessage* message, UInt size );

private:
	enum
	{
		ID_LOITER	= 100,
		ID_WALK		= 101,
		ID_RUN		= 102,
		ID_WAVE		= 103,
		ID_EXIT		= 104,
	};

	Bool													_running;
	PtrSynkro												_synkro;
	PtrConfiguration										_config;
	PtrIconWindow											_window;
	PtrNetworkPeer											_server;
	ServerResponse											_res;

	void													Configure();
};


#endif // __APP__
