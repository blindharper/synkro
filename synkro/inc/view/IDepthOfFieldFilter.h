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
// Purpose: Defines depth-of-field viewport filter.
//==============================================================================
#ifndef _SYNKRO_VIEW_IDEPTHOFFIELDFILTER_
#define _SYNKRO_VIEW_IDEPTHOFFIELDFILTER_


#include "config.h"
#include <view/IDepthFilter.h>


namespace synkro
{


namespace view
{


/**
 * Depth-of-field viewport filter.
 */
iface IDepthOfFieldFilter :
	public IDepthFilter
{
public:
	/**
	 * Sets camera's focal distance.
	 * @param distance Focal distance.
	 */
	virtual void											SetFocalDistance( Float distance ) = 0;

	/**
	 * Retrieves camera's focal distance.
	 */
	virtual Float											GetFocalDistance() const = 0;
};


} // view


} // synkro


#endif // _SYNKRO_VIEW_IDEPTHOFFIELDFILTER_
