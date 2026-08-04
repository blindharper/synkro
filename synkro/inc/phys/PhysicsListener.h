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
// Purpose: Defines physics listener.
//==============================================================================
#ifndef _SYNKRO_PHYS_PHYSICSLISTENER_
#define _SYNKRO_PHYS_PHYSICSLISTENER_


#include "config.h"


namespace synkro
{


namespace phys
{


/**
 * Physics events listener.
 */
iface PhysicsListener
{
public:
	/**
	 * Handles actor's "Wake" event.
	 * @param actor Dynamic actor that was awaken.
	 */
	virtual void											OnPhysicsActorWake( IDynamicActor* actor ) = 0;

	/**
	 * Handles actor's "Sleep" event.
	 * @param actor Dynamic actor that was put to sleep.
	 */
	virtual void											OnPhysicsActorSleep( IDynamicActor* actor ) = 0;
};


} // phys


} // synkro


#endif // _SYNKRO_PHYS_PHYSICSLISTENER_
