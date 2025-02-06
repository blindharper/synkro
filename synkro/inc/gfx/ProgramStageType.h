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
// Purpose: Defines graphics program stage type.
//==============================================================================
#ifndef _SYNKRO_GFX_PROGRAMSTAGETYPE_
#define _SYNKRO_GFX_PROGRAMSTAGETYPE_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace gfx
{


/**
 * Graphics program stage type.
 */
SYNKRO_ENUM_BEGIN( ProgramStageType )
	/** Unknown stage. */
	SYNKRO_ENUM_CONST( ProgramStageType, Unknown )

	/** Vertex stage. */
	SYNKRO_ENUM_CONST( ProgramStageType, Vertex )

	/** Hull stage. */
	SYNKRO_ENUM_CONST( ProgramStageType, Hull )

	/** Domain stage. */
	SYNKRO_ENUM_CONST( ProgramStageType, Domain )

	/** Geometry stage. */
	SYNKRO_ENUM_CONST( ProgramStageType, Geometry )

	/** Fragment stage. */
	SYNKRO_ENUM_CONST( ProgramStageType, Fragment )

	/** Creates stage type from string. */
	ProgramStageType( const lang::String& type );

	/** Converts stage type to string. */
	lang::String											ToString() const;
SYNKRO_ENUM_END()


} // gfx


} // synkro


#endif // _SYNKRO_GFX_PROGRAMSTAGETYPE_
