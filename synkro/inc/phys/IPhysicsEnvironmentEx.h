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
// Purpose: Defines extended physics environment.
//==============================================================================
#ifndef _SYNKRO_PHYS_IPHYSICSENVIRONMENTEX_
#define _SYNKRO_PHYS_IPHYSICSENVIRONMENTEX_


#include "config.h"
#include <phys/IPhysicsEnvironment.h>


namespace synkro
{


namespace phys
{


/**
 * Extended physics environment.
 */
iface IPhysicsEnvironmentEx :
	public IPhysicsEnvironment
{
public:
	/**
	 * Registers physics event listener.
	 * @param listener Event listener.
	 */
	virtual void											Listen( PhysicsListener* listener ) = 0;
};


} // phys


} // synkro


#endif // _SYNKRO_PHYS_IPHYSICSENVIRONMENTEX_
