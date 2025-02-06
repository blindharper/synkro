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
// Purpose: Defines viewport filter with 3x3 kernel.
//==============================================================================
#ifndef _SYNKRO_VIEW_IKERNEL3X3FILTER_
#define _SYNKRO_VIEW_IKERNEL3X3FILTER_


#include "config.h"
#include <view/IViewportFilter.h>


namespace synkro
{


namespace view
{


/**
 * Viewport filter with 3x3 kernel.
 */
iface IKernel3x3Filter :
	public IViewportFilter
{
public:
	/**
	 * Sets the number of times to apply the filter.
	 * @param count Filter's pass count.
	 */
	virtual void											SetPassCount( UInt count ) = 0;

	/**
	 * Retrieves filter's pass count.
	 */
	virtual UInt											GetPassCount() const = 0;

	/**
	 * Casts filter to emboss filter.
	 * @return Non-null for emboss filter, nullptr otherwise.
	 */
	virtual IEmbossFilter*									AsEmboss() const = 0;
};


} // view


} // synkro


#endif // _SYNKRO_VIEW_IKERNEL3X3FILTER_
