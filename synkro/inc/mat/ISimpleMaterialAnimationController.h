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
// Purpose: Defines animation controller for simple material.
//==============================================================================
#ifndef _SYNKRO_MAT_ISIMPLEMATERIALANIMATIONCONTROLLER_
#define _SYNKRO_MAT_ISIMPLEMATERIALANIMATIONCONTROLLER_


#include "config.h"
#include <mat/IVisualMaterialAnimationController.h>


namespace synkro
{


namespace mat
{


/**
 * Animation controller for simple material.
 */
iface ISimpleMaterialAnimationController :
	public IVisualMaterialAnimationController
{
public:
	/**
	 * Creates keyframed track controlling material's diffuse color.
	 * @return Created diffuse color track.
	 * @exception BadArgumentException Diffuse color track already exists.
	 */
	virtual anim::IKeyframedColorTrack*						CreateDiffuseColorTrack() = 0;

	/**
	 * Creates procedural track controlling material's diffuse color.
	 * @param type Track type.
	 * @return Created diffuse color track.
	 * @exception BadArgumentException Diffuse color track already exists.
	 */
	virtual anim::IProceduralColorTrack*					CreateDiffuseColorTrack( const anim::AnimationTrack& type ) = 0;

	/**
	 * Creates expression track controlling material's diffuse color.
	 * @param script Expression script.
	 * @return Created diffuse color track.
	 */
	virtual anim::IExpressionColorTrack*					CreateDiffuseColorTrack( anim::IExpressionScript* script ) = 0;

	/**
	 * Creates expression track controlling material's diffuse color.
	 * @param expression Expression text.
	 * @return Created diffuse color track.
	 */
	virtual anim::IExpressionColorTrack*					CreateDiffuseColorTrack( const lang::String& expression ) = 0;

	/**
	 * Creates keyframed track controlling material's ambient color.
	 * @return Created ambient color track.
	 * @exception BadArgumentException Ambient color track already exists.
	 */
	virtual anim::IKeyframedColorTrack*						CreateAmbientColorTrack() = 0;

	/**
	 * Creates procedural track controlling material's ambient color.
	 * @param type Track type.
	 * @return Created ambient color track.
	 * @exception BadArgumentException Ambient color track already exists.
	 */
	virtual anim::IProceduralColorTrack*					CreateAmbientColorTrack( const anim::AnimationTrack& type ) = 0;

	/**
	 * Creates expression track controlling material's ambient color.
	 * @param script Expression script.
	 * @return Created ambient color track.
	 */
	virtual anim::IExpressionColorTrack*					CreateAmbientColorTrack( anim::IExpressionScript* script ) = 0;

	/**
	 * Creates expression track controlling material's ambient color.
	 * @param expression Expression text.
	 * @return Created ambient color track.
	 */
	virtual anim::IExpressionColorTrack*					CreateAmbientColorTrack( const lang::String& expression ) = 0;

	/**
	 * Creates keyframed track controlling material's emissive color.
	 * @return Created emissive color track.
	 * @exception BadArgumentException Emissive color track already exists.
	 */
	virtual anim::IKeyframedColorTrack*						CreateEmissiveColorTrack() = 0;

	/**
	 * Creates procedural track controlling material's emissive color.
	 * @param type Track type.
	 * @return Created emissive color track.
	 * @exception BadArgumentException Emissive color track already exists.
	 */
	virtual anim::IProceduralColorTrack*					CreateEmissiveColorTrack( const anim::AnimationTrack& type ) = 0;

	/**
	 * Creates expression track controlling material's emissive color.
	 * @param script Expression script.
	 * @return Created ambient color track.
	 */
	virtual anim::IExpressionColorTrack*					CreateEmissiveColorTrack( anim::IExpressionScript* script ) = 0;

	/**
	 * Creates expression track controlling material's emissive color.
	 * @param expression Expression text.
	 * @return Created ambient color track.
	 */
	virtual anim::IExpressionColorTrack*					CreateEmissiveColorTrack( const lang::String& expression ) = 0;

	/**
	 * Creates keyframed track controlling material's specular color.
	 * @return Created specular color track.
	 * @exception BadArgumentException Specular color track already exists.
	 */
	virtual anim::IKeyframedColorTrack*						CreateSpecularColorTrack() = 0;

	/**
	 * Creates procedural track controlling material's specular color.
	 * @param type Track type.
	 * @return Created specular color track.
	 * @exception BadArgumentException Specular color track already exists.
	 */
	virtual anim::IProceduralColorTrack*					CreateSpecularColorTrack( const anim::AnimationTrack& type ) = 0;

	/**
	 * Creates expression track controlling material's specular color.
	 * @param script Expression script.
	 * @return Created specular color track.
	 */
	virtual anim::IExpressionColorTrack*					CreateSpecularColorTrack( anim::IExpressionScript* script ) = 0;

	/**
	 * Creates expression track controlling material's specular color.
	 * @param expression Expression text.
	 * @return Created specular color track.
	 */
	virtual anim::IExpressionColorTrack*					CreateSpecularColorTrack( const lang::String& expression ) = 0;

	/**
	 * Creates keyframed track controlling material's specular highlights power.
	 * @return Created specular power track.
	 * @exception BadArgumentException Specular color power already exists.
	 */
	virtual anim::IKeyframedFloatTrack*						CreateSpecularPowerTrack() = 0;

	/**
	 * Creates procedural track controlling material's specular highlights power.
	 * @param type Track type.
	 * @return Created specular power track.
	 * @exception BadArgumentException Specular color power already exists.
	 */
	virtual anim::IProceduralFloatTrack*					CreateSpecularPowerTrack( const anim::AnimationTrack& type ) = 0;

	/**
	 * Creates expression track controlling material's specular highlights power.
	 * @param script Expression script.
	 * @return Created specular power track.
	 */
	virtual anim::IExpressionFloatTrack*					CreateSpecularPowerTrack( anim::IExpressionScript* script ) = 0;

	/**
	 * Creates expression track controlling material's specular highlights power.
	 * @param expression Expression text.
	 * @return Created specular power track.
	 */
	virtual anim::IExpressionFloatTrack*					CreateSpecularPowerTrack( const lang::String& expression ) = 0;

	/**
	 * Casts controller to transparent material controller.
	 * @return Non-null for transparent material controller, nullptr otherwise.
	 */
	virtual ITransparentMaterialAnimationController*		AsTransparent() const = 0;
};


} // mat


} // synkro


#endif // _SYNKRO_MAT_ISIMPLEMATERIALANIMATIONCONTROLLER_
