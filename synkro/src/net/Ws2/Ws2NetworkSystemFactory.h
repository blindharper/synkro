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
// Purpose: WinSock 2.0 network system factory.
//==============================================================================
#ifndef _SYNKRO_NET_WS2NETWORKSYSTEMFACTORY_
#define _SYNKRO_NET_WS2NETWORKSYSTEMFACTORY_


#include "config.h"
#include <core/FactoryImpl.h>
#include <net/INetworkSystemFactory.h>
#include <net/NetworkSystem.h>
#include "Ws2NetworkSystem.h"


namespace synkro
{


namespace net
{


// WinSock 2.0 network system factory.
SYNKRO_FACTORY_BEGIN( Ws2NetworkSystemFactory, INetworkSystemFactory, NetworkSystem, NetworkSystem::WinSock2 )
	INetworkSystem*	Create( diag::ILog* log ) { return new Ws2NetworkSystem( log ); }
SYNKRO_FACTORY_END()


} // net


} // synkro


#endif // _SYNKRO_NET_WS2NETWORKSYSTEMFACTORY_
