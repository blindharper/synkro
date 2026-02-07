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
// Purpose: Defines physics material.
//==============================================================================
#ifndef _SYNKRO_PHYS_IPHYSICSMATERIAL_
#define _SYNKRO_PHYS_IPHYSICSMATERIAL_


#include "config.h"
#include <core/IObject.h>


namespace synkro
{


namespace phys
{


/**
 * Physics material. Defines body's physical properties.
 */
iface IPhysicsMaterial :
	public core::IObject
{
public:
	/**
	 * Sets static friction coefficient for the material.
	 * @param friction Coefficient of static friction.
	 */
	virtual void											SetStaticFriction( Float friction ) = 0;

	/**
	 * Sets dynamic friction coefficient for the material.
	 * @param friction Coefficient of dynamic friction.
	 */
	virtual void											SetDynamicFriction( Float friction ) = 0;

	/**
	 * Sets resitution coefficient for the material.
	 * @param restitution Coefficient of resitution.
	 */
	virtual void											SetRestitution( Float restitution ) = 0;

	/**
	 * Retrieves static friction coefficient.
	 */
	virtual Float											GetStaticFriction() const = 0;

	/**
	 * Retrieves dynamic friction coefficient.
	 */
	virtual Float											GetDynamicFriction() const = 0;

	/**
	 * Retrieves restitution coefficient.
	 */
	virtual Float											GetRestitution() const = 0;
};


} // phys


} // synkro


#endif // _SYNKRO_PHYS_IPHYSICSMATERIAL_
