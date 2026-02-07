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
// Purpose: PhysX base shape.
//==============================================================================
#ifndef _SYNKRO_PHYS_PHYSXBASESHAPE_
#define _SYNKRO_PHYS_PHYSXBASESHAPE_


#include "config.h"
#include <physx/include/PxShape.h>


namespace synkro
{


namespace phys
{


// PhysX base shape.
class PhysxBaseShape
{
public:
	// Returns underlying shape.
	virtual physx::PxShape*									AsPhysxShape() const = 0;
};


// Casts object to PhysxBaseShape.
#define AsPhysxBaseShape( OBJ ) dynamic_cast<PhysxBaseShape*>( OBJ )


} // phys


} // synkro


#endif // _SYNKRO_PHYS_PHYSXBASESHAPE_
