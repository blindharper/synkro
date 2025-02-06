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
// Purpose: Defines viewport property names.
//==============================================================================
#ifndef _SYNKRO_VIEW_VIEWPORTPROPERTY_
#define _SYNKRO_VIEW_VIEWPORTPROPERTY_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace view
{


// Viewport property names.
SYNKRO_ENUM_BEGIN( ViewportProperty )
	// Viewport location.
	SYNKRO_ENUM_CONST( ViewportProperty, Location )

	// Viewport size.
	SYNKRO_ENUM_CONST( ViewportProperty, Size )

	// Viewport rectangle.
	SYNKRO_ENUM_CONST( ViewportProperty, Rect )

	// Viewport color.
	SYNKRO_ENUM_CONST( ViewportProperty, Color )

	// Viewport opacity.
	SYNKRO_ENUM_CONST( ViewportProperty, Opacity )

	// Converts viewport property to string.
	lang::String											ToString() const;
SYNKRO_ENUM_END()


} // view


} // synkro


#endif // _SYNKRO_VIEW_VIEWPORTPROPERTY_
