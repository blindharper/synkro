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
// Purpose: PhysX API.
//==============================================================================
#ifndef _SYNKRO_PHYS_PHYSX_
#define _SYNKRO_PHYS_PHYSX_


#include "config.h"
#include <math/Matrix4x4.h>
#include <math/Vector3.h>
#include <math/Quaternion.h>
#include <phys/ForceMode.h>
#include <physx/include/foundation/PxTransform.h>
#include <physx/include/foundation/PxVec3.h>
#include <physx/include/foundation/PxQuat.h>
#include <physx/include/PxForceMode.h>


namespace synkro
{


namespace phys
{


// PhysX API.
class Physx
{
public:
	static void												Convert( const physx::PxTransform& trans, math::Matrix4x4& transform );
	static physx::PxTransform								Convert( const math::Matrix4x4& trans );
	static physx::PxVec3									Convert( const math::Vector3& vec );
	static physx::PxQuat									Convert( const math::Quaternion& quat );
	static physx::PxForceMode::Enum							Convert( const phys::ForceMode& mode );
};


} // phys


} // synkro


#endif // _SYNKRO_PHYS_PHYSX_
