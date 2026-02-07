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
// Purpose: Defines physics system factory.
//==============================================================================
#ifndef _SYNKRO_PHYS_IPHYSICSSYSTEMFACTORY_
#define _SYNKRO_PHYS_IPHYSICSSYSTEMFACTORY_


#include "config.h"
#include <core/IFactory.h>


namespace synkro
{


namespace phys
{


/**
 * Physics system factory.
 */
iface IPhysicsSystemFactory :
	public core::IFactory
{
public:
	/**
	 * Creates physics system.
	 * @param log Log to write debug messages to.
	 * @return Created physics system.
	 */
	virtual IPhysicsSystem*									Create( diag::ILog* log ) = 0;
};


} // phys


} // synkro


#endif // _SYNKRO_PHYS_IPHYSICSSYSTEMFACTORY_
