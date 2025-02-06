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


ConeLightAnimationController::ConeLightAnimationController( IConeLight* coneLight, IAnimationSystem* animationSystem, IAnimation* animation, AnimationListener* listener ) :
	LightAnimationControllerImpl<IConeLightAnimationController>( coneLight, animationSystem, animation, listener ),
	_coneLight( coneLight )
{
	SetAnimation( _animation );
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
		_trackRange->GetValue( _time, range );
		_coneLight->SetRange( range );
	}

	if ( _trackInnerAngle != nullptr )
	{
		Float angle;
		_trackInnerAngle->GetValue( _time, angle );
		_coneLight->SetInnerAngle( angle );
	}

	if ( _trackOuterAngle != nullptr )
	{
		Float angle;
		_trackOuterAngle->GetValue( _time, angle );
		_coneLight->SetOuterAngle( angle );
	}

	if ( _trackFalloff != nullptr )
	{
		Float falloff;
		_trackFalloff->GetValue( _time, falloff );
		_coneLight->SetFalloff( falloff );
	}
}

void ConeLightAnimationController::SetAnimation( IAnimation* animation )
{
	// Call base implementation.
	LightAnimationControllerImpl<IConeLightAnimationController>::SetAnimation( animation );

	_trackRange			= GetTrack( _trackRange, ConeLightProperty::Range );
	_trackInnerAngle	= GetTrack( _trackInnerAngle, ConeLightProperty::InnerAngle );
	_trackOuterAngle	= GetTrack( _trackOuterAngle, ConeLightProperty::OuterAngle );
	_trackFalloff		= GetTrack( _trackFalloff, ConeLightProperty::Falloff );
}

IConeLightAnimationController* ConeLightAnimationController::AsCone() const
{
	return (IConeLightAnimationController*)this;
}

IKeyframedFloatTrack* ConeLightAnimationController::CreateRangeTrack()
{
	return (_trackRange = (_trackRange == nullptr) ? _animation->CreateFloatTrack(ConeLightProperty::Range.ToString()) : _trackRange)->AsKeyframed();
}

IProceduralFloatTrack* ConeLightAnimationController::CreateRangeTrack( const AnimationTrack& type )
{
	return (_trackRange = (_trackRange == nullptr) ? _animation->CreateFloatTrack(ConeLightProperty::Range.ToString(), type) : _trackRange)->AsProcedural();
}

IKeyframedFloatTrack* ConeLightAnimationController::CreateInnerAngleTrack()
{
	return (_trackInnerAngle = (_trackInnerAngle == nullptr) ? _animation->CreateFloatTrack(ConeLightProperty::InnerAngle.ToString()) : _trackInnerAngle)->AsKeyframed();
}

IProceduralFloatTrack* ConeLightAnimationController::CreateInnerAngleTrack( const AnimationTrack& type )
{
	return (_trackInnerAngle = (_trackInnerAngle == nullptr) ? _animation->CreateFloatTrack(ConeLightProperty::InnerAngle.ToString(), type) : _trackInnerAngle)->AsProcedural();
}

IKeyframedFloatTrack* ConeLightAnimationController::CreateOuterAngleTrack()
{
	return (_trackOuterAngle = (_trackOuterAngle == nullptr) ? _animation->CreateFloatTrack(ConeLightProperty::OuterAngle.ToString()) : _trackOuterAngle)->AsKeyframed();
}

IProceduralFloatTrack* ConeLightAnimationController::CreateOuterAngleTrack( const AnimationTrack& type )
{
	return (_trackOuterAngle = (_trackOuterAngle == nullptr) ? _animation->CreateFloatTrack(ConeLightProperty::OuterAngle.ToString(), type) : _trackOuterAngle)->AsProcedural();
}

IKeyframedFloatTrack* ConeLightAnimationController::CreateFalloffTrack()
{
	return (_trackFalloff = (_trackFalloff == nullptr) ? _animation->CreateFloatTrack(ConeLightProperty::Falloff.ToString()) : _trackFalloff)->AsKeyframed();
}

IProceduralFloatTrack* ConeLightAnimationController::CreateFalloffTrack( const AnimationTrack& type )
{
	return (_trackFalloff = (_trackFalloff == nullptr) ? _animation->CreateFloatTrack(ConeLightProperty::Falloff.ToString(), type) : _trackFalloff)->AsProcedural();
}


} // scene


} // synkro
