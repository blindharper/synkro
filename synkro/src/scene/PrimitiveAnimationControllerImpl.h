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
// Purpose: Generic primitive animation controller implementation.
//==============================================================================
#ifndef _SYNKRO_SCENE_PRIMITIVEANIMATIONCONTROLLERIMPL_
#define _SYNKRO_SCENE_PRIMITIVEANIMATIONCONTROLLERIMPL_


#include "config.h"
#include <anim/PlaybackControllerImpl.h>
#include <scene/IPrimitive.h>
#include "PrimitiveProperty.h"


namespace synkro
{


namespace scene
{


// Generic primitive animation controller implementation.
template <class T>
class PrimitiveAnimationControllerImpl :
	public anim::PlaybackControllerImpl<T>
{
public:
	// Constructor & destructor.
	PrimitiveAnimationControllerImpl( IPrimitive* primitive, anim::IAnimationSystem* animationSystem, anim::IAnimation* animation, anim::AnimationListener* listener );
	virtual ~PrimitiveAnimationControllerImpl();

	// IController methods.
	virtual void											Update( Double delta );

	// IAnimationController methods.
	virtual void											SetAnimation( anim::IAnimation* animation );

	// IPrimitiveAnimationController methods.
	virtual anim::IKeyframedMatrix4x4Track*					CreateTransformTrack();
	virtual anim::IExpressionMatrix4x4Track*				CreateTransformTrack( anim::IExpressionScript* script );
	virtual anim::IExpressionMatrix4x4Track*				CreateTransformTrack( const lang::String& expression );
	virtual anim::IKeyframedQuaternionTrack*				CreateOrientationTrack();
	virtual anim::IExpressionQuaternionTrack*				CreateOrientationTrack( anim::IExpressionScript* script );
	virtual anim::IExpressionQuaternionTrack*				CreateOrientationTrack( const lang::String& expression );
	virtual anim::IKeyframedFloatTrack*						CreateOrientationYawTrack();
	virtual anim::IProceduralFloatTrack*					CreateOrientationYawTrack( const anim::AnimationTrack& type );
	virtual anim::IExpressionFloatTrack*					CreateOrientationYawTrack( anim::IExpressionScript* script );
	virtual anim::IExpressionFloatTrack*					CreateOrientationYawTrack( const lang::String& expression );
	virtual anim::IKeyframedFloatTrack*						CreateOrientationPitchTrack();
	virtual anim::IProceduralFloatTrack*					CreateOrientationPitchTrack( const anim::AnimationTrack& type );
	virtual anim::IExpressionFloatTrack*					CreateOrientationPitchTrack( anim::IExpressionScript* script );
	virtual anim::IExpressionFloatTrack*					CreateOrientationPitchTrack( const lang::String& expression );
	virtual anim::IKeyframedFloatTrack*						CreateOrientationRollTrack();
	virtual anim::IProceduralFloatTrack*					CreateOrientationRollTrack( const anim::AnimationTrack& type );
	virtual anim::IExpressionFloatTrack*					CreateOrientationRollTrack( anim::IExpressionScript* script );
	virtual anim::IExpressionFloatTrack*					CreateOrientationRollTrack( const lang::String& expression );
	virtual anim::IKeyframedRangeTrack*						CreateElementRangeTrack();
	virtual ILineSetAnimationController*					AsLineSet() const;
	virtual IPointSetAnimationController*					AsPointSet() const;

protected:
	IPrimitive*												_primitive;
	anim::IAnimationMatrix4x4Track*							_trackTransform;
	anim::IAnimationQuaternionTrack*						_trackOrientation;
	anim::IAnimationFloatTrack*								_trackOrientationYaw;
	anim::IAnimationFloatTrack*								_trackOrientationPitch;
	anim::IAnimationFloatTrack*								_trackOrientationRoll;
	anim::IAnimationRangeTrack*								_trackElementRange;
};


#include "PrimitiveAnimationControllerImpl.inl"


} // scene


} // synkro


#endif // _SYNKRO_SCENE_PRIMITIVEANIMATIONCONTROLLERIMPL_
