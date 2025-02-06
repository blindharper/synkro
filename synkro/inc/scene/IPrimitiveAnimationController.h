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
// Purpose: Defines animation controller for geometric primitive.
//==============================================================================
#ifndef _SYNKRO_SCENE_IPRIMITIVEANIMATIONCONTROLLER_
#define _SYNKRO_SCENE_IPRIMITIVEANIMATIONCONTROLLER_


#include "config.h"
#include <anim/IPlaybackAnimationController.h>


namespace synkro
{


namespace scene
{


/**
 * Animation controller for geometric primitive.
 */
iface IPrimitiveAnimationController :
	public anim::IPlaybackAnimationController
{
public:
	/**
	 * Creates keyframed track controlling primitive transformation.
	 * @return Created transformation track.
	 */
	virtual anim::IKeyframedMatrix4x4Track*					CreateTransformTrack() = 0;

	/**
	 * Creates expression track controlling primitive transformation.
	 * @param script Expression script.
	 * @return Created transformation track.
	 * @exception BadArgumentException Transformation track already exists.
	 */
	virtual anim::IExpressionMatrix4x4Track*				CreateTransformTrack( anim::IExpressionScript* script ) = 0;

	/**
	 * Creates expression track controlling primitive transformation.
	 * @param expression Expression text.
	 * @return Created transformation track.
	 * @exception BadArgumentException Transformation track already exists.
	 */
	virtual anim::IExpressionMatrix4x4Track*				CreateTransformTrack( const lang::String& expression ) = 0;

	/**
	 * Creates keyframed track controlling primitive orientation.
	 * @return Created orientation track.
	 */
	virtual anim::IKeyframedQuaternionTrack*				CreateOrientationTrack() = 0;

	/**
	 * Creates expression track controlling primitive orientation.
	 * @param script Expression script.
	 * @return Created orientation track.
	 * @exception BadArgumentException Orientation track already exists.
	 */
	virtual anim::IExpressionQuaternionTrack*				CreateOrientationTrack( anim::IExpressionScript* script ) = 0;

	/**
	 * Creates expression track controlling primitive orientation.
	 * @param expression Expression text.
	 * @return Created orientation track.
	 * @exception BadArgumentException Orientation track already exists.
	 */
	virtual anim::IExpressionQuaternionTrack*				CreateOrientationTrack( const lang::String& expression ) = 0;

	/**
	 * Creates keyframed track controlling primitive's yaw angle.
	 * @return Created yaw angle track.
	 * @exception BadArgumentException Yaw angle track already exists.
	 */
	virtual anim::IKeyframedFloatTrack*						CreateOrientationYawTrack() = 0;

	/**
	 * Creates procedural track controlling primitive's yaw angle.
	 * @param type Track type.
	 * @return Created yaw angle track.
	 * @exception BadArgumentException Yaw angle track already exists.
	 */
	virtual anim::IProceduralFloatTrack*					CreateOrientationYawTrack( const anim::AnimationTrack& type ) = 0;

	/**
	 * Creates expression track controlling primitive's yaw angle.
	 * @param script Expression script.
	 * @return Created yaw angle track.
	 * @exception BadArgumentException Yaw angle track already exists.
	 */
	virtual anim::IExpressionFloatTrack*					CreateOrientationYawTrack( anim::IExpressionScript* script ) = 0;

	/**
	 * Creates expression track controlling primitive's yaw angle.
	 * @param expression Expression text.
	 * @return Created yaw angle track.
	 * @exception BadArgumentException Yaw angle track already exists.
	 */
	virtual anim::IExpressionFloatTrack*					CreateOrientationYawTrack( const lang::String& expression ) = 0;

	/**
	 * Creates keyframed track controlling primitive's pitch angle.
	 * @return Created pitch angle track.
	 * @exception BadArgumentException Pitch angle track already exists.
	 */
	virtual anim::IKeyframedFloatTrack*						CreateOrientationPitchTrack() = 0;

	/**
	 * Creates procedural track controlling primitive's pitch angle.
	 * @param type Track type.
	 * @return Created pitch angle track.
	 * @exception BadArgumentException Pitch angle track already exists.
	 */
	virtual anim::IProceduralFloatTrack*					CreateOrientationPitchTrack( const anim::AnimationTrack& type ) = 0;

	/**
	 * Creates expression track controlling primitive's pitch angle.
	 * @param script Expression script.
	 * @return Created pitch angle track.
	 * @exception BadArgumentException Pitch angle track already exists.
	 */
	virtual anim::IExpressionFloatTrack*					CreateOrientationPitchTrack( anim::IExpressionScript* script ) = 0;

	/**
	 * Creates expression track controlling primitive's pitch angle.
	 * @param expression Expression text.
	 * @return Created pitch angle track.
	 * @exception BadArgumentException Pitch angle track already exists.
	 */
	virtual anim::IExpressionFloatTrack*					CreateOrientationPitchTrack( const lang::String& expression ) = 0;

	/**
	 * Creates keyframed track controlling primitive's roll angle.
	 * @return Created roll angle track.
	 * @exception BadArgumentException Roll angle track already exists.
	 */
	virtual anim::IKeyframedFloatTrack*						CreateOrientationRollTrack() = 0;

	/**
	 * Creates procedural track controlling primitive's roll angle.
	 * @param type Track type.
	 * @return Created roll angle track.
	 * @exception BadArgumentException Roll angle track already exists.
	 */
	virtual anim::IProceduralFloatTrack*					CreateOrientationRollTrack( const anim::AnimationTrack& type ) = 0;

	/**
	 * Creates expression track controlling primitive's roll angle.
	 * @param script Expression script.
	 * @return Created roll angle track.
	 * @exception BadArgumentException Roll angle track already exists.
	 */
	virtual anim::IExpressionFloatTrack*					CreateOrientationRollTrack( anim::IExpressionScript* script ) = 0;

	/**
	 * Creates expression track controlling primitive's roll angle.
	 * @param expression Expression text.
	 * @return Created roll angle track.
	 * @exception BadArgumentException Roll angle track already exists.
	 */
	virtual anim::IExpressionFloatTrack*					CreateOrientationRollTrack( const lang::String& expression ) = 0;

	/**
	 * Creates keyframed track controlling primitive element range.
	 * @return Created element range track.
	 */
	virtual anim::IKeyframedRangeTrack*						CreateElementRangeTrack() = 0;

	/**
	 * Casts controller to line set controller.
	 * @return Non-null for line set controller, nullptr otherwise.
	 */
	virtual ILineSetAnimationController*					AsLineSet() const = 0;

	/**
	 * Casts controller to point set controller.
	 * @return Non-null for point set controller, nullptr otherwise.
	 */
	virtual IPointSetAnimationController*					AsPointSet() const = 0;
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_IPRIMITIVEANIMATIONCONTROLLER_
