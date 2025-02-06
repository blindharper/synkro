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
// Purpose: Defines network address.
//==============================================================================
#include "config.h"
#include <net/NetworkAddress.h>
#include <net/NetworkException.h>
#include <lang/Convert.h>


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace net
{


NetworkAddress::NetworkAddress( const String& address ) :
	Address( 0 )
{
	UInt bytes = address.EntryCount( L'.' );
	if ( bytes != 4 )
		throw NetworkException( L"Bad network address", address, String::Empty );

	Address |= Convert::ToByte(address.Entry(0, L'.')) << 24;
	Address |= Convert::ToByte(address.Entry(1, L'.')) << 16;
	Address |= Convert::ToByte(address.Entry(2, L'.')) << 8;
	Address |= Convert::ToByte(address.Entry(3, L'.'));
}

NetworkAddress::NetworkAddress( Byte* address ) :
	Address( 0 )
{
	Address |= address[0] << 24;
	Address |= address[1] << 16;
	Address |= address[2] << 8;
	Address |= address[3];
}

NetworkAddress::NetworkAddress( UInt address ) :
	Address( address )
{
}

String NetworkAddress::ToString() const
{
	Byte b1 = (Address & 0xff000000) >> 24;
	Byte b2 = (Address & 0x00ff0000) >> 16;
	Byte b3 = (Address & 0x0000ff00) >> 8;
	Byte b4 = (Address & 0x000000ff);
	return String::Format( L"{0}.{1}.{2}.{3}", b1, b2, b3, b4 );
}


} // net


} // synkro
