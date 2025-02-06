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
// Purpose: Defines abstract factory.
//==============================================================================
#ifndef _SYNKRO_CORE_IFACTORY_
#define _SYNKRO_CORE_IFACTORY_


#include "config.h"
#include <core/Iface.h>


namespace synkro
{


namespace core
{


/**
 * Abstract factory.
 */
iface IFactory
{
public:
	/** 
	 * Retrieves factory interface identifier.
	 * @return Interface identifier.
	 */
	virtual Iface											GetIfaceID() const = 0;

	/** 
	 * Retrieves actual type of object produced by the factory.
	 * @return Class identifier.
	 */
	virtual lang::Enum										GetClassID() const = 0;
};


} // core


} // synkro


#endif // _SYNKRO_CORE_IFACTORY_
