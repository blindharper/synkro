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
// Purpose: Defines simple viewport filter.
//==============================================================================
#ifndef _SYNKRO_VIEW_ISIMPLEFILTER_
#define _SYNKRO_VIEW_ISIMPLEFILTER_


#include "config.h"
#include <view/IViewportFilter.h>


namespace synkro
{


namespace view
{


/**
 * Simple viewport filter.
 */
iface ISimpleFilter :
	public IViewportFilter
{
public:
	/**
	 * Sets filter's parameter value.
	 * @param value Parameter value.
	 */
	virtual void											SetValue( Float value ) = 0;

	/**
	 * Retrieves filter's parameter value.
	 */
	virtual Float											GetValue() const = 0;
};


} // view


} // synkro


#endif // _SYNKRO_VIEW_ISIMPLEFILTER_
