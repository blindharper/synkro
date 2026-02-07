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
// Purpose: PhysX static actor.
//=============================================================================
#include "config.h"
#include "PhysxStaticActor.h"
#include "PhysxBaseShape.h"
#include "Physx.h"
#include <phys/IShape.h>


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::math;
using namespace physx;

//------------------------------------------------------------------------------


namespace synkro
{


namespace phys
{


PhysxStaticActor::PhysxStaticActor( PxPhysics* physics, PxScene* environment, const Matrix4x4& transform, IShape* shape ) :
	_shape( shape )
{
	_actor = physics->createRigidStatic( Physx::Convert(transform) );
	_actor->attachShape( *AsPhysxBaseShape(shape)->AsPhysxShape() );
	environment->addActor( *_actor );
}

PhysxStaticActor::~PhysxStaticActor()
{
	PX_RELEASE( _actor );
}

IPhysicsEnvironment* PhysxStaticActor::GetEnvironment() const
{
	return nullptr;
}

IRigidActor* PhysxStaticActor::AsRigid() const
{
	return nullptr;
}

void PhysxStaticActor::SetWorldTransform( const Matrix4x4& transform )
{
	_actor->setGlobalPose( Physx::Convert(transform) );
}

void PhysxStaticActor::GetWorldTransform( Matrix4x4& transform ) const
{
	Physx::Convert( _actor->getGlobalPose(), transform );
}

IShape* PhysxStaticActor::GetShape() const
{
	return _shape;
}


} // phys


} // synkro
