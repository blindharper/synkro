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
// Purpose: Logical slider widget.
//==============================================================================
#include "config.h"
#include "Slider.h"
#include "OrientationConst.h"
#include <input/KeyConst.h>
#include <math/Math.h>


//------------------------------------------------------------------------------

using namespace synkro::input;
using namespace synkro::lang;
using namespace synkro::math;

//------------------------------------------------------------------------------


namespace synkro
{


namespace ui
{


Slider::Slider( BaseUiEx* ui, UInt id, IFrame* parent, ISlider* widget ) :
	WidgetWrapperImpl<ISlider>( ui, id, parent, widget ),
	BaseAnchoredObjectImpl<BaseAnchoredObject, IWidget>( widget ),
	_slider( widget ),
	_down( false ),
	_moved( false )
{
}

void Slider::Activate( Bool activate )
{
	// Call base implementation.
	WidgetWrapperImpl<ISlider>::Activate( activate );

	if ( activate )
	{
		const Key keysDiscrete[] = { Key::Home, Key::Numpad7, Key::End, Key::Numpad1, Key::Prior, Key::Numpad9, Key::Next, Key::Numpad3 };
		const Key keys[] = { Key::Up, Key::Down, Key::Left, Key::Right };
		_ui->ListenKeyDown( keysDiscrete, SizeOf(keysDiscrete), true );
		_ui->ListenKeyDown( keys, SizeOf(keys), false );
		_ui->ListenMouseAxisMove( Axis::Z );
	}
	else 
	{
		_down = false;
	}
}

UiEvent Slider::OnKeyDown( Double deltaTime, const Key& key, Bool alt, Bool shift, Bool control )
{
	const Float DELTA = 0.005f;
	Float delta = 0.0f;

	switch ( key )
	{
		case KEY_HOME:
		case KEY_NUMPAD7:
			delta = (_slider->GetOrientation() == Orientation::Horizontal) ? -1.0f : 1.0f;
			break;

		case KEY_END:
		case KEY_NUMPAD1:
			delta = (_slider->GetOrientation() == Orientation::Horizontal) ? 1.0f : -1.0f;
			break;

		case KEY_PRIOR:
		case KEY_NUMPAD9:
			delta = 0.1f;
			break;

		case KEY_NEXT:
		case KEY_NUMPAD3:
			delta = -0.1f;
			break;

		case KEY_DOWN:
		case KEY_LEFT:
			if ( _slider->GetPosition() > _slider->GetMinPosition() )
				delta = -DELTA;
			break;

		case KEY_UP:
		case KEY_RIGHT:
			if ( _slider->GetPosition() < _slider->GetMaxPosition() )
				delta = DELTA;
			break;
	}

	return AdjustPercentage( delta ) ? UI_EVENT_VALUE_CHANGED : UI_EVENT_NONE;
}

UiEvent Slider::OnMouseMove( const Point& location )
{
	_moved = true;
	_cursor = location;

	if ( _down )
	{
		Float percentage = 0.0f; Point pos = location;
		Rect rect; _widget->GetRect( rect );
		const Point loc = rect.TopLeft();
		const Size size( rect.Width(), rect.Height() );
		Size thumb; _slider->GetThumbSize( thumb );
		Int start = 0; Int end = 0;
		switch ( _slider->GetOrientation() )
		{
			case ORIENTATION_HORIZONTAL:
				start = loc.X;
				end = loc.X+CastInt(size.Width)-CastInt(thumb.Width);
				pos.X = Clamp( pos.X, start, end );
				pos.Y = loc.Y;
				percentage = CastFloat(pos.X-start) / CastFloat(end-start);
				break;

			case ORIENTATION_VERTICAL:
				start = loc.Y+CastInt(size.Height)-CastInt(thumb.Height);
				end = loc.Y;
				pos.X = loc.X;
				pos.Y = Clamp( pos.Y, end, start );
				percentage = CastFloat(pos.Y-start) / CastFloat(end-start);
				break;
		}
		const UInt minPosition = _slider->GetMinPosition();
		const UInt maxPosition = _slider->GetMaxPosition();
		_slider->SetPosition( minPosition + percentage*(maxPosition-minPosition) );
		return UI_EVENT_VALUE_CHANGED;
	}
	return UI_EVENT_NONE;
}

UiEvent Slider::OnMouseUp()
{
	_down = false;
	if ( !_moved )
	{
		Bool dirty = false;
		Float start = 0.0f; Float end = 0.0f; Float p = 0.0f;
		Rect rect; _widget->GetRect( rect );
		const Point loc = rect.TopLeft();
		const Size size( rect.Width(), rect.Height() );
		Size thumb; _slider->GetThumbSize( thumb );
		switch ( _slider->GetOrientation() )
		{
			case ORIENTATION_HORIZONTAL:
				if ( loc.X != _cursorOrg.X )
				{
					dirty = true;
					start = CastFloat(loc.X+CastInt(thumb.Width));
					end = CastFloat(loc.X+CastInt(size.Width)-CastInt(thumb.Width));
					p = Clamp( CastFloat(_cursorOrg.X), start, end );
				}
				break;

			case ORIENTATION_VERTICAL:
				if ( loc.Y != _cursorOrg.Y )
				{
					dirty = true;
					start = CastFloat(loc.Y+CastInt(size.Height)-CastInt(thumb.Height));
					end = CastFloat(loc.Y+CastInt(thumb.Height));
					p = Clamp( CastFloat(_cursorOrg.Y), end, start );
				}
				break;
		}

		if ( dirty )
		{
			const Float percentage = (p-start) / (end-start);
			const UInt minPosition = _slider->GetMinPosition();
			const UInt maxPosition = _slider->GetMaxPosition();
			_slider->SetPosition( minPosition + percentage*(maxPosition-minPosition) );
			return UI_EVENT_VALUE_CHANGED;
		}
	}
	return UI_EVENT_NONE;
}

Bool Slider::AdjustPercentage( Float delta )
{
	const UInt position = _slider->GetPosition();
	const UInt minPosition = _slider->GetMinPosition();
	const UInt maxPosition = _slider->GetMaxPosition();
	const Float percentageOrg = CastFloat(position-minPosition) / CastFloat(maxPosition-minPosition);
	const Float percentage = Clamp( percentageOrg+delta, 0.0f, 1.0f );
	if ( percentage != percentageOrg )
	{
		const UInt newPosition = minPosition + Math::Round( percentage*CastFloat(maxPosition-minPosition) );
		if ( newPosition != position )
		{
			_slider->SetPosition( newPosition );
			return true;
		}
	}
	return false;
}


} // ui


} // synkro
