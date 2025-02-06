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
// Purpose: Defines extended network system.
//==============================================================================
#ifndef _SYNKRO_NET_INETWORKSYSTEMEX_
#define _SYNKRO_NET_INETWORKSYSTEMEX_


#include "config.h"
#include <net/INetworkSystem.h>


namespace synkro
{


namespace net
{


/**
 * Extended network system.
 */
iface INetworkSystemEx :
	public INetworkSystem
{
public:
	/**
	 * Retrieves the total number of initialized network devices.
	 * @return Number of initialized network devices.
	 */
	virtual UInt											GetDeviceCount() const = 0;

	/**
	 * Retrieves network device by index.
	 * @param index Index of the network device to retrieve.
	 * @return Requested network device.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual INetworkDeviceEx*								GetDevice( UInt index ) const = 0;

	/**
	 * Retrieves default network device.
	 * @return Network device if one exists, nullptr otherwise.
	 */
	virtual INetworkDeviceEx*								GetDevice() const = 0;
};


} // net


} // synkro


#endif // _SYNKRO_NET_INETWORKSYSTEMEX_
