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
#include "config.h"
#include "Ws2NetworkDevice.h"
#include "Ws2NetworkPeer.h"


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace net
{


Ws2NetworkDevice::Ws2NetworkDevice( const NetworkDeviceDesc& desc, Bool fake ) :
	NetworkDeviceImpl<INetworkDevice>( desc ),
	_fake( fake )
{
}

void Ws2NetworkDevice::ListenPort( UShort port )
{
	// Do nothing.
}

INetworkPeer* Ws2NetworkDevice::CreatePeer( UShort port )
{
	return new Ws2NetworkPeer( this, port );
}


} // net


} // synkro
