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
// Purpose: Defines widget orientation.
//==============================================================================
#ifndef _SYNKRO_UI_ORIENTATION_
#define _SYNKRO_UI_ORIENTATION_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace ui
{


/**
 * Widget orientation.
 */
SYNKRO_ENUM_BEGIN( Orientation )
	/** Horizontal orientation. */
	SYNKRO_ENUM_CONST( Orientation, Horizontal )

	/** Vertical orientation. */
	SYNKRO_ENUM_CONST( Orientation, Vertical )

	/** Creates widget orientation from string. */
	Orientation( const lang::String& orientation );

	/** Converts widget orientation to string. */
	lang::String								ToString() const;
SYNKRO_ENUM_END()


} // ui


} // synkro


#endif // _SYNKRO_UI_ORIENTATION_
