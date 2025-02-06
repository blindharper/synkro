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
// Purpose: Defines input system factory.
//==============================================================================
#ifndef _SYNKRO_INPUT_IINPUTSYSTEMFACTORY_
#define _SYNKRO_INPUT_IINPUTSYSTEMFACTORY_


#include "config.h"
#include <core/IFactory.h>


namespace synkro
{


namespace input
{


/**
 * Input system factory.
 */
iface IInputSystemFactory :
	public core::IFactory
{
public:
	/**
	 * Creates an input system.
	 * @param module Application module handle.
	 * @param windowSystem Window system.
	 * @param log Log to write debug messages to.
	 * @return Created input system.
	 */
	virtual IInputSystem*									Create( Pointer module, win::IWindowSystemEx* windowSystem, diag::ILog* log ) = 0;
};


} // input


} // synkro


#endif // _SYNKRO_INPUT_IINPUTSYSTEMFACTORY_
