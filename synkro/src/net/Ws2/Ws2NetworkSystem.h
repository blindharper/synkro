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
// Purpose: WinSock 2.0 network system.
//==============================================================================
#ifndef _SYNKRO_NET_WS2NETWORKSYSTEM_
#define _SYNKRO_NET_WS2NETWORKSYSTEM_


#include "config.h"
#include <net/NetworkSystemImpl.h>
#include <net/INetworkSystem.h>


namespace synkro
{


namespace net
{


// WinSock 2.0 network system.
class Ws2NetworkSystem :
	public NetworkSystemImpl<INetworkSystem>
{
public:
	// Constructor & destructor.
	Ws2NetworkSystem( diag::ILog* log );
	~Ws2NetworkSystem();

	// ISystem methods.
	Bool													Update( Double delta );

	// INetworkSystem methods.
	INetworkDevice*											CreateRemoteDevice( UInt address );
	INetworkDevice*											CreateDevice( UInt index );

private:
	HMODULE													_dll;

#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
	FARPROC													GetEntryPoint( HMODULE dll, const char* name );
#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS
};


} // net


} // synkro


#endif // _SYNKRO_NET_WS2NETWORKSYSTEM_
