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
// Purpose: Implements animation controller for line set.
//==============================================================================
#ifndef _SYNKRO_SCENE_LINESETANIMATIONCONTROLLER_
#define _SYNKRO_SCENE_LINESETANIMATIONCONTROLLER_


#include "config.h"
#include "PrimitiveAnimationControllerImpl.h"
#include <scene/ILineSetAnimationController.h>


namespace synkro
{


namespace scene
{


// Animation controller for line set implementation.
class LineSetAnimationController :
	public PrimitiveAnimationControllerImpl<ILineSetAnimationController>
{
public:
	// Constructor.
	LineSetAnimationController( ILineSet* lineSet, anim::IAnimationSystem* animationSystem, anim::IAnimationSet* animations, anim::AnimationListener* listener );

	// IController methods.
	void													Update( Double delta );

	// IPrimitiveAnimationController methods.
	ILineSetAnimationController*							AsLineSet() const;

	// ILineSetAnimationController methods.
	anim::IKeyframedColorTrack*								CreateColorTrack();
	anim::IProceduralColorTrack*							CreateColorTrack( const anim::AnimationTrack& type );
	anim::IExpressionColorTrack*							CreateColorTrack( anim::IExpressionScript* script );
	anim::IExpressionColorTrack*							CreateColorTrack( const lang::String& expression );

	// Other methods.
	void													UpdateTracks();

private:
	ILineSet*												_lineSet;
	anim::IAnimationColorTrack*								_trackColor;
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_LINESETANIMATIONCONTROLLER_
