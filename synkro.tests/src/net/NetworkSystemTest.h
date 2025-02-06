#include <net/INetworkSystemFactory.h>
#include <net/NetworkSystemEx.h>
#include <net/NetworkListener.h>
#include <net/NetworkAddress.h>
#include <lang/Map.h>


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::lang;
using namespace synkro::mem;
using namespace synkro::net;
using namespace synkro;

//------------------------------------------------------------------------------

enum Event
{
	CLIENT_CONNECT = 1,
	CLIENT_DISCONNECT,
	SERVER_OK,
	SERVER_FAIL,
};

struct ClientConnect :
	public NetworkMessage
{
	ClientConnect( const Char* name ) :
		NetworkMessage( CLIENT_CONNECT )
	{
		memset( Name, 0, 30*sizeof(Char) );
		wmemcpy( Name, name, wcslen(name)+1 );
	}	
	Char Name[30];
};

struct ClientDisconnect :
	public NetworkMessage
{
	ClientDisconnect( const Char* name ) :
		NetworkMessage( CLIENT_DISCONNECT )
	{
		memset( Name, 0, 30*sizeof(Char) );
		wmemcpy( Name, name, wcslen(name)+1 );
	}
	Char Name[30];
};

struct ServerOk :
	public NetworkMessage
{
	ServerOk() :
		NetworkMessage( SERVER_OK )
	{
	}
};

struct ServerFail :
	public NetworkMessage
{
	ServerFail() :
		NetworkMessage( SERVER_FAIL )
	{
	}
};

class Server :
	public NetworkListener
{
public:
	Server( INetworkSystemEx* networkSystem ) :
		_sessions( Allocator<MapPair<String, UShort> >( __FILE__ ) ),
		_networkSystem( networkSystem )
	{
		_server = _networkSystem->CreateDevice( 0 )->CreatePeer( 9090 );
		_networkSystem->GetDevice()->ListenEvent( this, CLIENT_CONNECT );
		_networkSystem->GetDevice()->ListenEvent( this, CLIENT_DISCONNECT );
		_networkSystem->GetDevice()->ListenPort( 9090 );
	}

	Bool OnNetworkEvent( UInt device, UShort peer, UInt address, UShort port, const NetworkMessage* message, UInt size )
	{
		INetworkDevice* dev = _networkSystem->CreateRemoteDevice( address );
		INetworkPeer* client = dev->CreatePeer( port );
		if ( message->Type == CLIENT_CONNECT )
		{
			ClientConnect* cmd0 = (ClientConnect*)message;
			String name( cmd0->Name );

			if ( _sessions.ContainsKey(name) )
			{
				wprintf( L"SERVER: ERROR Client %s already connected\r\n", cmd0->Name );

				ServerFail fail;
				_server->Send( client, &fail, sizeof(fail) );
				return true;
			}
			else
			{
				wprintf( L"SERVER: OK Client %s sucessfully connected\r\n", cmd0->Name );

				_sessions[name] = port;
				ServerOk ok;
				_server->Send( client, &ok, sizeof(ok) );
				return true;
			}
		}
		else if ( message->Type == CLIENT_DISCONNECT )
		{
			ClientDisconnect* cmd0 = (ClientDisconnect*)message;
			String name( cmd0->Name );

			if ( _sessions.ContainsKey(name) )
			{
				wprintf( L"SERVER: OK Client %s successfully disconnected\r\n", cmd0->Name );

				_sessions.Remove( name );
				ServerOk ok;
				_server->Send( client, &ok, sizeof(ok) );
				return true;
			}
			else
			{
				wprintf( L"SERVER: ERROR Client %s already disconnected\r\n", cmd0->Name );

				ServerFail fail;
				_server->Send( client, &fail, sizeof(fail) );
				return true;
			}
		}

		return true;
	}

private:
	Map<String, UShort>		_sessions;
	INetworkSystemEx*		_networkSystem;
	INetworkPeer*			_server;
};

class Client :
	public NetworkListener
{
public:
	Client( INetworkSystemEx* networkSystem, const Char* name ) :
		_networkSystem( networkSystem ),
		_name( name )
	{
		NetworkDeviceDesc desc;
		_networkSystem->GetDevice(0)->GetDesc( desc );
		INetworkDevice* dev = _networkSystem->CreateRemoteDevice( desc.Address );
		_server = dev->CreatePeer( 9090 );

		_client = _networkSystem->CreateDevice( 0 )->CreatePeer( 9091 );
		_networkSystem->GetDevice()->ListenEvent( this, SERVER_OK );
		_networkSystem->GetDevice()->ListenEvent( this, SERVER_FAIL );
		_networkSystem->GetDevice()->ListenPort( 9091 );
	}

	void Connect()
	{
		wprintf( L"CLIENT: %s connecting to server...\r\n", _name );

		ClientConnect connect( _name );
		_client->Send( _server, &connect, sizeof(connect) );
	}

	void Disconnect()
	{
		wprintf( L"CLIENT: %s disconnecting from server...\r\n", _name );

		ClientDisconnect disconnect( _name );
		_client->Send( _server, &disconnect, sizeof(disconnect) );
	}

	Bool OnNetworkEvent( UInt device, UShort peer, UInt address, UShort port, const NetworkMessage* message, UInt size )
	{
		if ( message->Type == SERVER_OK )
		{
			wprintf( L"CLIENT: %s server ok...\r\n", _name );
		}
		else if ( message->Type == SERVER_FAIL )
		{
			wprintf( L"CLIENT: %s server failed...\r\n", _name );
		}
		return true;
	}

private:
	INetworkSystemEx*		_networkSystem;
	INetworkPeer*			_client;
	INetworkPeer*			_server;
	const Char*				_name;
};

class NetworkSystemTest
{
public:
	NetworkSystemTest( const String& name, INetworkSystemFactory* factNetworkSys ) :
		_name( name ),
		_factNetworkSys( factNetworkSys )
	{
	}

	void Run()
	{
		P(NetworkSystemEx) ns = new NetworkSystemEx( nullptr );
		ns->Initialize( _factNetworkSys );

		Server svr( ns );
		Client cli1( ns, L"Eugene" );
		Client cli2( ns, L"John" );
		cli1.Connect();
		cli2.Connect();

		for ( int i = 0; i < 4 ; ++i )
		{
			if ( i%2 == 0 )
			{
				cli1.Connect();
			}
			else
			{
				cli1.Disconnect();
				cli2.Disconnect();
			}
			ns->Update( 0.05 );
		}
		cli2.Disconnect();
		ns->Update( 0.05 );
		ns->Update( 0.05 );
	}

private:
	String					_name;
	INetworkSystemFactory*	_factNetworkSys;
};
