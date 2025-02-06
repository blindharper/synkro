#include "App.h"
#include "../Networking.h"


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::diag;
using namespace synkro::lang;
using namespace synkro::net;

//------------------------------------------------------------------------------


App::App() :
	_synkro( SynkroCreate(SYNKRO_VERSION, this) ),
	_running( true ),
	_res( L"" )
{
}

void App::Run()
{
	// Create configuration.
	Configure();

	// Create icon window.
	_window = _synkro->GetWindowSystem()->CreateWindow( 0, L"Animation Server" );
	_window->AddMenuItem( ID_LOITER, 0, L"Loiter" );
	_window->AddMenuItem( ID_WALK, 0, L"Walk" );
	_window->AddMenuItem( ID_RUN, 0, L"Run" );
	_window->AddMenuItem( ID_WAVE, 0, L"Wave" );
	_window->AddMenuItem( ID_EXIT, 0, L"Exit" );
	_window->Listen( this );

	// Enter main loop.
	_synkro->Initialize( _config );
	_synkro->Run( _running );
}

void App::OnSynkroInitialize()
{
	// Setup networking.
	_server = _synkro->GetNetworkSystem()->CreateDevice( 0 )->CreatePeer( SERVER_PORT );
	_synkro->GetNetworkSystem()->GetDevice()->ListenEvent( this, CLIENT_CONNECT );
	_synkro->GetNetworkSystem()->GetDevice()->ListenPort( SERVER_PORT );

	// Dump ip address.
	NetworkDeviceDesc desc;
	_synkro->GetNetworkSystem()->GetDevice()->GetDesc( desc );
	NetworkAddress ip( desc.Address );
	PtrStreamDirectory dirMedia = _synkro->GetStreamSystem()->GetDirectory( L"media" );
	PtrStream streamIP = dirMedia->CreateStream( IP_ADDRESS_FILE );
	_synkro->WriteString( streamIP, ip.ToString() );
}

void App::OnSynkroUpdate( Double delta )
{
	// Do nothing.
}

Bool App::OnSynkroException( const Exception& ex )
{
	return false;
}

void App::OnWindowResize( UInt window, UInt width, UInt height )
{
}

void App::OnWindowCommand( UInt window, UInt command )
{
	switch ( command )
	{
		case ID_LOITER:
			_res = ServerResponse( L"Loiter" );
			break;

		case ID_WALK:
			_res = ServerResponse( L"Walk" );
			break;

		case ID_RUN:
			_res = ServerResponse( L"Jog" );
			break;

		case ID_WAVE:
			_res = ServerResponse( L"Wave" );
			break;

		case ID_EXIT:
			_running = false;
			break;
	}
}

void App::OnWindowActivate( UInt window, Bool active )
{
}

Bool App::OnWindowClosing( UInt window )
{
	return true;
}

Bool App::OnNetworkEvent( UInt device, UShort peer, UInt address, UShort port, const NetworkMessage* message, UInt size )
{
	INetworkDevice* dev = _synkro->GetNetworkSystem()->CreateRemoteDevice( address );
	INetworkPeer* client = dev->CreatePeer( port );
	if ( message->Type == CLIENT_CONNECT )
	{
		_server->Send( client, &_res, sizeof(_res) );
		return true;
	}

	return false;
}

void App::Configure()
{
	// Set configuration parameters.
	_config = _synkro->GetConfiguration()->Clone();
	_config->Set( Param::AnimationEnable, false );
	_config->Set( Param::LogFileName, String(L"AnimationServer.txt") );
	_config->Set( Param::LogFilePlain, true );
	_config->Set( Param::LogFileAppend, false );
	_config->Set( Param::LogLevel, LogLevel::Extensive );
	_config->Set( Param::LogMode, LogMode::All );
	_config->Set( Param::StreamPath, String(L"../../media") );
	_config->Set( Param::NetworkEnable, true );
	_config->Set( Param::NetworkSystem, NetworkSystem::WinSock2 );
}
