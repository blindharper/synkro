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
// Purpose: Generic network system implementation.
//==============================================================================
#ifndef _SYNKRO_NET_NETWORKSYSTEMIMPL_
#define _SYNKRO_NET_NETWORKSYSTEMIMPL_


#include "config.h"
#include <lang/Vector.h>
#include <core/ObjectImpl.h>
#include <lang/Formatter.h>
#include <net/INetworkDevice.h>


namespace synkro
{


namespace net
{


// Generic network system implementation.
template <class T>
class NetworkSystemImpl :
	public core::ObjectImpl<T>,
	public Logger
{
public:
	// Constructor & destructor.
	NetworkSystemImpl( diag::ILog* log );
	virtual ~NetworkSystemImpl();

	// INetworkSystem methods.
	virtual UInt											GetTotalDeviceCount() const;
	virtual void											GetDeviceDesc( UInt index, NetworkDeviceDesc& desc ) const;

protected:
	lang::Vector<NetworkDeviceDesc>							_devices;
};


#include "NetworkSystemImpl.inl"


} // net


} // synkro


#endif // _SYNKRO_NET_NETWORKSYSTEMIMPL_
