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
#include "config.h"
#include "Ws2.h"


namespace synkro
{


namespace net
{


const Char* Ws2::ToString( int error )
{
	switch ( error )
	{
		case WSAEINTR:					return L"WSAEINTR";
		case WSAEBADF:					return L"WSAEBADF";
		case WSAEACCES:					return L"WSAEACCES";
		case WSAEFAULT:					return L"WSAEFAULT";
		case WSAEINVAL:					return L"WSAEINVAL";
		case WSAEMFILE:					return L"WSAEMFILE";
		case WSAEWOULDBLOCK:			return L"WSAEWOULDBLOCK";
		case WSAEINPROGRESS:			return L"WSAEINPROGRESS";
		case WSAEALREADY:				return L"WSAEALREADY";
		case WSAENOTSOCK:				return L"WSAENOTSOCK";
		case WSAEDESTADDRREQ:			return L"WSAEDESTADDRREQ";
		case WSAEMSGSIZE:				return L"WSAEMSGSIZE";
		case WSAEPROTOTYPE:				return L"WSAEPROTOTYPE";
		case WSAENOPROTOOPT:			return L"WSAENOPROTOOPT";
		case WSAEPROTONOSUPPORT:		return L"WSAEPROTONOSUPPORT";
		case WSAESOCKTNOSUPPORT:		return L"WSAESOCKTNOSUPPORT";
		case WSAEOPNOTSUPP:				return L"WSAEOPNOTSUPP";
		case WSAEPFNOSUPPORT:			return L"WSAEPFNOSUPPORT";
		case WSAEAFNOSUPPORT:			return L"WSAEAFNOSUPPORT";
		case WSAEADDRINUSE:				return L"WSAEADDRINUSE";
		case WSAEADDRNOTAVAIL:			return L"WSAEADDRNOTAVAIL";
		case WSAENETDOWN:				return L"WSAENETDOWN";
		case WSAENETUNREACH:			return L"WSAENETUNREACH";
		case WSAENETRESET:				return L"WSAENETRESET";
		case WSAECONNABORTED:			return L"WSAECONNABORTED";
		case WSAECONNRESET:				return L"WSAECONNRESET";
		case WSAENOBUFS:				return L"WSAENOBUFS";
		case WSAEISCONN:				return L"WSAEISCONN";
		case WSAENOTCONN:				return L"WSAENOTCONN";
		case WSAESHUTDOWN:				return L"WSAESHUTDOWN";
		case WSAETOOMANYREFS:			return L"WSAETOOMANYREFS";
		case WSAETIMEDOUT:				return L"WSAETIMEDOUT";
		case WSAECONNREFUSED:			return L"WSAECONNREFUSED";
		case WSAELOOP:					return L"WSAELOOP";
		case WSAENAMETOOLONG:			return L"WSAENAMETOOLONG";
		case WSAEHOSTDOWN:				return L"WSAEHOSTDOWN";
		case WSAEHOSTUNREACH:			return L"WSAEHOSTUNREACH";
		case WSAENOTEMPTY:				return L"WSAENOTEMPTY";
		case WSAEPROCLIM:				return L"WSAEPROCLIM";
		case WSAEUSERS:					return L"WSAEUSERS";
		case WSAEDQUOT:					return L"WSAEDQUOT";
		case WSAESTALE:					return L"WSAESTALE";
		case WSAEREMOTE:				return L"WSAEREMOTE";
		case WSASYSNOTREADY:			return L"WSASYSNOTREADY";
		case WSAVERNOTSUPPORTED:		return L"WSAVERNOTSUPPORTED";
		case WSANOTINITIALISED:			return L"WSANOTINITIALISED";
		case WSAEDISCON:				return L"WSAEDISCON";
		case WSAENOMORE:				return L"WSAENOMORE";
		case WSAECANCELLED:				return L"WSAECANCELLED";
		case WSAEINVALIDPROCTABLE:		return L"WSAEINVALIDPROCTABLE";
		case WSAEINVALIDPROVIDER:		return L"WSAEINVALIDPROVIDER";
		case WSAEPROVIDERFAILEDINIT:	return L"WSAEPROVIDERFAILEDINIT";
		case WSASYSCALLFAILURE:			return L"WSASYSCALLFAILURE";
		case WSASERVICE_NOT_FOUND:		return L"WSASERVICE_NOT_FOUND";
		case WSATYPE_NOT_FOUND:			return L"WSATYPE_NOT_FOUND";
		case WSA_E_NO_MORE:				return L"WSA_E_NO_MORE";
		case WSA_E_CANCELLED:			return L"WSA_E_CANCELLED";
		case WSAEREFUSED:				return L"WSAEREFUSED";
		case WSAHOST_NOT_FOUND:			return L"WSAHOST_NOT_FOUND";
		case WSATRY_AGAIN:				return L"WSATRY_AGAIN";
		case WSANO_RECOVERY:			return L"WSANO_RECOVERY";
		case WSANO_DATA:				return L"WSANO_DATA";
		default:						return L"WSA_UNKNOWN";
	}
}

LPWSASTARTUP Ws2::Startup;
LPWSACLEANUP Ws2::Cleanup;
LPWSAGETLASTERROR Ws2::GetLastError;
LPGETHOSTNAME Ws2::GetHostName;
LPGETADDRINFO Ws2::GetAddrInfo;
LPFREEADDRINFO Ws2::FreeAddrInfo;
LPSOCKET Ws2::Socket;
LPCLOSESOCKET Ws2::CloseSocket;
LPBIND Ws2::Bind;
LPIOCTLSOCKET Ws2::IOctlSocket;
LPRECVFROM Ws2::RecvFrom;
LPSENDTO Ws2::SendTo;
LPHTONL Ws2::htonl;
LPHTONS Ws2::htons;
LPHTONS Ws2::ntohs;


} // net


} // synkro
