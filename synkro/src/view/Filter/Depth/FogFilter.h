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
// Purpose: Fog viewport filter implementation.
//==============================================================================
#ifndef _SYNKRO_VIEW_FOGFILTER_
#define _SYNKRO_VIEW_FOGFILTER_


#include "config.h"
#include "DepthFilterImpl.h"
#include <view/IFogFilter.h>
#include <view/IFogFilterAnimationController.h>
#include <internal/ToVector.h>
#include <internal/ToColor.h>
#include <math/Math.h>


namespace synkro
{


namespace view
{


// Fog viewport filter implementation.
class FogFilter :
	public DepthFilterImpl<IFogFilter>
{
public:
	// Constructor.
	FogFilter( IViewport* viewport, anim::IAnimationSystem* animationSystem, gfx::IProgram* program );

	// IViewportFilter methods.
	IViewportFilterAnimationController*						CreateAnimationController( anim::IAnimation* animation, anim::AnimationListener* listener );

	// IDepthFilter methods.
	IFogFilter*												AsFog() const;

	// IFogFilter methods.
	void													SetColor( const img::Color& color );
	void													SetDensity( Float density );
	void													SetStart( Float start );
	void													SetEnd( Float end );
	void													SetType( const scene::FogType& type );
	void													GetColor( img::Color& color ) const;
	Float													GetDensity() const;
	Float													GetStart() const;
	Float													GetEnd() const;
	scene::FogType											GetType() const;

private:
	P(IFogFilterAnimationController)						_ctrlAnimation;
	scene::FogType											_type;
	gfx::ProgramParam*										_paramColor;
	gfx::ProgramParam*										_paramDensity;
	gfx::ProgramParam*										_paramStart;
	gfx::ProgramParam*										_paramEnd;
	gfx::ProgramParam*										_paramType;
};


#include "FogFilter.inl"


} // view


} // synkro


#endif // _SYNKRO_VIEW_FOGFILTER_
