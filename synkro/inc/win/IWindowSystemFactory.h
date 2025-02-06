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
// Purpose: Defines window system factory.
//==============================================================================
#ifndef _SYNKRO_WIN_IWINDOWSYSTEMFACTORY_
#define _SYNKRO_WIN_IWINDOWSYSTEMFACTORY_


#include "config.h"
#include <core/IFactory.h>


namespace synkro
{


namespace win
{


/**
 * Window system factory.
 */
iface IWindowSystemFactory :
	public core::IFactory
{
public:
	/**
	 * Creates a window system.
	 * @param module Application module handle.
	 * @param log Log to write debug messages to.
	 * @return Created window system.
	 */
	virtual IWindowSystem*									Create( Pointer module, diag::ILog* log ) = 0;
};


} // win


} // synkro


#endif // _SYNKRO_WIN_IWINDOWSYSTEMFACTORY_
