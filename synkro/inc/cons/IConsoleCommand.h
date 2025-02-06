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
// Purpose: Defines abstract console command.
//==============================================================================
#ifndef _SYNKRO_CONS_ICONSOLECOMMAND_
#define _SYNKRO_CONS_ICONSOLECOMMAND_


#include "config.h"
#include <core/IObject.h>
#include <lang/String.h>


namespace synkro
{


namespace cons
{


/**
 * Abstract console command.
 */
iface IConsoleCommand :
	public core::IObject
{
public:
	/**
	 * Executes the command.
	 * @param arg Command argument.
	 */
	virtual void											Execute( const lang::String& arg ) = 0;

	/**
	 * Retrieves command description.
	 */
	virtual lang::String									GetDescription() const = 0;

	/**
	 * Retrieves command syntax.
	 */
	virtual lang::String									GetSyntax() const = 0;
};


} // cons


} // synkro


#endif // _SYNKRO_CONS_ICONSOLECOMMAND_
