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
// Purpose: Defines dynamic actor.
//==============================================================================
#ifndef _SYNKRO_PHYS_IDYNAMICACTOR_
#define _SYNKRO_PHYS_IDYNAMICACTOR_


#include "config.h"
#include <phys/IRigidBody.h>


namespace synkro
{


namespace phys
{


/**
 * Dynamic actor.
 */
iface IDynamicActor :
	public IRigidBody
{
public:
	/**
	 * Sets actor's linear velocity.
	 * @param velocity Body's linear velocity.
	 */
	virtual void											SetLinearVelocity( const math::Vector3& velocity ) = 0;

	/**
	 * Sets actor's angular velocity.
	 * @param velocity Body's angular velocity.
	 */
	virtual void											SetAngularVelocity( const math::Vector3& velocity ) = 0;

	/**
	 * Retrieves actor's linear velocity.
	 * @param [out] velocity Variable where to store actor's linear velocity.
	 */
	virtual void											GetLinearVelocity( math::Vector3& velocity ) const = 0;

	/**
	 * Retrieves actor's angular velocity.
	 * @param [out] velocity Variable where to store actor's angular velocity.
	 */
	virtual void											GetAngularVelocity( math::Vector3& velocity ) const = 0;
};


} // phys


} // synkro


#endif // _SYNKRO_PHYS_IDYNAMICACTOR_
