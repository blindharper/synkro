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


OmniLightAnimationController::OmniLightAnimationController( IOmniLight* omniLight, IAnimationSystem* animationSystem, IAnimationSet* animations, AnimationListener* listener ) :
	LightAnimationControllerImpl<IOmniLightAnimationController>( omniLight, animationSystem, animations, listener ),
	_omniLight( omniLight ),
	_trackRange( nullptr )
{
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
		_trackRange->GetValue( CurrentTime(), range );
		_omniLight->SetRange( range );
	}
}

IOmniLightAnimationController* OmniLightAnimationController::AsOmni() const
{
	return (IOmniLightAnimationController*)this;
}

IKeyframedFloatTrack* OmniLightAnimationController::CreateRangeTrack()
{
	return (_trackRange = _animations->GetActiveAnimation()->CreateFloatTrack( OmniLightProperty::Range.ToString()) )->AsKeyframed();
}

IProceduralFloatTrack* OmniLightAnimationController::CreateRangeTrack( const AnimationTrack& type )
{
	return (_trackRange = _animations->GetActiveAnimation()->CreateFloatTrack( OmniLightProperty::Range.ToString(), type) )->AsProcedural();
}

void OmniLightAnimationController::UpdateTracks()
{
	// Call base implementation.
	LightAnimationControllerImpl<IOmniLightAnimationController>::UpdateTracks();

	_trackRange = GetTrack( _trackRange, OmniLightProperty::Range );
}


} // scene


} // synkro
