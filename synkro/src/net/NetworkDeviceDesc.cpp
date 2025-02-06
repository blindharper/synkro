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
// Purpose: Implements network device description.
//==============================================================================
#include "config.h"
#include <net/NetworkDeviceDesc.h>


namespace synkro
{


namespace net
{


NetworkDeviceDesc::NetworkDeviceDesc() :
	Address( 0 )
{
}

NetworkDeviceDesc::NetworkDeviceDesc( UInt address ) :
	Address( address )
{
}


} // net


} // synkro
