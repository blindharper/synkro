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
// Purpose: Generic network device implementation.
//==============================================================================
#ifndef _SYNKRO_NET_NETWORKDEVICEIMPL_
#define _SYNKRO_NET_NETWORKDEVICEIMPL_


#include "config.h"
#include <core/ObjectImpl.h>
#include <net/NetworkDeviceDesc.h>


namespace synkro
{


namespace net
{


// Generic network device implementation.
template <class T>
class NetworkDeviceImpl :
	public core::ObjectImpl<T>
{
public:
	// Constructor & destructor.
	NetworkDeviceImpl( const NetworkDeviceDesc& desc );
	virtual ~NetworkDeviceImpl();

	// INetworkDevice methods.
	virtual void											GetDesc( NetworkDeviceDesc& desc ) const;

protected:
	NetworkDeviceDesc										_desc;
};


#include "NetworkDeviceImpl.inl"


} // net


} // synkro


#endif // _SYNKRO_NET_NETWORKDEVICEIMPL_
