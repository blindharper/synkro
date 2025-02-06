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
//==============================================================================
#include "config.h"
#include "NetworkPeer.h"


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace net
{


NetworkPeer::NetworkPeer( INetworkDevice* device, INetworkPeer* peer ) :
	_device( device ),
	_peer( peer )
{
}

NetworkPeer::~NetworkPeer()
{
}

INetworkDevice* NetworkPeer::GetDevice() const
{
	return _device;
}


} // net


} // synkro
