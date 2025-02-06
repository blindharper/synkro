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
// Purpose: Defines animation controller for an abstract node.
//==============================================================================
#ifndef _SYNKRO_SCENE_INODEANIMATIONCONTROLLER_
#define _SYNKRO_SCENE_INODEANIMATIONCONTROLLER_


#include "config.h"
#include <anim/IPlaybackAnimationController.h>


namespace synkro
{


namespace scene
{


/**
 * Animation controller for an abstract node.
 */
iface INodeAnimationController :
	public anim::IPlaybackAnimationController
{
public:
	/**
	 * Creates keyframed track controlling node transformation.
	 * @return Created transformation track.
	 * @exception BadArgumentException Transformation track already exists.
	 */
	virtual anim::IKeyframedMatrix4x4Track*					CreateTransformTrack() = 0;

	/**
	 * Creates expression track controlling node transformation.
	 * @param script Expression script.
	 * @return Created transformation track.
	 * @exception BadArgumentException Transformation track already exists.
	 */
	virtual anim::IExpressionMatrix4x4Track*				CreateTransformTrack( anim::IExpressionScript* script ) = 0;

	/**
	 * Creates expression track controlling node transformation.
	 * @param expression Expression text.
	 * @return Created transformation track.
	 * @exception BadArgumentException Transformation track already exists.
	 */
	virtual anim::IExpressionMatrix4x4Track*				CreateTransformTrack( const lang::String& expression ) = 0;

	/**
	 * Creates keyframed track controlling node position.
	 * @return Created position track.
	 * @exception BadArgumentException Position track already exists.
	 */
	virtual anim::IKeyframedVector3Track*					CreatePositionTrack() = 0;

	/**
	 * Creates procedural track controlling node position.
	 * @param type Track type.
	 * @return Created position track.
	 * @exception BadArgumentException Position track already exists.
	 */
	virtual anim::IProceduralVector3Track*					CreatePositionTrack( const anim::AnimationTrack& type ) = 0;

	/**
	 * Creates expression track controlling node position.
	 * @param script Expression script.
	 * @return Created position track.
	 * @exception BadArgumentException Position track already exists.
	 */
	virtual anim::IExpressionVector3Track*					CreatePositionTrack( anim::IExpressionScript* script ) = 0;

	/**
	 * Creates expression track controlling node position.
	 * @param expression Expression text.
	 * @return Created position track.
	 * @exception BadArgumentException Position track already exists.
	 */
	virtual anim::IExpressionVector3Track*					CreatePositionTrack( const lang::String& expression ) = 0;

	/**
	 * Creates keyframed track controlling node's X coordinate.
	 * @return Created X coordinate track.
	 * @exception BadArgumentException X coordinate track already exists.
	 */
	virtual anim::IKeyframedFloatTrack*						CreatePositionXTrack() = 0;

	/**
	 * Creates procedural track controlling node's X coordinate.
	 * @param type Track type.
	 * @return Created X coordinate track.
	 * @exception BadArgumentException X coordinate track already exists.
	 */
	virtual anim::IProceduralFloatTrack*					CreatePositionXTrack( const anim::AnimationTrack& type ) = 0;

	/**
	 * Creates expression track controlling node's X coordinate.
	 * @param script Expression script.
	 * @return Created X coordinate track.
	 * @exception BadArgumentException X coordinate track already exists.
	 */
	virtual anim::IExpressionFloatTrack*					CreatePositionXTrack( anim::IExpressionScript* script ) = 0;

	/**
	 * Creates expression track controlling node's X coordinate.
	 * @param expression Expression text.
	 * @return Created X coordinate track.
	 * @exception BadArgumentException X coordinate track already exists.
	 */
	virtual anim::IExpressionFloatTrack*					CreatePositionXTrack( const lang::String& expression ) = 0;

	/**
	 * Creates keyframed track controlling node's Y coordinate.
	 * @return Created Y coordinate track.
	 * @exception BadArgumentException Y coordinate track already exists.
	 */
	virtual anim::IKeyframedFloatTrack*						CreatePositionYTrack() = 0;

	/**
	 * Creates procedural track controlling node's Y coordinate.
	 * @param type Track type.
	 * @return Created Y coordinate track.
	 * @exception BadArgumentException Y coordinate track already exists.
	 */
	virtual anim::IProceduralFloatTrack*					CreatePositionYTrack( const anim::AnimationTrack& type ) = 0;

	/**
	 * Creates expression track controlling node's Y coordinate.
	 * @param script Expression script.
	 * @return Created Y coordinate track.
	 * @exception BadArgumentException Y coordinate track already exists.
	 */
	virtual anim::IExpressionFloatTrack*					CreatePositionYTrack( anim::IExpressionScript* script ) = 0;

	/**
	 * Creates expression track controlling node's Y coordinate.
	 * @param expression Expression text.
	 * @return Created Y coordinate track.
	 * @exception BadArgumentException Y coordinate track already exists.
	 */
	virtual anim::IExpressionFloatTrack*					CreatePositionYTrack( const lang::String& expression ) = 0;

	/**
	 * Creates keyframed track controlling node's Z coordinate.
	 * @return Created Z coordinate track.
	 * @exception BadArgumentException Z coordinate track already exists.
	 */
	virtual anim::IKeyframedFloatTrack*						CreatePositionZTrack() = 0;

	/**
	 * Creates procedural track controlling node's Z coordinate.
	 * @param type Track type.
	 * @return Created Z coordinate track.
	 * @exception BadArgumentException Z coordinate track already exists.
	 */
	virtual anim::IProceduralFloatTrack*					CreatePositionZTrack( const anim::AnimationTrack& type ) = 0;

	/**
	 * Creates expression track controlling node's Z coordinate.
	 * @param script Expression script.
	 * @return Created Z coordinate track.
	 * @exception BadArgumentException Z coordinate track already exists.
	 */
	virtual anim::IExpressionFloatTrack*					CreatePositionZTrack( anim::IExpressionScript* script ) = 0;

	/**
	 * Creates expression track controlling node's Z coordinate.
	 * @param expression Expression text.
	 * @return Created Z coordinate track.
	 * @exception BadArgumentException Z coordinate track already exists.
	 */
	virtual anim::IExpressionFloatTrack*					CreatePositionZTrack( const lang::String& expression ) = 0;

	/**
	 * Creates keyframed track controlling node orientation.
	 * @return Created orientation track.
	 * @exception BadArgumentException Orientation track already exists.
	 */
	virtual anim::IKeyframedQuaternionTrack*				CreateOrientationTrack() = 0;

	/**
	 * Creates expression track controlling node orientation.
	 * @param script Expression script.
	 * @return Created orientation track.
	 * @exception BadArgumentException Orientation track already exists.
	 */
	virtual anim::IExpressionQuaternionTrack*				CreateOrientationTrack( anim::IExpressionScript* script ) = 0;

	/**
	 * Creates expression track controlling node orientation.
	 * @param expression Expression text.
	 * @return Created orientation track.
	 * @exception BadArgumentException Orientation track already exists.
	 */
	virtual anim::IExpressionQuaternionTrack*				CreateOrientationTrack( const lang::String& expression ) = 0;

	/**
	 * Creates keyframed track controlling node's yaw angle.
	 * @return Created yaw angle track.
	 * @exception BadArgumentException Yaw angle track already exists.
	 */
	virtual anim::IKeyframedFloatTrack*						CreateOrientationYawTrack() = 0;

	/**
	 * Creates procedural track controlling node's yaw angle.
	 * @param type Track type.
	 * @return Created yaw angle track.
	 * @exception BadArgumentException Yaw angle track already exists.
	 */
	virtual anim::IProceduralFloatTrack*					CreateOrientationYawTrack( const anim::AnimationTrack& type ) = 0;

	/**
	 * Creates expression track controlling node's yaw angle.
	 * @param script Expression script.
	 * @return Created yaw angle track.
	 * @exception BadArgumentException Yaw angle track already exists.
	 */
	virtual anim::IExpressionFloatTrack*					CreateOrientationYawTrack( anim::IExpressionScript* script ) = 0;

	/**
	 * Creates expression track controlling node's yaw angle.
	 * @param expression Expression text.
	 * @return Created yaw angle track.
	 * @exception BadArgumentException Yaw angle track already exists.
	 */
	virtual anim::IExpressionFloatTrack*					CreateOrientationYawTrack( const lang::String& expression ) = 0;

	/**
	 * Creates keyframed track controlling node's pitch angle.
	 * @return Created pitch angle track.
	 * @exception BadArgumentException Pitch angle track already exists.
	 */
	virtual anim::IKeyframedFloatTrack*						CreateOrientationPitchTrack() = 0;

	/**
	 * Creates procedural track controlling node's pitch angle.
	 * @param type Track type.
	 * @return Created pitch angle track.
	 * @exception BadArgumentException Pitch angle track already exists.
	 */
	virtual anim::IProceduralFloatTrack*					CreateOrientationPitchTrack( const anim::AnimationTrack& type ) = 0;

	/**
	 * Creates expression track controlling node's pitch angle.
	 * @param script Expression script.
	 * @return Created pitch angle track.
	 * @exception BadArgumentException Pitch angle track already exists.
	 */
	virtual anim::IExpressionFloatTrack*					CreateOrientationPitchTrack( anim::IExpressionScript* script ) = 0;

	/**
	 * Creates expression track controlling node's pitch angle.
	 * @param expression Expression text.
	 * @return Created pitch angle track.
	 * @exception BadArgumentException Pitch angle track already exists.
	 */
	virtual anim::IExpressionFloatTrack*					CreateOrientationPitchTrack( const lang::String& expression ) = 0;

	/**
	 * Creates keyframed track controlling node's roll angle.
	 * @return Created roll angle track.
	 * @exception BadArgumentException Roll angle track already exists.
	 */
	virtual anim::IKeyframedFloatTrack*						CreateOrientationRollTrack() = 0;

	/**
	 * Creates procedural track controlling node's roll angle.
	 * @param type Track type.
	 * @return Created roll angle track.
	 * @exception BadArgumentException Roll angle track already exists.
	 */
	virtual anim::IProceduralFloatTrack*					CreateOrientationRollTrack( const anim::AnimationTrack& type ) = 0;

	/**
	 * Creates expression track controlling node's roll angle.
	 * @param script Expression script.
	 * @return Created roll angle track.
	 * @exception BadArgumentException Roll angle track already exists.
	 */
	virtual anim::IExpressionFloatTrack*					CreateOrientationRollTrack( anim::IExpressionScript* script ) = 0;

	/**
	 * Creates expression track controlling node's roll angle.
	 * @param expression Expression text.
	 * @return Created roll angle track.
	 * @exception BadArgumentException Roll angle track already exists.
	 */
	virtual anim::IExpressionFloatTrack*					CreateOrientationRollTrack( const lang::String& expression ) = 0;

	/**
	 * Creates keyframed track controlling node scale.
	 * @return Created scale track.
	 * @exception BadArgumentException Scale track already exists.
	 */
	virtual anim::IKeyframedVector3Track*					CreateScaleTrack() = 0;

	/**
	 * Creates procedural track controlling node scale.
	 * @param type Track type.
	 * @return Created scale track.
	 * @exception BadArgumentException Scale track already exists.
	 */
	virtual anim::IProceduralVector3Track*					CreateScaleTrack( const anim::AnimationTrack& type ) = 0;

	/**
	 * Creates expression track controlling node scale.
	 * @param script Expression script.
	 * @return Created orientation track.
	 * @exception BadArgumentException Orientation track already exists.
	 */
	virtual anim::IExpressionVector3Track*					CreateScaleTrack( anim::IExpressionScript* script ) = 0;

	/**
	 * Creates expression track controlling node scale.
	 * @param expression Expression text.
	 * @return Created orientation track.
	 * @exception BadArgumentException Orientation track already exists.
	 */
	virtual anim::IExpressionVector3Track*					CreateScaleTrack( const lang::String& expression ) = 0;

	/**
	 * Creates keyframed track controlling node scale along X axis.
	 * @return Created X scale track.
	 * @exception BadArgumentException X scale track already exists.
	 */
	virtual anim::IKeyframedFloatTrack*						CreateScaleXTrack() = 0;

	/**
	 * Creates procedural track controlling node scale along X axis.
	 * @param type Track type.
	 * @return Created X scale track.
	 * @exception BadArgumentException X scale track already exists.
	 */
	virtual anim::IProceduralFloatTrack*					CreateScaleXTrack( const anim::AnimationTrack& type ) = 0;

	/**
	 * Creates expression track controlling node scale along X axis.
	 * @param script Expression script.
	 * @return Created X scale track.
	 * @exception BadArgumentException X scale track already exists.
	 */
	virtual anim::IExpressionFloatTrack*					CreateScaleXTrack( anim::IExpressionScript* script ) = 0;

	/**
	 * Creates expression track controlling node scale along X axis.
	 * @param expression Expression text.
	 * @return Created X scale track.
	 * @exception BadArgumentException X scale track already exists.
	 */
	virtual anim::IExpressionFloatTrack*					CreateScaleXTrack( const lang::String& expression ) = 0;

	/**
	 * Creates keyframed track controlling node scale along Y axis.
	 * @return Created Y scale track.
	 * @exception BadArgumentException Y scale track already exists.
	 */
	virtual anim::IKeyframedFloatTrack*						CreateScaleYTrack() = 0;

	/**
	 * Creates procedural track controlling node scale along Y axis.
	 * @param type Track type.
	 * @return Created Y scale track.
	 * @exception BadArgumentException Y scale track already exists.
	 */
	virtual anim::IProceduralFloatTrack*					CreateScaleYTrack( const anim::AnimationTrack& type ) = 0;

	/**
	 * Creates expression track controlling node scale along Y axis.
	 * @param script Expression script.
	 * @return Created Y scale track.
	 * @exception BadArgumentException Y scale track already exists.
	 */
	virtual anim::IExpressionFloatTrack*					CreateScaleYTrack( anim::IExpressionScript* script ) = 0;

	/**
	 * Creates expression track controlling node scale along Y axis.
	 * @param expression Expression text.
	 * @return Created Y scale track.
	 * @exception BadArgumentException Y scale track already exists.
	 */
	virtual anim::IExpressionFloatTrack*					CreateScaleYTrack( const lang::String& expression ) = 0;

	/**
	 * Creates keyframed track controlling node scale along Z axis.
	 * @return Created Z scale track.
	 * @exception BadArgumentException Z scale track already exists.
	 */
	virtual anim::IKeyframedFloatTrack*						CreateScaleZTrack() = 0;

	/**
	 * Creates procedural track controlling node scale along Z axis.
	 * @param type Track type.
	 * @return Created Z scale track.
	 * @exception BadArgumentException Z scale track already exists.
	 */
	virtual anim::IProceduralFloatTrack*					CreateScaleZTrack( const anim::AnimationTrack& type ) = 0;

	/**
	 * Creates expression track controlling node scale along Z axis.
	 * @param script Expression script.
	 * @return Created Z scale track.
	 * @exception BadArgumentException Z scale track already exists.
	 */
	virtual anim::IExpressionFloatTrack*					CreateScaleZTrack( anim::IExpressionScript* script ) = 0;

	/**
	 * Creates expression track controlling node scale along Z axis.
	 * @param expression Expression text.
	 * @return Created Z scale track.
	 * @exception BadArgumentException Z scale track already exists.
	 */
	virtual anim::IExpressionFloatTrack*					CreateScaleZTrack( const lang::String& expression ) = 0;

	/**
	 * Creates keyframed track controlling node uniform scale.
	 * @return Created scale track.
	 * @exception BadArgumentException Uniform scale track already exists.
	 */
	virtual anim::IKeyframedFloatTrack*						CreateScaleUniformTrack() = 0;

	/**
	 * Creates procedural track controlling node uniform scale.
	 * @param type Track type.
	 * @return Created scale track.
	 * @exception BadArgumentException Uniform scale track already exists.
	 */
	virtual anim::IProceduralFloatTrack*					CreateScaleUniformTrack( const anim::AnimationTrack& type ) = 0;

	/**
	 * Creates expression track controlling node uniform scale.
	 * @param script Expression script.
	 * @return Created scale track.
	 * @exception BadArgumentException Uniform scale track already exists.
	 */
	virtual anim::IExpressionFloatTrack*					CreateScaleUniformTrack( anim::IExpressionScript* script ) = 0;

	/**
	 * Creates expression track controlling node uniform scale.
	 * @param expression Expression text.
	 * @return Created scale track.
	 * @exception BadArgumentException Uniform scale track already exists.
	 */
	virtual anim::IExpressionFloatTrack*					CreateScaleUniformTrack( const lang::String& expression ) = 0;

	/**
	 * Creates keyframed track controlling node path phase.
	 * @return Created path phase track.
	 * @exception BadArgumentException Path phase track already exists.
	 */
	virtual anim::IKeyframedFloatTrack*						CreatePathPhaseTrack() = 0;

	/**
	 * Creates procedural track controlling node path phase.
	 * @param type Track type.
	 * @return Created path phase track.
	 * @exception BadArgumentException Path phase track already exists.
	 */
	virtual anim::IProceduralFloatTrack*					CreatePathPhaseTrack( const anim::AnimationTrack& type ) = 0;

	/**
	 * Casts node controller to camera controller.
	 * @return Non-null for camera controller, nullptr otherwise.
	 */
	virtual ICameraAnimationController*						AsCamera() const = 0;

	/**
	 * Casts node controller to light controller.
	 * @return Non-null for light controller, nullptr otherwise.
	 */
	virtual ILightAnimationController*						AsLight() const = 0;

	/**
	 * Casts node controller to mesh batch controller.
	 * @return Non-null for mesh batch controller, nullptr otherwise.
	 */
	virtual IMeshBatchAnimationController*					AsMeshBatch() const = 0;

	/**
	 * Casts node controller to sound controller.
	 * @return Non-null for sound controller, nullptr otherwise.
	 */
	virtual ISoundAnimationController*						AsSound() const = 0;
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_INODEANIMATIONCONTROLLER_
