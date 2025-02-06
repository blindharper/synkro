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
// Purpose: Defines viewport transition listener.
//==============================================================================
#ifndef _SYNKRO_VIEW_VIEWPORTLISTENER_
#define _SYNKRO_VIEW_VIEWPORTLISTENER_


#include "config.h"


namespace synkro
{


namespace view
{


/**
 * Viewport transition listener.
 */
iface ViewportListener
{
public:
	/**
	 * Processes "Animation Stopped" event.
	 * @param sender Event sender.
	 */
	virtual void											OnViewportTransitionStop( IViewportTransitionController* sender ) = 0;

	/**
	 * Processes "Animation Loop" event.
	 * @param sender Event sender.
	 */
	virtual void											OnViewportTransitionLoop( IViewportTransitionController* sender ) = 0;
};


} // view


} // synkro


#endif // _SYNKRO_VIEW_VIEWPORTLISTENER_
