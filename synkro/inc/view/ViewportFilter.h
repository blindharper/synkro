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
// Purpose: Defines viewport filter types.
//==============================================================================
#ifndef _SYNKRO_VIEW_VIEWPORTFILTER_
#define _SYNKRO_VIEW_VIEWPORTFILTER_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace view
{


/**
 * Viewport filter types.
 */
SYNKRO_ENUM_BEGIN( ViewportFilter )
	/** Custom viewport filter. */
	SYNKRO_ENUM_CONST( ViewportFilter, Custom )

	/** Red channel filter. */
	SYNKRO_ENUM_CONST( ViewportFilter, Red )

	/** Green channel filter. */
	SYNKRO_ENUM_CONST( ViewportFilter, Green )

	/** Blue channel filter. */
	SYNKRO_ENUM_CONST( ViewportFilter, Blue )

	/** Alpha channel filter. */
	SYNKRO_ENUM_CONST( ViewportFilter, Alpha )

	/** Grayscale filter. */
	SYNKRO_ENUM_CONST( ViewportFilter, Grayscale )

	/** Sepia filter. */
	SYNKRO_ENUM_CONST( ViewportFilter, Sepia )

	/** Negative filter. */
	SYNKRO_ENUM_CONST( ViewportFilter, Negative )

	/** Color filter. */
	SYNKRO_ENUM_CONST( ViewportFilter, Color )

	/** Hue filter. */
	SYNKRO_ENUM_CONST( ViewportFilter, Hue )

	/** Brightness filter. */
	SYNKRO_ENUM_CONST( ViewportFilter, Brightness )

	/** Contrast filter. */
	SYNKRO_ENUM_CONST( ViewportFilter, Contrast )

	/** Depth buffer filter. */
	SYNKRO_ENUM_CONST( ViewportFilter, Depth )

	/** Pixel fog filter. */
	SYNKRO_ENUM_CONST( ViewportFilter, Fog )

	/** Motion blur filter. */
	SYNKRO_ENUM_CONST( ViewportFilter, MotionBlur )

	/** Depth-of-Field filter. */
	SYNKRO_ENUM_CONST( ViewportFilter, DepthOfField )

	/** Blur filter. */
	SYNKRO_ENUM_CONST( ViewportFilter, Blur )

	/** Dilation filter. */
	SYNKRO_ENUM_CONST( ViewportFilter, Dilation )

	/** Erosion filter. */
	SYNKRO_ENUM_CONST( ViewportFilter, Erosion )

	/** Sharpen filter. */
	SYNKRO_ENUM_CONST( ViewportFilter, Sharpen )

	/** Emboss filter. */
	SYNKRO_ENUM_CONST( ViewportFilter, Emboss )

	/** Laplacian edge-detection filter. */
	SYNKRO_ENUM_CONST( ViewportFilter, Laplacian )

	/** Prewitt edge-detection filter. */
	SYNKRO_ENUM_CONST( ViewportFilter, Prewitt )

	/** Sobel edge-detection filter. */
	SYNKRO_ENUM_CONST( ViewportFilter, Sobel )

	/** Converts viewport filter type to string. */
	lang::String											ToString() const;
SYNKRO_ENUM_END()


} // view


} // synkro


#endif // _SYNKRO_VIEW_VIEWPORTFILTER_
