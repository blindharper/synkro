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
// Purpose: Animation controller for generic node.
//==============================================================================
#ifndef _SYNKRO_SCENE_NODEANIMATIONCONTROLLERIMPL_
#define _SYNKRO_SCENE_NODEANIMATIONCONTROLLERIMPL_


#include "config.h"
#include <anim/PlaybackControllerImpl.h>
#include <scene/INodeAnimationController.h>
#include <scene/ILookAtConstraint.h>
#include <scene/IParentConstraint.h>
#include <scene/INode.h>
#include "NodeProperty.h"


namespace synkro
{


namespace scene
{


// Animation controller for generic node.
template <class T>
class NodeAnimationControllerImpl :
	public anim::PlaybackControllerImpl<T>
{
public:
	// Constructor & destructor.
	NodeAnimationControllerImpl( INode* node, anim::IAnimationSystem* animationSystem, anim::IAnimation* animation, anim::AnimationListener* listener );
	virtual ~NodeAnimationControllerImpl();

	// IController methods.
	virtual void											Update( Double delta );

	// IAnimationController methods.
	virtual void											SetAnimation( anim::IAnimation* animation );

	// INodeAnimationController methods.
	virtual anim::IKeyframedMatrix4x4Track*					CreateTransformTrack();
	virtual anim::IExpressionMatrix4x4Track*				CreateTransformTrack( anim::IExpressionScript* script );
	virtual anim::IExpressionMatrix4x4Track*				CreateTransformTrack( const lang::String& expression );
	virtual anim::IKeyframedVector3Track*					CreatePositionTrack();
	virtual anim::IProceduralVector3Track*					CreatePositionTrack( const anim::AnimationTrack& type );
	virtual anim::IExpressionVector3Track*					CreatePositionTrack( anim::IExpressionScript* script );
	virtual anim::IExpressionVector3Track*					CreatePositionTrack( const lang::String& expression );
	virtual anim::IKeyframedFloatTrack*						CreatePositionXTrack();
	virtual anim::IProceduralFloatTrack*					CreatePositionXTrack( const anim::AnimationTrack& type );
	virtual anim::IExpressionFloatTrack*					CreatePositionXTrack( anim::IExpressionScript* script );
	virtual anim::IExpressionFloatTrack*					CreatePositionXTrack( const lang::String& expression );
	virtual anim::IKeyframedFloatTrack*						CreatePositionYTrack();
	virtual anim::IProceduralFloatTrack*					CreatePositionYTrack( const anim::AnimationTrack& type );
	virtual anim::IExpressionFloatTrack*					CreatePositionYTrack( anim::IExpressionScript* script );
	virtual anim::IExpressionFloatTrack*					CreatePositionYTrack( const lang::String& expression );
	virtual anim::IKeyframedFloatTrack*						CreatePositionZTrack();
	virtual anim::IProceduralFloatTrack*					CreatePositionZTrack( const anim::AnimationTrack& type );
	virtual anim::IExpressionFloatTrack*					CreatePositionZTrack( anim::IExpressionScript* script );
	virtual anim::IExpressionFloatTrack*					CreatePositionZTrack( const lang::String& expression );
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
	virtual anim::IKeyframedVector3Track*					CreateScaleTrack();
	virtual anim::IProceduralVector3Track*					CreateScaleTrack( const anim::AnimationTrack& type );
	virtual anim::IExpressionVector3Track*					CreateScaleTrack( anim::IExpressionScript* script );
	virtual anim::IExpressionVector3Track*					CreateScaleTrack( const lang::String& expression );
	virtual anim::IKeyframedFloatTrack*						CreateScaleXTrack();
	virtual anim::IProceduralFloatTrack*					CreateScaleXTrack( const anim::AnimationTrack& type );
	virtual anim::IExpressionFloatTrack*					CreateScaleXTrack( anim::IExpressionScript* script );
	virtual anim::IExpressionFloatTrack*					CreateScaleXTrack( const lang::String& expression );
	virtual anim::IKeyframedFloatTrack*						CreateScaleYTrack();
	virtual anim::IProceduralFloatTrack*					CreateScaleYTrack( const anim::AnimationTrack& type );
	virtual anim::IExpressionFloatTrack*					CreateScaleYTrack( anim::IExpressionScript* script );
	virtual anim::IExpressionFloatTrack*					CreateScaleYTrack( const lang::String& expression );
	virtual anim::IKeyframedFloatTrack*						CreateScaleZTrack();
	virtual anim::IProceduralFloatTrack*					CreateScaleZTrack( const anim::AnimationTrack& type );
	virtual anim::IExpressionFloatTrack*					CreateScaleZTrack( anim::IExpressionScript* script );
	virtual anim::IExpressionFloatTrack*					CreateScaleZTrack( const lang::String& expression );
	virtual anim::IKeyframedFloatTrack*						CreateScaleUniformTrack();
	virtual anim::IProceduralFloatTrack*					CreateScaleUniformTrack( const anim::AnimationTrack& type );
	virtual anim::IExpressionFloatTrack*					CreateScaleUniformTrack( anim::IExpressionScript* script );
	virtual anim::IExpressionFloatTrack*					CreateScaleUniformTrack( const lang::String& expression );
	virtual anim::IKeyframedFloatTrack*						CreatePathPhaseTrack();
	virtual anim::IProceduralFloatTrack*					CreatePathPhaseTrack( const anim::AnimationTrack& type );
	virtual ICameraAnimationController*						AsCamera() const;
	virtual ILightAnimationController*						AsLight() const;
	virtual IMeshBatchAnimationController*					AsMeshBatch() const;
	virtual ISoundAnimationController*						AsSound() const;

protected:
	INode*													_node;
	anim::IAnimationMatrix4x4Track*							_trackTransform;
	anim::IAnimationVector3Track*							_trackPosition;
	anim::IAnimationFloatTrack*								_trackPositionX;
	anim::IAnimationFloatTrack*								_trackPositionY;
	anim::IAnimationFloatTrack*								_trackPositionZ;
	anim::IAnimationQuaternionTrack*						_trackOrientation;
	anim::IAnimationFloatTrack*								_trackOrientationYaw;
	anim::IAnimationFloatTrack*								_trackOrientationPitch;
	anim::IAnimationFloatTrack*								_trackOrientationRoll;
	anim::IAnimationVector3Track*							_trackScale;
	anim::IAnimationFloatTrack*								_trackScaleX;
	anim::IAnimationFloatTrack*								_trackScaleY;
	anim::IAnimationFloatTrack*								_trackScaleZ;
	anim::IAnimationFloatTrack*								_trackScaleUniform;
	anim::IAnimationFloatTrack*								_trackPathPhase;
};


#include "NodeAnimationControllerImpl.inl"


} // scene


} // synkro


#endif // _SYNKRO_SCENE_NODEANIMATIONCONTROLLERIMPL_
