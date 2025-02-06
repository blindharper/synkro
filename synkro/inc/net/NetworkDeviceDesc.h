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
// Purpose: Defines network device description.
//==============================================================================
#ifndef _SYNKRO_NET_NETWORKDEVICEDESC_
#define _SYNKRO_NET_NETWORKDEVICEDESC_


#include "config.h"


namespace synkro
{


namespace net
{


/**
 * Network device description.
 */
class SYNKRO_API NetworkDeviceDesc
{
public:
	/** Creates default device description. */
	NetworkDeviceDesc();

	/** Creates device description with the specified address. */
	NetworkDeviceDesc( UInt address );

	/** Device IP address. */
	UInt													Address;
};


} // net


} // synkro


#endif // _SYNKRO_NET_NETWORKDEVICEDESC_
