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
// Purpose: Defines overlay item's z-order.
//==============================================================================
#include "config.h"
#include <over/Order.h>
#include <internal/Enum.h>


namespace synkro
{


namespace over
{


SYNKRO_DEFINE_CONST( Order, Highest,		0 )
SYNKRO_DEFINE_CONST( Order, High,			1 )
SYNKRO_DEFINE_CONST( Order, AboveNormal,	2 )
SYNKRO_DEFINE_CONST( Order, Normal,			3 )
SYNKRO_DEFINE_CONST( Order, BelowNormal,	4 )
SYNKRO_DEFINE_CONST( Order, Low,			5 )
SYNKRO_DEFINE_CONST( Order, Lowest,			6 )


UInt Order::GetValue( const Order& majorOrder, const Order& minorOrder )
{
	return 7*majorOrder + minorOrder;
}


} // over


} // synkro
