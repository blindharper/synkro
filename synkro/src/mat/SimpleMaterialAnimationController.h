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
// Purpose: Animation controller for simple material.
//==============================================================================
#ifndef _SYNKRO_MAT_SIMPLEMATERIALANIMATIONCONTROLLER_
#define _SYNKRO_MAT_SIMPLEMATERIALANIMATIONCONTROLLER_


#include "config.h"
#include "SimpleMaterialAnimationControllerImpl.h"
#include <mat/ISimpleMaterialAnimationController.h>


namespace synkro
{


namespace mat
{


// Animation controller for simple material.
class SYNKRO_API SimpleMaterialAnimationController :
	public SimpleMaterialAnimationControllerImpl<ISimpleMaterialAnimationController>
{
public:
	// Constructor.
	SimpleMaterialAnimationController( ISimpleMaterial* material, anim::IAnimationSystem* animationSystem, anim::IAnimation* animation, anim::AnimationListener* listener );
};


} // mat


} // synkro


#endif // _SYNKRO_MAT_SIMPLEMATERIALANIMATIONCONTROLLER_
