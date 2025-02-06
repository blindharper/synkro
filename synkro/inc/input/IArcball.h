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
// Purpose: Defines logical arcball.
//==============================================================================
#ifndef _SYNKRO_INPUT_IARCBALL_
#define _SYNKRO_INPUT_IARCBALL_


#include "config.h"
#include <input/IInputDevice.h>
#include <math/Quaternion.h>


namespace synkro
{


namespace input
{


/**
 * Logical arcball.
 */
iface IArcball :
	public IInputDevice
{
public:
	/**
	 * Subscribes for orientation event listening.
	 * @param listener Event listener.
	 * @exception BadArgumentException listener is null.
	 */
	virtual void											ListenOrientation( ArcballListener* listener ) = 0;

	/**
	 * Subscribes for zoom event listening.
	 * @param listener Event listener.
	 * @exception BadArgumentException listener is null.
	 */
	virtual void											ListenZoom( ArcballListener* listener ) = 0;

	/**
	 * Retrieves orientation after the last state poll.
	 * @param [out] orientation Current orientation.
	 */
	virtual void											GetOrientation( math::Quaternion& orientation ) const = 0;

	/**
	 * Retrieves zoom after the last state poll.
	 * @return Current zoom.
	 */
	virtual Int												GetZoom() const = 0;
};


} // input


} // synkro


#endif // _SYNKRO_INPUT_IARCBALL_
