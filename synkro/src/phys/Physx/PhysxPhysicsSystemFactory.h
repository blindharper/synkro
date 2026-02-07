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
// Purpose: PhysX physics system factory.
//==============================================================================
#ifndef _SYNKRO_PHYS_PHYSXPHYSICSSYSTEMFACTORY_
#define _SYNKRO_PHYS_PHYSXPHYSICSSYSTEMFACTORY_


#include "config.h"
#include <core/FactoryImpl.h>
#include <phys/IPhysicsSystemFactory.h>
#include <phys/PhysicsSystem.h>
#include "PhysxPhysicsSystem.h"


namespace synkro
{


namespace phys
{


// PhysX physics system factory.
SYNKRO_FACTORY_BEGIN( PhysxPhysicsSystemFactory, IPhysicsSystemFactory, PhysicsSystem, PhysicsSystem::PhysX )
	IPhysicsSystem*	Create( diag::ILog* log ) { return new PhysxPhysicsSystem(log); }
SYNKRO_FACTORY_END()


} // phys


} // synkro


#endif // _SYNKRO_PHYS_PHYSXPHYSICSSYSTEMFACTORY_
