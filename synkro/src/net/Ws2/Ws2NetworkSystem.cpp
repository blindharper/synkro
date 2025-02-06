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
#include "config.h"
#include "Ws2NetworkSystem.h"
#include "Ws2NetworkDevice.h"
#include "Ws2.h"
#include <net/NetworkAddress.h>
#include <net/NetworkException.h>


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::diag;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace net
{


Ws2NetworkSystem::Ws2NetworkSystem( ILog* log ) :
	NetworkSystemImpl<INetworkSystem>( log ),
	_dll( nullptr )
{
	// Get entry points.
	_dll = ::LoadLibrary( L"Ws2_32.dll" );

	Ws2::Startup = (LPWSASTARTUP)GetEntryPoint( _dll, "WSAStartup" );
	Ws2::Cleanup = (LPWSACLEANUP)GetEntryPoint( _dll, "WSACleanup" );
	Ws2::GetLastError = (LPWSAGETLASTERROR)GetEntryPoint( _dll, "WSAGetLastError" );
	Ws2::GetHostName = (LPGETHOSTNAME)GetEntryPoint( _dll, "gethostname" );
	Ws2::GetAddrInfo = (LPGETADDRINFO)GetEntryPoint( _dll, "getaddrinfo" );
	Ws2::FreeAddrInfo = (LPFREEADDRINFO)GetEntryPoint( _dll, "freeaddrinfo" );
	Ws2::Socket = (LPSOCKET)GetEntryPoint( _dll, "socket" );
	Ws2::CloseSocket = (LPCLOSESOCKET)GetEntryPoint( _dll, "closesocket" );
	Ws2::Bind = (LPBIND)GetEntryPoint( _dll, "bind" );
	Ws2::IOctlSocket = (LPIOCTLSOCKET)GetEntryPoint( _dll, "ioctlsocket" );
	Ws2::RecvFrom = (LPRECVFROM)GetEntryPoint( _dll, "recvfrom" );
	Ws2::SendTo = (LPSENDTO)GetEntryPoint( _dll, "sendto" );
	Ws2::htonl = (LPHTONL)GetEntryPoint( _dll, "htonl" );
	Ws2::htons = (LPHTONS)GetEntryPoint( _dll, "htons" );
	Ws2::ntohs = (LPHTONS)GetEntryPoint( _dll, "ntohs" );

	// Initialize network system.
	WSADATA wsaData;
	int err = Ws2::Startup( MAKEWORD(2, 2), &wsaData );
	if ( err != NO_ERROR )
		throw NetworkException( L"Failed to initialize WinSock 2.0", Ws2::ToString(err) );

	// Enumerate network devices.
	char buf[200];
	Ws2::GetHostName( buf, 200 );

	addrinfo* result = nullptr;
	addrinfo hints;
	Zero( &hints );
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_DGRAM;
	hints.ai_protocol = IPPROTO_UDP;
	DWORD dwRetval = Ws2::GetAddrInfo( buf, nullptr, &hints, &result );
	for ( addrinfo* ptr = result; ptr != nullptr; ptr = ptr->ai_next )
	{
		UInt address = 0; Byte b = 0;
		b = ptr->ai_addr->sa_data[2];
		address |= b << 24;
		b = ptr->ai_addr->sa_data[3];
		address |= b << 16;
		b = ptr->ai_addr->sa_data[4];
		address |= b << 8;
		b = ptr->ai_addr->sa_data[5];
		address |= b;
		_devices.Add( NetworkDeviceDesc(address) );

		NetworkAddress ip( address );
		LogInfo( MessagePriority::Low, Formatter::Format(Str::NetworkDeviceDetected, ip.ToString()) );
	}
	Ws2::FreeAddrInfo( result );
}

Ws2NetworkSystem::~Ws2NetworkSystem()
{
	Ws2::Cleanup();
	::FreeLibrary( _dll );
}

Bool Ws2NetworkSystem::Update( Double delta )
{
	return true;
}

INetworkDevice* Ws2NetworkSystem::CreateRemoteDevice( UInt address )
{
	NetworkDeviceDesc desc( address );
	return new Ws2NetworkDevice( desc, true );
}

INetworkDevice* Ws2NetworkSystem::CreateDevice( UInt index )
{
	assert( index < _devices.Size() );

	if ( index >= _devices.Size() )
		throw OutOfRangeException( index, _devices.Size() );

	return new Ws2NetworkDevice( _devices[index], false );
}

#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
FARPROC Ws2NetworkSystem::GetEntryPoint( HMODULE dll, const char* name )
{
	FARPROC proc = ::GetProcAddress( dll, name );
	if ( proc == nullptr )
		throw NetworkException( String::Format(Str::InitializeFail, L"Winsock"), String::Format(Str::NotFound, name), String::Empty );
	return proc;
}
#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS


} // net


} // synkro
