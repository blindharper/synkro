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
// Purpose: Defines network system.
//==============================================================================
#ifndef _SYNKRO_NET_INETWORKSYSTEM_
#define _SYNKRO_NET_INETWORKSYSTEM_


#include "config.h"
#include <core/ISystem.h>
#include <net/NetworkDeviceDesc.h>


namespace synkro
{


namespace net
{


/**
 * Network system. Provides networking functionality.
 */
iface INetworkSystem :
	public core::ISystem
{
public:
	/**
	 * Creates remote network device.
	 * @param address Network device address.
	 * @return Created network device.
	 * @exception NetworkException Invalid address.
	 */
	virtual INetworkDevice*									CreateRemoteDevice( UInt address ) = 0;

	/**
	 * Initializes one of the network devices installed in the system.
	 * @param index Index of the network device to initialize.
	 * @return Created network device.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual INetworkDevice*									CreateDevice( UInt index ) = 0;

	/**
	 * Retrieves the total number of network devices installed in the system.
	 */
	virtual UInt											GetTotalDeviceCount() const = 0;

	/**
	 * Retrieves network device description.
	 * @param index Index of the network device.
	 * @param [out] desc Device description.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual void											GetDeviceDesc( UInt index, NetworkDeviceDesc& desc ) const = 0;
};


} // net


} // synkro


#endif // _SYNKRO_NET_INETWORKSYSTEM_
