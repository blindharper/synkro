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
#include "config.h"
#include "PhysxConeShape.h"
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


PhysxConeShape::PhysxConeShape( PxPhysics* physics, IPhysicsMaterial* material, Float radius, Float height ) :
	PhysxShapeImpl<IShape>( physics, PxCustomGeometry(*(_cone = new PxCustomGeometryExt::ConeCallbacks(height, radius, 1))), material )
{
}

PhysxConeShape::~PhysxConeShape()
{
	SafeDelete( _cone );
}

PxShape* PhysxConeShape::AsPhysxShape() const
{
	return _shape;
}


} // phys


} // synkro
