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
// Purpose: Defines sprite property names.
//==============================================================================
#ifndef _SYNKRO_OVER_SPRITEPROPERTY_
#define _SYNKRO_OVER_SPRITEPROPERTY_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace over
{


// Sprite property names.
SYNKRO_ENUM_BEGIN( SpriteProperty )
	// Sprite location.
	SYNKRO_ENUM_CONST( SpriteProperty, Location )

	// Sprite location's X coordinate.
	SYNKRO_ENUM_CONST( SpriteProperty, LocationX )

	// Sprite location's Y coordinate.
	SYNKRO_ENUM_CONST( SpriteProperty, LocationY )

	// Sprite size.
	SYNKRO_ENUM_CONST( SpriteProperty, Size )

	// Sprite orientation.
	SYNKRO_ENUM_CONST( SpriteProperty, Orientation )

	// Sprite opacity.
	SYNKRO_ENUM_CONST( SpriteProperty, Opacity )

	// Sprite's image frame.
	SYNKRO_ENUM_CONST( SpriteProperty, Frame )

	// Sprite visibility.
	SYNKRO_ENUM_CONST( SpriteProperty, Visibility )

	// Converts sprite property to string.
	lang::String											ToString() const;
SYNKRO_ENUM_END()


} // over


} // synkro


#endif // _SYNKRO_OVER_SPRITEPROPERTY_
