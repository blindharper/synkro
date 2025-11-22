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


EmbossFilterAnimationController::EmbossFilterAnimationController( IEmbossFilter* embossFilter, IAnimationSystem* animationSystem, IAnimationSet* animations, AnimationListener* listener ) :
	Kernel3x3FilterAnimationControllerImpl<IEmbossFilterAnimationController>( embossFilter, animationSystem, animations, listener ),
	_embossFilter( embossFilter ),
	_trackAngle( nullptr ),
	_trackDepth( nullptr )
{
}

void EmbossFilterAnimationController::Update( Double delta )
{
	// Call base implementation.
	Kernel3x3FilterAnimationControllerImpl<IEmbossFilterAnimationController>::Update( delta );

	// Update filter.
	if ( _trackAngle != nullptr )
	{
		Float angle;
		_trackAngle->GetValue( CurrentTime(), angle );
		_embossFilter->SetAngle( angle );
	}

	if ( _trackDepth != nullptr )
	{
		Float depth;
		_trackDepth->GetValue( CurrentTime(), depth );
		_embossFilter->SetDepth( depth );
	}
}

IEmbossFilterAnimationController* EmbossFilterAnimationController::AsEmboss() const
{
	return (IEmbossFilterAnimationController*)this;
}

IKeyframedFloatTrack* EmbossFilterAnimationController::CreateAngleTrack()
{
	return (_trackAngle = _animations->GetActiveAnimation()->CreateFloatTrack(EmbossFilterProperty::Angle.ToString()))->AsKeyframed();
}

IKeyframedFloatTrack* EmbossFilterAnimationController::CreateDepthTrack()
{
	return (_trackDepth = _animations->GetActiveAnimation()->CreateFloatTrack( EmbossFilterProperty::Depth.ToString()) )->AsKeyframed();
}

IProceduralFloatTrack* EmbossFilterAnimationController::CreateDepthTrack( const AnimationTrack& type )
{
	return (_trackDepth = _animations->GetActiveAnimation()->CreateFloatTrack( EmbossFilterProperty::Depth.ToString(), type) )->AsProcedural();
}

void EmbossFilterAnimationController::UpdateTracks()
{
	// Call base implementation.
	Kernel3x3FilterAnimationControllerImpl<IEmbossFilterAnimationController>::UpdateTracks();

	_trackAngle = GetTrack( _trackAngle, EmbossFilterProperty::Angle );
	_trackDepth = GetTrack( _trackDepth, EmbossFilterProperty::Depth );
}


} // view


} // synkro
