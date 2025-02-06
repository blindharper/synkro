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
// Purpose: Defines color viewport filter.
//==============================================================================
#ifndef _SYNKRO_VIEW_ICOLORFILTER_
#define _SYNKRO_VIEW_ICOLORFILTER_


#include "config.h"
#include <img/Color.h>
#include <view/IViewportFilter.h>


namespace synkro
{


namespace view
{


/**
 * Color viewport filter.
 */
iface IColorFilter :
	public IViewportFilter
{
public:
	/**
	 * Sets filter color.
	 * @param color Filter color value.
	 */
	virtual void											SetColor( const img::Color& color ) = 0;

	/**
	 * Retrieves filter color.
	 * @param [out] color Filter color value.
	 */
	virtual void											GetColor( img::Color& color ) const = 0;
};


} // view


} // synkro


#endif // _SYNKRO_VIEW_ICOLORFILTER_
