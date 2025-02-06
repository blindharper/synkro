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
// Purpose: Defines text property names.
//==============================================================================
#ifndef _SYNKRO_OVER_TEXTPROPERTY_
#define _SYNKRO_OVER_TEXTPROPERTY_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace over
{


// Text property names.
SYNKRO_ENUM_BEGIN( TextProperty )
	// Text location.
	SYNKRO_ENUM_CONST( TextProperty, Location )

	// Text location's X coordinate.
	SYNKRO_ENUM_CONST( TextProperty, LocationX )

	// Text location's Y coordinate.
	SYNKRO_ENUM_CONST( TextProperty, LocationY )

	// Text clipping rectangle.
	SYNKRO_ENUM_CONST( TextProperty, Rect )

	// Text orientation.
	SYNKRO_ENUM_CONST( TextProperty, Orientation )

	// Text scale.
	SYNKRO_ENUM_CONST( TextProperty, Scale )

	// Text color gradient.
	SYNKRO_ENUM_CONST( TextProperty, ColorGradient )

	// Text color.
	SYNKRO_ENUM_CONST( TextProperty, Color )

	// Text opacity.
	SYNKRO_ENUM_CONST( TextProperty, Opacity )

	// Text visibility.
	SYNKRO_ENUM_CONST( TextProperty, Visibility )

	// Converts text property to string.
	lang::String											ToString() const;
SYNKRO_ENUM_END()


} // over


} // synkro


#endif // _SYNKRO_OVER_TEXTPROPERTY_
