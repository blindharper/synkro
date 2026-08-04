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
// Purpose: Wrapper dynamic actor.
//=============================================================================
#ifndef _SYNKRO_PHYS_DYNAMICACTOR_
#define _SYNKRO_PHYS_DYNAMICACTOR_


#include "config.h"
#include <core/ObjectImpl.h>
#include <phys/IDynamicActor.h>
#include <phys/IShape.h>


namespace synkro
{


namespace phys
{


// Wrapper dynamic actor.
class DynamicActor :
	public core::ObjectImpl<IDynamicActor>
{
public:
	// Constructor.
	DynamicActor( IPhysicsEnvironment* environment, IDynamicActor* actor, IShape* shape );

	// IActor methods.
	IPhysicsEnvironment*									GetEnvironment() const;
	IRigidActor*											AsRigid() const;

	// IRigidActor methods.
	void													SetWorldTransform( const math::Matrix4x4& transform );
	void													GetWorldTransform( math::Matrix4x4& transform ) const;
	IShape*													GetShape() const;
	IRigidBody*												AsBody() const;

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
	IDynamicActor*											AsDynamic() const;

	// IDynamicActor methods.
	void													SetLinearVelocity( const math::Vector3& velocity );
	void													SetAngularVelocity( const math::Vector3& velocity );
	void													GetLinearVelocity( math::Vector3& velocity ) const;
	void													GetAngularVelocity( math::Vector3& velocity ) const;

private:
	IPhysicsEnvironment*									_environment;
	P(IDynamicActor)										_actor;
	P(IShape)												_shape;
};


} // phys


} // synkro


#endif // _SYNKRO_PHYS_DYNAMICACTOR_
