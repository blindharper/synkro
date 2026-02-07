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
// Purpose: Defines physics system.
//==============================================================================
#ifndef _SYNKRO_PHYS_IPHYSICSSYSTEM_
#define _SYNKRO_PHYS_IPHYSICSSYSTEM_


#include "config.h"
#include <lang/String.h>
#include <math/Vector3.h>
#include <core/ISystem.h>


namespace synkro
{


namespace phys
{


/**
 * Physics system. Performs dynamic simulations.
 */
iface IPhysicsSystem :
	public core::ISystem
{
public:
	/**
	 * Creates physics environment.
	 * @param name Unique environment name.
	 * @return Created physics environment.
	 */
	virtual IPhysicsEnvironment*							CreateEnvironment( const lang::String& name ) = 0;

	/**
	 * Creates physics material with the given properties.
	 * @param staticFriction Coefficient of static friction.
	 * @param dynamicFriction Coefficient of dynamic friction.
	 * @param restitution Coefficient of restitution.
	 * @return Created material.
	 */
	virtual IPhysicsMaterial*								CreateMaterial( Float staticFriction, Float dynamicFriction, Float restitution ) = 0;

	/**
	 * Creates plane shape.
	 * @param material Shape's material.
	 * @param normal Normal to the plane.
	 * @param distance Distance to the origin.
	 * @return Created shape.
	 */
	virtual IShape*											CreatePlaneShape( IPhysicsMaterial* material, const math::Vector3& normal, Float distance ) = 0;

	/**
	 * Creates box shape.
	 * @param material Shape's material.
	 * @param width Box width.
	 * @param depth Box depth.
	 * @param height Box height.
	 * @return Created shape.
	 */
	virtual IShape*											CreateBoxShape( IPhysicsMaterial* material, Float width, Float depth, Float height ) = 0;
};


} // phys


} // synkro


#endif // _SYNKRO_PHYS_IPHYSICSSYSTEM_
