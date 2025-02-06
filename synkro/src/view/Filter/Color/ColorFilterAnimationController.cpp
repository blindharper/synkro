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
// Purpose: Animation controller for color filter.
//==============================================================================
#include "config.h"
#include "ColorFilterAnimationController.h"
#include "ColorFilterProperty.h"
#include <view/IColorFilter.h>


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::img;

//------------------------------------------------------------------------------


namespace synkro
{


namespace view
{


ColorFilterAnimationController::ColorFilterAnimationController( IColorFilter* colorFilter, IAnimationSystem* animationSystem, IAnimation* animation, AnimationListener* listener ) :
	ViewportFilterAnimationControllerImpl<IColorFilterAnimationController>( colorFilter, animationSystem, animation, listener ),
	_colorFilter( colorFilter )
{
	SetAnimation( _animation );
}

void ColorFilterAnimationController::Update( Double delta )
{
	// Call base implementation.
	ViewportFilterAnimationControllerImpl<IColorFilterAnimationController>::Update( delta );

	// Update filter.
	if ( _trackColor != nullptr )
	{
		Color color;
		_trackColor->GetValue( _time, color );
		_colorFilter->SetColor( color );
	}
}

void ColorFilterAnimationController::SetAnimation( IAnimation* animation )
{
	// Call base implementation.
	ViewportFilterAnimationControllerImpl<IColorFilterAnimationController>::SetAnimation( animation );

	_trackColor = GetTrack( _trackColor, ColorFilterProperty::Color );
}

IColorFilterAnimationController* ColorFilterAnimationController::AsColor() const
{
	return (IColorFilterAnimationController*)this;
}

IKeyframedColorTrack* ColorFilterAnimationController::CreateColorTrack()
{
	return (_trackColor = (_trackColor == nullptr) ? _animation->CreateColorTrack(ColorFilterProperty::Color.ToString()) : _trackColor)->AsKeyframed();
}

IProceduralColorTrack* ColorFilterAnimationController::CreateColorTrack( const AnimationTrack& type )
{
	return (_trackColor = (_trackColor == nullptr) ? _animation->CreateColorTrack(ColorFilterProperty::Color.ToString(), type) : _trackColor)->AsProcedural();
}


} // view


} // synkro
