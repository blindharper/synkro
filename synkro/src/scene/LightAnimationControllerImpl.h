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
// Purpose: Animation controller for generic light source.
//==============================================================================
#ifndef _SYNKRO_SCENE_LIGHTANIMATIONCONTROLLERIMPL_
#define _SYNKRO_SCENE_LIGHTANIMATIONCONTROLLERIMPL_


#include "config.h"
#include "NodeAnimationControllerImpl.h"
#include <scene/ILightAnimationController.h>
#include "LightProperty.h"


namespace synkro
{


namespace scene
{


// Animation controller for generic light source.
template <class T>
class LightAnimationControllerImpl :
	public NodeAnimationControllerImpl<T>
{
public:
	// Constructor & destructor.
	LightAnimationControllerImpl( ILight* light, anim::IAnimationSystem* animationSystem, anim::IAnimation* animation, anim::AnimationListener* listener );
	virtual ~LightAnimationControllerImpl();

	// IController methods.
	virtual void											Update( Double delta );

	// IAnimationController methods.
	virtual void											SetAnimation( anim::IAnimation* animation );

	// INodeAnimationController methods.
	virtual ILightAnimationController*						AsLight() const;

	// ILightAnimationController methods.
	virtual anim::IKeyframedColorTrack*						CreateDiffuseColorTrack();
	virtual anim::IProceduralColorTrack*					CreateDiffuseColorTrack( const anim::AnimationTrack& type );
	virtual anim::IExpressionColorTrack*					CreateDiffuseColorTrack( anim::IExpressionScript* script );
	virtual anim::IExpressionColorTrack*					CreateDiffuseColorTrack( const lang::String& expression );
	virtual anim::IKeyframedColorTrack*						CreateAmbientColorTrack();
	virtual anim::IProceduralColorTrack*					CreateAmbientColorTrack( const anim::AnimationTrack& type );
	virtual anim::IExpressionColorTrack*					CreateAmbientColorTrack( anim::IExpressionScript* script );
	virtual anim::IExpressionColorTrack*					CreateAmbientColorTrack( const lang::String& expression );
	virtual anim::IKeyframedColorTrack*						CreateSpecularColorTrack();
	virtual anim::IProceduralColorTrack*					CreateSpecularColorTrack( const anim::AnimationTrack& type );
	virtual anim::IExpressionColorTrack*					CreateSpecularColorTrack( anim::IExpressionScript* script );
	virtual anim::IExpressionColorTrack*					CreateSpecularColorTrack( const lang::String& expression );
	virtual anim::IKeyframedFloatTrack*						CreateIntensityTrack();
	virtual anim::IProceduralFloatTrack*					CreateIntensityTrack( const anim::AnimationTrack& type );
	virtual anim::IExpressionFloatTrack*					CreateIntensityTrack( anim::IExpressionScript* script );
	virtual anim::IExpressionFloatTrack*					CreateIntensityTrack( const lang::String& expression );
	virtual anim::IKeyframedBoolTrack*						CreateAvailabilityTrack();
	virtual IConeLightAnimationController*					AsCone() const;
	virtual IOmniLightAnimationController*					AsOmni() const;

protected:
	ILight*													_light;
	anim::IAnimationColorTrack*								_trackDiffuse;
	anim::IAnimationColorTrack*								_trackAmbient;
	anim::IAnimationColorTrack*								_trackSpecular;
	anim::IAnimationFloatTrack*								_trackIntensity;
	anim::IAnimationBoolTrack*								_trackAvailability;
};


#include "LightAnimationControllerImpl.inl"


} // scene


} // synkro


#endif // _SYNKRO_SCENE_LIGHTANIMATIONCONTROLLERIMPL_
