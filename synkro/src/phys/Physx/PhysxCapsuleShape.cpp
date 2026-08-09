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
#include "config.h"
#include "PhysxCapsuleShape.h"
#include "Physx.h"


//------------------------------------------------------------------------------

using namespace synkro::math;
using namespace physx;

//------------------------------------------------------------------------------


namespace synkro
{


namespace phys
{


PhysxCapsuleShape::PhysxCapsuleShape( PxPhysics* physics, IPhysicsMaterial* material, Float radius, Float height ) :
	PhysxShapeImpl<IShape>( physics, PxCapsuleGeometry(radius, 0.5f*height), material )
{
	Matrix4x4 trans;
	trans.SetOrientation( Quaternion(Vector3::Z, Math::HalfPi) );
	_shape->setLocalPose( Physx::Convert(trans) );
}

PxShape* PhysxCapsuleShape::AsPhysxShape() const
{
	return _shape;
}


} // phys


} // synkro
