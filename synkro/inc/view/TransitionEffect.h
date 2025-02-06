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
// Purpose: Defines viewport transition effect.
//==============================================================================
#ifndef _SYNKRO_VIEW_TRANSITIONEFFECT_
#define _SYNKRO_VIEW_TRANSITIONEFFECT_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace view
{


/**
 * Viewport transition effect.
 */
SYNKRO_ENUM_BEGIN( TransitionEffect )
	/** Viewports are switched instantly. */
	SYNKRO_ENUM_CONST( TransitionEffect, Step )

	/** Previous viewport fades out and the next one fades in. */
	SYNKRO_ENUM_CONST( TransitionEffect, Blend )
SYNKRO_ENUM_END()


} // view


} // synkro


#endif // _SYNKRO_VIEW_TRANSITIONEFFECT_
