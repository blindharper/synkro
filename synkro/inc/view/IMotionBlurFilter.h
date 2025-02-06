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
// Purpose: Defines motion blur viewport filter.
//==============================================================================
#ifndef _SYNKRO_VIEW_IMOTIONBLURFILTER_
#define _SYNKRO_VIEW_IMOTIONBLURFILTER_


#include "config.h"
#include <view/IDepthFilter.h>


namespace synkro
{


namespace view
{


/**
 * Motion blur viewport filter.
 */
iface IMotionBlurFilter :
	public IDepthFilter
{
public:
	/**
	 * Sets the number of samples to use for blurring.
	 * @param count Sample count.
	 */
	virtual void											SetSampleCount( UInt count ) = 0;

	/**
	 * Retrieves blur sample count.
	 */
	virtual UInt											GetSampleCount() const = 0;
};


} // view


} // synkro


#endif // _SYNKRO_VIEW_IMOTIONBLURFILTER_
