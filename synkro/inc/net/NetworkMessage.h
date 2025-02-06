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
// Purpose: Defines base network message.
//==============================================================================
#ifndef _SYNKRO_NET_NETWORKMESSAGE_
#define _SYNKRO_NET_NETWORKMESSAGE_


#include "config.h"


namespace synkro
{


namespace net
{


/**
 * Base network message.
 */
class SYNKRO_API NetworkMessage
{
public:
	/** Creates network message of the given type. */
	NetworkMessage( UShort type );

	/**
	 * Compares network message to another one.
	 * @param other Message to compare to.
	 * @return True if the messages are identical, false otherwise.
	 */
	virtual Bool											EqualsTo( const NetworkMessage* other ) const;

	/** Actual message type. */
	UShort													Type;
};


} // net


} // synkro


#endif // _SYNKRO_NET_NETWORKMESSAGE_
