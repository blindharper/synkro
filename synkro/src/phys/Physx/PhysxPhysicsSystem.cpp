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
// Purpose: PhysX physics system.
//=============================================================================
#include "config.h"
#include "PhysxPhysicsSystem.h"
#include "PhysxPhysicsMaterial.h"
#include "PhysxBoxShape.h"
#include "PhysxPlaneShape.h"
#include "PhysxPhysicsEnvironment.h"


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::diag;
using namespace synkro::lang;
using namespace synkro::math;
using namespace physx;

//------------------------------------------------------------------------------


static PxDefaultAllocator _allocator;
static PxDefaultErrorCallback _callback;

namespace synkro
{


namespace phys
{


PhysxPhysicsSystem::PhysxPhysicsSystem( ILog* log ) :
	_foundation( NULL ),
	_physics( NULL )
{
	_foundation = PxCreateFoundation( PX_PHYSICS_VERSION, _allocator, _callback );
	_physics = PxCreatePhysics( PX_PHYSICS_VERSION, *_foundation, PxTolerancesScale(), true );
}

PhysxPhysicsSystem::~PhysxPhysicsSystem()
{
	PX_RELEASE( _physics );
	PX_RELEASE( _foundation );
}

Bool PhysxPhysicsSystem::Update( Double delta )
{
	return true;
}

IPhysicsEnvironment* PhysxPhysicsSystem::CreateEnvironment( const String& name )
{
	return new PhysxPhysicsEnvironment( _physics, name );
}

IPhysicsMaterial* PhysxPhysicsSystem::CreateMaterial( Float staticFriction, Float dynamicFriction, Float restitution )
{
	return new PhysxPhysicsMaterial( _physics, staticFriction, dynamicFriction, restitution );
}

IShape* PhysxPhysicsSystem::CreatePlaneShape( IPhysicsMaterial* material, const Vector3& normal, Float distance )
{
	return new PhysxPlaneShape( _physics, material, normal, distance );
}

IShape* PhysxPhysicsSystem::CreateBoxShape( IPhysicsMaterial* material, Float width, Float depth, Float height )
{
	return new PhysxBoxShape( _physics, material, width, depth, height );
}


} // phys


} // synkro
