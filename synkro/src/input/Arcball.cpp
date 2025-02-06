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
// Purpose: Logical arcball.
//==============================================================================
#include "config.h"
#include "Arcball.h"
#include <win/IWindow.h>
#include <math/Math.h>


//------------------------------------------------------------------------------

using namespace synkro::lang;
using namespace synkro::math;
using namespace synkro::win;

//------------------------------------------------------------------------------


namespace synkro
{


namespace input
{


Arcball::Arcball( BaseInputSystem* inputSystem, IMouse* mouse, IWindow* window ) :
	_orientations( A(OrientationEvent) ),
	_zooms( A(ZoomEvent) ),
	_zoom( 0L ),
	_inputSystem( inputSystem ),
	_mouse( (Mouse*)mouse ),
	_width( CastFloat(window->GetWidth()) ),
	_height( CastFloat(window->GetHeight()) ),
	_lastPos( 0.0f, 0.0f, 0.0f ),
	_dragging( false ),
	_listenRotates( false ),
	_listenZooms( false )
{
	// Set mouse position to window center.
	_point.X = CastInt(_width / 2.0f);
	_point.Y = CastInt(_height / 2.0f);
}

Bool Arcball::Update( Double delta )
{
	// Remove old events.
	_orientations.Clear();
	_zooms.Clear();

	// Generate events.
	if ( _listenRotates )
	{
		// Accumulate mouse moves.
		Int deltaX = 0L; Int dx = 0L;
		Int deltaY = 0L; Int dy = 0L;
		UInt eventX = _mouse->GetNextAxisMove( none, Axis::X, dx, false );
		UInt eventY = _mouse->GetNextAxisMove( none, Axis::Y, dy, false );
		if ( (eventX != none) || (eventY != none) )
		{
			do
			{
				deltaX += dx;
				deltaY += dy;
				eventX = _mouse->GetNextAxisMove( eventX, Axis::X, dx, false );
				eventY = _mouse->GetNextAxisMove( eventY, Axis::Y, dy, false );
			}
			while( (eventX != none) || (eventY != none) );
		}

		_point.X += deltaX;
		_point.Y += deltaY;
		if ( _point.X < 0 ) { _point.X = 0; }
		if ( CastFloat(_point.X) > _width ) { _point.X = CastInt(_width); }
		if ( _point.Y < 0 ) { _point.Y = 0; }
		if ( CastFloat(_point.Y) > _height ) { _point.Y = CastInt(_height); }

		MouseButton btn;
		const UInt eventDown = _mouse->GetNextButtonDown( none, MouseButton::Left, btn, false );
		const UInt eventUp = _mouse->GetNextButtonUp( none, MouseButton::Left, btn, false );
		if ( eventDown != none )
		{
			_dragging = true;
			_lastOrientation = _orientation;
			PointToVector( CastFloat(_point.X), CastFloat(_point.Y), _lastPos );
		}
		else if ( eventUp != none )
		{
			_dragging = false;
		}

		if ( ((deltaX != 0L) || (deltaY != 0L)) && _dragging )
		{
			Vector3 currPos;
			PointToVector( CastFloat(_point.X), CastFloat(_point.Y), currPos );
			const Vector3 cross = currPos^_lastPos;
			if ( cross.Length() > Math::Eps )
			{
				const Quaternion rot( cross.x, cross.y, cross.z, currPos*_lastPos );
				_orientation = _lastOrientation * rot;
				_orientations.Add( _orientation );
			}
		}
	}

	// Zooms.
	if ( _listenZooms )
	{
		Int deltaZoom = 0L;
		const Axis axis = Axis::Z;
		UInt event = none;
		if ( (event = _mouse->GetNextAxisMove(none, axis, deltaZoom, true)) != none )
		{
			_zooms.Add( deltaZoom );
			do
			{
				_zooms.Add( deltaZoom );
			}
			while( (event = _mouse->GetNextAxisMove(event, axis, deltaZoom, true)) != none );
		}
	}

	return true;
}

void Arcball::ListenOrientation( ArcballListener* listener )
{
	assert( listener != nullptr );

	_inputSystem->ListenArcballRotate( this, listener );
	_listenRotates = true;
}

void Arcball::ListenZoom( ArcballListener* listener )
{
	assert( listener != nullptr );

	_inputSystem->ListenArcballZoom( this, listener );
	_listenZooms = true;
}

UInt Arcball::GetNextOrientation( UInt event, Quaternion& orientation, Bool handle )
{
	if ( (event != none) && handle )
	{
		_orientations[event].Handled = handle;
	}

	for ( UInt i = (event != none) ? event+1 : 0; i < _orientations.Size(); ++i )
	{
		if ( !_orientations[i].Handled )
		{
			orientation = _orientations[i].Orientation;
			return i;
		}
	}

	return none;
}

UInt Arcball::GetNextZoom( UInt event, Int& delta, Bool handle )
{
	if ( (event != none) && handle )
	{
		_zooms[event].Handled = handle;
	}

	for ( UInt i = (event != none) ? event+1 : 0; i < _zooms.Size(); ++i )
	{
		if ( !_zooms[i].Handled )
		{
			delta = _zooms[i].Delta;
			return i;
		}
	}

	return none;
}

void Arcball::PointToVector( Float x, Float y, Vector3& vec )
{
	vec.x = (2.0f*x - _width) / (_width);
	vec.y = (_height - 2.0f*y) / (_height);
	vec.z = 0.0f;

	const Float d = vec.x*vec.x + vec.y*vec.y;
	if ( d > 1.0f )
	{
		const Float factor = 1.0f / Math::Sqrt( d );
		vec.x *= factor;
		vec.y *= factor;
	}
	else
	{
		vec.z = Math::Sqrt( 1.0f - d );
	}
}


} // input


} // synkro
