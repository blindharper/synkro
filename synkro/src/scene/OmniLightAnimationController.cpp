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
// Purpose: Animation controller for omni light source.
//==============================================================================
#include "config.h"
#include "OmniLightAnimationController.h"
#include "OmniLightProperty.h"
#include <scene/IOmniLight.h>


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::core;

//------------------------------------------------------------------------------


namespace synkro
{


namespace scene
{


OmniLightAnimationController::OmniLightAnimationController( IOmniLight* omniLight, IAnimationSystem* animationSystem, IAnimation* animation, AnimationListener* listener ) :
	LightAnimationControllerImpl<IOmniLightAnimationController>( omniLight, animationSystem, animation, listener ),
	_omniLight( omniLight )
{
	SetAnimation( _animation );
}

void OmniLightAnimationController::Update( Double delta )
{
	// Call base implementation.
	LightAnimationControllerImpl<IOmniLightAnimationController>::Update( delta );

	if ( !_omniLight->IsEnabled() )
		return;

	// Update omni light.
	if ( _trackRange != nullptr )
	{
		Float range;
		_trackRange->GetValue( _time, range );
		_omniLight->SetRange( range );
	}
}

void OmniLightAnimationController::SetAnimation( IAnimation* animation )
{
	// Call base implementation.
	LightAnimationControllerImpl<IOmniLightAnimationController>::SetAnimation( animation );

	_trackRange = GetTrack( _trackRange, OmniLightProperty::Range );
}

IOmniLightAnimationController* OmniLightAnimationController::AsOmni() const
{
	return (IOmniLightAnimationController*)this;
}

IKeyframedFloatTrack* OmniLightAnimationController::CreateRangeTrack()
{
	return (_trackRange = (_trackRange == nullptr) ? _animation->CreateFloatTrack(OmniLightProperty::Range.ToString()) : _trackRange)->AsKeyframed();
}

IProceduralFloatTrack* OmniLightAnimationController::CreateRangeTrack( const AnimationTrack& type )
{
	return (_trackRange = (_trackRange == nullptr) ? _animation->CreateFloatTrack(OmniLightProperty::Range.ToString(), type) : _trackRange)->AsProcedural();
}


} // scene


} // synkro
