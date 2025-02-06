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
// Purpose: Defines console command factory.
//==============================================================================
#ifndef _SYNKRO_CONS_ICONSOLECOMMANDFACTORY_
#define _SYNKRO_CONS_ICONSOLECOMMANDFACTORY_


#include "config.h"
#include <core/IFactory.h>


namespace synkro
{


namespace cons
{


/**
 * Console command factory.
 */
iface IConsoleCommandFactory :
	public core::IFactory
{
public:
	/**
	 * Creates console command.
	 * @param console Console interface.
	 */
	virtual IConsoleCommand*								Create( IConsole* console ) = 0;

	/** 
	 * Retrieves command name.
	 */
	virtual lang::String									GetName() const = 0;

	/** 
	 * Retrieves command alias.
	 */
	virtual lang::String									GetAlias() const = 0;
};


} // cons


} // synkro


#endif // _SYNKRO_CONS_ICONSOLECOMMANDFACTORY_
