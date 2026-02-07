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
// Purpose: PhysX dynamic actor.
//=============================================================================
#ifndef _SYNKRO_PHYS_PHYSXDYNAMICACTOR_
#define _SYNKRO_PHYS_PHYSXDYNAMICACTOR_


#include "config.h"
#include <core/ObjectImpl.h>
#include <phys/IDynamicActor.h>
#include <phys/IShape.h>
#include <physx/include/PxRigidDynamic.h>
#include <physx/include/PxPhysics.h>
#include <physx/include/PxScene.h>


namespace synkro
{


namespace phys
{


// PhysX dynamic actor.
class PhysxDynamicActor :
	public core::ObjectImpl<IDynamicActor>
{
public:
	// Constructor & destructor.
	PhysxDynamicActor( physx::PxPhysics* physics, physx::PxScene* environment, const math::Matrix4x4& transform, IShape* shape, Float density );
	~PhysxDynamicActor();

	// IActor methods.
	IPhysicsEnvironment*									GetEnvironment() const;
	IRigidActor*											AsRigid() const;

	// IRigidActor methods.
	void													SetWorldTransform( const math::Matrix4x4& transform );
	void													GetWorldTransform( math::Matrix4x4& transform ) const;
	IShape*													GetShape() const;

	// IRigidBody methods.
	void													AddForce( const ForceMode& mode, const math::Vector3& force );
	void													AddTorque( const ForceMode& mode, const math::Vector3& torque );
	void													ClearForce( const ForceMode& mode );
	void													ClearTorque( const ForceMode& mode );
	void													SetMass( Float mass );
	void													SetInertia( const math::Vector3& inertia );
	void													SetMaximumLinearVelocity( Float velocity );
	void													SetMaximumAngularVelocity( Float velocity );
	Float													GetMass() const;
	void													GetInertia( math::Vector3& inertia ) const;
	Float													GetMaximumLinearVelocity() const;
	Float													GetMaximumAngularVelocity() const;

	// IDynamicActor methods.
	void													SetLinearVelocity( const math::Vector3& velocity );
	void													SetAngularVelocity( const math::Vector3& velocity );
	void													GetLinearVelocity( math::Vector3& velocity ) const;
	void													GetAngularVelocity( math::Vector3& velocity ) const;

private:
	physx::PxRigidDynamic*									_actor;
	P(IShape)												_shape;
};


} // phys


} // synkro


#endif // _SYNKRO_PHYS_PHYSXDYNAMICACTOR_
