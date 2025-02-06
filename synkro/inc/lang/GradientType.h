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
// Purpose: Defines gradient types.
//==============================================================================
#ifndef _SYNKRO_LANG_GRADIENTTYPE_
#define _SYNKRO_LANG_GRADIENTTYPE_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace lang
{


/**
 * Gradient type.
 */
SYNKRO_ENUM_BEGIN( GradientType )
	/** Horizontal gradient. */
	SYNKRO_ENUM_CONST( GradientType, Horizontal )

	/** Vertical gradient. */
	SYNKRO_ENUM_CONST( GradientType, Vertical )

	/** Diagonal gradient. */
	SYNKRO_ENUM_CONST( GradientType, BottomUp )

	/** Diagonal gradient. */
	SYNKRO_ENUM_CONST( GradientType, TopDown )

	/** Radial gradient. */
	SYNKRO_ENUM_CONST( GradientType, Radial )
SYNKRO_ENUM_END()


} // lang


} // synkro


#endif // _SYNKRO_LANG_GRADIENTTYPE_
