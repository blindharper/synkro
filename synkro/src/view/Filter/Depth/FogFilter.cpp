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
#include "config.h"
#include "FogFilter.h"
#include "FogFilterAnimationController.h"


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::core;
using namespace synkro::gfx;
using namespace synkro::img;
using namespace synkro::scene;

//------------------------------------------------------------------------------


namespace synkro
{


namespace view
{


FogFilter::FogFilter( IViewport* viewport, IAnimationSystem* animationSystem, IProgram* program ) :
	DepthFilterImpl<IFogFilter>( viewport, animationSystem, program )
{
	// Extract filter parameters.
	_paramColor		= _params->GetParam( L"p_color" );
	_paramStart		= _params->GetParam( L"p_start" );
	_paramEnd		= _params->GetParam( L"p_end" );
	_paramDensity	= _params->GetParam( L"p_density" );
	_paramType		= _params->GetParam( L"p_type" );

	// Set default values.
	SetType( FogType::Linear );
	SetColor( Color::LightGray );
	SetStart( 0.0f );
	SetEnd( 100.0f );
	SetDensity( 0.01f );
}

IViewportFilterAnimationController* FogFilter::CreateAnimationController( IAnimation* animation, AnimationListener* listener )
{
	return (_ctrlAnimation == nullptr) ? _ctrlAnimation = new FogFilterAnimationController( this, _animationSystem, animation, listener ) : _ctrlAnimation;
}


} // view


} // synkro
