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
#ifndef _SYNKRO_PHYS_PHYSXPHYSICSSYSTEM_
#define _SYNKRO_PHYS_PHYSXPHYSICSSYSTEM_


#include "config.h"
#include <core/ObjectImpl.h>
#include <phys/IPhysicsSystem.h>
#include <physx/include/PxPhysicsAPI.h>


namespace synkro
{


namespace phys
{


// PhysX physics system.
class PhysxPhysicsSystem :
	public core::ObjectImpl<IPhysicsSystem>
{
public:
	// Constructor & destructor.
	PhysxPhysicsSystem( diag::ILog* log );
	~PhysxPhysicsSystem();

	// ISystem methods.
	Bool													Update( Double delta );

	// IPhysicsSystem methods.
	IPhysicsEnvironment*									CreateEnvironment( const lang::String& name );
	IPhysicsMaterial*										CreateMaterial( Float staticFriction, Float dynamicFriction, Float restitution );
	IShape*													CreatePlaneShape( IPhysicsMaterial* material, const math::Vector3& normal, Float distance );
	IShape*													CreateBoxShape( IPhysicsMaterial* material, Float width, Float depth, Float height );
	IShape*													CreateCapsuleShape( IPhysicsMaterial* material, Float radius, Float height );

private:
	physx::PxFoundation*									_foundation;
	physx::PxPhysics*										_physics;
};


} // phys


} // synkro


#endif // _SYNKRO_PHYS_PHYSXPHYSICSSYSTEM_
