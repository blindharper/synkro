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
// Purpose: Defines network device.
//==============================================================================
#ifndef _SYNKRO_NET_INETWORKDEVICE_
#define _SYNKRO_NET_INETWORKDEVICE_


#include "config.h"
#include <core/IObject.h>
#include <net/NetworkDeviceDesc.h>


namespace synkro
{


namespace net
{


/**
 * Network device.
 */
iface INetworkDevice :
	public core::IObject
{
public:
	/**
	 * Subscribes for network event listening.
	 * @param port Network device port to listen to.
	 */
	virtual void											ListenPort( UShort port ) = 0;

	/**
	 * Creates peer with the specified port.
	 * @param port Peer's port.
	 */
	virtual INetworkPeer*									CreatePeer( UShort port ) = 0;

	/**
	 * Retrieves device description.
	 * @param [out] desc Device description.
	 */
	virtual void											GetDesc( NetworkDeviceDesc& desc ) const = 0;
};


} // net


} // synkro


#endif // _SYNKRO_NET_INETWORKDEVICE_
