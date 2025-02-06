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
// Purpose: Defines network system types.
//==============================================================================
#ifndef _SYNKRO_NET_NETWORKSYSTEM_
#define _SYNKRO_NET_NETWORKSYSTEM_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace net
{


/**
 * Network system types.
 */
SYNKRO_ENUM_BEGIN( NetworkSystem )
	/** Custom network system. */
	SYNKRO_ENUM_CONST( NetworkSystem, Custom )

	/** WinSock 2.0 based network system. */
	SYNKRO_ENUM_CONST( NetworkSystem, WinSock2 )
SYNKRO_ENUM_END()


} // net


} // synkro


#endif // _SYNKRO_NET_NETWORKSYSTEM_
