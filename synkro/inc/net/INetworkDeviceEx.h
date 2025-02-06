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
// Purpose: Defines extended network device.
//==============================================================================
#ifndef _SYNKRO_NET_INETWORKDEVICEEX_
#define _SYNKRO_NET_INETWORKDEVICEEX_


#include "config.h"
#include <net/INetworkDevice.h>


namespace synkro
{


namespace net
{


/**
 * Extended network device.
 */
iface INetworkDeviceEx :
	public INetworkDevice
{
public:
	/**
	 * Subscribes for network event listening.
	 * @param listener Network event listener.
	 * @param type Network event type.
	 */
	virtual void											ListenEvent( NetworkListener* listener, UShort type ) = 0;
};


} // net


} // synkro


#endif // _SYNKRO_NET_INETWORKDEVICEEX_
