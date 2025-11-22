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


TextAnimationController::TextAnimationController( IText* text, IAnimationSystem* animationSystem, IAnimationSet* animations, AnimationListener* listener ) :
	PlaybackControllerImpl<ITextAnimationController>( animationSystem, animations, listener ),
	_text( text ),
	_trackLocation( nullptr ),
	_trackLocationX( nullptr ),
	_trackLocationY( nullptr ),
	_trackRect( nullptr ),
	_trackOrientation( nullptr ),
	_trackScale( nullptr ),
	_trackColorGradient( nullptr ),
	_trackColor( nullptr ),
	_trackOpacity( nullptr ),
	_trackVisibility( nullptr )
{
}

void TextAnimationController::Update( Double delta )
{
	// Call base implementation.
	PlaybackControllerImpl<ITextAnimationController>::Update( delta );

	// Update text.
	if ( _trackLocation != nullptr )
	{
		Point location;
		_trackLocation->GetValue( CurrentTime(), location );
		_text->SetLocation( location );
	}
	else
	{
		if ( _trackLocationX != nullptr )
		{
			Float pos;
			_trackLocationX->GetValue( CurrentTime(), pos );
			_text->SetLocationX( pos );
		}

		if ( _trackLocationY != nullptr )
		{
			Float pos;
			_trackLocationY->GetValue( CurrentTime(), pos );
			_text->SetLocationY( pos );
		}
	}

	if ( _trackRect != nullptr )
	{
		Rect rect;
		_trackRect->GetValue( CurrentTime(), rect );
		_text->SetRect( rect );
	}

	if ( _trackOrientation != nullptr )
	{
		Float orientation;
		_trackOrientation->GetValue( CurrentTime(), orientation );
		_text->SetOrientation( orientation );
	}

	if ( _trackScale != nullptr )
	{
		Float scale;
		_trackScale->GetValue( CurrentTime(), scale );
		_text->SetScale( scale );
	}

	if ( _trackColorGradient != nullptr )
	{
		ColorGradient gradient;
		_trackColorGradient->GetValue( CurrentTime(), gradient );
		_text->SetGradient( gradient );
	}
	else
	{
		if ( _trackColor != nullptr )
		{
			Color color;
			_trackColor->GetValue( CurrentTime(), color );
			_text->SetColor( color );
		}
	}

	if ( _trackOpacity != nullptr )
	{
		Float opacity;
		_trackOpacity->GetValue( CurrentTime(), opacity );
		_text->SetOpacity( opacity );
	}

	if ( _trackVisibility != nullptr )
	{
		Bool show;
		_trackVisibility->GetValue( CurrentTime(), show );
		_text->Show( show );
	}
}

IKeyframedPointTrack* TextAnimationController::CreateLocationTrack()
{
	return (_trackLocation = _animations->GetActiveAnimation()->CreatePointTrack( TextProperty::Location.ToString()) )->AsKeyframed();
}

IKeyframedFloatTrack* TextAnimationController::CreateLocationXTrack()
{
	return (_trackLocationX = _animations->GetActiveAnimation()->CreateFloatTrack( TextProperty::LocationX.ToString()) )->AsKeyframed();
}

IProceduralFloatTrack* TextAnimationController::CreateLocationXTrack( const AnimationTrack& type )
{
	return (_trackLocationX = _animations->GetActiveAnimation()->CreateFloatTrack( TextProperty::LocationX.ToString(), type) )->AsProcedural();
}

IKeyframedFloatTrack* TextAnimationController::CreateLocationYTrack()
{
	return (_trackLocationY = _animations->GetActiveAnimation()->CreateFloatTrack( TextProperty::LocationY.ToString()) )->AsKeyframed();
}

IProceduralFloatTrack* TextAnimationController::CreateLocationYTrack( const AnimationTrack& type )
{
	return (_trackLocationY = _animations->GetActiveAnimation()->CreateFloatTrack( TextProperty::LocationY.ToString(), type) )->AsProcedural();
}

IKeyframedRectTrack* TextAnimationController::CreateRectTrack()
{
	return (_trackRect = _animations->GetActiveAnimation()->CreateRectTrack( TextProperty::Rect.ToString()) )->AsKeyframed();
}

IKeyframedFloatTrack* TextAnimationController::CreateOrientationTrack()
{
	return (_trackOrientation = _animations->GetActiveAnimation()->CreateFloatTrack( TextProperty::Orientation.ToString()) )->AsKeyframed();
}

IProceduralFloatTrack* TextAnimationController::CreateOrientationTrack( const AnimationTrack& type )
{
	return (_trackOrientation = _animations->GetActiveAnimation()->CreateFloatTrack( TextProperty::Orientation.ToString(), type) )->AsProcedural();
}

IKeyframedFloatTrack* TextAnimationController::CreateScaleTrack()
{
	return (_trackScale = _animations->GetActiveAnimation()->CreateFloatTrack( TextProperty::Scale.ToString()) )->AsKeyframed();
}

IProceduralFloatTrack* TextAnimationController::CreateScaleTrack( const AnimationTrack& type )
{
	return (_trackScale = _animations->GetActiveAnimation()->CreateFloatTrack( TextProperty::Scale.ToString(), type) )->AsProcedural();
}

IKeyframedColorGradientTrack* TextAnimationController::CreateColorGradientTrack()
{
	return (_trackColorGradient = _animations->GetActiveAnimation()->CreateColorGradientTrack( TextProperty::ColorGradient.ToString()) )->AsKeyframed();
}

IKeyframedColorTrack* TextAnimationController::CreateColorTrack()
{
	return (_trackColor = _animations->GetActiveAnimation()->CreateColorTrack( TextProperty::Color.ToString()) )->AsKeyframed();
}

IProceduralColorTrack* TextAnimationController::CreateColorTrack( const AnimationTrack& type )
{
	return (_trackColor = _animations->GetActiveAnimation()->CreateColorTrack( TextProperty::Color.ToString(), type) )->AsProcedural();
}

IKeyframedFloatTrack* TextAnimationController::CreateOpacityTrack()
{
	return (_trackOpacity = _animations->GetActiveAnimation()->CreateFloatTrack( TextProperty::Opacity.ToString()) )->AsKeyframed();
}

IProceduralFloatTrack* TextAnimationController::CreateOpacityTrack( const AnimationTrack& type )
{
	return (_trackOpacity = _animations->GetActiveAnimation()->CreateFloatTrack( TextProperty::Opacity.ToString(), type) )->AsProcedural();
}

IKeyframedBoolTrack* TextAnimationController::CreateVisibilityTrack()
{
	return (_trackVisibility = _animations->GetActiveAnimation()->CreateBoolTrack( TextProperty::Visibility.ToString()) )->AsKeyframed();
}

void TextAnimationController::UpdateTracks()
{
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


} // over


} // synkro
