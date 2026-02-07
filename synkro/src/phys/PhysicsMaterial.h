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
// Purpose: Wrapper physics material.
//=============================================================================
#ifndef _SYNKRO_PHYS_PHYSICSMATERIAL_
#define _SYNKRO_PHYS_PHYSICSMATERIAL_


#include "config.h"
#include <core/ObjectImpl.h>
#include <phys/IPhysicsMaterial.h>


namespace synkro
{


namespace phys
{


// Wrapper physics material.
class PhysicsMaterial :
	public core::ObjectImpl<IPhysicsMaterial>
{
public:
	// Constructor.
	PhysicsMaterial( IPhysicsMaterial* material );

	// IPhysicsMaterial methods.
	void													SetStaticFriction( Float friction );
	void													SetDynamicFriction( Float friction );
	void													SetRestitution( Float restitution );
	Float													GetStaticFriction() const;
	Float													GetDynamicFriction() const;
	Float													GetRestitution() const;

private:
	friend class PhysicsSystemEx;

	P(IPhysicsMaterial)										_material;
};


} // phys


} // synkro


#endif // _SYNKRO_PHYS_PHYSICSMATERIAL_
