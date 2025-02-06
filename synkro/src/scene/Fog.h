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
// Purpose: Fog effect implementation.
//==============================================================================
#ifndef _SYNKRO_SCENE_FOG_
#define _SYNKRO_SCENE_FOG_


#include "config.h"
#include <core/ObjectImpl.h>
#include <scene/IFog.h>
#include <scene/IFogAnimationController.h>
#include <core/IContext.h>
#include "BaseFog.h"


namespace synkro
{


namespace scene
{


// Fog effect implementation.
class Fog :
	public core::ObjectImpl<IFog>,
	public BaseFog
{
public:
	// Constructor.
	Fog( core::IContext* context );

	// IFog methods.
	IFogAnimationController*								CreateAnimationController( anim::IAnimation* animation, anim::AnimationListener* listener );
	void													SetColor( const img::Color& color );
	void													SetDensity( Float density );
	void													SetStart( Float start );
	void													SetEnd( Float end );
	void													SetType( const FogType& type );
	void													GetColor( img::Color& color ) const;
	Float													GetDensity() const;
	Float													GetStart() const;
	Float													GetEnd() const;
	FogType													GetType() const;

	// BaseFog methods.
	void													GetState( FogState& state ) const;

private:
	core::IContext*											_context;
	P(IFogAnimationController)								_ctrlAnimation;
	FogType													_type;
	FogState												_state;
};


#include "Fog.inl"


} // scene


} // synkro


#endif // _SYNKRO_SCENE_FOG_
