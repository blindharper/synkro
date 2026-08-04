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
#include "config.h"
#include "PhysxPhysicsEnvironment.h"
#include "PhysxStaticActor.h"
#include "PhysxDynamicActor.h"
#include "Physx.h"
#include <physx/include/extensions/PxDefaultSimulationFilterShader.h>


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::lang;
using namespace synkro::math;
using namespace physx;

//------------------------------------------------------------------------------


namespace synkro
{


namespace phys
{


PhysxPhysicsEnvironment::PhysxPhysicsEnvironment( PxPhysics* physics, const String& name, Float speed ) :
	PhysicsEnvironmentImpl<IPhysicsEnvironment>( name ),
	_physics( physics ),
	_speed( speed )
{
	_cpuDispatcher = PxDefaultCpuDispatcherCreate( 2 );
	PxSceneDesc sceneDesc( physics->getTolerancesScale() );
	sceneDesc.gravity = PxVec3( 0.0f, -9.81f, 0.0f );
	sceneDesc.cpuDispatcher = _cpuDispatcher;
	sceneDesc.filterShader = PxDefaultSimulationFilterShader;
	_environment = _physics->createScene( sceneDesc );
	
	PhysicsEnvironmentImpl<IPhysicsEnvironment>::SetGravity( Vector3(sceneDesc.gravity.x, sceneDesc.gravity.y, sceneDesc.gravity.z) );
}

PhysxPhysicsEnvironment::~PhysxPhysicsEnvironment()
{
	PX_RELEASE( _environment );
	PX_RELEASE( _cpuDispatcher );
}

void PhysxPhysicsEnvironment::Update( Double delta )
{
	_environment->simulate( _speed*delta );
	_environment->fetchResults( true );
}

IStaticActor* PhysxPhysicsEnvironment::CreateStaticActor( const Matrix4x4& transform, IShape* shape )
{
	return new PhysxStaticActor( _physics, _environment, transform, shape );
}

IDynamicActor* PhysxPhysicsEnvironment::CreateDynamicActor( const Matrix4x4& transform, IShape* shape, Float density )
{
	return new PhysxDynamicActor( _physics, _environment, transform, shape, density );
}

void PhysxPhysicsEnvironment::SetGravity( const Vector3& gravity )
{
	// Call base implementation.
	PhysicsEnvironmentImpl<IPhysicsEnvironment>::SetGravity( gravity );

	_environment->setGravity( Physx::Convert(gravity) );
}


} // phys


} // synkro
