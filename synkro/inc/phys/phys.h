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
// Purpose: 'phys' namespace includes.
//==============================================================================
#ifndef _SYNKRO_PHYS_
#define _SYNKRO_PHYS_


#include <phys/PhysicsSystem.h>
#include <phys/PhysicsListener.h>
#include <phys/IPhysicsEnvironmentEx.h>
#include <phys/IPhysicsMaterial.h>
#include <phys/IShape.h>
#include <phys/IDynamicActor.h>
#include <phys/IStaticActor.h>
#include <phys/IPhysicsSystemEx.h>


#define PtrPhysicsEnvironmentEx P(synkro::phys::IPhysicsEnvironmentEx)
#define PtrPhysicsMaterial P(synkro::phys::IPhysicsMaterial)
#define PtrShape P(synkro::phys::IShape)
#define PtrDynamicActor P(synkro::phys::IDynamicActor)
#define PtrStaticActor P(synkro::phys::IStaticActor)


namespace synkro
{


/**
 * The 'phys' namespace contains interfaces
 * for performing physical simulations.
 */
namespace phys
{
} // phys


} // synkro


#endif // _SYNKRO_PHYS_
