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
// Purpose: Defines abstract physics actor.
//==============================================================================
#ifndef _SYNKRO_PHYS_IACTOR_
#define _SYNKRO_PHYS_IACTOR_


#include "config.h"
#include <core/IObject.h>


namespace synkro
{


namespace phys
{


/**
 * Physics actor.
 */
iface IActor :
	public core::IObject
{
public:
	/**
	 * Retrieves environment owning the actor.
	 */
	virtual IPhysicsEnvironment*							GetEnvironment() const = 0;

	/**
	 * Casts actor to rigid actor.
	 * @return Non-null for rigid actor, nullptr otherwise.
	 */
	virtual IRigidActor*									AsRigid() const = 0;
};


} // phys


} // synkro


#endif // _SYNKRO_PHYS_IACTOR_
