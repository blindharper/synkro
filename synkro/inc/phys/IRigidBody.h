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
// Purpose: Defines rigid body.
//==============================================================================
#ifndef _SYNKRO_PHYS_IRIGIDBODY_
#define _SYNKRO_PHYS_IRIGIDBODY_


#include "config.h"
#include <phys/IRigidActor.h>
#include <phys/ForceMode.h>
#include <math/Vector3.h>


namespace synkro
{


namespace phys
{


/**
 * Rigid body.
 */
iface IRigidBody :
	public IRigidActor
{
public:
	/**
	 * Applies a force to the body.
	 * @param mode Force mode.
	 * @param force Force value.
	 */
	virtual void											AddForce( const ForceMode& mode, const math::Vector3& force ) = 0;

	/**
	 * Applies a torque to the body.
	 * @param mode Force mode.
	 * @param torque Torque value.
	 */
	virtual void											AddTorque( const ForceMode& mode, const math::Vector3& torque ) = 0;

	/**
	 * Clears the accumulated forces (sets the accumulated force back to zero).
	 * @param mode Force mode.
	 */
	virtual void											ClearForce( const ForceMode& mode ) = 0;

	/**
	 * Clears the accumulated torques (sets the accumulated torque back to zero).
	 * @param mode Force mode.
	 */
	virtual void											ClearTorque( const ForceMode& mode ) = 0;

	/**
	 * Sets body's mass.
	 * @param mass Body's mass. Default is 1.0.
	 */
	virtual void											SetMass( Float mass ) = 0;

	/**
	 * Sets actor's inertia tensor.
	 * @param inertia Inertia tensor.
	 */
	virtual void											SetInertia( const math::Vector3& inertia ) = 0;

	/**
	 * Sets actor's maximum linear velocity.
	 * @param velocity Body's linear velocity.
	 */
	virtual void											SetMaximumLinearVelocity( Float velocity ) = 0;

	/**
	 * Sets actor's maximum angular velocity.
	 * @param velocity Body's angular velocity.
	 */
	virtual void											SetMaximumAngularVelocity( Float velocity ) = 0;

	/**
	 * Retrieves actor's mass.
	 */
	virtual Float											GetMass() const = 0;

	/**
	 * Retrieves actor's inertia tensor.
	 * @param [out] inertia Variable where to store inertia tensor.
	 */
	virtual void											GetInertia( math::Vector3& inertia ) const = 0;

	/**
	 * Retrieves actor's maximum linear velocity.
	 */
	virtual Float											GetMaximumLinearVelocity() const = 0;

	/**
	 * Retrieves actor's maximum angular velocity.
	 */
	virtual Float											GetMaximumAngularVelocity() const = 0;
};


} // phys


} // synkro


#endif // _SYNKRO_PHYS_IRIGIDBODY_
