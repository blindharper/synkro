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
// Purpose: PhysX cylinder collision shape.
//=============================================================================
#ifndef _SYNKRO_PHYS_PHYSXCYLINDERSHAPE_
#define _SYNKRO_PHYS_PHYSXCYLINDERSHAPE_


#include "config.h"
#include "PhysxShapeImpl.h"
#include <phys/IShape.h>
#include "PhysxBaseShape.h"
#include <physx/include/extensions/PxCustomGeometryExt.h>


namespace synkro
{


namespace phys
{


// PhysX cylinder collision shape.
class PhysxCylinderShape :
	public PhysxShapeImpl<IShape>,
	public PhysxBaseShape
{
public:
	// Constructor & destructor.
	PhysxCylinderShape( physx::PxPhysics* physics, IPhysicsMaterial* material, Float radius, Float height );
	~PhysxCylinderShape();

	// PhysxBaseShape methods.
	physx::PxShape*											AsPhysxShape() const;

private:
	physx::PxCustomGeometryExt::CylinderCallbacks*			_cylinder;
};


} // phys


} // synkro


#endif // _SYNKRO_PHYS_PHYSXCYLINDERSHAPE_
