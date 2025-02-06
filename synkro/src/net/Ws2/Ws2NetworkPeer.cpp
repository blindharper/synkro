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
// Purpose: WinSock 2.0 based network peer implementation.
//==============================================================================
#include "config.h"
#include "Ws2NetworkPeer.h"
#include "Ws2NetworkDevice.h"
#include <net/NetworkException.h>


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace net
{


Ws2NetworkPeer::Ws2NetworkPeer( INetworkDevice* device, UShort port ) :
	NetworkPeerImpl<INetworkPeer>( device, port ),
	_socket( 0 )
{
	assert( device != nullptr );

	// Initialize socket address.
	NetworkDeviceDesc desc; device->GetDesc( desc );
	Zero( &_socketAddr );
	_socketAddr.sin_family		= AF_INET;
	_socketAddr.sin_addr.s_addr	= Ws2::htonl( desc.Address );
	_socketAddr.sin_port		= Ws2::htons( port );

	// Create socket.
	_socket = Ws2::Socket( AF_INET, SOCK_DGRAM, IPPROTO_UDP );
	if ( _socket == INVALID_SOCKET )
		throw NetworkException( L"Failed to create peer", String::Format(Str::CallFail, L"socket()"), String::Empty );

	// Skip binding for fake devices.
	if ( ((Ws2NetworkDevice*)device)->_fake )
		return;

	// Bind socket.
	if ( Ws2::Bind(_socket, (const sockaddr*)&_socketAddr, sizeof(_socketAddr)) == SOCKET_ERROR )
	{
		int error = Ws2::GetLastError();
		throw NetworkException( L"Failed to create peer", String::Format(Str::CallFail, L"bind()"), Ws2::ToString(error) );
	}

	// Make socket non-blocking.
	u_long arg = 1;
	if ( Ws2::IOctlSocket(_socket, FIONBIO, &arg) == SOCKET_ERROR )
	{
		int error = Ws2::GetLastError();
		throw NetworkException( L"Failed to create peer", String::Format(Str::CallFail, L"ioctlsocket()"), Ws2::ToString(error) );
	}

	// Clear receive stuff.
	_senderAddrSize = sizeof(_senderAddr);
	Zero( &_senderAddr );
}

Ws2NetworkPeer::~Ws2NetworkPeer()
{
	Ws2::CloseSocket( _socket );
}

UInt Ws2NetworkPeer::Send( INetworkPeer* peer, const NetworkMessage* message, UInt size )
{
	Ws2NetworkPeer* p = (Ws2NetworkPeer*)peer;
	int ret = Ws2::SendTo( _socket, (const char*)message, size, 0, (const sockaddr*)&p->_socketAddr, sizeof(p->_socketAddr) );
	if ( ret == SOCKET_ERROR )
	{
		int error = Ws2::GetLastError();
		return 0;
	}
	return (UInt)ret;
}

UInt Ws2NetworkPeer::Receive( UInt* address, UShort* port, NetworkMessage* message, UInt size )
{
	int ret = Ws2::RecvFrom( _socket, (char*)message, size, 0, (sockaddr*)&_senderAddr, &_senderAddrSize );
	// Datagram should be at least 2 bytes long.
	if ( ret < 2 )
	{
		return 0;
	}
	UInt addr = (_senderAddr.sin_addr.S_un.S_un_b.s_b1) << 24;
	addr |= (_senderAddr.sin_addr.S_un.S_un_b.s_b2) << 16;
	addr |= (_senderAddr.sin_addr.S_un.S_un_b.s_b3) << 8;
	addr |= (_senderAddr.sin_addr.S_un.S_un_b.s_b4);
	*address = addr;
	*port = Ws2::ntohs( _senderAddr.sin_port );
	return (UInt)ret;
}


} // net


} // synkro
