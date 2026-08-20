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
// Purpose: Defines camera viewport filter.
//==============================================================================
#ifndef _SYNKRO_VIEW_ICAMERAFILTER_
#define _SYNKRO_VIEW_ICAMERAFILTER_


#include "config.h"
#include <view/IViewportFilter.h>


namespace synkro
{


namespace view
{


/**
 * Camera viewport filter.
 */
iface ICameraFilter :
	public IViewportFilter
{
public:
	/**
	 * Sets camera to be used with the filter.
	 * @param camera Camera used to get pixel depth.
	 * @exception BadArgumentException camera is nullptr.
	 */
	virtual void											SetCamera( scene::ICamera* camera ) = 0;

	/**
	 * Retrieves camera used with the filter.
	 */
	virtual scene::ICamera*									GetCamera() const = 0;
};


} // view


} // synkro


#endif // _SYNKRO_VIEW_ICAMERAFILTER_
