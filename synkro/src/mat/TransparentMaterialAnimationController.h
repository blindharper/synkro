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
#ifndef _SYNKRO_MAT_TRANSPARENTMATERIALANIMATIONCONTROLLER_
#define _SYNKRO_MAT_TRANSPARENTMATERIALANIMATIONCONTROLLER_


#include "config.h"
#include "SimpleMaterialAnimationControllerImpl.h"
#include <mat/ITransparentMaterialAnimationController.h>
#include <mat/ITransparentMaterial.h>


namespace synkro
{


namespace mat
{


// Animation controller for transparent material.
class SYNKRO_API TransparentMaterialAnimationController :
	public SimpleMaterialAnimationControllerImpl<ITransparentMaterialAnimationController>
{
public:
	// Constructor.
	TransparentMaterialAnimationController( ITransparentMaterial* transparentMaterial, anim::IAnimationSystem* animationSystem, anim::IAnimation* animation, anim::AnimationListener* listener );

	// IController methods.
	void													Update( Double delta );

	// IAnimationController methods.
	void													SetAnimation( anim::IAnimation* animation );

	// ISimpleMaterialAnimationController methods.
	ITransparentMaterialAnimationController*				AsTransparent() const;

	// ITransparentMaterialAnimationController methods.
	anim::IKeyframedFloatTrack*								CreateOpacityTrack();
	anim::IProceduralFloatTrack*							CreateOpacityTrack( const anim::AnimationTrack& type );
	anim::IExpressionFloatTrack*							CreateOpacityTrack( anim::IExpressionScript* script );
	anim::IExpressionFloatTrack*							CreateOpacityTrack( const lang::String& expression );

private:
	ITransparentMaterial*									_transparentMaterial;
	anim::IAnimationFloatTrack*								_trackOpacity;
};


} // mat


} // synkro


#endif // _SYNKRO_MAT_TRANSPARENTMATERIALANIMATIONCONTROLLER_
