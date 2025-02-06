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
#include "config.h"
#include <net/NetworkMessage.h>


namespace synkro
{


namespace net
{


NetworkMessage::NetworkMessage( UShort type ) :
	Type( type )
{
}

Bool NetworkMessage::EqualsTo( const NetworkMessage* other ) const
{
	return (other != nullptr) && (Type == other->Type);
}


} // net


} // synkro
