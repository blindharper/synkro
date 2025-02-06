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
// Purpose: Defines network peer.
//==============================================================================
#ifndef _SYNKRO_NET_INETWORKPEER_
#define _SYNKRO_NET_INETWORKPEER_


#include "config.h"
#include <core/IObject.h>
#include <net/NetworkMessage.h>


namespace synkro
{


namespace net
{


/**
 * Network peer.
 */
iface INetworkPeer :
	public core::IObject
{
public:
	/**
	 * Sends a message to the specified peer.
	 * @param peer Peer to send message to.
	 * @param message Network message.
	 * @param size message size, in bytes.
	 * @exception BadArgumentException Bad message.
	 * @return Number of bytes actually sent.
	 */
	virtual UInt											Send( INetworkPeer* peer, const NetworkMessage* message, UInt size ) = 0;

	/**
	 * Receives a datagram.
	 * @param [out] address Pointer to sender address.
	 * @param [out] port Pointer to sender port.
	 * @param [out] message Pointer to message.
	 * @param size Message size, in bytes.
	 * @exception BadArgumentException Bad message.
	 * @return Number of bytes actually received, or 0 if nothing to receive.
	 */
	virtual UInt											Receive( UInt* address, UShort* port, NetworkMessage* message, UInt size ) = 0;

	/**
	 * Retrieves peer's device.
	 */
	virtual INetworkDevice*									GetDevice() const = 0;

	/**
	 * Retrieves peer's port number.
	 */
	virtual UShort											GetPort() const = 0;
};


} // net


} // synkro


#endif // _SYNKRO_NET_INETWORKPEER_
