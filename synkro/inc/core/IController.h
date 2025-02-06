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
// Purpose: Defines abstract controller.
//==============================================================================
#ifndef _SYNKRO_CORE_ICONTROLLER_
#define _SYNKRO_CORE_ICONTROLLER_


#include "config.h"
#include <core/IObject.h>
#include <core/ControllerState.h>


namespace synkro
{


namespace core
{


/**
 * Abstract controller.
 */
iface IController :
	public IObject
{
public:
	/**
	 * Starts or stops updating controller.
	 * @param start Set to true to start controller or to false to stop it.
	 */
	virtual void											Start( Bool start ) = 0;

	/**
	 * Suspends or resumes updating controller.
	 * @param pause Set to true to pause the controller or to false to resume it.
	 */
	virtual void											Pause( Bool pause ) = 0;

	/**
	 * Updates the controller by the given amount of time.
	 * @param delta Time passed since the last update.
	 */
	virtual void											Update( Double delta ) = 0;

	/**
	 * Sets internal controller time, in seconds.
	 * @param time Internal controller time.
	 */
	virtual void											SetTime( Double time ) = 0;

	/**
	 * Stops and then starts the controller.
	 */
	virtual void											Restart() = 0;

	/**
	 * Resets internal controller state.
	 */
	virtual void											Reset() = 0;

	/**
	 * Retrieves internal controller time, in seconds.
	 */
	virtual Double											GetTime() const = 0;

	/**
	 * Retrieves current controller state.
	 */
	virtual ControllerState									GetState() const = 0;
};


} // core


} // synkro


#endif // _SYNKRO_CORE_ICONTROLLER_
