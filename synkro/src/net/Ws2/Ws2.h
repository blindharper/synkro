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
// Purpose: WinSock 2.0 API.
//==============================================================================
#ifndef _SYNKRO_NET_WS2_
#define _SYNKRO_NET_WS2_


#include "config.h"
#include <winsock2.h>
#include <ws2tcpip.h>


typedef int (WSAAPI *LPWSASTARTUP)( WORD, LPWSADATA );
typedef int (WSAAPI *LPWSACLEANUP)( void );
typedef int (WSAAPI *LPWSAGETLASTERROR)( void );
typedef int (WSAAPI *LPGETHOSTNAME)( char*, int );
typedef int (WSAAPI *LPGETADDRINFO)( const char*, const char*, const ADDRINFOA*, PADDRINFOA* );
typedef void (WSAAPI *LPFREEADDRINFO)( PADDRINFOA );
typedef SOCKET (WSAAPI *LPSOCKET)( int, int, int );
typedef int (WSAAPI *LPCLOSESOCKET)( SOCKET );
typedef int (WSAAPI *LPBIND)( SOCKET, const struct sockaddr*, int );
typedef int (WSAAPI *LPIOCTLSOCKET)( SOCKET, long, u_long* );
typedef int (WSAAPI *LPRECVFROM)( SOCKET, char*, int, int, struct sockaddr*, int* );
typedef int (WSAAPI *LPSENDTO)( SOCKET, const char*, int, int, const struct sockaddr*, int );
typedef u_long (WSAAPI *LPHTONL)( u_long );
typedef u_short (WSAAPI *LPHTONS)( u_short );


namespace synkro
{


namespace net
{


// WinSock 2.0 API.
class Ws2
{
public:
	static const Char*										ToString( int error );

	static LPWSASTARTUP										Startup;
	static LPWSACLEANUP										Cleanup;
	static LPWSAGETLASTERROR								GetLastError;
	static LPGETHOSTNAME									GetHostName;
	static LPGETADDRINFO									GetAddrInfo;
	static LPFREEADDRINFO									FreeAddrInfo;
	static LPSOCKET											Socket;
	static LPCLOSESOCKET									CloseSocket;
	static LPBIND											Bind;
	static LPIOCTLSOCKET									IOctlSocket;
	static LPRECVFROM										RecvFrom;
	static LPSENDTO											SendTo;
	static LPHTONL											htonl;
	static LPHTONS											htons;
	static LPHTONS											ntohs;
};


} // net


} // synkro


#endif // _SYNKRO_NET_WS2_
