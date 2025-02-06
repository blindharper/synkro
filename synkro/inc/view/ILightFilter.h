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
// Purpose: Defines light viewport filter.
//==============================================================================
#ifndef _SYNKRO_VIEW_ILIGHTFILTER_
#define _SYNKRO_VIEW_ILIGHTFILTER_


#include "config.h"
#include <view/IViewportFilter.h>


namespace synkro
{


namespace view
{


/**
 * Light viewport filter.
 */
iface ILightFilter :
	public IViewportFilter
{
public:
	/**
	 * Sets lighting map.
	 * @param lighting Lighting map.
	 * @exception BadArgumentException lighting is null.
	 */
	virtual void											SetLightMap( img::IImage* lighting ) = 0;

	/**
	 * Retrieves lighting map.
	 */
	virtual img::IImage*									GetLightMap() const = 0;
};


} // view


} // synkro


#endif // _SYNKRO_VIEW_ILIGHTFILTER_
