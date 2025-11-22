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
// Purpose: Animation controller for cone light source.
//==============================================================================
#include "config.h"
#include "ConeLightAnimationController.h"
#include "ConeLightProperty.h"
#include <scene/IConeLight.h>


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::core;

//------------------------------------------------------------------------------


namespace synkro
{


namespace scene
{


ConeLightAnimationController::ConeLightAnimationController( IConeLight* coneLight, IAnimationSystem* animationSystem, IAnimationSet* animations, AnimationListener* listener ) :
	LightAnimationControllerImpl<IConeLightAnimationController>( coneLight, animationSystem, animations, listener ),
	_coneLight( coneLight ),
	_trackRange( nullptr ),
	_trackInnerAngle( nullptr ),
	_trackOuterAngle( nullptr ),
	_trackFalloff( nullptr )
{
}

void ConeLightAnimationController::Update( Double delta )
{
	// Call base implementation.
	LightAnimationControllerImpl<IConeLightAnimationController>::Update( delta );

	if ( !_coneLight->IsEnabled() )
		return;

	// Update cone light.
	if ( _trackRange != nullptr )
	{
		Float range;
		_trackRange->GetValue( CurrentTime(), range );
		_coneLight->SetRange( range );
	}

	if ( _trackInnerAngle != nullptr )
	{
		Float angle;
		_trackInnerAngle->GetValue( CurrentTime(), angle );
		_coneLight->SetInnerAngle( angle );
	}

	if ( _trackOuterAngle != nullptr )
	{
		Float angle;
		_trackOuterAngle->GetValue( CurrentTime(), angle );
		_coneLight->SetOuterAngle( angle );
	}

	if ( _trackFalloff != nullptr )
	{
		Float falloff;
		_trackFalloff->GetValue( CurrentTime(), falloff );
		_coneLight->SetFalloff( falloff );
	}
}

IConeLightAnimationController* ConeLightAnimationController::AsCone() const
{
	return (IConeLightAnimationController*)this;
}

IKeyframedFloatTrack* ConeLightAnimationController::CreateRangeTrack()
{
	return (_trackRange = _animations->GetActiveAnimation()->CreateFloatTrack( ConeLightProperty::Range.ToString()) )->AsKeyframed();
}

IProceduralFloatTrack* ConeLightAnimationController::CreateRangeTrack( const AnimationTrack& type )
{
	return (_trackRange = _animations->GetActiveAnimation()->CreateFloatTrack( ConeLightProperty::Range.ToString(), type) )->AsProcedural();
}

IKeyframedFloatTrack* ConeLightAnimationController::CreateInnerAngleTrack()
{
	return (_trackInnerAngle = _animations->GetActiveAnimation()->CreateFloatTrack( ConeLightProperty::InnerAngle.ToString()) )->AsKeyframed();
}

IProceduralFloatTrack* ConeLightAnimationController::CreateInnerAngleTrack( const AnimationTrack& type )
{
	return (_trackInnerAngle = _animations->GetActiveAnimation()->CreateFloatTrack( ConeLightProperty::InnerAngle.ToString(), type) )->AsProcedural();
}

IKeyframedFloatTrack* ConeLightAnimationController::CreateOuterAngleTrack()
{
	return (_trackOuterAngle = _animations->GetActiveAnimation()->CreateFloatTrack( ConeLightProperty::OuterAngle.ToString()) )->AsKeyframed();
}

IProceduralFloatTrack* ConeLightAnimationController::CreateOuterAngleTrack( const AnimationTrack& type )
{
	return (_trackOuterAngle = _animations->GetActiveAnimation()->CreateFloatTrack( ConeLightProperty::OuterAngle.ToString(), type) )->AsProcedural();
}

IKeyframedFloatTrack* ConeLightAnimationController::CreateFalloffTrack()
{
	return (_trackFalloff = _animations->GetActiveAnimation()->CreateFloatTrack( ConeLightProperty::Falloff.ToString()) )->AsKeyframed();
}

IProceduralFloatTrack* ConeLightAnimationController::CreateFalloffTrack( const AnimationTrack& type )
{
	return (_trackFalloff = _animations->GetActiveAnimation()->CreateFloatTrack( ConeLightProperty::Falloff.ToString(), type) )->AsProcedural();
}

void ConeLightAnimationController::UpdateTracks()
{
	// Call base implementation.
	LightAnimationControllerImpl<IConeLightAnimationController>::UpdateTracks();

	_trackRange			= GetTrack( _trackRange, ConeLightProperty::Range );
	_trackInnerAngle	= GetTrack( _trackInnerAngle, ConeLightProperty::InnerAngle );
	_trackOuterAngle	= GetTrack( _trackOuterAngle, ConeLightProperty::OuterAngle );
	_trackFalloff		= GetTrack( _trackFalloff, ConeLightProperty::Falloff );
}


} // scene


} // synkro
