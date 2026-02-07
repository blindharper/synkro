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
// Purpose: PhysX plane collision shape.
//=============================================================================
#ifndef _SYNKRO_PHYS_PHYSXPLANESHAPE_
#define _SYNKRO_PHYS_PHYSXPLANESHAPE_


#include "config.h"
#include "PhysxShapeImpl.h"
#include <phys/IShape.h>
#include "PhysxBaseShape.h"


namespace synkro
{


namespace phys
{


// PhysX plane collision shape.
class PhysxPlaneShape :
	public PhysxShapeImpl<IShape>,
	public PhysxBaseShape
{
public:
	// Constructor.
	PhysxPlaneShape( physx::PxPhysics* physics, IPhysicsMaterial* material, const math::Vector3& normal, Float distance );

	// PhysxBaseShape methods.
	physx::PxShape*											AsPhysxShape() const;
};


} // phys


} // synkro


#endif // _SYNKRO_PHYS_PHYSXPLANESHAPE_
