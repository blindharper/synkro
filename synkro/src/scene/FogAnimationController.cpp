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


FogAnimationController::FogAnimationController( IFog* fog, IAnimationSystem* animationSystem, IAnimationSet* animations, AnimationListener* listener ) :
	PlaybackControllerImpl<IFogAnimationController>( animationSystem, animations, listener ),
	_fog( fog ),
	_trackColor( nullptr ),
	_trackDensity( nullptr ),
	_trackStart( nullptr ),
	_trackEnd( nullptr )
{
}

void FogAnimationController::Update( Double delta )
{
	// Call base implementation.
	PlaybackControllerImpl<IFogAnimationController>::Update( delta );

	// Update fog.
	if ( _trackColor != nullptr )
	{
		Color color;
		_trackColor->GetValue( CurrentTime(), color );
		_fog->SetColor( color );
	}

	if ( _trackDensity != nullptr )
	{
		Float density;
		_trackDensity->GetValue( CurrentTime(), density );
		_fog->SetDensity( density );
	}

	if ( _trackStart != nullptr )
	{
		Float start;
		_trackStart->GetValue( CurrentTime(), start );
		_fog->SetStart( start );
	}

	if ( _trackEnd != nullptr )
	{
		Float end;
		_trackEnd->GetValue( CurrentTime(), end );
		_fog->SetEnd( end );
	}
}

IKeyframedColorTrack* FogAnimationController::CreateColorTrack()
{
	return (_trackColor = _animations->GetActiveAnimation()->CreateColorTrack( FogProperty::Color.ToString()) )->AsKeyframed();
}

IProceduralColorTrack* FogAnimationController::CreateColorTrack( const AnimationTrack& type )
{
	return (_trackColor = _animations->GetActiveAnimation()->CreateColorTrack( FogProperty::Color.ToString(), type) )->AsProcedural();
}

IKeyframedFloatTrack* FogAnimationController::CreateDensityTrack()
{
	return (_trackDensity = _animations->GetActiveAnimation()->CreateFloatTrack( FogProperty::Density.ToString()) )->AsKeyframed();
}

IProceduralFloatTrack* FogAnimationController::CreateDensityTrack( const AnimationTrack& type )
{
	return (_trackDensity = _animations->GetActiveAnimation()->CreateFloatTrack( FogProperty::Density.ToString(), type) )->AsProcedural();
}

IKeyframedFloatTrack* FogAnimationController::CreateStartTrack()
{
	return (_trackStart = _animations->GetActiveAnimation()->CreateFloatTrack( FogProperty::Start.ToString()) )->AsKeyframed();
}

IProceduralFloatTrack* FogAnimationController::CreateStartTrack( const AnimationTrack& type )
{
	return (_trackStart = _animations->GetActiveAnimation()->CreateFloatTrack( FogProperty::Start.ToString(), type) )->AsProcedural();
}

IKeyframedFloatTrack* FogAnimationController::CreateEndTrack()
{
	return (_trackEnd = _animations->GetActiveAnimation()->CreateFloatTrack( FogProperty::End.ToString()) )->AsKeyframed();
}

IProceduralFloatTrack* FogAnimationController::CreateEndTrack( const AnimationTrack& type )
{
	return (_trackEnd = _animations->GetActiveAnimation()->CreateFloatTrack( FogProperty::End.ToString(), type) )->AsProcedural();
}

void FogAnimationController::UpdateTracks()
{
	_trackColor		= GetTrack( _trackColor, FogProperty::Color );
	_trackDensity	= GetTrack( _trackDensity, FogProperty::Density );
	_trackStart		= GetTrack( _trackStart, FogProperty::Start );
	_trackEnd		= GetTrack( _trackEnd, FogProperty::End );
}


} // scene


} // synkro
