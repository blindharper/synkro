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
// Purpose: Logical network peer implementation.
//=============================================================================
#ifndef _SYNKRO_NET_NETWORKPEER_
#define _SYNKRO_NET_NETWORKPEER_


#include "config.h"
#include <core/ObjectImpl.h>
#include <net/INetworkPeer.h>


namespace synkro
{


namespace net
{


// Logical peer implementation.
class NetworkPeer :
	public core::ObjectImpl<INetworkPeer>
{
public:
	// Constructor and destructor.
	NetworkPeer( INetworkDevice* device, INetworkPeer* peer );
	virtual ~NetworkPeer();

	// INetworkPeer methods.
	UInt													Send( INetworkPeer* peer, const NetworkMessage* message, UInt size );
	UInt													Receive( UInt* address, UShort* port, NetworkMessage* message, UInt size );
	INetworkDevice*											GetDevice() const;
	UShort													GetPort() const;

protected:
	INetworkDevice*											_device;
	P(INetworkPeer)											_peer;
};


#include "NetworkPeer.inl"


} // net


} // synkro


#endif // _SYNKRO_NET_NETWORKPEER_
