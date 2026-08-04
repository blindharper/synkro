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
// Purpose: Defines extended physics system.
//==============================================================================
#ifndef _SYNKRO_PHYS_IPHYSICSSYSTEMEX_
#define _SYNKRO_PHYS_IPHYSICSSYSTEMEX_


#include "config.h"
#include <phys/IPhysicsSystem.h>


namespace synkro
{


namespace phys
{


/**
 * Extended physics system.
 */
iface IPhysicsSystemEx :
	public IPhysicsSystem
{
public:
	/**
	 * Retrieves the total number of environments.
	 */
	virtual ULong											GetEnvironmentCount() const = 0;

	/**
	 * Retrieves an environment by index.
	 * @param index Index of the environment to retrieve.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual IPhysicsEnvironmentEx*							GetEnvironment( ULong index ) const = 0;

	/**
	 * Retrieves an environment by name.
	 * @param name Name of the environment to retrieve.
	 */
	virtual IPhysicsEnvironmentEx*							GetEnvironment( const lang::String& name ) const = 0;
};


} // phys


} // synkro


#endif // _SYNKRO_PHYS_IPHYSICSSYSTEMEX_
