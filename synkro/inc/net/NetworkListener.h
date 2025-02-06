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
// Purpose: Defines network listener.
//==============================================================================
#ifndef _SYNKRO_NET_NETWORKLISTENER_
#define _SYNKRO_NET_NETWORKLISTENER_


#include "config.h"
#include <net/NetworkMessage.h>


namespace synkro
{


namespace net
{


/**
 * Network listener.
 */
iface NetworkListener
{
public:
	/**
	 * Processes network event.
	 * @param device Network device index.
	 * #param peer Local peer's port.
	 * @param address Sender's address.
	 * @param port Sender's port.
	 * @param message Network message.
	 * @param size Message size, in bytes.
	 * @return True if the event has been consumed, false otherwise.
	 */
	virtual Bool											OnNetworkEvent( UInt device, UShort peer, UInt address, UShort port, const NetworkMessage* message, UInt size ) = 0;
};


} // net


} // synkro


#endif // _SYNKRO_NET_NETWORKLISTENER_
