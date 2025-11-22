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
// Purpose: Implements animation controller for point set.
//==============================================================================
#include "config.h"
#include "PointSetAnimationController.h"
#include "PointSetProperty.h"
#include <scene/IPointSet.h>


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::img;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace scene
{


PointSetAnimationController::PointSetAnimationController( IPointSet* pointSet, IAnimationSystem* animationSystem, IAnimationSet* animations, AnimationListener* listener ) :
	PrimitiveAnimationControllerImpl<IPointSetAnimationController>( pointSet, animationSystem, animations, listener ),
	_pointSet( pointSet ),
	_trackColor( nullptr )
{
}

void PointSetAnimationController::Update( Double delta )
{
	// Call base implementation.
	PrimitiveAnimationControllerImpl<IPointSetAnimationController>::Update( delta );

	// Update point set.
	if ( _trackColor != nullptr )
	{
		Color color;
		_trackColor->GetValue( CurrentTime(), color );
		_pointSet->SetColor( color );
	}
}

IPointSetAnimationController* PointSetAnimationController::AsPointSet() const
{
	return (IPointSetAnimationController*)this;
}

IKeyframedColorTrack* PointSetAnimationController::CreateColorTrack()
{
	return (_trackColor = _animations->GetActiveAnimation()->CreateColorTrack( PointSetProperty::Color.ToString()) )->AsKeyframed();
}

IProceduralColorTrack* PointSetAnimationController::CreateColorTrack( const AnimationTrack& type )
{
	return (_trackColor = _animations->GetActiveAnimation()->CreateColorTrack( PointSetProperty::Color.ToString(), type) )->AsProcedural();
}

IExpressionColorTrack* PointSetAnimationController::CreateColorTrack( IExpressionScript* script )
{
	return (_trackColor = _animations->GetActiveAnimation()->CreateColorTrack( PointSetProperty::Color.ToString(), script) )->AsExpression();
}

IExpressionColorTrack* PointSetAnimationController::CreateColorTrack( const String& expression )
{
	return (_trackColor = _animations->GetActiveAnimation()->CreateColorTrack( PointSetProperty::Color.ToString(), expression) )->AsExpression();
}

void PointSetAnimationController::UpdateTracks()
{
	// Call base implementation.
	PrimitiveAnimationControllerImpl<IPointSetAnimationController>::UpdateTracks();

	_trackColor = GetTrack( _trackColor, PointSetProperty::Color );
}


} // scene


} // synkro
