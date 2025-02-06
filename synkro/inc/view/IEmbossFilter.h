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
// Purpose: Defines emboss viewport filter.
//==============================================================================
#ifndef _SYNKRO_VIEW_IEMBOSSFILTER_
#define _SYNKRO_VIEW_IEMBOSSFILTER_


#include "config.h"
#include <view/IKernel3x3Filter.h>


namespace synkro
{


namespace view
{


/**
 * Emboss filter.
 */
iface IEmbossFilter :
	public IKernel3x3Filter
{
public:
	/**
	 * Sets incident light angle, in degrees. Default is 0.0.
	 * @param angle Light angle.
	 */
	virtual void											SetAngle( Float angle ) = 0;

	/**
	 * Sets emboss depth. Valid range is [0.0-1.0]. Default is 0.5.
	 * @param depth Emboss depth.
	 */
	virtual void											SetDepth( Float depth ) = 0;

	/**
	 * Retrieves incident light angle.
	 */
	virtual Float											GetAngle() const = 0;

	/**
	 * Retrieves emboss depth.
	 */
	virtual Float											GetDepth() const = 0;
};


} // view


} // synkro


#endif // _SYNKRO_VIEW_IEMBOSSFILTER_
