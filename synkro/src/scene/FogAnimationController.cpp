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
// Purpose: Animation controller for fog effect.
//==============================================================================
#include "config.h"
#include "FogAnimationController.h"
#include "FogProperty.h"
#include <Scene/IFog.h>


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::core;
using namespace synkro::img;

//------------------------------------------------------------------------------


namespace synkro
{


namespace scene
{


FogAnimationController::FogAnimationController( IFog* fog, IAnimationSystem* animationSystem, IAnimation* animation, AnimationListener* listener ) :
	PlaybackControllerImpl<IFogAnimationController>( animationSystem, animation, listener ),
	_fog( fog )
{
	SetAnimation( _animation );
}

void FogAnimationController::Update( Double delta )
{
	// Call base implementation.
	PlaybackControllerImpl<IFogAnimationController>::Update( delta );

	// Update fog.
	if ( _trackColor != nullptr )
	{
		Color color;
		_trackColor->GetValue( _time, color );
		_fog->SetColor( color );
	}

	if ( _trackDensity != nullptr )
	{
		Float density;
		_trackDensity->GetValue( _time, density );
		_fog->SetDensity( density );
	}

	if ( _trackStart != nullptr )
	{
		Float start;
		_trackStart->GetValue( _time, start );
		_fog->SetStart( start );
	}

	if ( _trackEnd != nullptr )
	{
		Float end;
		_trackEnd->GetValue( _time, end );
		_fog->SetEnd( end );
	}
}

void FogAnimationController::SetAnimation( IAnimation* animation )
{
	// Call base implementation.
	PlaybackControllerImpl<IFogAnimationController>::SetAnimation( animation );

	_trackColor		= GetTrack( _trackColor, FogProperty::Color );
	_trackDensity	= GetTrack( _trackDensity, FogProperty::Density );
	_trackStart		= GetTrack( _trackStart, FogProperty::Start );
	_trackEnd		= GetTrack( _trackEnd, FogProperty::End );
}

IKeyframedColorTrack* FogAnimationController::CreateColorTrack()
{
	return (_trackColor = (_trackColor == nullptr) ? _animation->CreateColorTrack(FogProperty::Color.ToString()) : _trackColor)->AsKeyframed();
}

IProceduralColorTrack* FogAnimationController::CreateColorTrack( const AnimationTrack& type )
{
	return (_trackColor = (_trackColor == nullptr) ? _animation->CreateColorTrack(FogProperty::Color.ToString(), type) : _trackColor)->AsProcedural();
}

IKeyframedFloatTrack* FogAnimationController::CreateDensityTrack()
{
	return (_trackDensity = (_trackDensity == nullptr) ? _animation->CreateFloatTrack(FogProperty::Density.ToString()) : _trackDensity)->AsKeyframed();
}

IProceduralFloatTrack* FogAnimationController::CreateDensityTrack( const AnimationTrack& type )
{
	return (_trackDensity = (_trackDensity == nullptr) ? _animation->CreateFloatTrack(FogProperty::Density.ToString(), type) : _trackDensity)->AsProcedural();
}

IKeyframedFloatTrack* FogAnimationController::CreateStartTrack()
{
	return (_trackStart = (_trackStart == nullptr) ? _animation->CreateFloatTrack(FogProperty::Start.ToString()) : _trackStart)->AsKeyframed();
}

IProceduralFloatTrack* FogAnimationController::CreateStartTrack( const AnimationTrack& type )
{
	return (_trackStart = (_trackStart == nullptr) ? _animation->CreateFloatTrack(FogProperty::Start.ToString(), type) : _trackStart)->AsProcedural();
}

IKeyframedFloatTrack* FogAnimationController::CreateEndTrack()
{
	return (_trackEnd = (_trackEnd == nullptr) ? _animation->CreateFloatTrack(FogProperty::End.ToString()) : _trackEnd)->AsKeyframed();
}

IProceduralFloatTrack* FogAnimationController::CreateEndTrack( const AnimationTrack& type )
{
	return (_trackEnd = (_trackEnd == nullptr) ? _animation->CreateFloatTrack(FogProperty::End.ToString(), type) : _trackEnd)->AsProcedural();
}


} // scene


} // synkro
