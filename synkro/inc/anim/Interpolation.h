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
// Purpose: Defines animation key interpolation.
//==============================================================================
#ifndef _SYNKRO_ANIM_INTERPOLATION_
#define _SYNKRO_ANIM_INTERPOLATION_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace anim
{


/**
 * Animation key interpolation. Defines how the value between two keyframes is calculated.
 */
SYNKRO_ENUM_BEGIN( Interpolation )
	/** Value is changed instantly from one keyframe to another. */
	SYNKRO_ENUM_CONST( Interpolation, Stepped )

	/** Value is linearly intepolated between keyframes. */
	SYNKRO_ENUM_CONST( Interpolation, Linear )

	/** Value is intepolated between keyframes using "ease" bezier curve. */
	SYNKRO_ENUM_CONST( Interpolation, Ease )

	/** Value is intepolated between keyframes using "ease-in" bezier curve. */
	SYNKRO_ENUM_CONST( Interpolation, EaseIn )

	/** Value is intepolated between keyframes using "ease-out" bezier curve. */
	SYNKRO_ENUM_CONST( Interpolation, EaseOut )

	/** Value is intepolated between keyframes using "ease-in-out" bezier curve. */
	SYNKRO_ENUM_CONST( Interpolation, EaseInOut )
SYNKRO_ENUM_END()


} // anim


} // synkro


#endif // _SYNKRO_ANIM_INTERPOLATION_
