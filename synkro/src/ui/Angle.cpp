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
// Purpose: Logical angle widget.
//==============================================================================
#include "config.h"
#include "Angle.h"
#include <math/Math.h>
#include <input/KeyConst.h>


//------------------------------------------------------------------------------

using namespace synkro::input;
using namespace synkro::lang;
using namespace synkro::math;

//------------------------------------------------------------------------------


namespace synkro
{


namespace ui
{


Angle::Angle( BaseUiEx* ui, UInt id, IFrame* parent, IAngle* widget ) :
	WidgetWrapperImpl<IAngle>( ui, id, parent, widget ),
	BaseAnchoredObjectImpl<BaseAnchoredObject, IWidget>( widget ),
	_angle( widget ),
	_down( false ),
	_moved( false )
{
}

void Angle::Activate( Bool activate )
{
	// Call base implementation.
	WidgetWrapperImpl<IAngle>::Activate( activate );

	if ( activate )
	{
		const Key keysDiscrete[] = { Key::Home, Key::Numpad7, Key::Prior, Key::Numpad9, Key::Next, Key::Numpad3 };
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

UiEvent Angle::OnKeyDown( Double deltaTime, const Key& key, Bool alt, Bool shift, Bool control )
{
	const Float DELTA = 60.0f*deltaTime;
	Float delta = 0.0f;

	switch ( key )
	{
		case KEY_HOME:
		case KEY_NUMPAD7:
			if ( _angle->GetValue() != 0.0f )
			{
				_angle->SetValue( 0.0f );
				return UI_EVENT_VALUE_CHANGED;
			}
			return UI_EVENT_NONE;

		case KEY_UP:
		case KEY_LEFT:
			delta = DELTA;
			break;

		case KEY_DOWN:
		case KEY_RIGHT:
			delta = -DELTA;
			break;

		case KEY_PRIOR:
		case KEY_NUMPAD9:
			delta = 10.0f;
			break;

		case KEY_NEXT:
		case KEY_NUMPAD3:
			delta = -10.0f;
			break;
	}

	AdjustValue( delta );
	return UI_EVENT_VALUE_CHANGED;
}

UiEvent Angle::OnMouseMove( const Point& location )
{
	_moved = true;
	_cursor = location;
	if ( _down )
	{
		return LocationToValue( _cursor ) ? UI_EVENT_VALUE_CHANGED : UI_EVENT_NONE;
	}
	return UI_EVENT_NONE;
}

UiEvent Angle::OnMouseUp()
{
	_down = false;
	if ( !_moved )
	{
		return LocationToValue( _cursorOrg ) ? UI_EVENT_VALUE_CHANGED : UI_EVENT_NONE;
	}
	return UI_EVENT_NONE;
}

Bool Angle::LocationToValue( const Point& location )
{
	Rect rect; _widget->GetRect( rect );
	const Point loc = rect.TopLeft();
	const Float centerX = CastFloat(loc.X) + CastFloat(rect.Width()/2);
	const Float centerY = CastFloat(loc.Y) + CastFloat(rect.Height()/2);
	const Float deltaX = CastFloat(location.X) - centerX;
	const Float deltaY = centerY - CastFloat(location.Y);
	Float a = 0.0f;
	if ( deltaX == 0.0f )
	{
		if ( deltaY > 0.0f )
			a = 90.0f;
		else if ( deltaY < 0.0f )
			a = 270.0f;
		else
			return false;
	}
	else if ( deltaX > 0.0f )
	{
		const Float tan = deltaY / deltaX;
		a = Math::ToDegrees( Math::Atan(tan) );
		if ( a < 0.0f )
			a += 360.0f;
		else if ( a >= 360.0f )
			a -= 360.0f;
	}
	else // ( deltaX < 0.0f )
	{
		const Float tan = deltaY / deltaX;
		a = Math::ToDegrees( Math::Atan(tan) );
		a -= 180.0f;
		if ( a < 0.0f )
			a += 360.0f;
		else if ( a >= 360.0f )
			a -= 360.0f;
	}
	_angle->SetValue( a );
	return true;
}

void Angle::AdjustValue( Float delta )
{
	const Float oldValue = _angle->GetValue();
	Float newValue = oldValue + delta;
	if ( newValue < 0.0f )
	{
		newValue += 360.0f;
	}
	else if ( newValue >= 360.0f )
	{
		newValue -= 360.0f;
	}
	_angle->SetValue( newValue );
}


} // ui


} // synkro
