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
#ifndef _SYNKRO_OVER_ORDER_
#define _SYNKRO_OVER_ORDER_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace over
{


/**
 * Overlay item's z-order.
 */
SYNKRO_ENUM_BEGIN( Order )
	/** Item is drawn above all other items. */
	SYNKRO_ENUM_CONST( Order, Highest )

	/** Item is drawn above all other items except highest items. */
	SYNKRO_ENUM_CONST( Order, High )

	/** Item is drawn above all normal items. */
	SYNKRO_ENUM_CONST( Order, AboveNormal )

	/** Default z-order. */
	SYNKRO_ENUM_CONST( Order, Normal )

	/** Item is drawn below all normal items. */
	SYNKRO_ENUM_CONST( Order, BelowNormal )
	
	/** Item is drawn below all other items except lowest items. */
	SYNKRO_ENUM_CONST( Order, Low )

	/** Item is drawn below all other items. */
	SYNKRO_ENUM_CONST( Order, Lowest )

	/**
	 * Calculates numeric value for a combination of orders.
	 * @param majorOrder Major order.
	 * @param minorOrder Minor order.
	 */
	static UInt												GetValue( const Order& majorOrder, const Order& minorOrder );
SYNKRO_ENUM_END()


} // over


} // synkro


#endif // _SYNKRO_OVER_ORDER_
