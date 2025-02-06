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
// Purpose: Defines animation track types.
//==============================================================================
#ifndef _SYNKRO_ANIM_ANIMATIONTRACK_
#define _SYNKRO_ANIM_ANIMATIONTRACK_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace anim
{


/**
 * Animation track types.
 */
SYNKRO_ENUM_BEGIN( AnimationTrack )
	/** Custom track. */
	SYNKRO_ENUM_CONST( AnimationTrack, Custom )

	/** Scalar floating-point noise. */
	SYNKRO_ENUM_CONST( AnimationTrack, FloatNoise )

	/** Scalar wave. */
	SYNKRO_ENUM_CONST( AnimationTrack, FloatWave )

	/** Converts animation track type to string. */
	lang::String											ToString() const;
SYNKRO_ENUM_END()


} // anim


} // synkro


#endif // _SYNKRO_ANIM_ANIMATIONTRACK_
