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
// Purpose: Animation controller for simple filter.
//==============================================================================
#include "config.h"
#include "SimpleFilterAnimationController.h"
#include "SimpleFilterProperty.h"
#include <view/ISimpleFilter.h>


//------------------------------------------------------------------------------

using namespace synkro::anim;

//------------------------------------------------------------------------------


namespace synkro
{


namespace view
{


SimpleFilterAnimationController::SimpleFilterAnimationController( ISimpleFilter* simpleFilter, IAnimationSystem* animationSystem, IAnimation* animation, AnimationListener* listener ) :
	ViewportFilterAnimationControllerImpl<ISimpleFilterAnimationController>( simpleFilter, animationSystem, animation, listener ),
	_simpleFilter( simpleFilter )
{
	SetAnimation( _animation );
}

void SimpleFilterAnimationController::Update( Double delta )
{
	// Call base implementation.
	ViewportFilterAnimationControllerImpl<ISimpleFilterAnimationController>::Update( delta );

	// Update filter.
	if ( _trackValue != nullptr )
	{
		Float value;
		_trackValue->GetValue( _time, value );
		_simpleFilter->SetValue( value );
	}
}

void SimpleFilterAnimationController::SetAnimation( IAnimation* animation )
{
	// Call base implementation.
	ViewportFilterAnimationControllerImpl<ISimpleFilterAnimationController>::SetAnimation( animation );

	_trackValue = GetTrack( _trackValue, SimpleFilterProperty::ParamValue );
}

ISimpleFilterAnimationController* SimpleFilterAnimationController::AsSimple() const
{
	return (ISimpleFilterAnimationController*)this;
}

IKeyframedFloatTrack* SimpleFilterAnimationController::CreateValueTrack()
{
	return (_trackValue = (_trackValue == nullptr) ? _animation->CreateFloatTrack(SimpleFilterProperty::ParamValue.ToString()) : _trackValue)->AsKeyframed();
}

IProceduralFloatTrack* SimpleFilterAnimationController::CreateValueTrack( const AnimationTrack& type )
{
	return (_trackValue = (_trackValue == nullptr) ? _animation->CreateFloatTrack(SimpleFilterProperty::ParamValue.ToString(), type) : _trackValue)->AsProcedural();
}


} // view


} // synkro
