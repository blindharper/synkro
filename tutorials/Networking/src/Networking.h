#ifndef __NETWORKING__
#define __NETWORKING__


#include <net/NetworkMessage.h>


#define SERVER_PORT 9090
#define CLIENT_PORT 9091
#define IP_ADDRESS_FILE L"server_ip.txt"


enum NetworkEvent
{
	CLIENT_CONNECT = 1,
	SERVER_RESPONSE,
};

struct ServerResponse :
	public synkro::net::NetworkMessage
{
	ServerResponse( const synkro::Char* animation ) :
		synkro::net::NetworkMessage( SERVER_RESPONSE )
	{
		memset( Animation, 0, 10*sizeof(synkro::Char) );
		wmemcpy( Animation, animation, wcslen(animation)+1 );
	}
	synkro::Char Animation[10];
};


#endif // __NETWORKING__
