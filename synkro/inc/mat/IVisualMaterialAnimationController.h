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
// Purpose: Defines animation controller for abstract visual material.
//==============================================================================
#ifndef _SYNKRO_MAT_IVISUALMATERIALANIMATIONCONTROLLER_
#define _SYNKRO_MAT_IVISUALMATERIALANIMATIONCONTROLLER_


#include "config.h"
#include <anim/IPlaybackAnimationController.h>


namespace synkro
{


namespace mat
{


/**
 * Animation controller for abstract visual material.
 */
iface IVisualMaterialAnimationController :
	public anim::IPlaybackAnimationController
{
public:
	/**
	 * Casts controller to simple material controller.
	 * @return Non-null for simple material controller, nullptr otherwise.
	 */
	virtual ISimpleMaterialAnimationController*				AsSimple() const = 0;
};


} // mat


} // synkro


#endif // _SYNKRO_MAT_IVISUALMATERIALANIMATIONCONTROLLER_
