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
// Purpose: Defines static actor.
//==============================================================================
#ifndef _SYNKRO_PHYS_ISTATICACTOR_
#define _SYNKRO_PHYS_ISTATICACTOR_


#include "config.h"
#include <phys/IRigidActor.h>


namespace synkro
{


namespace phys
{


/**
 * Static actor.
 */
iface IStaticActor :
	public IRigidActor
{
public:
};


} // phys


} // synkro


#endif // _SYNKRO_PHYS_ISTATICACTOR_
