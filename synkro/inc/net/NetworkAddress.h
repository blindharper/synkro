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
#ifndef _SYNKRO_NET_NETWORKADDRESS_
#define _SYNKRO_NET_NETWORKADDRESS_


#include "config.h"
#include <lang/String.h>


namespace synkro
{


namespace net
{


/**
 * Network address.
 */
class SYNKRO_API NetworkAddress
{
public:
	/** Creates IPv4 address from a string. */
	NetworkAddress( const lang::String& address );

	/** Creates IPv4 address from a numeric quadruple. */
	NetworkAddress( Byte* address );

	/** Creates IPv4 address from a number. */
	NetworkAddress( UInt address );

	/** IP Address. */
	UInt													Address;

	/** Converts network address to a string. */
	lang::String											ToString() const;
};


} // net


} // synkro


#endif // _SYNKRO_NET_NETWORKADDRESS_
