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


FogFilterAnimationController::FogFilterAnimationController( IFogFilter* fogFilter, IAnimationSystem* animationSystem, IAnimationSet* animations, AnimationListener* listener ) :
	ViewportFilterAnimationControllerImpl<IFogFilterAnimationController>( fogFilter, animationSystem, animations, listener ),
	_fogFilter( fogFilter ),
	_trackColor( nullptr ),
	_trackDensity( nullptr ),
	_trackStart( nullptr ),
	_trackEnd( nullptr )
{
}

void FogFilterAnimationController::Update( Double delta )
{
	// Call base implementation.
	ViewportFilterAnimationControllerImpl<IFogFilterAnimationController>::Update( delta );

	// Update filter.
	if ( _trackColor != nullptr )
	{
		Color color;
		_trackColor->GetValue( CurrentTime(), color );
		_fogFilter->SetColor( color );
	}

	if ( _trackDensity != nullptr )
	{
		Float density;
		_trackDensity->GetValue( CurrentTime(), density );
		_fogFilter->SetDensity( density );
	}

	if ( _trackStart != nullptr )
	{
		Float start;
		_trackStart->GetValue( CurrentTime(), start );
		_fogFilter->SetStart( start );
	}

	if ( _trackEnd != nullptr )
	{
		Float end;
		_trackEnd->GetValue( CurrentTime(), end );
		_fogFilter->SetEnd( end );
	}
}

IFogFilterAnimationController* FogFilterAnimationController::AsFog() const
{
	return (IFogFilterAnimationController*)this;
}

IKeyframedColorTrack* FogFilterAnimationController::CreateColorTrack()
{
	return (_trackColor = _animations->GetActiveAnimation()->CreateColorTrack( FogFilterProperty::Color.ToString()) )->AsKeyframed();
}

IProceduralColorTrack* FogFilterAnimationController::CreateColorTrack( const AnimationTrack& type )
{
	return (_trackColor = _animations->GetActiveAnimation()->CreateColorTrack( FogFilterProperty::Color.ToString(), type) )->AsProcedural();
}

IKeyframedFloatTrack* FogFilterAnimationController::CreateDensityTrack()
{
	return (_trackDensity = _animations->GetActiveAnimation()->CreateFloatTrack( FogFilterProperty::Density.ToString()) )->AsKeyframed();
}

IProceduralFloatTrack* FogFilterAnimationController::CreateDensityTrack( const AnimationTrack& type )
{
	return (_trackDensity = _animations->GetActiveAnimation()->CreateFloatTrack( FogFilterProperty::Density.ToString(), type) )->AsProcedural();
}

IKeyframedFloatTrack* FogFilterAnimationController::CreateStartTrack()
{
	return (_trackStart = _animations->GetActiveAnimation()->CreateFloatTrack( FogFilterProperty::Start.ToString()) )->AsKeyframed();
}

IProceduralFloatTrack* FogFilterAnimationController::CreateStartTrack( const AnimationTrack& type )
{
	return (_trackStart = _animations->GetActiveAnimation()->CreateFloatTrack( FogFilterProperty::Start.ToString(), type) )->AsProcedural();
}

IKeyframedFloatTrack* FogFilterAnimationController::CreateEndTrack()
{
	return (_trackEnd = _animations->GetActiveAnimation()->CreateFloatTrack( FogFilterProperty::End.ToString()) )->AsKeyframed();
}

IProceduralFloatTrack* FogFilterAnimationController::CreateEndTrack( const AnimationTrack& type )
{
	return (_trackEnd = _animations->GetActiveAnimation()->CreateFloatTrack( FogFilterProperty::End.ToString(), type) )->AsProcedural();
}

void FogFilterAnimationController::UpdateTracks()
{
	// Call base implementation.
	ViewportFilterAnimationControllerImpl<IFogFilterAnimationController>::UpdateTracks();

	_trackColor		= GetTrack( _trackColor, FogFilterProperty::Color );
	_trackDensity	= GetTrack( _trackDensity, FogFilterProperty::Density );
	_trackStart		= GetTrack( _trackStart, FogFilterProperty::Start );
	_trackEnd		= GetTrack( _trackEnd, FogFilterProperty::End );
}


} // view


} // synkro
