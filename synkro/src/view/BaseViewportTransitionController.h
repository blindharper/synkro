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
// Purpose: Base viewport transition controller.
//==============================================================================
#ifndef _SYNKRO_VIEW_BASEVIEWPORTTRANSITIONCONTROLLER_
#define _SYNKRO_VIEW_BASEVIEWPORTTRANSITIONCONTROLLER_


#include "config.h"


namespace synkro
{


namespace view
{


// Base viewport transition controller.
class BaseViewportTransitionController
{
public:
	virtual void											PostUpdate() = 0;
};


// Casts object to BaseAnimationController.
#define AsBaseViewportTransitionController( OBJ ) dynamic_cast<BaseViewportTransitionController*>( OBJ )


} // view


} // synkro


#endif // _SYNKRO_VIEW_BASEVIEWPORTTRANSITIONCONTROLLER_
