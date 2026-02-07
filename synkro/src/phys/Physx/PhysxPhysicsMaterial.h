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
#ifndef _SYNKRO_PHYS_PHYSXPHYSICSMATERIAL_
#define _SYNKRO_PHYS_PHYSXPHYSICSMATERIAL_


#include "config.h"
#include <phys/PhysicsMaterialImpl.h>
#include <phys/IPhysicsMaterial.h>
#include "PhysxBaseMaterial.h"
#include <physx/include/PxMaterial.h>
#include <physx/include/PxPhysics.h>


namespace synkro
{


namespace phys
{


// PhysX physics material.
class PhysxPhysicsMaterial :
	public PhysicsMaterialImpl<IPhysicsMaterial>,
	public PhysxBaseMaterial
{
public:
	// Constructor.
	PhysxPhysicsMaterial( physx::PxPhysics* physics, Float staticFriction, Float dynamicFriction, Float restitution );

	// IPhysicsMaterial methods.
	void													SetStaticFriction( Float friction );
	void													SetDynamicFriction( Float friction );
	void													SetRestitution( Float restitution );

	// PhysxBaseMaterial methods.
	physx::PxMaterial*										AsPhysxMaterial() const;

private:
	physx::PxMaterial*										_material;
};


} // phys


} // synkro


#endif // _SYNKRO_PHYS_PHYSXPHYSICSMATERIAL_
