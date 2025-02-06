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
// Purpose: Animation controller for fog filter.
//==============================================================================
#include "config.h"
#include "FogFilterAnimationController.h"
#include "FogFilterProperty.h"
#include <view/IFogFilter.h>


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::img;

//------------------------------------------------------------------------------


namespace synkro
{


namespace view
{


FogFilterAnimationController::FogFilterAnimationController( IFogFilter* fogFilter, IAnimationSystem* animationSystem, IAnimation* animation, AnimationListener* listener ) :
	ViewportFilterAnimationControllerImpl<IFogFilterAnimationController>( fogFilter, animationSystem, animation, listener ),
	_fogFilter( fogFilter )
{
	SetAnimation( _animation );
}

void FogFilterAnimationController::Update( Double delta )
{
	// Call base implementation.
	ViewportFilterAnimationControllerImpl<IFogFilterAnimationController>::Update( delta );

	// Update filter.
	if ( _trackColor != nullptr )
	{
		Color color;
		_trackColor->GetValue( _time, color );
		_fogFilter->SetColor( color );
	}

	if ( _trackDensity != nullptr )
	{
		Float density;
		_trackDensity->GetValue( _time, density );
		_fogFilter->SetDensity( density );
	}

	if ( _trackStart != nullptr )
	{
		Float start;
		_trackStart->GetValue( _time, start );
		_fogFilter->SetStart( start );
	}

	if ( _trackEnd != nullptr )
	{
		Float end;
		_trackEnd->GetValue( _time, end );
		_fogFilter->SetEnd( end );
	}
}

void FogFilterAnimationController::SetAnimation( IAnimation* animation )
{
	// Call base implementation.
	ViewportFilterAnimationControllerImpl<IFogFilterAnimationController>::SetAnimation( animation );

	_trackColor		= GetTrack( _trackColor, FogFilterProperty::Color );
	_trackDensity	= GetTrack( _trackDensity, FogFilterProperty::Density );
	_trackStart		= GetTrack( _trackStart, FogFilterProperty::Start );
	_trackEnd		= GetTrack( _trackEnd, FogFilterProperty::End );
}

IFogFilterAnimationController* FogFilterAnimationController::AsFog() const
{
	return (IFogFilterAnimationController*)this;
}

IKeyframedColorTrack* FogFilterAnimationController::CreateColorTrack()
{
	return (_trackColor = (_trackColor == nullptr) ? _animation->CreateColorTrack(FogFilterProperty::Color.ToString()) : _trackColor)->AsKeyframed();
}

IProceduralColorTrack* FogFilterAnimationController::CreateColorTrack( const AnimationTrack& type )
{
	return (_trackColor = (_trackColor == nullptr) ? _animation->CreateColorTrack(FogFilterProperty::Color.ToString(), type) : _trackColor)->AsProcedural();
}

IKeyframedFloatTrack* FogFilterAnimationController::CreateDensityTrack()
{
	return (_trackDensity = (_trackDensity == nullptr) ? _animation->CreateFloatTrack(FogFilterProperty::Density.ToString()) : _trackDensity)->AsKeyframed();
}

IProceduralFloatTrack* FogFilterAnimationController::CreateDensityTrack( const AnimationTrack& type )
{
	return (_trackDensity = (_trackDensity == nullptr) ? _animation->CreateFloatTrack(FogFilterProperty::Density.ToString(), type) : _trackDensity)->AsProcedural();
}

IKeyframedFloatTrack* FogFilterAnimationController::CreateStartTrack()
{
	return (_trackStart = (_trackStart == nullptr) ? _animation->CreateFloatTrack(FogFilterProperty::Start.ToString()) : _trackStart)->AsKeyframed();
}

IProceduralFloatTrack* FogFilterAnimationController::CreateStartTrack( const AnimationTrack& type )
{
	return (_trackStart = (_trackStart == nullptr) ? _animation->CreateFloatTrack(FogFilterProperty::Start.ToString(), type) : _trackStart)->AsProcedural();
}

IKeyframedFloatTrack* FogFilterAnimationController::CreateEndTrack()
{
	return (_trackEnd = (_trackEnd == nullptr) ? _animation->CreateFloatTrack(FogFilterProperty::End.ToString()) : _trackEnd)->AsKeyframed();
}

IProceduralFloatTrack* FogFilterAnimationController::CreateEndTrack( const AnimationTrack& type )
{
	return (_trackEnd = (_trackEnd == nullptr) ? _animation->CreateFloatTrack(FogFilterProperty::End.ToString(), type) : _trackEnd)->AsProcedural();
}


} // view


} // synkro
