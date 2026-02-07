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
#include "config.h"
#include "PhysxDynamicActor.h"
#include "PhysxBaseShape.h"
#include "Physx.h"
#include <phys/IShape.h>
#include <physx/include/extensions/PxRigidBodyExt.h>


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::math;
using namespace physx;

//------------------------------------------------------------------------------


namespace synkro
{


namespace phys
{


PhysxDynamicActor::PhysxDynamicActor( PxPhysics* physics, PxScene* environment, const Matrix4x4& transform, IShape* shape, Float density ) :
	_shape( shape )
{
	_actor = physics->createRigidDynamic( Physx::Convert(transform) );
	_actor->attachShape( *AsPhysxBaseShape(shape)->AsPhysxShape() );
	PxRigidBodyExt::updateMassAndInertia( *_actor, density );
	environment->addActor( *_actor );
}

PhysxDynamicActor::~PhysxDynamicActor()
{
	PX_RELEASE( _actor );
}

IPhysicsEnvironment* PhysxDynamicActor::GetEnvironment() const
{
	return nullptr;
}

IRigidActor* PhysxDynamicActor::AsRigid() const
{
	return nullptr;
}

void PhysxDynamicActor::SetWorldTransform( const Matrix4x4& transform )
{
	_actor->setGlobalPose( Physx::Convert(transform) );
}

void PhysxDynamicActor::GetWorldTransform( Matrix4x4& transform ) const
{
	Physx::Convert( _actor->getGlobalPose(), transform );
}

IShape* PhysxDynamicActor::GetShape() const
{
	return _shape;
}

void PhysxDynamicActor::AddForce( const ForceMode& mode, const Vector3& force )
{
	_actor->addForce( Physx::Convert(force), Physx::Convert(mode) );
}

void PhysxDynamicActor::AddTorque( const ForceMode& mode, const Vector3& torque )
{
	_actor->addTorque( Physx::Convert(torque), Physx::Convert(mode) );
}

void PhysxDynamicActor::ClearForce( const ForceMode& mode )
{
	_actor->clearForce( Physx::Convert(mode) );
}

void PhysxDynamicActor::ClearTorque( const ForceMode& mode )
{
	_actor->clearTorque( Physx::Convert(mode) );
}

void PhysxDynamicActor::SetMass( Float mass )
{
	_actor->setMass( mass );
}

void PhysxDynamicActor::SetInertia( const Vector3& inertia )
{
	_actor->setMassSpaceInertiaTensor( Physx::Convert(inertia) );
}

void PhysxDynamicActor::SetMaximumLinearVelocity( Float velocity )
{
	_actor->setMaxLinearVelocity( velocity );
}

void PhysxDynamicActor::SetMaximumAngularVelocity( Float velocity )
{
	_actor->setMaxAngularVelocity( velocity );
}

Float PhysxDynamicActor::GetMass() const
{
	return _actor->getMass();
}

void PhysxDynamicActor::GetInertia( Vector3& inertia ) const
{
	PxVec3 t = _actor->getMassSpaceInertiaTensor();
	inertia.x = t.x;
	inertia.y = t.y;
	inertia.z = t.z;
}

Float PhysxDynamicActor::GetMaximumLinearVelocity() const
{
	return _actor->getMaxLinearVelocity();
}

Float PhysxDynamicActor::GetMaximumAngularVelocity() const
{
	return _actor->getMaxAngularVelocity();
}

void PhysxDynamicActor::SetLinearVelocity( const Vector3& velocity )
{
	_actor->setLinearVelocity( Physx::Convert(velocity) );
}

void PhysxDynamicActor::SetAngularVelocity( const Vector3& velocity )
{
	_actor->setAngularVelocity( Physx::Convert(velocity) );
}

void PhysxDynamicActor::GetLinearVelocity( Vector3& velocity ) const
{
	PxVec3 v = _actor->getLinearVelocity();
	velocity.x = v.x;
	velocity.y = v.y;
	velocity.z = v.z;
}

void PhysxDynamicActor::GetAngularVelocity( Vector3& velocity ) const
{
	PxVec3 v = _actor->getAngularVelocity();
	velocity.x = v.x;
	velocity.y = v.y;
	velocity.z = v.z;
}


} // phys


} // synkro
