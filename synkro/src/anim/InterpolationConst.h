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
// Purpose: Defines interpolation constant values.
//==============================================================================
#ifndef _SYNKRO_ANIM_INTERPOLATIONCONST_
#define _SYNKRO_ANIM_INTERPOLATIONCONST_


#include "config.h"


namespace synkro
{


namespace anim
{


// Interpolation constant values.
enum InterpolationConst
{
	INTERPOLATION_STEPPED		= 0,
	INTERPOLATION_LINEAR		= 1,
	INTERPOLATION_EASE			= 2,
	INTERPOLATION_EASE_IN		= 3,
	INTERPOLATION_EASE_OUT		= 4,
	INTERPOLATION_EASE_IN_OUT	= 5,
};


} // anim


} // synkro


#endif // _SYNKRO_ANIM_INTERPOLATIONCONST_
