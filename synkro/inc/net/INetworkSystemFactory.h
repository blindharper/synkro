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
// Purpose: Defines network system factory.
//==============================================================================
#ifndef _SYNKRO_NET_INETWORKSYSTEMFACTORY_
#define _SYNKRO_NET_INETWORKSYSTEMFACTORY_


#include "config.h"
#include <core/IFactory.h>


namespace synkro
{


namespace net
{


/**
 * Network system factory.
 */
iface INetworkSystemFactory :
	public core::IFactory
{
public:
	/**
	 * Instantiates network system.
	 * @param log Log to write debug messages to.
	 * @return Created network system.
	 */
	virtual INetworkSystem*									Create( diag::ILog* log ) = 0;
};


} // net


} // synkro


#endif // _SYNKRO_NET_INETWORKSYSTEMFACTORY_
