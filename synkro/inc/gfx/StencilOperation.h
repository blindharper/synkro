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
// Purpose: Defines stencil buffer operations.
//==============================================================================
#ifndef _SYNKRO_GFX_STENCILOPERATION_
#define _SYNKRO_GFX_STENCILOPERATION_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace gfx
{


/**
 * Available stencil buffer operations.
 */
SYNKRO_ENUM_BEGIN( StencilOperation )
	/** Do not update the entry in the stencil buffer. */
	SYNKRO_ENUM_CONST( StencilOperation, None )

	/** Set the stencil buffer entry to 0. */
	SYNKRO_ENUM_CONST( StencilOperation, Zero )

	/** Replace the stencil buffer entry with a reference value. */
	SYNKRO_ENUM_CONST( StencilOperation, Replace )

	/** Invert the bits in the stencil buffer entry. */
	SYNKRO_ENUM_CONST( StencilOperation, Invert )

	/** Increment the stencil buffer entry, clamping to the maximum value. */
	SYNKRO_ENUM_CONST( StencilOperation, IncrementClamp )

	/** Decrement the stencil buffer entry, clamping to zero. */
	SYNKRO_ENUM_CONST( StencilOperation, DecrementClamp )

	/** Increment the stencil buffer entry, wrapping to zero if the new value exceeds the maximum value. */
	SYNKRO_ENUM_CONST( StencilOperation, IncrementWrap )

	/** Decrement the stencil buffer entry, wrapping to the maximum value if the new value is less than zero. */
	SYNKRO_ENUM_CONST( StencilOperation, DecrementWrap )

	/** Creates stencil operation from string. */
	StencilOperation( const lang::String& operation );

	/** Converts stencil operation to string. */
	lang::String											ToString() const;
SYNKRO_ENUM_END()


} // gfx


} // synkro


#endif // _SYNKRO_GFX_STENCILOPERATION_
