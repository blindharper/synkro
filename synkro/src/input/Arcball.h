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
#ifndef _SYNKRO_INPUT_ARCBALL_
#define _SYNKRO_INPUT_ARCBALL_


#include "config.h"
#include <core/ObjectImpl.h>
#include "Mouse.h"
#include <input/IArcball.h>
#include <lang/Vector.h>
#include <lang/Point.h>


namespace synkro
{


namespace input
{


// Logical arcball device.
class Arcball :
	public core::ObjectImpl<IArcball>
{
public:
	// Constructor.
	Arcball( BaseInputSystem* inputSystem, IMouse* mouse, win::IWindow* window );

	// IInputDevice methods.
	Bool													Update( Double delta );

	// IArcball methods.
	void													ListenOrientation( ArcballListener* listener );
	void													ListenZoom( ArcballListener* listener );
	void													GetOrientation( math::Quaternion& orientation ) const;
	Int														GetZoom() const;

	// Other methods.
	UInt													GetNextOrientation( UInt event, math::Quaternion& orientation, Bool handle );
	UInt													GetNextZoom( UInt event, Int& delta, Bool handle );

private:
	struct OrientationEvent
	{
		OrientationEvent( const math::Quaternion& orientation ) :
			Orientation( orientation ),
			Handled( false )
		{
		}

		OrientationEvent() :
			Handled( false )
		{
		}

		math::Quaternion	Orientation;
		Bool				Handled;
	};

	struct ZoomEvent
	{
		ZoomEvent( Int delta ) :
			Delta( delta ),
			Handled( false )
		{
		}

		ZoomEvent() :
			Handled( false )
		{
		}

		Int		Delta;
		Bool	Handled;
	};

	BaseInputSystem*										_inputSystem;
	P(Mouse)												_mouse;
	math::Quaternion										_orientation;
	math::Quaternion										_lastOrientation;
	math::Vector3											_lastPos;
	lang::Point												_point;
	Int														_zoom;
	Float													_width;
	Float													_height;
	Bool													_dragging;
	
	lang::Vector<OrientationEvent>							_orientations;
	lang::Vector<ZoomEvent>									_zooms;

	Bool													_listenRotates;
	Bool													_listenZooms;

	void													PointToVector( Float x, Float y, math::Vector3& vec );
};


#include "Arcball.inl"


} // input


} // synkro


#endif // _SYNKRO_INPUT_ARCBALL_
