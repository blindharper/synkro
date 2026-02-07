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
#include "config.h"
#include "PhysxBoxShape.h"


//------------------------------------------------------------------------------

using namespace physx;

//------------------------------------------------------------------------------


namespace synkro
{


namespace phys
{


PhysxBoxShape::PhysxBoxShape( PxPhysics* physics, IPhysicsMaterial* material, Float width, Float depth, Float height ) :
	PhysxShapeImpl<IShape>( physics, PxBoxGeometry(0.5f*width, 0.5f*height, 0.5f*depth), material )
{
}

PxShape* PhysxBoxShape::AsPhysxShape() const
{
	return _shape;
}


} // phys


} // synkro
