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
// Purpose: Defines face filling mode.
//==============================================================================
#ifndef _SYNKRO_GFX_FILLMODE_
#define _SYNKRO_GFX_FILLMODE_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace gfx
{


/**
 * Face filling mode.
 */
SYNKRO_ENUM_BEGIN( FillMode )
	/** Draws face vertices. */
	SYNKRO_ENUM_CONST( FillMode, Point )

	/** Draws face edges. */
	SYNKRO_ENUM_CONST( FillMode, Wireframe )

	/** Draws face interior. */
	SYNKRO_ENUM_CONST( FillMode, Solid )

	/** Creates fillmode from string. */
	FillMode( const lang::String& mode );

	/** Converts fill mode to string. */
	lang::String											ToString() const;
SYNKRO_ENUM_END()


} // gfx


} // synkro


#endif // _SYNKRO_GFX_FILLMODE_
