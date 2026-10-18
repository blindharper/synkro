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
// Purpose: PhysX cone collision shape.
//=============================================================================
#ifndef _SYNKRO_PHYS_PHYSXCONESHAPE_
#define _SYNKRO_PHYS_PHYSXCONESHAPE_


#include "config.h"
#include "PhysxShapeImpl.h"
#include <phys/IShape.h>
#include "PhysxBaseShape.h"
#include <physx/include/extensions/PxCustomGeometryExt.h>


namespace synkro
{


namespace phys
{


// PhysX cone collision shape.
class PhysxConeShape :
	public PhysxShapeImpl<IShape>,
	public PhysxBaseShape
{
public:
	// Constructor & destructor.
	PhysxConeShape( physx::PxPhysics* physics, IPhysicsMaterial* material, Float radius, Float height );
	~PhysxConeShape();

	// PhysxBaseShape methods.
	physx::PxShape*											AsPhysxShape() const;

private:
	physx::PxCustomGeometryExt::ConeCallbacks*				_cone;
};


} // phys


} // synkro


#endif // _SYNKRO_PHYS_PHYSXCONESHAPE_
