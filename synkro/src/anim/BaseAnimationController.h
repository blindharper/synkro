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
// Purpose: Base animation controller.
//==============================================================================
#ifndef _SYNKRO_ANIM_BASEANIMATIONCONTROLLER_
#define _SYNKRO_ANIM_BASEANIMATIONCONTROLLER_


#include "config.h"


namespace synkro
{


namespace anim
{


// Base animation controller.
class BaseAnimationController
{
public:
	virtual void											PostUpdate() = 0;
};


// Casts object to BaseAnimationController.
#define AsBaseAnimationController( OBJ ) dynamic_cast<BaseAnimationController*>( OBJ )


} // anim


} // synkro


#endif // _SYNKRO_ANIM_BASEANIMATIONCONTROLLER_
