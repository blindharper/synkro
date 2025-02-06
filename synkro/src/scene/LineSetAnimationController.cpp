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


LineSetAnimationController::LineSetAnimationController( ILineSet* lineSet, IAnimationSystem* animationSystem, IAnimation* animation, AnimationListener* listener ) :
	PrimitiveAnimationControllerImpl<ILineSetAnimationController>( lineSet, animationSystem, animation, listener ),
	_lineSet( lineSet )
{
	SetAnimation( _animation );
}

void LineSetAnimationController::Update( Double delta )
{
	// Call base implementation.
	PrimitiveAnimationControllerImpl<ILineSetAnimationController>::Update( delta );

	// Update line set.
	if ( _trackColor != nullptr )
	{
		Color color;
		_trackColor->GetValue( _time, color );
		_lineSet->SetColor( color );
	}
}

void LineSetAnimationController::SetAnimation( IAnimation* animation )
{
	// Call base implementation.
	PrimitiveAnimationControllerImpl<ILineSetAnimationController>::SetAnimation( animation );

	_trackColor = GetTrack( _trackColor, LineSetProperty::Color );
}

ILineSetAnimationController* LineSetAnimationController::AsLineSet() const
{
	return (ILineSetAnimationController*)this;
}

IKeyframedColorTrack* LineSetAnimationController::CreateColorTrack()
{
	return (_trackColor = (_trackColor == nullptr) ? _animation->CreateColorTrack(LineSetProperty::Color.ToString()) : _trackColor)->AsKeyframed();
}

IProceduralColorTrack* LineSetAnimationController::CreateColorTrack( const AnimationTrack& type )
{
	return (_trackColor = (_trackColor == nullptr) ? _animation->CreateColorTrack(LineSetProperty::Color.ToString(), type) : _trackColor)->AsProcedural();
}

IExpressionColorTrack* LineSetAnimationController::CreateColorTrack( IExpressionScript* script )
{
	return (_trackColor = (_trackColor == nullptr) ? _animation->CreateColorTrack(LineSetProperty::Color.ToString(), script) : _trackColor)->AsExpression();
}

IExpressionColorTrack* LineSetAnimationController::CreateColorTrack( const String& expression )
{
	return (_trackColor = (_trackColor == nullptr) ? _animation->CreateColorTrack(LineSetProperty::Color.ToString(), expression) : _trackColor)->AsExpression();
}


} // scene


} // synkro
