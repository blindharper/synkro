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
// Purpose: PhysX capsule collision shape.
//=============================================================================
#ifndef _SYNKRO_PHYS_PHYSXCAPSULESHAPE_
#define _SYNKRO_PHYS_PHYSXCAPSULESHAPE_


#include "config.h"
#include "PhysxShapeImpl.h"
#include <phys/IShape.h>
#include "PhysxBaseShape.h"


namespace synkro
{


namespace phys
{


// PhysX capsule collision shape.
class PhysxCapsuleShape :
	public PhysxShapeImpl<IShape>,
	public PhysxBaseShape
{
public:
	// Constructor.
	PhysxCapsuleShape( physx::PxPhysics* physics, IPhysicsMaterial* material, Float radius, Float height );

	// PhysxBaseShape methods.
	physx::PxShape*											AsPhysxShape() const;
};


} // phys


} // synkro


#endif // _SYNKRO_PHYS_PHYSXCAPSULESHAPE_
