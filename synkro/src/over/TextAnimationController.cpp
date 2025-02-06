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
// Purpose: Animation controller for text implementation.
//==============================================================================
#include "config.h"
#include "TextAnimationController.h"
#include "TextProperty.h"
#include <over/IText.h>


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::img;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace over
{


TextAnimationController::TextAnimationController( IText* text, IAnimationSystem* animationSystem, IAnimation* animation, AnimationListener* listener ) :
	PlaybackControllerImpl<ITextAnimationController>( animationSystem, animation, listener ),
	_text( text )
{
	SetAnimation( _animation );
}

void TextAnimationController::Update( Double delta )
{
	// Call base implementation.
	PlaybackControllerImpl<ITextAnimationController>::Update( delta );

	// Update text.
	if ( _trackLocation != nullptr )
	{
		Point location;
		_trackLocation->GetValue( _time, location );
		_text->SetLocation( location );
	}
	else
	{
		if ( _trackLocationX != nullptr )
		{
			Float pos;
			_trackLocationX->GetValue( _time, pos );
			_text->SetLocationX( pos );
		}

		if ( _trackLocationY != nullptr )
		{
			Float pos;
			_trackLocationY->GetValue( _time, pos );
			_text->SetLocationY( pos );
		}
	}

	if ( _trackRect != nullptr )
	{
		Rect rect;
		_trackRect->GetValue( _time, rect );
		_text->SetRect( rect );
	}

	if ( _trackOrientation != nullptr )
	{
		Float orientation;
		_trackOrientation->GetValue( _time, orientation );
		_text->SetOrientation( orientation );
	}

	if ( _trackScale != nullptr )
	{
		Float scale;
		_trackScale->GetValue( _time, scale );
		_text->SetScale( scale );
	}

	if ( _trackColorGradient != nullptr )
	{
		ColorGradient gradient;
		_trackColorGradient->GetValue( _time, gradient );
		_text->SetGradient( gradient );
	}
	else
	{
		if ( _trackColor != nullptr )
		{
			Color color;
			_trackColor->GetValue( _time, color );
			_text->SetColor( color );
		}
	}

	if ( _trackOpacity != nullptr )
	{
		Float opacity;
		_trackOpacity->GetValue( _time, opacity );
		_text->SetOpacity( opacity );
	}

	if ( _trackVisibility != nullptr )
	{
		Bool show;
		_trackVisibility->GetValue( _time, show );
		_text->Show( show );
	}
}

void TextAnimationController::SetAnimation( IAnimation* animation )
{
	// Call base implementation.
	PlaybackControllerImpl<ITextAnimationController>::SetAnimation( animation );

	_trackLocation		= GetTrack( _trackLocation, TextProperty::Location );
	_trackLocationX		= GetTrack( _trackLocationX, TextProperty::LocationX );
	_trackLocationY		= GetTrack( _trackLocationY, TextProperty::LocationY );
	_trackRect			= GetTrack( _trackRect, TextProperty::Rect );
	_trackOrientation	= GetTrack( _trackOrientation, TextProperty::Orientation );
	_trackScale			= GetTrack( _trackScale, TextProperty::Scale );
	_trackColorGradient	= GetTrack( _trackColorGradient, TextProperty::ColorGradient );
	_trackColor			= GetTrack( _trackColor, TextProperty::Color );
	_trackOpacity		= GetTrack( _trackOpacity, TextProperty::Opacity );
	_trackVisibility	= GetTrack( _trackVisibility, TextProperty::Visibility );
}

IKeyframedPointTrack* TextAnimationController::CreateLocationTrack()
{
	return (_trackLocation = (_trackLocation == nullptr) ? _animation->CreatePointTrack(TextProperty::Location.ToString()) : _trackLocation)->AsKeyframed();
}

IKeyframedFloatTrack* TextAnimationController::CreateLocationXTrack()
{
	return (_trackLocationX = (_trackLocationX == nullptr) ? _animation->CreateFloatTrack(TextProperty::LocationX.ToString()) : _trackLocationX)->AsKeyframed();
}

IProceduralFloatTrack* TextAnimationController::CreateLocationXTrack( const AnimationTrack& type )
{
	return (_trackLocationX = (_trackLocationX == nullptr) ? _animation->CreateFloatTrack(TextProperty::LocationX.ToString(), type) : _trackLocationX)->AsProcedural();
}

IKeyframedFloatTrack* TextAnimationController::CreateLocationYTrack()
{
	return (_trackLocationY = (_trackLocationY == nullptr) ? _animation->CreateFloatTrack(TextProperty::LocationY.ToString()) : _trackLocationY)->AsKeyframed();
}

IProceduralFloatTrack* TextAnimationController::CreateLocationYTrack( const AnimationTrack& type )
{
	return (_trackLocationY = (_trackLocationY == nullptr) ? _animation->CreateFloatTrack(TextProperty::LocationY.ToString(), type) : _trackLocationY)->AsProcedural();
}

IKeyframedRectTrack* TextAnimationController::CreateRectTrack()
{
	return (_trackRect = (_trackRect == nullptr) ? _animation->CreateRectTrack(TextProperty::Rect.ToString()) : _trackRect)->AsKeyframed();
}

IKeyframedFloatTrack* TextAnimationController::CreateOrientationTrack()
{
	return (_trackOrientation = (_trackOrientation == nullptr) ? _animation->CreateFloatTrack(TextProperty::Orientation.ToString()) : _trackOrientation)->AsKeyframed();
}

IProceduralFloatTrack* TextAnimationController::CreateOrientationTrack( const AnimationTrack& type )
{
	return (_trackOrientation = (_trackOrientation == nullptr) ? _animation->CreateFloatTrack(TextProperty::Orientation.ToString(), type) : _trackOrientation)->AsProcedural();
}

IKeyframedFloatTrack* TextAnimationController::CreateScaleTrack()
{
	return (_trackScale = (_trackScale == nullptr) ? _animation->CreateFloatTrack(TextProperty::Scale.ToString()) : _trackScale)->AsKeyframed();
}

IProceduralFloatTrack* TextAnimationController::CreateScaleTrack( const AnimationTrack& type )
{
	return (_trackScale = (_trackScale == nullptr) ? _animation->CreateFloatTrack(TextProperty::Scale.ToString(), type) : _trackScale)->AsProcedural();
}

IKeyframedColorGradientTrack* TextAnimationController::CreateColorGradientTrack()
{
	return (_trackColorGradient = (_trackColorGradient == nullptr) ? _animation->CreateColorGradientTrack(TextProperty::ColorGradient.ToString()) : _trackColorGradient)->AsKeyframed();
}

IKeyframedColorTrack* TextAnimationController::CreateColorTrack()
{
	return (_trackColor = (_trackColor == nullptr) ? _animation->CreateColorTrack(TextProperty::Color.ToString()) : _trackColor)->AsKeyframed();
}

IProceduralColorTrack* TextAnimationController::CreateColorTrack( const AnimationTrack& type )
{
	return (_trackColor = (_trackColor == nullptr) ? _animation->CreateColorTrack(TextProperty::Color.ToString(), type) : _trackColor)->AsProcedural();
}

IKeyframedFloatTrack* TextAnimationController::CreateOpacityTrack()
{
	return (_trackOpacity = (_trackOpacity == nullptr) ? _animation->CreateFloatTrack(TextProperty::Opacity.ToString()) : _trackOpacity)->AsKeyframed();
}

IProceduralFloatTrack* TextAnimationController::CreateOpacityTrack( const AnimationTrack& type )
{
	return (_trackOpacity = (_trackOpacity == nullptr) ? _animation->CreateFloatTrack(TextProperty::Opacity.ToString(), type) : _trackOpacity)->AsProcedural();
}

IKeyframedBoolTrack* TextAnimationController::CreateVisibilityTrack()
{
	return (_trackVisibility = (_trackVisibility == nullptr) ? _animation->CreateBoolTrack(TextProperty::Visibility.ToString()) : _trackVisibility)->AsKeyframed();
}


} // over


} // synkro
