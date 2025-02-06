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
// Purpose: Animation controller for generic simple material.
//==============================================================================
#ifndef _SYNKRO_MAT_SIMPLEMATERIALANIMATIONCONTROLLERIMPL_
#define _SYNKRO_MAT_SIMPLEMATERIALANIMATIONCONTROLLERIMPL_


#include "config.h"
#include <anim/PlaybackControllerImpl.h>
#include <mat/ISimpleMaterial.h>
#include "SimpleMaterialProperty.h"


namespace synkro
{


namespace mat
{


// Animation controller for generic simple material.
template <class T>
class SimpleMaterialAnimationControllerImpl :
	public anim::PlaybackControllerImpl<T>
{
public:
	// Constructor & destructor.
	SimpleMaterialAnimationControllerImpl( ISimpleMaterial* material, anim::IAnimationSystem* animationSystem, anim::IAnimation* animation, anim::AnimationListener* listener );
	virtual ~SimpleMaterialAnimationControllerImpl();

	// IController methods.
	virtual void											Update( Double delta );

	// IAnimationController methods.
	virtual void											SetAnimation( anim::IAnimation* animation );

	// IVisualMaterialAnimationController methods.
	virtual ISimpleMaterialAnimationController*				AsSimple() const;

	// ISimpleMaterialAnimationController methods.
	virtual anim::IKeyframedColorTrack*						CreateDiffuseColorTrack();
	virtual anim::IProceduralColorTrack*					CreateDiffuseColorTrack( const anim::AnimationTrack& type );
	virtual anim::IExpressionColorTrack*					CreateDiffuseColorTrack( anim::IExpressionScript* script );
	virtual anim::IExpressionColorTrack*					CreateDiffuseColorTrack( const lang::String& expression );
	virtual anim::IKeyframedColorTrack*						CreateAmbientColorTrack();
	virtual anim::IProceduralColorTrack*					CreateAmbientColorTrack( const anim::AnimationTrack& type );
	virtual anim::IExpressionColorTrack*					CreateAmbientColorTrack( anim::IExpressionScript* script );
	virtual anim::IExpressionColorTrack*					CreateAmbientColorTrack( const lang::String& expression );
	virtual anim::IKeyframedColorTrack*						CreateEmissiveColorTrack();
	virtual anim::IProceduralColorTrack*					CreateEmissiveColorTrack( const anim::AnimationTrack& type );
	virtual anim::IExpressionColorTrack*					CreateEmissiveColorTrack( anim::IExpressionScript* script );
	virtual anim::IExpressionColorTrack*					CreateEmissiveColorTrack( const lang::String& expression );
	virtual anim::IKeyframedColorTrack*						CreateSpecularColorTrack();
	virtual anim::IProceduralColorTrack*					CreateSpecularColorTrack( const anim::AnimationTrack& type );
	virtual anim::IExpressionColorTrack*					CreateSpecularColorTrack( anim::IExpressionScript* script );
	virtual anim::IExpressionColorTrack*					CreateSpecularColorTrack( const lang::String& expression );
	virtual anim::IKeyframedFloatTrack*						CreateSpecularPowerTrack();
	virtual anim::IProceduralFloatTrack*					CreateSpecularPowerTrack( const anim::AnimationTrack& type );
	virtual anim::IExpressionFloatTrack*					CreateSpecularPowerTrack( anim::IExpressionScript* script );
	virtual anim::IExpressionFloatTrack*					CreateSpecularPowerTrack( const lang::String& expression );
	virtual ITransparentMaterialAnimationController*		AsTransparent() const;

protected:
	ISimpleMaterial*										_material;
	anim::IAnimationColorTrack*								_trackDiffuse;
	anim::IAnimationColorTrack*								_trackAmbient;
	anim::IAnimationColorTrack*								_trackEmissive;
	anim::IAnimationColorTrack*								_trackSpecular;
	anim::IAnimationFloatTrack*								_trackSpecularPower;
};


#include "SimpleMaterialAnimationControllerImpl.inl"


} // mat


} // synkro


#endif // _SYNKRO_MAT_SIMPLEMATERIALANIMATIONCONTROLLERIMPL_
