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
// Purpose: PhysX physics material.
//=============================================================================
#include "config.h"
#include "PhysxPhysicsMaterial.h"


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace physx;

//------------------------------------------------------------------------------


namespace synkro
{


namespace phys
{


PhysxPhysicsMaterial::PhysxPhysicsMaterial( PxPhysics* physics, Float staticFriction, Float dynamicFriction, Float restitution ) :
	PhysicsMaterialImpl<IPhysicsMaterial>( staticFriction, dynamicFriction, restitution )
{
	_material = physics->createMaterial( staticFriction, dynamicFriction, restitution );
}

void PhysxPhysicsMaterial::SetStaticFriction( Float friction )
{
	// Call base implementation.
	PhysicsMaterialImpl<IPhysicsMaterial>::SetStaticFriction( friction );

	_material->setStaticFriction( friction );
}

void PhysxPhysicsMaterial::SetDynamicFriction( Float friction )
{
	// Call base implementation.
	PhysicsMaterialImpl<IPhysicsMaterial>::SetDynamicFriction( friction );

	_material->setDynamicFriction( friction );
}

void PhysxPhysicsMaterial::SetRestitution( Float restitution )
{
	// Call base implementation.
	PhysicsMaterialImpl<IPhysicsMaterial>::SetRestitution( restitution );

	_material->setRestitution( restitution );
}

PxMaterial* PhysxPhysicsMaterial::AsPhysxMaterial() const
{
	return _material;
}


} // phys


} // synkro
