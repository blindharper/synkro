//==============================================================================
// This file is a part of the Synkro Framework.
// 
// Copyright (c) Nobody. No rights reserved ;-7
//
// The contents herein is the property of the Mankind.
// Use, distribution and modification of this source code
// is allowed without any permission from the Synkro Project.
// Website: https://synkro.pro Email: mailto:blindharper70@gmail.com
//
// Purpose: WinSock 2.0 based network peer implementation.
//==============================================================================
#ifndef _SYNKRO_NET_WS2NETWORKPEER_
#define _SYNKRO_NET_WS2NETWORKPEER_


#include "config.h"
#include <net/NetworkPeerImpl.h>
#include <net/INetworkPeer.h>
#include "Ws2.h"


namespace synkro
{


namespace net
{


// WinSock 2.0 based network peer.
class Ws2NetworkPeer :
	public NetworkPeerImpl<INetworkPeer>
{
public:
	// Constructor & destructor.
	Ws2NetworkPeer( INetworkDevice* device, UShort port );
	~Ws2NetworkPeer();

	// INetworkPeer methods.
	UInt													Send( INetworkPeer* peer, const NetworkMessage* message, UInt size );
	UInt													Receive( UInt* address, UShort* port, NetworkMessage* message, UInt size );

private:
	SOCKET													_socket;
	sockaddr_in												_socketAddr;
	sockaddr_in												_senderAddr;
	int														_senderAddrSize;
};


} // net


} // synkro


#endif // _SYNKRO_NET_WS2NETWORKPEER_
