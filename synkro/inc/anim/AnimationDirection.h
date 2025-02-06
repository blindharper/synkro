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
// Purpose: Defines animation direction.
//==============================================================================
#ifndef _SYNKRO_ANIM_ANIMATIONDIRECTION_
#define _SYNKRO_ANIM_ANIMATIONDIRECTION_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace anim
{


/**
 * Animation direction.
 */
SYNKRO_ENUM_BEGIN( AnimationDirection )
	/** Animation is played forward. */
	SYNKRO_ENUM_CONST( AnimationDirection, Forward )

	/** Animation is played backwards. */
	SYNKRO_ENUM_CONST( AnimationDirection, Reverse )
SYNKRO_ENUM_END()


} // anim


} // synkro


#endif // _SYNKRO_ANIM_ANIMATIONDIRECTION_
