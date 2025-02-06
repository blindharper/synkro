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
// Purpose: Defines abstract system.
//==============================================================================
#ifndef _SYNKRO_CORE_ISYSTEM_
#define _SYNKRO_CORE_ISYSTEM_


#include "config.h"
#include <core/IObject.h>


namespace synkro
{


namespace core
{


/**
 * Abstract system.
 */
iface ISystem :
	public IObject
{
public:
	/**
	 * Updates system by the given amount of time.
	 * @param delta Time passed since the last update.
	 * @return True if update succeded, false otherwise.
	 */
	virtual Bool											Update( Double delta ) = 0;
};


} // core


} // synkro


#endif // _SYNKRO_CORE_ISYSTEM_
