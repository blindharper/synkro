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
#include "config.h"
#include "PhysxPlaneShape.h"
#include "Physx.h"
#include <physx/include/foundation/PxMathUtils.h>


//------------------------------------------------------------------------------

using namespace synkro::math;
using namespace physx;

//------------------------------------------------------------------------------


namespace synkro
{


namespace phys
{


PhysxPlaneShape::PhysxPlaneShape( PxPhysics* physics, IPhysicsMaterial* material, const Vector3& normal, Float distance ) :
	PhysxShapeImpl<IShape>( physics, PxPlaneGeometry(), material )
{
	PxTransform trans = PxTransformFromPlaneEquation( PxPlane(normal.x, normal.y, normal.z, distance) );
	Physx::Convert( trans, _transform );
}

PxShape* PhysxPlaneShape::AsPhysxShape() const
{
	return _shape;
}


} // phys


} // synkro
