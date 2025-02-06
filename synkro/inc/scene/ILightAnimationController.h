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
// Purpose: Defines animation controller for light node.
//==============================================================================
#ifndef _SYNKRO_SCENE_ILIGHTANIMATIONCONTROLLER_
#define _SYNKRO_SCENE_ILIGHTANIMATIONCONTROLLER_


#include "config.h"
#include <scene/INodeAnimationController.h>


namespace synkro
{


namespace scene
{


/**
 * Animation controller for light node.
 */
iface ILightAnimationController :
	public INodeAnimationController
{
public:
	/**
	 * Creates keyframed track controlling light diffuse color.
	 * @return Created diffuse color track.
	 * @exception BadArgumentException Diffuse color track already exists.
	 */
	virtual anim::IKeyframedColorTrack*						CreateDiffuseColorTrack() = 0;

	/**
	 * Creates procedural track controlling light diffuse color.
	 * @param type Track type.
	 * @return Created diffuse color track.
	 * @exception BadArgumentException Diffuse color track already exists.
	 */
	virtual anim::IProceduralColorTrack*					CreateDiffuseColorTrack( const anim::AnimationTrack& type ) = 0;

	/**
	 * Creates expression track controlling light diffuse color.
	 * @param script Expression script.
	 * @return Created diffuse color track.
	 * @exception BadArgumentException Diffuse color track already exists.
	 */
	virtual anim::IExpressionColorTrack*					CreateDiffuseColorTrack( anim::IExpressionScript* script ) = 0;

	/**
	 * Creates expression track controlling light diffuse color.
	 * @param expression Expression text.
	 * @return Created diffuse color track.
	 * @exception BadArgumentException Diffuse color track already exists.
	 */
	virtual anim::IExpressionColorTrack*					CreateDiffuseColorTrack( const lang::String& expression ) = 0;

	/**
	 * Creates keyframed track controlling light ambient color.
	 * @return Created ambient color track.
	 * @exception BadArgumentException Ambient color track already exists.
	 */
	virtual anim::IKeyframedColorTrack*						CreateAmbientColorTrack() = 0;

	/**
	 * Creates procedural track controlling light ambient color.
	 * @param type Track type.
	 * @return Created ambient color track.
	 * @exception BadArgumentException Ambient color track already exists.
	 */
	virtual anim::IProceduralColorTrack*					CreateAmbientColorTrack( const anim::AnimationTrack& type ) = 0;

	/**
	 * Creates expression track controlling light ambient color.
	 * @param script Expression script.
	 * @return Created ambient color track.
	 * @exception BadArgumentException Ambient color track already exists.
	 */
	virtual anim::IExpressionColorTrack*					CreateAmbientColorTrack( anim::IExpressionScript* script ) = 0;

	/**
	 * Creates expression track controlling light ambient color.
	 * @param expression Expression text.
	 * @return Created ambient color track.
	 * @exception BadArgumentException Ambient color track already exists.
	 */
	virtual anim::IExpressionColorTrack*					CreateAmbientColorTrack( const lang::String& expression ) = 0;

	/**
	 * Creates keyframed track controlling light specular color.
	 * @return Created specular color track.
	 * @exception BadArgumentException Specular color track already exists.
	 */
	virtual anim::IKeyframedColorTrack*						CreateSpecularColorTrack() = 0;

	/**
	 * Creates procedural track controlling light specular color.
	 * @param type Track type.
	 * @return Created specular color track.
	 * @exception BadArgumentException Specular color track already exists.
	 */
	virtual anim::IProceduralColorTrack*					CreateSpecularColorTrack( const anim::AnimationTrack& type ) = 0;

	/**
	 * Creates expression track controlling light specular color.
	 * @param script Expression script.
	 * @return Created specular color track.
	 * @exception BadArgumentException Specular color track already exists.
	 */
	virtual anim::IExpressionColorTrack*					CreateSpecularColorTrack( anim::IExpressionScript* script ) = 0;

	/**
	 * Creates expression track controlling light specular color.
	 * @param expression Expression text.
	 * @return Created specular color track.
	 * @exception BadArgumentException Specular color track already exists.
	 */
	virtual anim::IExpressionColorTrack*					CreateSpecularColorTrack( const lang::String& expression ) = 0;

	/**
	 * Creates keyframed track controlling light intensity.
	 * @return Created intensity track.
	 * @exception BadArgumentException Intensity track already exists.
	 */
	virtual anim::IKeyframedFloatTrack*						CreateIntensityTrack() = 0;

	/**
	 * Creates procedural track controlling light intensity.
	 * @param type Track type.
	 * @return Created intensity track.
	 * @exception BadArgumentException Intensity track already exists.
	 */
	virtual anim::IProceduralFloatTrack*					CreateIntensityTrack( const anim::AnimationTrack& type ) = 0;

	/**
	 * Creates expression track controlling light intensity.
	 * @param script Expression script.
	 * @return Created intensity track.
	 * @exception BadArgumentException Intensity track already exists.
	 */
	virtual anim::IExpressionFloatTrack*					CreateIntensityTrack( anim::IExpressionScript* script ) = 0;

	/**
	 * Creates expression track controlling light intensity.
	 * @param expression Expression text.
	 * @return Created intensity track.
	 * @exception BadArgumentException Intensity track already exists.
	 */
	virtual anim::IExpressionFloatTrack*					CreateIntensityTrack( const lang::String& expression ) = 0;

	/**
	 * Creates keyframed track controlling light availability.
	 */
	virtual anim::IKeyframedBoolTrack*						CreateAvailabilityTrack() = 0;

	/**
	 * Casts light controller to cone light controller.
	 * @return Non-null for cone light controller, nullptr otherwise.
	 */
	virtual IConeLightAnimationController*					AsCone() const = 0;

	/**
	 * Casts light controller to omni light controller.
	 * @return Non-null for omni light controller, nullptr otherwise.
	 */
	virtual IOmniLightAnimationController*					AsOmni() const = 0;
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_ILIGHTANIMATIONCONTROLLER_
