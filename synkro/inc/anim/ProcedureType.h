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
// Purpose: Defines procedural animation type.
//==============================================================================
#ifndef _SYNKRO_ANIM_PROCEDURETYPE_
#define _SYNKRO_ANIM_PROCEDURETYPE_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace anim
{


/**
 * Procedural animation type.
 */
SYNKRO_ENUM_BEGIN( ProcedureType )
	/** Unknown animation type. */
	SYNKRO_ENUM_CONST( ProcedureType, Unknown )

	/** Wave animation. */
	SYNKRO_ENUM_CONST( ProcedureType, Wave )

	/** Noise animation. */
	SYNKRO_ENUM_CONST( ProcedureType, Noise )
SYNKRO_ENUM_END()


} // anim


} // synkro


#endif // _SYNKRO_ANIM_PROCEDURETYPE_
