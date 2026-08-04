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
// Purpose: PhysX physics environment.
//=============================================================================
#ifndef _SYNKRO_PHYS_PHYSXPHYSICSENVIRONMENT_
#define _SYNKRO_PHYS_PHYSXPHYSICSENVIRONMENT_


#include "config.h"
#include <phys/PhysicsEnvironmentImpl.h>
#include <phys/IPhysicsEnvironment.h>
#include <physx/include/PxPhysics.h>
#include <physx/include/PxScene.h>
#include <physx/include/PxSimulationEventCallback.h>
#include <physx/include/extensions/PxDefaultCpuDispatcher.h>


namespace synkro
{


namespace phys
{


// PhysX physics environment.
class PhysxPhysicsEnvironment :
	public PhysicsEnvironmentImpl<IPhysicsEnvironment>,
	public physx::PxSimulationEventCallback
{
public:
	// Constructor & destructor.
	PhysxPhysicsEnvironment( physx::PxPhysics* physics, const lang::String& name );
	~PhysxPhysicsEnvironment();

	// IPhysicsEnvironment methods.
	void													Update( Double delta );
	IStaticActor*											CreateStaticActor( const math::Matrix4x4& transform, IShape* shape );
	IDynamicActor*											CreateDynamicActor( const math::Matrix4x4& transform, IShape* shape, Float density );
	void													SetGravity( const math::Vector3& gravity );

	// physx::PxSimulationEventCallback methods.
	void													onConstraintBreak( physx::PxConstraintInfo* constraints, physx::PxU32 count );
	void													onWake( physx::PxActor** actors, physx::PxU32 count );
	void													onSleep( physx::PxActor** actors, physx::PxU32 count );
	void													onContact( const physx::PxContactPairHeader& pairHeader, const physx::PxContactPair* pairs, physx::PxU32 nbPairs );
	void													onTrigger( physx::PxTriggerPair* pairs, physx::PxU32 count );
	void													onAdvance( const physx::PxRigidBody*const* bodyBuffer, const physx::PxTransform* poseBuffer, const physx::PxU32 count );

private:
	physx::PxPhysics*										_physics;
	physx::PxDefaultCpuDispatcher*							_cpuDispatcher;
	physx::PxScene*											_environment;
};


} // phys


} // synkro


#endif // _SYNKRO_PHYS_PHYSXPHYSICSENVIRONMENT_
