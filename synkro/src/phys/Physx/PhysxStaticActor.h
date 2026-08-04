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
#ifndef _SYNKRO_PHYS_PHYSXSTATICACTOR_
#define _SYNKRO_PHYS_PHYSXSTATICACTOR_


#include "config.h"
#include <core/ObjectImpl.h>
#include <phys/IStaticActor.h>
#include <phys/IShape.h>
#include <physx/include/PxRigidStatic.h>
#include <physx/include/PxPhysics.h>
#include <physx/include/PxScene.h>


namespace synkro
{


namespace phys
{


// PhysX static actor.
class PhysxStaticActor :
	public core::ObjectImpl<IStaticActor>
{
public:
	// Constructor & destructor.
	PhysxStaticActor( physx::PxPhysics* physics, physx::PxScene* environment, const math::Matrix4x4& transform, IShape* shape );
	~PhysxStaticActor();

	// IActor methods.
	IPhysicsEnvironment*									GetEnvironment() const;
	IRigidActor*											AsRigid() const;

	// IRigidActor methods.
	void													SetWorldTransform( const math::Matrix4x4& transform );
	void													GetWorldTransform( math::Matrix4x4& transform ) const;
	IShape*													GetShape() const;
	IRigidBody*												AsBody() const;

private:
	physx::PxRigidStatic*									_actor;
	P(IShape)												_shape;
};


} // phys


} // synkro


#endif // _SYNKRO_PHYS_PHYSXSTATICACTOR_
