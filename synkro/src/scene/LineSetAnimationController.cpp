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
// Purpose: Implements animation controller for line set.
//==============================================================================
#include "config.h"
#include "LineSetAnimationController.h"
#include "LineSetProperty.h"
#include <scene/ILineSet.h>


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::img;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace scene
{


LineSetAnimationController::LineSetAnimationController( ILineSet* lineSet, IAnimationSystem* animationSystem, IAnimationSet* animations, AnimationListener* listener ) :
	PrimitiveAnimationControllerImpl<ILineSetAnimationController>( lineSet, animationSystem, animations, listener ),
	_lineSet( lineSet ),
	_trackColor( nullptr )
{
}

void LineSetAnimationController::Update( Double delta )
{
	// Call base implementation.
	PrimitiveAnimationControllerImpl<ILineSetAnimationController>::Update( delta );

	// Update line set.
	if ( _trackColor != nullptr )
	{
		Color color;
		_trackColor->GetValue( CurrentTime(), color );
		_lineSet->SetColor( color );
	}
}

ILineSetAnimationController* LineSetAnimationController::AsLineSet() const
{
	return (ILineSetAnimationController*)this;
}

IKeyframedColorTrack* LineSetAnimationController::CreateColorTrack()
{
	return (_trackColor = _animations->GetActiveAnimation()->CreateColorTrack( LineSetProperty::Color.ToString()) )->AsKeyframed();
}

IProceduralColorTrack* LineSetAnimationController::CreateColorTrack( const AnimationTrack& type )
{
	return (_trackColor = _animations->GetActiveAnimation()->CreateColorTrack( LineSetProperty::Color.ToString(), type) )->AsProcedural();
}

IExpressionColorTrack* LineSetAnimationController::CreateColorTrack( IExpressionScript* script )
{
	return (_trackColor = _animations->GetActiveAnimation()->CreateColorTrack( LineSetProperty::Color.ToString(), script) )->AsExpression();
}

IExpressionColorTrack* LineSetAnimationController::CreateColorTrack( const String& expression )
{
	return (_trackColor = _animations->GetActiveAnimation()->CreateColorTrack( LineSetProperty::Color.ToString(), expression) )->AsExpression();
}

void LineSetAnimationController::UpdateTracks()
{
	// Call base implementation.
	PrimitiveAnimationControllerImpl<ILineSetAnimationController>::UpdateTracks();

	_trackColor = GetTrack( _trackColor, LineSetProperty::Color );
}


} // scene


} // synkro
