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
// Purpose: PhysX box collision shape.
//=============================================================================
#ifndef _SYNKRO_PHYS_PHYSXBOXSHAPE_
#define _SYNKRO_PHYS_PHYSXBOXSHAPE_


#include "config.h"
#include "PhysxShapeImpl.h"
#include <phys/IShape.h>
#include "PhysxBaseShape.h"


namespace synkro
{


namespace phys
{


// PhysX box collision shape.
class PhysxBoxShape :
	public PhysxShapeImpl<IShape>,
	public PhysxBaseShape
{
public:
	// Constructor.
	PhysxBoxShape( physx::PxPhysics* physics, IPhysicsMaterial* material, Float width, Float depth, Float height );

	// PhysxBaseShape methods.
	physx::PxShape*											AsPhysxShape() const;
};


} // phys


} // synkro


#endif // _SYNKRO_PHYS_PHYSXBOXSHAPE_
