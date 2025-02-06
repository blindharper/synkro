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
// Purpose: Defines depth buffer format.
//==============================================================================
#ifndef _SYNKRO_GFX_DEPTHFORMAT_
#define _SYNKRO_GFX_DEPTHFORMAT_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace gfx
{


/**
 * Depth buffer formats.
 */
SYNKRO_ENUM_BEGIN( DepthFormat )
	/** Unknown format. */
	SYNKRO_ENUM_CONST( DepthFormat, Unknown )

	/** 32-bit floating-point depth format. */
	SYNKRO_ENUM_CONST( DepthFormat, D32F )

	/** 24-bit depth format. */
	SYNKRO_ENUM_CONST( DepthFormat, D24 )

	/** 16-bit depth format. */
	SYNKRO_ENUM_CONST( DepthFormat, D16 )

	/** Creates depth format from string. */
	DepthFormat( const lang::String& format );

	/** Converts depth format to string. */
	lang::String											ToString() const;
SYNKRO_ENUM_END()


} // gfx


} // synkro


#endif // _SYNKRO_GFX_DEPTHFORMAT_
