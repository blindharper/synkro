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
// Purpose: WinSock 2.0 network device implementation.
//==============================================================================
#ifndef _SYNKRO_NET_WS2NETWORKDEVICE_
#define _SYNKRO_NET_WS2NETWORKDEVICE_


#include "config.h"
#include <net/NetworkDeviceImpl.h>
#include <net/INetworkDevice.h>
#include "Ws2.h"


namespace synkro
{


namespace net
{


// WinSock 2.0 network device implementation.
class Ws2NetworkDevice :
	public NetworkDeviceImpl<INetworkDevice>
{
public:
	// Constructor.
	Ws2NetworkDevice( const NetworkDeviceDesc& desc, Bool fake );

	// INetworkDevice methods.
	void													ListenPort( UShort port );
	INetworkPeer*											CreatePeer( UShort port );

private:
	friend class Ws2NetworkPeer;

	Bool													_fake;
};


} // net


} // synkro


#endif // _SYNKRO_NET_WS2NETWORKDEVICE_
