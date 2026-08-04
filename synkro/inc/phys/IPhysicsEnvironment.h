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
// Purpose: Defines physics environment.
//==============================================================================
#ifndef _SYNKRO_PHYS_IPHYSICSENVIRONMENT_
#define _SYNKRO_PHYS_IPHYSICSENVIRONMENT_


#include "config.h"
#include <core/IObject.h>
#include <math/Vector3.h>


namespace synkro
{


namespace phys
{


/**
 * Physics environment.
 */
iface IPhysicsEnvironment :
	public core::IObject
{
public:
	/**
	 * Executes a single step of dynamic simulations.
	 * @param delta Time passed since the last update.
	 */
	virtual void											Update( Double delta ) = 0;

	/**
	 * Creates static actor.
	 * @param transform Actor's initial transform.
	 * @param shape Actor's collision shape.
	 * @return Created actor.
	 */
	virtual IStaticActor*									CreateStaticActor( const math::Matrix4x4& transform, IShape* shape ) = 0;

	/**
	 * Creates dynamic actor.
	 * @param transform Actor's initial transform.
	 * @param shape Actor's collision shape.
	 * @param density Actor's density.
	 * @return Created actor.
	 */
	virtual IDynamicActor*									CreateDynamicActor( const math::Matrix4x4& transform, IShape* shape, Float density ) = 0;

	/**
	 * Sets environment gravity vector.
	 * @param gravity New environment gravity.
	 */
	virtual void											SetGravity( const math::Vector3& gravity ) = 0;

	/**
	 * Retrieves environment gravity vector.
	 * @param [out] gravity New environment gravity.
	 */
	virtual void											GetGravity( math::Vector3& gravity ) const = 0;

	/**
	 * Retrieves environment name.
	 */
	virtual lang::String									GetName() const = 0;

	/**
	 * Retrieves the number of actors that awoke during last update.
	 * @return Number of dynamic actors.
	 */
	virtual UInt											GetAwakenActorCount() const = 0;

	/**
	 * Retrieves dynamic actor just awaken by index.
	 * @param index Index of the actor to retrieve.
	 * @return Requested actor.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual IDynamicActor*									GetAwakenActor( UInt index ) const = 0;

	/**
	 * Retrieves the number of actors that were put to sleep during last update.
	 * @return Number of dynamic actors.
	 */
	virtual UInt											GetPutToSleepActorCount() const = 0;

	/**
	 * Retrieves dynamic actor just put to sleep by index.
	 * @param index Index of the actor to retrieve.
	 * @return Requested actor.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual IDynamicActor*									GetPutToSleepActor( UInt index ) const = 0;
};


} // phys


} // synkro


#endif // _SYNKRO_PHYS_IPHYSICSENVIRONMENT_
