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


ColorFilterAnimationController::ColorFilterAnimationController( IColorFilter* colorFilter, IAnimationSystem* animationSystem, IAnimationSet* animations, AnimationListener* listener ) :
	ViewportFilterAnimationControllerImpl<IColorFilterAnimationController>( colorFilter, animationSystem, animations, listener ),
	_colorFilter( colorFilter ),
	_trackColor( nullptr )
{
}

void ColorFilterAnimationController::Update( Double delta )
{
	// Call base implementation.
	ViewportFilterAnimationControllerImpl<IColorFilterAnimationController>::Update( delta );

	// Update filter.
	if ( _trackColor != nullptr )
	{
		Color color;
		_trackColor->GetValue( CurrentTime(), color );
		_colorFilter->SetColor( color );
	}
}

IColorFilterAnimationController* ColorFilterAnimationController::AsColor() const
{
	return (IColorFilterAnimationController*)this;
}

IKeyframedColorTrack* ColorFilterAnimationController::CreateColorTrack()
{
	return (_trackColor = _animations->GetActiveAnimation()->CreateColorTrack(ColorFilterProperty::Color.ToString()))->AsKeyframed();
}

IProceduralColorTrack* ColorFilterAnimationController::CreateColorTrack( const AnimationTrack& type )
{
	return (_trackColor = _animations->GetActiveAnimation()->CreateColorTrack( ColorFilterProperty::Color.ToString(), type) )->AsProcedural();
}

void ColorFilterAnimationController::UpdateTracks()
{
	// Call base implementation.
	ViewportFilterAnimationControllerImpl<IColorFilterAnimationController>::UpdateTracks();

	_trackColor = GetTrack( _trackColor, ColorFilterProperty::Color );
}


} // view


} // synkro
