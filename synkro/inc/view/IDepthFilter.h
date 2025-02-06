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
// Purpose: Defines depth-based viewport filter.
//==============================================================================
#ifndef _SYNKRO_VIEW_IDEPTHFILTER_
#define _SYNKRO_VIEW_IDEPTHFILTER_


#include "config.h"
#include <view/IViewportFilter.h>


namespace synkro
{


namespace view
{


/**
 * Depth-based viewport filter. Uses depth texture as an input resource.
 */
iface IDepthFilter :
	public IViewportFilter
{
public:
	/**
	 * Sets depth map.
	 * @param depth Depth map.
	 * @exception BadArgumentException depth is null.
	 */
	virtual void											SetDepthMap( IDepthMap* depth ) = 0;

	/**
	 * Sets camera to be used with the filter.
	 * @param camera Camera used to get pixel depth.
	 * @exception BadArgumentException camera is null.
	 */
	virtual void											SetCamera( scene::ICamera* camera ) = 0;

	/**
	 * Retrieves depth map.
	 */
	virtual IDepthMap*										GetDepthMap() const = 0;

	/**
	 * Retrieves camera used with the filter.
	 */
	virtual scene::ICamera*									GetCamera() const = 0;

	/**
	 * Casts filter to depth-of-field filter.
	 * @return Non-null for depth-of-field filter, nullptr otherwise.
	 */
	virtual IDepthOfFieldFilter*							AsDepthOfField() const = 0;

	/**
	 * Casts filter to fog filter.
	 * @return Non-null for fog filter, nullptr otherwise.
	 */
	virtual IFogFilter*										AsFog() const = 0;

	/**
	 * Casts filter to motion blur filter.
	 * @return Non-null for motion blur filter, nullptr otherwise.
	 */
	virtual IMotionBlurFilter*								AsMotionBlur() const = 0;
};


} // view


} // synkro


#endif // _SYNKRO_VIEW_IDEPTHFILTER_
