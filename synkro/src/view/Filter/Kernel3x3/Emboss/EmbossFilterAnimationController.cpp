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
// Purpose: Animation controller for emboss filter.
//==============================================================================
#include "config.h"
#include "EmbossFilterAnimationController.h"
#include "EmbossFilterProperty.h"
#include <view/IEmbossFilter.h>


//------------------------------------------------------------------------------

using namespace synkro::anim;

//------------------------------------------------------------------------------


namespace synkro
{


namespace view
{


EmbossFilterAnimationController::EmbossFilterAnimationController( IEmbossFilter* embossFilter, IAnimationSystem* animationSystem, IAnimation* animation, AnimationListener* listener ) :
	Kernel3x3FilterAnimationControllerImpl<IEmbossFilterAnimationController>( embossFilter, animationSystem, animation, listener ),
	_embossFilter( embossFilter )
{
	SetAnimation( _animation );
}

void EmbossFilterAnimationController::Update( Double delta )
{
	// Call base implementation.
	Kernel3x3FilterAnimationControllerImpl<IEmbossFilterAnimationController>::Update( delta );

	// Update filter.
	if ( _trackAngle != nullptr )
	{
		Float angle;
		_trackAngle->GetValue( _time, angle );
		_embossFilter->SetAngle( angle );
	}

	if ( _trackDepth != nullptr )
	{
		Float depth;
		_trackDepth->GetValue( _time, depth );
		_embossFilter->SetDepth( depth );
	}
}

void EmbossFilterAnimationController::SetAnimation( IAnimation* animation )
{
	// Call base implementation.
	Kernel3x3FilterAnimationControllerImpl<IEmbossFilterAnimationController>::SetAnimation( animation );

	_trackAngle = GetTrack( _trackAngle, EmbossFilterProperty::Angle );
	_trackDepth = GetTrack( _trackDepth, EmbossFilterProperty::Depth );
}

IEmbossFilterAnimationController* EmbossFilterAnimationController::AsEmboss() const
{
	return (IEmbossFilterAnimationController*)this;
}

IKeyframedFloatTrack* EmbossFilterAnimationController::CreateAngleTrack()
{
	return (_trackAngle = (_trackAngle == nullptr) ? _animation->CreateFloatTrack(EmbossFilterProperty::Angle.ToString()) : _trackAngle)->AsKeyframed();
}

IKeyframedFloatTrack* EmbossFilterAnimationController::CreateDepthTrack()
{
	return (_trackDepth = (_trackDepth == nullptr) ? _animation->CreateFloatTrack(EmbossFilterProperty::Depth.ToString()) : _trackDepth)->AsKeyframed();
}

IProceduralFloatTrack* EmbossFilterAnimationController::CreateDepthTrack( const AnimationTrack& type )
{
	return (_trackDepth = (_trackDepth == nullptr) ? _animation->CreateFloatTrack(EmbossFilterProperty::Depth.ToString(), type) : _trackDepth)->AsProcedural();
}


} // view


} // synkro
