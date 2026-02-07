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
// Purpose: PhysX base material.
//==============================================================================
#ifndef _SYNKRO_PHYS_PHYSXBASEMATERIAL_
#define _SYNKRO_PHYS_PHYSXBASEMATERIAL_


#include "config.h"
#include <physx/include/PxMaterial.h>


namespace synkro
{


namespace phys
{


// PhysX base material.
class PhysxBaseMaterial
{
public:
	// Returns underlying material.
	virtual physx::PxMaterial*								AsPhysxMaterial() const = 0;
};


// Casts object to PhysxBaseMaterial.
#define AsPhysxBaseMaterial( OBJ ) dynamic_cast<PhysxBaseMaterial*>( OBJ )


} // phys


} // synkro


#endif // _SYNKRO_PHYS_PHYSXBASEMATERIAL_
