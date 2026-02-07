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
// Purpose: Generic physical material implementation.
//=============================================================================
#ifndef _SYNKRO_PHYS_PHYSICSMATERIALIMPL_
#define _SYNKRO_PHYS_PHYSICSMATERIALIMPL_


#include "config.h"
#include <core/ObjectImpl.h>


namespace synkro
{


namespace phys
{


// Generic material implementation.
template <class T>
class PhysicsMaterialImpl :
	public core::ObjectImpl<T>
{
public:
	// Constructor & destructor.
	PhysicsMaterialImpl( Float staticFriction, Float dynamicFriction, Float restitution );
	virtual ~PhysicsMaterialImpl();

	// IPhysicsMaterial methods.
	virtual void											SetStaticFriction( Float friction );
	virtual void											SetDynamicFriction( Float friction );
	virtual void											SetRestitution( Float restitution );
	virtual Float											GetStaticFriction() const;
	virtual Float											GetDynamicFriction() const;
	virtual Float											GetRestitution() const;

protected:
	Float													_staticFriction;
	Float													_dynamicFriction;
	Float													_restitution;
};


#include "PhysicsMaterialImpl.inl"


} // phys


} // synkro


#endif // _SYNKRO_PHYS_PHYSICSMATERIALIMPL_
