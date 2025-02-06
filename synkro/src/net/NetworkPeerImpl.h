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
// Purpose: Generic network peer implementation.
//==============================================================================
#ifndef _SYNKRO_NET_NETWORKPEERIMPL_
#define _SYNKRO_NET_NETWORKPEERIMPL_


#include "config.h"
#include <core/ObjectImpl.h>


namespace synkro
{


namespace net
{


// Generic network peer implementation.
template <class T>
class NetworkPeerImpl :
	public core::ObjectImpl<T>
{
public:
	// Constructor & destructor.
	NetworkPeerImpl( INetworkDevice* device, UShort port );
	virtual ~NetworkPeerImpl();

	// INetworkPeer methods.
	virtual INetworkDevice*									GetDevice() const;
	virtual UShort											GetPort() const;

protected:
	INetworkDevice*											_device;
	UShort													_port;
};


#include "NetworkPeerImpl.inl"


} // net


} // synkro


#endif // _SYNKRO_NET_NETWORKPEERIMPL_
