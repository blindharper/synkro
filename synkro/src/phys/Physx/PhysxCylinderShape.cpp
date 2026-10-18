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
#include "config.h"
#include "PhysxCylinderShape.h"
#include "Physx.h"
#include <internal/SafeDelete.h>


//------------------------------------------------------------------------------

using namespace synkro::math;
using namespace physx;

//------------------------------------------------------------------------------


namespace synkro
{


namespace phys
{


PhysxCylinderShape::PhysxCylinderShape( PxPhysics* physics, IPhysicsMaterial* material, Float radius, Float height ) :
	PhysxShapeImpl<IShape>( physics, PxCustomGeometry(*(_cylinder = new PxCustomGeometryExt::CylinderCallbacks(height, radius, 1))), material )
{
}

PhysxCylinderShape::~PhysxCylinderShape()
{
	SafeDelete( _cylinder );
}

PxShape* PhysxCylinderShape::AsPhysxShape() const
{
	return _shape;
}


} // phys


} // synkro
