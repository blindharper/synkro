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


SimpleFilterAnimationController::SimpleFilterAnimationController( ISimpleFilter* simpleFilter, IAnimationSystem* animationSystem, IAnimationSet* animations, AnimationListener* listener ) :
	ViewportFilterAnimationControllerImpl<ISimpleFilterAnimationController>( simpleFilter, animationSystem, animations, listener ),
	_simpleFilter( simpleFilter ),
	_trackValue( nullptr )
{
}

void SimpleFilterAnimationController::Update( Double delta )
{
	// Call base implementation.
	ViewportFilterAnimationControllerImpl<ISimpleFilterAnimationController>::Update( delta );

	// Update filter.
	if ( _trackValue != nullptr )
	{
		Float value;
		_trackValue->GetValue( CurrentTime(), value );
		_simpleFilter->SetValue( value );
	}
}

ISimpleFilterAnimationController* SimpleFilterAnimationController::AsSimple() const
{
	return (ISimpleFilterAnimationController*)this;
}

IKeyframedFloatTrack* SimpleFilterAnimationController::CreateValueTrack()
{
	return (_trackValue = _animations->GetActiveAnimation()->CreateFloatTrack(SimpleFilterProperty::ParamValue.ToString()))->AsKeyframed();
}

IProceduralFloatTrack* SimpleFilterAnimationController::CreateValueTrack( const AnimationTrack& type )
{
	return (_trackValue = _animations->GetActiveAnimation()->CreateFloatTrack( SimpleFilterProperty::ParamValue.ToString(), type) )->AsProcedural();
}

void SimpleFilterAnimationController::UpdateTracks()
{
	// Call base implementation.
	ViewportFilterAnimationControllerImpl<ISimpleFilterAnimationController>::UpdateTracks();

	_trackValue = GetTrack( _trackValue, SimpleFilterProperty::ParamValue );
}


} // view


} // synkro
